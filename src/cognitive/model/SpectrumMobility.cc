// CRAHNs Model START
// @author:  Marco Di Felice


#include "SpectrumMobility.h"

namespace ns3 {
// Spectrum Mobility initializer
SpectrumMobility::SpectrumMobility(SpectrumManager *sm): htimer_(this) {

	smanager_=sm;
	switching_=false;
}



// performHandoff: start handoff timer, during which a CR can not transmit data               
void
SpectrumMobility::performHandoff() {

	// Change current state
	switching_=true;
	
	htimer_.start(SWITCHING_DELAY);
}



// is_switching: return true if the CR is performing a spectrum handoff
bool
SpectrumMobility::is_switching() {
	
	return switching_;	

}



// endHandoff: Change current state and notify the Spectrum Manager, so that the CR can perform sensing on the new channel
void
SpectrumMobility::endHandoff() {

	switching_=false;

	smanager_->endHandoff();

}
}
// CRAHNs Model END
// @author:  Marco Di Felice


