
#include "PUmodel.h"

NS_LOG_COMPONENT_DEFINE ("CogPUModel");
// PU model class
// Implementation of the model of PU activity for CRAHNs

namespace ns3 {

TypeId
PUModel::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::PUModel")
    .SetParent<Object> ()
    .AddConstructor<PUModel> ()
  ;
  return tid;
}


// PUmodel Initializer
PUModel::PUModel() {
	
	number_pu_=0;
	
	// Initialize Interference Statistics
	interference_events_=0;
	interference_power_=0.0;
	
	
}



// read_data: Read the content of the current file and saves the information on the PU data structure
void
PUModel::read_data(char* dir) {

	FILE* fd;	
	
	fd=fopen(dir,"rt");

	NS_LOG_DEBUG ("Reading PU Data from File: " << dir);
	

	if (fd==NULL) {
		NS_FATAL_ERROR("Can't open file " << dir);
	}
	
	// The first line contains the following entry:
	// <# number_of_PU>
	fscanf(fd,"%d",&number_pu_);

	if (ferror(fd)) {
		NS_FATAL_ERROR ("Can't read PU number Information from file " << dir);
	}


	if (IO_DEBUG)
		NS_LOG_DEBUG ("[READING MAP FILE] #PU users: " << number_pu_);

	
	if (number_pu_>	 MAX_PU_USERS)
	  NS_LOG_ERROR ("Too many PU in the file. Max allowed is " << MAX_PU_USERS);
	
	// The second section contains the following entry:
	// <PU_id, x_loc, y_loc, x_loc_receiver, y_loc_receiver, alpha, beta, tx_range>

	for (int i=0; i< number_pu_; i++) {
		int channel;
		float x,y,x2,y2;
		float alpha, beta;
		float range;		
	
		fscanf(fd,"%d %f %f %f %f %e %e %f",&channel,&x,&y,&x2,&y2,&alpha,&beta,&range);
		
		if (ferror(fd))
			NS_LOG_ERROR ("Can't read PU number Information from file " << dir);


		NS_LOG_DEBUG ("[READING MAP FILE] #PU Location: channel: " << channel << " x="
		    << x << " y=" << y << " #PU Receiver: x=" << x2 << " y=" << y2 << " ALPHA: "
		    << alpha << " BETA: " << beta << " TX RANGE: " << range );


		pu_data[i].main_channel=channel;
		pu_data[i].x_loc=x;
		pu_data[i].y_loc=y;
		pu_data[i].x_loc_receiver=x2;
		pu_data[i].y_loc_receiver=y2;
		pu_data[i].alpha=alpha;
		pu_data[i].beta=beta;
		pu_data[i].radius=range;
		pu_data[i].interference=0.0;
	}


	
	// The third section contains the following entry:
	// <arrival_PU_0, ..,arrival_PU_n>
	// <departure_PU_0, ..,departure_PU_n>
	
	for (int j=0; j< number_pu_; j++) {
		int arrivals=0;
		int departures=0;
		int number=0;
		
		fscanf(fd,"%d",&number);

		if (ferror(fd))
			NS_LOG_ERROR ("Can't read PU number DATA Information from file " << dir);

		NS_LOG_DEBUG ("[READING MAP FILE] #PU ON times: " << number);
	
		if (number>MAX_PU_DATA_ENTRY)
			NS_FATAL_ERROR("Too many PU DATA ON times in the file. Max allowed is " << MAX_PU_DATA_ENTRY << " " << number);
		
		pu_data[j].number_data=number;

		for (int i=0; i< (2*number); i++) {
			float time;
			fscanf(fd," %f ",&time);
			if (i%2==0) {		
				// Reading the arrival time			
				pu_data[j].arrival_time[arrivals]=Seconds(time);
				arrivals++;
				NS_LOG_DEBUG ("[READING MAP FILE] #PU arrival: " << j << " " << time);
			} else {
				// Reading the departure time
				pu_data[j].departure_time[departures]=Seconds(time);
				departures++;
				NS_LOG_DEBUG ("[READING MAP FILE] #PU departure: " << j << time);


			}			
	
			pu_data[j].detected[arrivals]=false;

		}
	}
}





// is_PU_active: Check if a PU is active in the time interval [timeNow, timeNow + ts]
bool
PUModel::is_PU_active(Time timeNow, Time ts, double x, double y, int channel) {

	bool active=false;

	for (int i=0; i< number_pu_; i++) {
		if ((pu_data[i].main_channel==channel) && (distance(x,y,i) <=pu_data[i].radius))
			active=check_active(timeNow,ts,i);

		if (active) {
			return true;
		}
		
	}

	return false;

}





// check:active: Check if a PU is transmitting in the interval [timeNow, timeNow + ts]
bool
PUModel::check_active(Time timeNow, Time ts, int channel) {

	Time endTime=timeNow+ts;
	int number=pu_data[channel].number_data;
	double active=false;

	for (int i=0; i<number; i++) {

		// Check if there is an overlapping with the current PU activity	
		if( (pu_data[channel].arrival_time[i]>=timeNow && pu_data[channel].departure_time[i]>=endTime && pu_data[channel].arrival_time[i]<=endTime) || (pu_data[channel].arrival_time[i]<=timeNow && pu_data[channel].departure_time[i]>=endTime) ||
    (pu_data[channel].arrival_time[i]<=timeNow && pu_data[channel].departure_time[i]>=timeNow && pu_data[channel].departure_time[i]<=endTime)) {

			active=true;
			pu_data[channel].detected[i]=true;

	 	}

		// If there is on overlapping, then jump out from the cycle
		if (active || pu_data[channel].arrival_time[i]>endTime) 
        	              i=number; 
	}
	
	return(active);

}



/*
 * this function checks if PU is active in a time period. This is useful for our TFRC implementation
 * where we assume that the database returns only PUs that are affecting the chain
 */
bool
PUModel::check_active(Time timeNow, Time ts) {


	Time endTime=timeNow+ts;
	double active=false;

	for (int j=0; j<number_pu_; j++) {
		for (int i=0; i<pu_data[j].number_data; i++) {

			// Check if there is an overlapping with the current PU activity
			if( (pu_data[j].arrival_time[i]>=timeNow && pu_data[j].departure_time[i]>=endTime && pu_data[j].arrival_time[i]<=endTime) || (pu_data[j].arrival_time[i]<=timeNow && pu_data[j].departure_time[i]>=endTime) ||
					(pu_data[j].arrival_time[i]<=timeNow && pu_data[j].departure_time[i]>=timeNow && pu_data[j].departure_time[i]<=endTime)) {

				active=true;
				pu_data[j].detected[i]=true;

			}

			// If there is on overlapping, then jump out from the cycle
			if (active) {
				i=pu_data[j].number_data;
				j=number_pu_;
			}
			if (pu_data[j].arrival_time[i]>endTime) {
				i=pu_data[j].number_data;
			}
		}
	}

	return(active);

}

/*
 * Get the next time the PU goes off.
 * This is needed for our TFRC protocol so that it can start sending immediately at this time
 * returns -1 if there is no PU currently
 */
Time
PUModel::get_next_off_time(Time timeNow) {


	Time endTime=timeNow+Seconds(0.001);
	bool active=false;
	Time timeOff = Seconds(0);

	for (int j=0; j<number_pu_; j++) {
		for (int i=0; i<pu_data[j].number_data; i++) {

			// Check if there is an overlapping with the current PU activity
			if( (pu_data[j].arrival_time[i]>=timeNow && pu_data[j].departure_time[i]>=endTime && pu_data[j].arrival_time[i]<=endTime) || (pu_data[j].arrival_time[i]<=timeNow && pu_data[j].departure_time[i]>=endTime) ||
					(pu_data[j].arrival_time[i]<=timeNow && pu_data[j].departure_time[i]>=timeNow && pu_data[j].departure_time[i]<=endTime)) {

				active=true;
				pu_data[j].detected[i]=true;

			}

			// If there is on overlapping, then jump out from the cycle
			if (active) {
				timeOff = pu_data[j].departure_time[i];
				NS_LOG_DEBUG ("time off: " << pu_data[j].departure_time[i] <<" i="<< i <<" and j="<< j );
				i=pu_data[j].number_data;
				j=number_pu_;
			}
			if (pu_data[j].arrival_time[i]>endTime) {
				i=pu_data[j].number_data;
			}
		}
	}

	return(timeOff);

}


/**********************************************************/
/* DISTANCE METHODS
 **********************************************************/

//distance: Return the current distance from the PU transmitter on a given channel
double 
PUModel::distance(double x, double y, int channel) {
	double dx=(x-pu_data[channel].x_loc)*(x-pu_data[channel].x_loc);
	double dy=(y-pu_data[channel].y_loc)*(y-pu_data[channel].y_loc);
	double dist=std::sqrt((float)(dx+dy));

	return dist;
}




///distance_receiver: Return the current distance from the PU receiver on a given channel 
double 
PUModel::distance_receiver(double x, double y, int channel) {

	double dx=(x-pu_data[channel].x_loc_receiver)*(x-pu_data[channel].x_loc_receiver);
	double dy=(y-pu_data[channel].y_loc_receiver)*(y-pu_data[channel].y_loc_receiver);
	double dist=std::sqrt((float)(dx+dy));

	return dist;
}





// recv method: Receive a pkt (EMPTY METHOD)
//void
//PUmodel::recv(Packet*, Handler*) {
//}





// update_stat_pu_receiver: Check if the tranmission of a CR may cause interference to a PU receiver
void
PUModel::update_stat_pu_receiver(int id, Time timeNow, Time txtime, double x, double y, int channel) {

	double active=false;
	// Power injected by CR nodes 
	double TX_POWER=0.2818;
	

	// Check all the PU receivers
	for (int i=0; (i< number_pu_); i++) {
		// Check if the CR is in the channel and range of a PU receiver		
		if ((pu_data[i].main_channel==channel) && (distance_receiver(x,y,i) < pu_data[i].radius) ) {

			// Check if PU is transmitting at that time
			active=check_active(timeNow,txtime,i);	

			// If the PU is transmitting, compute the amount of interference injected by the CR
			if (active) {
				
				// Compute the Interference Power * Interference Time received by the destination
		 		interference_power_=interference_power_+((TX_POWER * std::pow(1.5,4))/(std::pow(distance_receiver(x,y,i),4))) * txtime.GetSeconds();
				interference_events_++;
			}
		}
	}
	

}




// write_stat: Write the statistics about avg interference on PU receivers on a file
void 
PUModel::write_stat(int param) {

	double power=0;	
	FILE *fd;
	FILE *fd2;

	// Statistics 1: Compute the avg. Interference perceived by each PU receiver
	if (interference_events_>0)
		//power=interference_power_/interference_events_;
		power=interference_power_ * 1000 / (100*27);

	
	fd=fopen("interference_pu","w");	

	fprintf(fd,"%d %e\n",param,power);
	
	fclose(fd);

	// Statistics 2: Compute the avg probability of PU detection
	int  number_PU_events=0;
	int  number_PU_sense_detected=0;

	// Compute the number of time a PU was transmitting and a CR detected its transmission
	for (int i=0; (i< number_pu_); i++) {
		int number_activities=pu_data[i].number_data;
		number_PU_events+=number_activities;

		for (int j=0; j<number_activities; j++) 
			if (pu_data[i].detected[j])  
				number_PU_sense_detected++;					
	}

	
	fd2=fopen("sensing","w");	

	fprintf(fd2,"%d %f\n",param,((double)number_PU_sense_detected)/number_PU_events);

	fclose(fd2);


}

void
PUModel::SetPuMapFile(char * fileName)
{
  read_data(fileName);
}


// Command method
/*int
PUmodel::command(int argc, const char*const* argv) {
 	
	if(argc == 3) {
		
		// Read the current PU activity file
		if(strcmp(argv[1], "set_input_map") == 0) {
  		    read_data((char*)argv[2]);
   		    return TCL_OK;
		
		}
		
		// Write the statistics about current PU activity on the interference file
		else if(strcmp(argv[1], "write_stat") == 0) {
		    write_stat(atoi(argv[2]));
   		    return TCL_OK;
		}

	} 

	return TCL_OK;
}*/
}
