// CRAHNs Model START
// @author:  Marco Di Felice

#ifndef SPECTRUM_DECISION_H
#define SPECTRUM_DECISION_H


// Decision policy, when a PU is detected on the current channel
// Policy 0: Switch to a new channel asa a PU is detected
#define DECISION_POLICY_ALWAYS_SWITCH 		0
// Policy 1: Switch to a new channel, with probability THRESHOLD_SWITCH
#define DECISION_POLICY_PROBABILISTIC_SWITCH 	1
// Policy 2: Never switch!
#define DECISION_POLICY_NEVER_SWITCH 2

// Switching threshold, for policy 1
#define THRESHOLD_SWITCH 	0.8

// Next Spectrum Selection
// Policy 1: next channel -> ( next_channel + 1 ) % MAX_CHANNELS
#define ROUND_ROBIN_SWITCH  	0
// Policy 2: next_channel -> random(1..MAX_CHANNELS)
#define RANDOM_SWITCH		1



#include "SpectrumManager.h"

namespace ns3 {
class SpectrumManager;

// Spectrum Decision module: decide the next channel when a PU is detected on the current one
class SpectrumDecision {

	public:

		// Spectrum Decision Initializer
		SpectrumDecision(SpectrumManager *sm);
	
		// Decide wheter to stay on the current channel or switch to a new channel
		bool decideSwitch();		
		
		// Get the next channel to be used, based on the allocation policy	
		int decideSpectrum(int current_channel);		
	
	private:
		
		// Decision policy: stay or leave the current channel
		int decision_policy_;
		
		// Switching policy: decide the next channel to be used
		int spectrum_policy_;
		
		// Spectrum Manager reference
		SpectrumManager *smanager_;
};

}
#endif

// CRAHNs Model END
// @author:  Marco Di Felice


