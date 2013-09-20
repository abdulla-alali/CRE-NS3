#!/bin/bash

NS_LOG="AodvRoutingProtocol=level_all|prefix_func|prefix_time:Ipv4L3Protocol=level_all|prefix_func|prefix_time:ArpL3Protocol=level_all|prefix_func|prefix_time:Ipv4Interface=level_all|prefix_func|prefix_time" ./waf --run wifi-test
