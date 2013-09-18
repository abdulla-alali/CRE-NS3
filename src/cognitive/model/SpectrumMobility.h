// CRAHNs Model START
// @author:  Marco Di Felice

#ifndef SPECTRUM_MOBILITY_H
#define SPECTRUM_MOBILITY_H

#include "SpectrumManager.h"
#include "SpectrumTimer.h"
//#include "repository.h"


namespace ns3 {
class SpectrumManager;
class HandoffTimer;


// Implementation of Spectrum Mobility to manage spectrum handoff events
class SpectrumMobility {

	friend class HandoffTimer;

	public:

		// Spectrum Mobility initializer
		SpectrumMobility(SpectrumManager *smanager_);
		
		// Start handoff timer
		void performHandoff();	

		// End handoff 
		void endHandoff();	
		
		// Return true if the CR is performing spectrum handoff
		bool is_switching();
	
	private:

		// Switching state
		bool switching_;

		// Spectrum Manager reference
		SpectrumManager	*smanager_;
		
		// Handoff Timer
		HandoffTimer htimer_;
};

}
#endif
// CRAHNs Model END
// @author:  Marco Di Felice


