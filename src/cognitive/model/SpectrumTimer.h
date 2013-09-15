

#ifndef SPECTRUM_TIMER_H
#define SPECTRUM_TIMER_H

//#include <delay.h>
//#include <connector.h>
//#include <packet.h>
#include "ns3/object.h"

namespace ns3 {
class SpectrumManager;
class SpectrumMobility;

//TODO declare all getID functions
class SenseTimer: public Object {

	public:

        	SenseTimer(SpectrumManager *s); 

	        //void handle(Event *e);

		void start(double time);

	private:
		//Event           intr;
		//SpectrumManager *handler_;
};





class TransmitTimer: public Object {

	public:

		 TransmitTimer(SpectrumManager *s);

                 //void handle(Event *e);

		 void start(double time);

	private:
		//Event           intr;
		//SpectrumManager *handler_;

};




class HandoffTimer: public Object {

	public:

		HandoffTimer(SpectrumMobility *s);

                //void  handle(Event *e);
		
		void  start (double time);

	private:
		//Event           intr;
		//SpectrumMobility *handler_;

};

}
#endif
