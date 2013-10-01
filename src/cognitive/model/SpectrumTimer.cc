

#include "SpectrumTimer.h"
#include "SpectrumManager.h"
#include "SpectrumMobility.h"

namespace ns3 {

/*TypeId
SenseTimer::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::SenseTimer")
    .SetParent<Object> ()
    .AddConstructor<SenseTimer> ()
    //.AddAttribute ("DeviceList", "The list of devices associated to this Node.",
    //               ObjectVectorValue (),
    //               MakeObjectVectorAccessor (&Node::m_devices),
    //               MakeObjectVectorChecker<NetDevice> ())
  ;
  return tid;
}*/

//SenseTimer::SenseTimer(SpectrumManager *s) {

//	m_handler=s;
//}




//void
//SenseTimer::handle(Event *e) {

//	handler_->senseHandler();
//}




//void
//SenseTimer::start(Time time) {

	//Simulator::Schedule (time, &SpectrumManager::senseHandler, m_handler);
	//s.schedule(this, &intr, time);
//}


/*
TypeId
TransmitTimer::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::TransmitTimer")
    .SetParent<Object> ()
    .AddConstructor<TransmitTimer> ()
    //.AddAttribute ("DeviceList", "The list of devices associated to this Node.",
    //               ObjectVectorValue (),
    //               MakeObjectVectorAccessor (&Node::m_devices),
    //               MakeObjectVectorChecker<NetDevice> ())
  ;
  return tid;
}*/

TransmitTimer::TransmitTimer(SpectrumManager *s) {

	m_handler=s;

}




//void
//TransmitTimer::handle(Event *e) {

//	handler_->transmitHandler();

//}



void 
TransmitTimer::start(Time time) {

	Simulator::Schedule (time, &SpectrumManager::transmitHandler, m_handler);
}

/*
TypeId
HandoffTimer::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::HandoffTimer")
    .SetParent<Object> ()
    .AddConstructor<HandoffTimer> ()
    //.AddAttribute ("DeviceList", "The list of devices associated to this Node.",
    //               ObjectVectorValue (),
    //               MakeObjectVectorAccessor (&Node::m_devices),
    //               MakeObjectVectorChecker<NetDevice> ())
  ;
  return tid;
}*/

HandoffTimer::HandoffTimer(SpectrumMobility *s) {

	m_handler=s;

}





//void
//HandoffTimer::handle(Event *e) {

//handler_->endHandoff();

//}



void 
HandoffTimer::start(double time) {

	//Scheduler &s = Scheduler::instance();
	Simulator::Schedule (Seconds (time), &SpectrumMobility::endHandoff, m_handler);
	//s.schedule(this, &intr, time);
}

}
