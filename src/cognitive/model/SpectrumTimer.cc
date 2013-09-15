

#include "SpectrumTimer.h"
#include "SpectrumManager.h"
#include "SpectrumMobility.h"

namespace ns3 {

SenseTimer::SenseTimer(SpectrumManager *s) {

	//handler_=s;
}




//void
//SenseTimer::handle(Event *e) {

//	handler_->senseHandler();
//}




void 
SenseTimer::start(double time) {

	Simulator::Schedule (Seconds (time), &SpectrumManager::senseHandler, this);
	//s.schedule(this, &intr, time);
}





TransmitTimer::TransmitTimer(SpectrumManager *s) {

	//handler_=s;

}




//void
//TransmitTimer::handle(Event *e) {

//	handler_->transmitHandler();

//}



void 
TransmitTimer::start(double time) {

	Simulator::Schedule (Seconds (time), &SpectrumManager::transmitHandler, this);
}



HandoffTimer::HandoffTimer(SpectrumMobility *s) {

	//handler_=s;

}





//void
//HandoffTimer::handle(Event *e) {

//handler_->endHandoff();

//}



void 
HandoffTimer::start(double time) {

	//Scheduler &s = Scheduler::instance();
	Simulator::Schedule (Seconds (time), &SpectrumManager::endHandoff, this);
	//s.schedule(this, &intr, time);
}

}
