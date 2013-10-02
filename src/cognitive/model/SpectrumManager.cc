
// CRAHNs Model END
// @author:  Marco Di Felice


#include "SpectrumManager.h"

NS_LOG_COMPONENT_DEFINE ("CogSpectrumManager");

namespace ns3 {
//SpectrumManager Initializer
SpectrumManager::SpectrumManager(Ptr<WifiMac> mac, int id): ttimer_(this) {

	mac_=mac;
	nodeId_=id;

	// State Initialization
	pu_on_=false;	
	sensing_=false;

	// Spectrum Module Definition
	sensingMod_=new SpectrumSensing(this);
	decisionMod_=new SpectrumDecision(this);
	mobilityMod_=new SpectrumMobility(this);



}



//SpectrumManager Initializer
SpectrumManager::SpectrumManager(Ptr<WifiMac> mac, Ptr<WifiPhy> phy,
    int id, Time sense_time, Time transmit_time): ttimer_(this)  {

	mac_=mac;
	nodeId_=id;
	m_wifiPhy = phy;
	pu_on_=false;
	sensing_=false;	

	// State Initialization
	sense_time_=sense_time;
	transmit_time_=transmit_time;

	// Spectrum Module Definition
	sensingMod_=new SpectrumSensing(this);
	decisionMod_=new SpectrumDecision(this);
	mobilityMod_=new SpectrumMobility(this);

}



//start: CR starts sensing on the current channel
void
SpectrumManager::start() {

	// Retrive the current channel on which the CR is tuned on the RECEIVER interface

	//int current_channel=m_repository->get_recv_channel(nodeId_);
	// Load spectrum characteristics (bandwidth, PER, ...)

	//TODO load spectrum in mac layer
	//mac_->load_spectrum(dataMod_->get_spectrum_data(current_channel));

	// Start sensing on the current channel for a sense_time_ interval
  Simulator::Schedule (sense_time_, &SpectrumManager::senseHandler, this);

}


//is_channel_available: return true if CR is NOT doing sensing and is NOT doing spectrum handoff
bool 
SpectrumManager::is_channel_available() {

	bool available= !(sensing_ || mobilityMod_->is_switching());

	return available;

}



// is_PU_interfering: return true if there is a PU which is transmitting on the same channel and within the tx range of the CR receiving a packet
bool 
SpectrumManager::is_PU_interfering(Time txDuration) {

	// Get the tx time of a packet
	Time time_tx=txDuration;
	// Check if a PU is active in the interval [now: now+time_tx]
	int  current_channel=m_repository->get_recv_channel(nodeId_);
	bool interference=sensingMod_->sense(nodeId_,time_tx,transmit_time_, current_channel);

#ifdef SENSING_VERBOSE_MODE
	if (interference)
	  {
	    char buffer [50];
	    std::sprintf(buffer, "[SENSING-DBG] Node %d sensed some PU activity on channel %d while receiving data\n", nodeId_,current_channel);
	    NS_LOG_DEBUG (buffer);
	  }
#endif
	return interference;
}



/*********************************************************
 * SETUP METHODS
 * *******************************************************/

//setPUmodel: set the current PU model
void
SpectrumManager::setPUmodel(double prob, Ptr<PUModel> p) {

	sensingMod_=new SpectrumSensing(this,prob,p);

}



//setRepository: set the current cross-layer repository
void
SpectrumManager::setRepository(Ptr<Repository> rep) {

  m_repository=rep;
}


//setSpectrumData: set the current Spectrum Loader module
void 
SpectrumManager::setSpectrumData(SpectrumData *sd) {

	dataMod_=sd;

}







/*********************************************************
 * TIMER METHODS
 * *******************************************************/

//senseHandler: handler for sensing timer. 
//Check if PU was detected during the last sensing interval, in case ask the spectrumDecision to switch to a new channel.
//In case of channel switching, use Spectrum Mobility to perform handoff, and notify the event to the upper layers.
void 
SpectrumManager::senseHandler() {

	bool need_to_switch=false;

	int  current_channel=m_repository->get_recv_channel(nodeId_);

#ifdef SENSING_VERBOSE_MODE //abdulla
	char buffer [100];
	std::sprintf(buffer, "[SENSING-DBG] Node %d is on channel %d and PU activity is %s", nodeId_, current_channel, (pu_on_)?"true":"false");
	NS_LOG_DEBUG(buffer);
#endif

	// Check if PU was detected 
	if (pu_on_) {

		// Ask the Spectrum Decision if channel switching is needed
		need_to_switch=decisionMod_->decideSwitch();

		// CR needs to vacate the channel
		if (need_to_switch) {

			// Starts handoff timer
			mobilityMod_->performHandoff();

			// Channel allocation is decided at MAC Layer
#ifdef CHANNEL_DECISION_MAC_LAYER

			// Choose next channel and store the information in the shared repository
			int next_channel=decisionMod_->decideSpectrum(current_channel);

			m_repository->set_recv_channel(nodeId_,next_channel);
			// Load the spectrum data for the new channel
			//TODO; make sure you tie up the mac layer
			//mac_->load_spectrum(dataMod_->get_spectrum_data(next_channel));

#endif

#ifdef ENABLE_SPECTRUM_HANDOFF_NOTIFICATION
			// Notify the spectrum handoff to the upper layers
			//TODO; make sure you tie up the mac layer
			//mac_->notifyUpperLayer(current_channel);
#endif

#ifdef SENSING_VERBOSE_MODE
			char buffer [100];
			std::sprintf(buffer, "[SENSING-DBG] Node %d starts handoff on channel %d to channel %d",nodeId_,current_channel,next_channel);
			NS_LOG_DEBUG (buffer);
#endif

			// Sensing Time is off, since the node is performing a spectrum handoff
			sensing_=false;

		} else  {

			// CR does not vacate the spectrum, but it must not interfere with PU activity
			// In this case, CR keeps sensing and waits for the channel to be free 	
			pu_on_= sensingMod_->sense(nodeId_,sense_time_,transmit_time_, current_channel);


			//printf("node: %i restarting sensor at time %f\n", nodeId_, Scheduler::instance().clock());
			NS_LOG_DEBUG ("restarting sensor");
			m_wifiPhy->StartSensing(sense_time_);
		  Simulator::Schedule (sense_time_, &SpectrumManager::senseHandler, this);
		  sensing_=true;

		}

	} else { //if pu is not on. without this else, sensetimer gets scheduled twice



		// Start/Stop the backoff timer
		//TODO; make sure you tie up the mac layer
		//mac_->checkBackoffTimer();

		// The CR can transmit if PU is not detected
		if ( !pu_on_ )  {

			// Sensing Time is on
			sensing_=false;

			// No channel switching, the CR can start transmitting on the current channel
			ttimer_.start(transmit_time_);

#ifdef SENSING_VERBOSE_MODE
			char buffer [50];
			std::sprintf(buffer, "[SENSING-DBG] Node %d starts transmitting on channel %d",nodeId_,current_channel);
			NS_LOG_DEBUG (buffer);
#endif
		}

	}
}





//transmitHandler: the CR stops transmitting, and starts sensing for PU detection
void 
SpectrumManager::transmitHandler() {

	int current_channel=m_repository->get_recv_channel(nodeId_);

	// Perform sensing on the current channel
	pu_on_= sensingMod_->sense(nodeId_,sense_time_,transmit_time_, current_channel);

	// Start the sensing interval
	Simulator::Schedule (sense_time_, &SpectrumManager::senseHandler, this);

	// Set the sensing ON
	sensing_=true;

#ifdef SENSING_VERBOSE_MODE
	char buffer [50];
	std::sprintf(buffer, "[SENSING-DBG] Node %d starts sensing on channel %d",nodeId_,current_channel);
	NS_LOG_DEBUG (buffer);
#endif

	// Stop any current backoff attempt
	//printf("starting sensing, calling backoff \n");
	//TODO; make sure you tie up the mac layer
	//mac_->checkBackoffTimer();
	m_wifiPhy->StartSensing(sense_time_);

}




//endHandoff: the CR has performed spectrum handoff to a new channel. Then, it starts sensing on it to detect PU activity.
void 
SpectrumManager::endHandoff() {

	int current_channel=m_repository->get_recv_channel(nodeId_);

	// Perform sensing on the new channel
	pu_on_ = sensingMod_->sense(nodeId_,sense_time_,transmit_time_, current_channel);

	// Start the sensing interval
  Simulator::Schedule (sense_time_, &SpectrumManager::senseHandler, this);

#ifdef SENSING_VERBOSE_MODE

	char buffer [50];
	std::sprintf(buffer,"[SENSING-DBG] Node %d ends handoff on channel %d",nodeId_,current_channel);
	NS_LOG_DEBUG (buffer);
	std::sprintf(buffer, "[SENSING-DBG] Node %d starts sensing on channel %d",nodeId_,current_channel);
	NS_LOG_DEBUG (buffer);

#endif

}

}
// CRAHNs Model END
// @author:  Marco Di Felice


