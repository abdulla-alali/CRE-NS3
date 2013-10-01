// CRAHNs Model END
// @author:  Marco Di Felice


/*
 * Implementation of the spectrum management activities performed by CRs
 * Includes:
 * 1. Spectrum sensing:      PU detection through Carrier Sensing Detection
 * 2. Spectrum decision:     Decision of the next-channel to be used in case of PU detection
 * 3. Spectrum mobility:     Handoff Managment    
 * 4. Spectrum data loader:  Loader of spectrum information
 * 5. Spectrum timers:       Timers for spectrum management (handoff/sensing/transmitting/...) 
 */

#ifndef SPECTRUM_MANAGER_H
#define SPECTRUM_MANAGER_H

#include "SpectrumTimer.h"
#include "SpectrumSensing.h"
#include "SpectrumDecision.h"
#include "SpectrumMobility.h"
#include "SpectrumData.h"

#include "PUmodel.h"
#include "repository.h"
#include "ns3/wifi-mac.h"
#include "ns3/nstime.h"
//#include "mac/mac-802_11.h"
//#include "common/packet.h"

// Spectrum Manager modules
// Enable/Disable channel allocation performed at MAC Layer, by the SpectrumDecision Module
// Comment this line if channel allocation is performed by the routing agent 
#define CHANNEL_DECISION_MAC_LAYER

// Enable/Disable Notifications MAC->NET layers, in case of PU detection on the current channel
#define ENABLE_SPECTRUM_HANDOFF_NOTIFICATION


// Spectrum Manager constant values
#define DEFAULT_SENSING_INTERVAL 	0.1    //Default Sensing duration
#define DEFAULT_TRANSMITTING_INTERVAL 	0.5    //Default Transmitting duration
#define DEFAULT_PROBABILITY_MISDETECT   0.0    //Accuracy of the sensing scheme 

namespace ns3 {

// Other classes
class SpectrumSensing;
class SpectrumDecision;
class SpectrumMobility;
class HandoffTimer;
class SenseTimer;
class TransmitTimer;
class Mac802_11;

// Spectrum Manager Implementation
class SpectrumManager  {

	friend class SenseTimer;
	friend class TransmitTimer;

public:

	// Initialize a new Spectrum Manager
	SpectrumManager(Ptr<WifiMac> mac, int id);

	// Initialize a new Spectrum Manager
	SpectrumManager(Ptr<WifiMac> mac, int id, Time sense_time, Time transmit_time);

	// Start method: CR agent starts sensing activity on the current channel
	void start();

	// Return true if CR is NOT doing sensing and is NOT doing spectrum handoff
	bool is_channel_available();
	// Return true if a PU is active while receiving the packet, on the same channel
	bool is_PU_interfering(Time txDuration);

	// Timer Handlers
	// Handler for sensing timer
	void senseHandler();
	// Handler for handoff management: start sensing on the new channel
	void endHandoff();
	// Handler for transmission timer: start sensing on the current channel
	void transmitHandler();



	// Setup Functions
	void setPUmodel(double prob, Ptr<PUModel> p);
	void setRepository(Ptr<Repository> rep);
	void setSpectrumData(SpectrumData *sd);


private:

	// Spectrum Cycle Timers and Variables
	// Sensing Timer
	//SenseTimer stimer_;
	// Transmitting Timer
	TransmitTimer ttimer_;
	// Sensing interval
	Time sense_time_;
	// Transmitting interval
	Time transmit_time_;


	// State Variables
	// pu_on_ is true wheter PU activity is detected in the current sensing cycle
	bool pu_on_;
	// sensing_ is true wheter a CR is performing sensing
	bool sensing_;


	// MAC References and address
	Ptr<WifiMac> mac_;
	int nodeId_;


	// Modules
	// Cross-layer repository for information sharing about the current channel
	Ptr<Repository> m_repository;

	// Spectrum Sensing Module
	SpectrumSensing  *sensingMod_;
	// Spectrum Decision Module
	SpectrumDecision *decisionMod_;
	// Spectrum Mobility Module
	SpectrumMobility *mobilityMod_;
	// Spectrum Data Loader Module
	SpectrumData 	 *dataMod_;



};
}
#endif

// CRAHNs Model END
// @author:  Marco Di Felice


