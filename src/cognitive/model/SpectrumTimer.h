

#ifndef SPECTRUM_TIMER_H
#define SPECTRUM_TIMER_H

//#include <delay.h>
//#include <connector.h>
//#include <packet.h>
//#include "ns3/object.h"

namespace ns3 {
class SpectrumManager;
class SpectrumMobility;

//TODO declare all getID functions
class SenseTimer {

	public:
	//static TypeId GetTypeId (void);
        	SenseTimer(SpectrumManager *s); 

	        //void handle(Event *e);

		void start(double time);

	private:
		//Event           intr;
		SpectrumManager *m_handler;
};





class TransmitTimer {

	public:
	//static TypeId GetTypeId (void);
		 TransmitTimer(SpectrumManager *s);

                 //void handle(Event *e);

		 void start(double time);

	private:
		//Event           intr;
		SpectrumManager *m_handler;

};




class HandoffTimer {

	public:
	//static TypeId GetTypeId (void);
		HandoffTimer(SpectrumMobility *s);

                //void  handle(Event *e);
		
		void  start (double time);

	private:
		//Event           intr;
		SpectrumMobility *m_handler;

};

}
#endif
