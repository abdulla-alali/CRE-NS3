/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2009 The Boeing Company
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

//
// This script configures two nodes on an 802.11b physical layer, with
// 802.11b NICs in adhoc mode, and by default, sends one packet of 1000
// (application) bytes to the other node.  The physical layer is configured
// to receive at a fixed RSS (regardless of the distance and transmit
// power); therefore, changing position of the nodes has no effect.
//
// There are a number of command-line options available to control
// the default behavior.  The list of available command-line options
// can be listed with the following command:
// ./waf --run "wifi-simple-adhoc --help"
//
// For instance, for this configuration, the physical layer will
// stop successfully receiving packets when rss drops below -97 dBm.
// To see this effect, try running:
//
// ./waf --run "wifi-simple-adhoc --rss=-97 --numPackets=20"
// ./waf --run "wifi-simple-adhoc --rss=-98 --numPackets=20"
// ./waf --run "wifi-simple-adhoc --rss=-99 --numPackets=20"
//
// Note that all ns-3 attributes (not just the ones exposed in the below
// script) can be changed at command line; see the documentation.
//
// This script can also be helpful to put the Wifi layer into verbose
// logging mode; this command will turn on all wifi logging:
//
// ./waf --run "wifi-simple-adhoc --verbose=1"
//
// When you are done, you will notice two pcap trace files in your directory.
// If you have tcpdump installed, you can try this:
//
// tcpdump -r wifi-simple-adhoc-0-0.pcap -nn -tt
//

#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/mobility-module.h"
#include "ns3/config-store-module.h"
#include "ns3/wifi-module.h"
#include "ns3/aodv-module.h"
#include "ns3/internet-module.h"
#include "ns3/applications-module.h"
#include "ns3/packet-sink.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

NS_LOG_COMPONENT_DEFINE ("WifiSimpleAdhoc");

using namespace ns3;

void ReceivePacket (Ptr<Socket> socket)
{
	NS_LOG_UNCOND ("Received one packet!");
}

static void GenerateTraffic (Ptr<Socket> socket, uint32_t pktSize,
		uint32_t pktCount, Time pktInterval )
{
	if (pktCount > 0)
	{
		socket->Send (Create<Packet> (pktSize));
		Simulator::Schedule (pktInterval, &GenerateTraffic,
				socket, pktSize,pktCount-1, pktInterval);
	}
	else
	{
		socket->Close ();
	}
}


int main (int argc, char *argv[])
{
	std::string phyMode ("ErpOfdmRate54Mbps");
	bool verbose = false;

	CommandLine cmd;

	cmd.AddValue ("phyMode", "Wifi Phy mode", phyMode);
	cmd.AddValue ("verbose", "turn on all WifiNetDevice log components", verbose);

	cmd.Parse (argc, argv);

	// disable fragmentation for frames below 2200 bytes
	Config::SetDefault ("ns3::WifiRemoteStationManager::FragmentationThreshold", StringValue ("2200"));
	// turn off RTS/CTS for frames below 2200 bytes
	Config::SetDefault ("ns3::WifiRemoteStationManager::RtsCtsThreshold", StringValue ("2200"));
	// Fix non-unicast data rate to be the same as that of unicast
	Config::SetDefault ("ns3::WifiRemoteStationManager::NonUnicastMode",
			StringValue (phyMode));

	NodeContainer c;
	c.Create (2);

	// The below set of helpers will help us to put together the wifi NICs we want
	WifiHelper wifi;
	if (verbose)
	{
		wifi.EnableLogComponents ();  // Turn on all Wifi logging
	}
	wifi.SetStandard (WIFI_PHY_STANDARD_80211g);

	YansWifiPhyHelper wifiPhy =  YansWifiPhyHelper::Default ();
	// This is one parameter that matters when using FixedRssLossModel
	// set it to zero; otherwise, gain will be added
	wifiPhy.Set ("RxGain", DoubleValue (0) );
	// ns-3 supports RadioTap and Prism tracing extensions for 802.11b
	wifiPhy.SetPcapDataLinkType (YansWifiPhyHelper::DLT_IEEE802_11_RADIO);

	YansWifiChannelHelper wifiChannel;
	wifiChannel.SetPropagationDelay ("ns3::ConstantSpeedPropagationDelayModel");
	// The below FixedRssLossModel will cause the rss to be fixed regardless
	// of the distance between the two stations, and the transmit power
	wifiChannel.AddPropagationLoss ("ns3::JakesPropagationLossModel");
	wifiPhy.SetChannel (wifiChannel.Create ());

	// Add a non-QoS upper mac, and disable rate control
	NqosWifiMacHelper wifiMac = NqosWifiMacHelper::Default ();
	wifi.SetRemoteStationManager ("ns3::ConstantRateWifiManager",
			"DataMode",StringValue (phyMode),
			"ControlMode",StringValue (phyMode));
	// Set it to adhoc mode
	wifiMac.SetType ("ns3::AdhocWifiMac");
	NetDeviceContainer devices = wifi.Install (wifiPhy, wifiMac, c);

	MobilityHelper mobility;
	Ptr<ListPositionAllocator> positionAlloc = CreateObject<ListPositionAllocator> ();
	positionAlloc->Add (Vector (0.0, 0.0, 0.0));
	positionAlloc->Add (Vector (5.0, 0.0, 0.0)); //5 meters away
	mobility.SetPositionAllocator (positionAlloc);
	mobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
	mobility.Install (c);


	InternetStackHelper internet;
	AodvHelper aodv;
	internet.SetRoutingHelper(aodv);
	internet.Install (c);

	Ipv4AddressHelper ipv4;
	NS_LOG_INFO ("Assign IP Addresses.");
	ipv4.SetBase ("10.1.1.0", "255.255.255.0");
	Ipv4InterfaceContainer i = ipv4.Assign (devices);

	//
	// Create a BulkSendApplication and install it on node 0
	//
	uint16_t port = 9;  // well-known echo port number


	BulkSendHelper source ("ns3::TcpSocketFactory",
			InetSocketAddress (i.GetAddress (1), port));
	// Set the amount of data to send in bytes.  Zero is unlimited.
	source.SetAttribute ("MaxBytes", UintegerValue (5000));
	ApplicationContainer sourceApps = source.Install (c.Get (0));
	sourceApps.Start (Seconds (0.0));
	sourceApps.Stop (Seconds (10.0));

	//
	// Create a PacketSinkApplication and install it on node 1
	//
	PacketSinkHelper sink ("ns3::TcpSocketFactory",
			InetSocketAddress (Ipv4Address::GetAny (), port));
	ApplicationContainer sinkApps = sink.Install (c.Get (1));
	sinkApps.Start (Seconds (0.0));
	sinkApps.Stop (Seconds (10.0));


	// Tracing
	wifiPhy.EnablePcap ("wifi-simple-adhoc", devices);

	// Output what we are doing
	NS_LOG_UNCOND ("Testing ");

	Simulator::Stop (Seconds (10.0));
	Simulator::Run ();
	Simulator::Destroy ();

	Ptr<PacketSink> sink1 = DynamicCast<PacketSink> (sinkApps.Get (0));
	std::cout << "Total Bytes Received: " << sink1->GetTotalRx () << std::endl;
	return 0;
}

