#ifndef commCognitive_H
#define commCognitive_H



// Max number of nodes in the simulation
#define MAX_NODES		 	200


// Defines the time a node spends on each queue
#define QUEUE_UTILIZATION_INTERVAL 	0.2
// Defines the channel switching delay
#define SWITCHING_DELAY			0.001
// Defines the TIMEOUT_ALIVE to check wheter a node is active on a given channel or not
#define TIMEOUT_ALIVE			2


// Multi-radio multi-channel specification
// Channels/Radio Definition. DO NOT MODIFY HERE!


// Interface Classification
#define CONTROL_RADIO 		0
#define TRANSMITTER_RADIO 	1
#define RECEIVER_RADIO  	2

// Channe/Radio Information
#define MAX_RADIO	3
#define	MAX_CHANNELS 	11 //#modify to accomodate changes (he says dont modify, why ?)
#define CONTROL_CHANNEL 0
#define MAX_HOPS_STORE 40 //max number of hops to store


#define SENSING_VERBOSE_MODE

enum PacketType
{
  CTRL_PACKET  = 1,   //for packets destined to ctrl interface
  DATA_PACKET  = 2   //for packets destined to tx interface
};

#endif
