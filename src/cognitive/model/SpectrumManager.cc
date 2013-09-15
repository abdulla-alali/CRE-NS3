
// CRAHNs Model END
// @author:  Marco Di Felice


#include "SpectrumManager.h"

namespace ns3 {
//SpectrumManager Initializer
SpectrumManager::SpectrumManager(Mac802_11 *mac, int id): stimer_(this), ttimer_(this) {

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
SpectrumManager::SpectrumManager(Mac802_11 *mac, int id, double sense_time, double transmit_time): stimer_(this), ttimer_(this)  {

	mac_=mac;
	nodeId_=id;
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
	int current_channel=repository_->get_recv_channel(nodeId_);
	// Load spectrum characteristics (bandwidth, PER, ...)			
	mac_->load_spectrum(dataMod_->get_spectrum_data(current_channel));
	// Start sensing on the current channel for a sense_time_ interval
	stimer_.start(sense_time_);

}


//is_channel_available: return true if CR is NOT doing sensing and is NOT doing spectrum handoff
bool 
SpectrumManager::is_channel_available() {

	bool available= !(sensing_ || mobilityMod_->is_switching());

	return available;

}



// is_PU_interfering: return true if there is a PU which is transmitting on the same channel and within the tx range of the CR receiving a packet
bool 
SpectrumManager::is_PU_interfering(Packet *p) {
	DelayJitterEstimationTimestampTag tag;
	   bool found;
	   found = packet->FindFirstMatchingByteTag (tag);
	    if (!found)
	       {
	         return;
	       }
	    tag.GetTxTime ();
	// Get the tx time of a packet
	double time_tx=HDR_CMN(p)->txtime();
	// Check if a PU is active in the interval [now: now+time_tx]
	int  current_channel=repository_->get_recv_channel(nodeId_);
	bool interference=sensingMod_->sense(nodeId_,time_tx,transmit_time_, current_channel);

#ifdef SENSING_VERBOSE_MODE
	if (interference)	printf("[SENSING-DBG] Node %d sensed some PU activity on channel %d while receiving data\n", nodeId_,current_channel);
#endif
	return interference;
}



/*********************************************************
 * SETUP METHODS
 * *******************************************************/

//setPUmodel: set the current PU model
void
SpectrumManager::setPUmodel(double prob, PUmodel *p) {

	sensingMod_=new SpectrumSensing(this,prob,p);

}



//setRepository: set the current cross-layer repository
void
SpectrumManager::setRepository(Repository* rep) {

	repository_=rep;
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

	int  current_channel=repository_->get_recv_channel(nodeId_);

#ifdef SENSING_VERBOSE_MODE //abdulla
	printf("[SENSING-DBG] Node %d is on channel %d and PU activity is %s at time: %f\n", nodeId_, current_channel, (pu_on_)?"true":"false", Scheduler::instance().clock());
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

			repository_->set_recv_channel(nodeId_,next_channel);
			// Load the spectrum data for the new channel
			mac_->load_spectrum(dataMod_->get_spectrum_data(next_channel));

#endif

#ifdef ENABLE_SPECTRUM_HANDOFF_NOTIFICATION
			// Notify the spectrum handoff to the upper layers
			mac_->notifyUpperLayer(current_channel);
#endif

#ifdef SENSING_VERBOSE_MODE
			printf("[SENSING-DBG] Node %d starts handoff on channel %d to channel %d at time %f \n",nodeId_,current_channel,next_channel,Scheduler::instance().clock());
#endif

			// Sensing Time is off, since the node is performing a spectrum handoff
			sensing_=false;

		} else  {

			// CR does not vacate the spectrum, but it must not interfere with PU activity
			// In this case, CR keeps sensing and waits for the channel to be free 	
			pu_on_= sensingMod_->sense(nodeId_,sense_time_,transmit_time_, current_channel);


			//printf("node: %i restarting sensor at time %f\n", nodeId_, Scheduler::instance().clock());
			stimer_.start(sense_time_);
			sensing_=true;

		}

	} else { //if pu is not on. without this else, sensetimer gets scheduled twice



		// Start/Stop the backoff timer
		mac_->checkBackoffTimer();

		// The CR can transmit if PU is not detected
		if ( !pu_on_ )  {

			// Sensing Time is on
			sensing_=false;

			// No channel switching, the CR can start transmitting on the current channel
			ttimer_.start(transmit_time_);

#ifdef SENSING_VERBOSE_MODE
			printf("[SENSING-DBG] Node %d starts transmitting on channel %d at time %f \n",nodeId_,current_channel,Scheduler::instance().clock()); 
#endif
		}

	}
}





//transmitHandler: the CR stops transmitting, and starts sensing for PU detection
void 
SpectrumManager::transmitHandler() {


	int current_channel=repository_->get_recv_channel(nodeId_);

	// Perform sensing on the current channel
	pu_on_= sensingMod_->sense(nodeId_,sense_time_,transmit_time_, current_channel);

	// Start the sensing interval
	stimer_.start(sense_time_);

	// Set the sensing ON
	sensing_=true;

#ifdef SENSING_VERBOSE_MODE
	printf("[SENSING-DBG] Node %d starts sensing on channel %d at time %f \n",nodeId_,current_channel,Scheduler::instance().clock());
	//if (pu_on_) printf("[SENSING-DBG] Node %d sensed pu activity on channel %d \n", nodeId_, current_channel);
#endif

	// Stop any current backoff attempt
	//printf("starting sensing, calling backoff \n");
	mac_->checkBackoffTimer();

}




//endHandoff: the CR has performed spectrum handoff to a new channel. Then, it starts sensing on it to detect PU activity.
void 
SpectrumManager::endHandoff() {

	int current_channel=repository_->get_recv_channel(nodeId_);

	// Perform sensing on the new channel
	pu_on_ = sensingMod_->sense(nodeId_,sense_time_,transmit_time_, current_channel);

	// Start the sensing interval
	stimer_.start(sense_time_);

#ifdef SENSING_VERBOSE_MODE

	printf("[SENSING-DBG] Node %d ends handoff on channel %d at time %f \n",nodeId_,current_channel,Scheduler::instance().clock());

	printf("[SENSING-DBG] Node %d starts sensing on channel %d at time %f \n",nodeId_,current_channel,Scheduler::instance().clock());

#endif

}

}
// CRAHNs Model END
// @author:  Marco Di Felice


