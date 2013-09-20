// Switchable Interface Implementation START
// @author:  Marco Di Felice	

// Class Repository 
// Cross-Layer Repository to enable channel information sharing between MAC and routing protocols

#include "repository.h"

namespace ns3 {

TypeId
Repository::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::Repository")
    .SetParent<Object> ()
    .AddConstructor<Repository> ()
    //.AddAttribute ("DeviceList", "The list of devices associated to this Node.",
    //               ObjectVectorValue (),
    //               MakeObjectVectorAccessor (&Node::m_devices),
    //               MakeObjectVectorChecker<NetDevice> ())
  ;
  return tid;
}


// Initializer
Repository::Repository() {
	
	// Set randomly the receiver channel for each node	
	for (int i=0; i<MAX_NODES; i++) {
		int channel=get_random_channel();
		repository_table[i].recv_channel= channel;
	}

	for (int i=0; i<5; i++) {
		printf("node %i got channel %i\n", i, repository_table[i].recv_channel);
	}

	// Initialize each sending channel as NOT active for each node
	for (int node=0; node<MAX_NODES; node++) 
		for (int channel=0; channel< MAX_CHANNELS; channel++) 
			repository_table_sender[node][channel].active=false;



}




//get_recv_channel: Return the receiving channel for a node
int 
Repository::get_recv_channel(int node) {
	if (node < MAX_NODES)
		return repository_table[node].recv_channel;
	else
		return -1;

}
		 

//set_recv_channel: Set the receiving channel for a node
void 
Repository::set_recv_channel(int node, int channel) {
	if (node < MAX_NODES)
		repository_table[node].recv_channel=channel;

}

		
// update_send_channel: Set the sending channel as active, at the current time
void 
Repository::update_send_channel(int node, int channel, double time) {

	if (node < MAX_NODES)  {
		
		repository_table_sender[node][channel].active=true;
		repository_table_sender[node][channel].time=time;
	
	 }

}
		 

//is_channel_used_for_sending: Check wheter a given sending channel is active for a given node
bool 
Repository::is_channel_used_for_sending(int node, int channel, double timeNow) {

	if (repository_table_sender[node][channel].active) {
		if (timeNow - repository_table_sender[node][channel].time > TIMEOUT_ALIVE)
			repository_table_sender[node][channel].active=false;
	}
	
	return repository_table_sender[node][channel].active;
	
}



//get_random_channel: Return a random channel between 1 and MAX_CHANNELS
int 
Repository::get_random_channel() {
	Ptr<UniformRandomVariable> uv = CreateObject<UniformRandomVariable>();
	uv->SetAttribute ("Min", DoubleValue (1));
	uv->SetAttribute ("Max", DoubleValue (MAX_CHANNELS));
	int channel=uv->GetInteger();
	if (channel >= MAX_CHANNELS)
		channel = MAX_CHANNELS-1;
	return channel;
}


// recv: Empty method
//void
//Repository::recv(Packet*, Handler* = 0) {
//
//}

// command: Empty method
int
Repository::command(int argc, const char*const* argv) {
	return 0;
}

/*
 * This gets set by AODV for our transport protocol to poll
 */
void
Repository::set_number_hops(int dst, int num) {
	repository_num_hops[dst] = num;
}

/*
 * this gets called by the transport protocol to calculate slow-down rate
 */
int
Repository::get_number_hops(int dst) {
	return repository_num_hops[dst];
}

// Switchable Interface Implementation END



PacketTypeByteTag::PacketTypeByteTag (PacketType t) :
  m_type (t)
{
}

TypeId
PacketTypeByteTag::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::PacketTypeByteTag")
    .SetParent<Tag> ()
    .AddConstructor<PacketTypeByteTag> ()
  ;
  return tid;
}
TypeId
PacketTypeByteTag::GetInstanceTypeId (void) const
{
  return GetTypeId ();
}

uint32_t
PacketTypeByteTag::GetSerializedSize (void) const
{
  return 1;
}
void
PacketTypeByteTag::Serialize (TagBuffer i) const
{
  i.WriteU8 (m_type);
}
void
PacketTypeByteTag::Deserialize (TagBuffer i)
{
  m_type = (PacketType) i.ReadU8 ();
}

void
PacketTypeByteTag::Print (std::ostream &os) const
{
  switch (m_type)
    {
    case CTRL_PACKET:
      {
        os << "ctrl_packet";
        break;
      }
    case DATA_PACKET:
      {
        os << "data_packet";
        break;
      }
    default:
      os << "UNKNOWN_TYPE";
      break;
    }
}


}
