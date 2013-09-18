// CRAHNs Model START
// @author:  Marco Di Felice


#ifndef SPECTRUM_DATA_H
#define SPECTRUM_DATA_H


//#include "repository.h"
#include "commCognitiveHeader.h"
#include <stdio.h>
#include "ns3/object.h"

// Verbose mode
#define IO_SPECTRUM_DEBUG 1

namespace ns3 {
// Spectrum Entry Information
struct spectrum_entry_t  {
	
	// current bandwidth
	double bandwidth;
	
	// Packet Error Rate (PER) value	
	double per;

 };


class SpectrumData : public Object {

	public:
	static TypeId GetTypeId (void);
		// SpectrumData Initializer
		SpectrumData();
		
		// Return the spectrum-entry information for the current channel
		spectrum_entry_t get_spectrum_data(int channel);
	
		// command method 
		int command(int argc, const char*const* argv);
		
		// recv method (EMPTY)
		//void recv(Packet*, Handler*);

	private:
		
		// read the current spectrum file, and load the information in the spectrum_table_
		void read_spectrum_file(char *fileName);
		
		// Spectrum_table, loaded by the spectrum file
		spectrum_entry_t spectrum_table_[MAX_CHANNELS];

 };

}
#endif

// CRAHNs Model END
// @author:  Marco Di Felice



