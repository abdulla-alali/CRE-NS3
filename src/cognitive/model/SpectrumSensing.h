// CRAHNs Model START
// @author:  Marco Di Felice

#ifndef SPECTRUM_SENSING_H
#define SPECTRUM_SENSING_H

//#include <mobilenode.h>

#include "PUmodel.h"
#include "SpectrumManager.h"
#include "ns3/node-container.h"
#include "ns3/log.h"

namespace ns3 {
class SpectrumManager;

// Implementation of the Spectrum Sensing activity performed by CRs
class SpectrumSensing {
	
	public:
		
		// Initialitation method: PUmodel off
		SpectrumSensing(SpectrumManager *sm);

		// Initialization method: PUmodel on
		SpectrumSensing(SpectrumManager *sm, double prob, Ptr<PUModel> p);
	
		// Perform sensing and return true if PU activity is detected on the current channel
		bool sense(int id, Time sense_time, Time transmit_time, int channel);

	
	private:
		
		// Primary User Map and Model
		Ptr<PUModel> pumodel_;
		
		// Spectrum Manager reference
		SpectrumManager *smanager_;

		// Probability to have false negative detection of PUs.
		double prob_misdetect_;
};

}
#endif


// CRAHNs Model END
// @author:  Marco Di Felice


