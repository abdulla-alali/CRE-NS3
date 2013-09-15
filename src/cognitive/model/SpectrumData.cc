// CRAHNs Model START
// @author:  Marco Di Felice



#include "SpectrumData.h"


namespace ns3 {

TypeId
SpectrumData::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::SpectrumData")
    .SetParent<Object> ()
    .AddConstructor<SpectrumData> ()
    //.AddAttribute ("DeviceList", "The list of devices associated to this Node.",
    //               ObjectVectorValue (),
    //               MakeObjectVectorAccessor (&Node::m_devices),
    //               MakeObjectVectorChecker<NetDevice> ())
  ;
  return tid;
}



// SpectrumData initializer
SpectrumData::SpectrumData()  {

}



// read_spectrum_file: load the information form the spectrum file into the spectrum_table_
void
SpectrumData::read_spectrum_file(char *fileName) {
	
	FILE* fd;	
	
	fd=fopen(fileName,"rt");	
	
	if (IO_SPECTRUM_DEBUG) 
		printf("Reading PU Data from File: %s \n", fileName);
	

	if (fd==NULL) {
		printf(" ERROR. Can't open file %s \n",fileName);
		exit(0);
	}


	// For each channel in the range [0: MAX_CHANNELS]
	// the spectrum file contains these entries:
	// - bandwidth (b/s)
	// - packet error rate 
	
	for (int i=0; i<MAX_CHANNELS; i++)  {
		
		int channel;
		float bandwidth;
		float per;
	
		// read the next entry
		fscanf(fd,"%d %f %f",&channel,&bandwidth,&per);
		
		if (ferror(fd)) {
			printf(" ERROR. Can't read Spectrum Information from file %s \n", fileName);		
			exit(0);
		}


		if (IO_SPECTRUM_DEBUG)
			printf("[READING SPECTRUM FILE] #CHANNEL: %d #BANDWIDTH: %f PER: %f\n",channel, bandwidth, per); 
	
		// save the information in the spectrum_table_
		spectrum_table_[channel].bandwidth=bandwidth;
		spectrum_table_[channel].per=per;
	 }
	
	 fclose(fd);
}




// get_spectrum_data: return the spectrum_entry for the current channel
spectrum_entry_t 
SpectrumData::get_spectrum_data(int channel) {

	if ((channel>=0) && (channel <MAX_CHANNELS)) 
		return spectrum_table_[channel];

	else  {
		printf(" ERROR. Can't retrive Spectrum Information for channel %d \n", channel);		
		exit(0);
	
	 }
	
}





// comman: get input from OTCL file
/*int
SpectrumData::command(int argc, const char*const* argv) {
 	
	if(argc == 3) {
		
		// Read the current spectrum file		
		if(strcmp(argv[1], "set_input_map") == 0) {
  		    read_spectrum_file((char*)argv[2]);
   		    return TCL_OK;
		
		}
	
	} 

	return TCL_OK;
}




// recv method: Receive a pkt (EMPTY METHOD)
void 
SpectrumData::recv(Packet*, Handler*) {

}*/


}
// CRAHNs Model START
// @author:  Marco Di Felice


