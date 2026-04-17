#include "graph.h"
#include <memory.h>
#include "utils.h"
#include <stdio.h>

// as soon as you add a link to the topology/graph and connect
// two nodes, the interfaces must be assigned a unique MAC address. 
// This is because the MAC address is used to identify the interface on the network,
// and ensure that data packets are correctly routed to their destination

// assigning unique MAC address to an interface in the graph

void interfaceAssignMACAddress(interface_t* interface) {
	memset(IF_MAC(interface), 0, 8);
	strcpy(IF_MAC(interface), interface->attachedNode->nodeName);
	strcat(IF_MAC(interface), interface->interfaceName);
}

// seeing if loopback address can be properly configured for a node

bool_t nodeSetLoopbackAddress(node_t* node, char* ipAddr) {
	assert(ipAddr);

	node->nodeNetworkProperties.isAddressLoopback = true;
	strncpy(NODE_LO_ADDR(node), ipAddr, 16);
	NODE_LO_ADDR(node)[15] = '\0'; // Ensure there is null termination

	return true;
}

bool_t nodeSetInterfaceIPAddress(node_t* node, char* localInterface, char* ipAddr, char mask) {
	interface_t* interface = getNodeInterfaceByName(node, localInterface);
	if (!interface)
		assert(0); // Interface not found
	strncpy(IF_IP(interface), ipAddr, 16);
	IF_IP(interface)[15] = '\0'; // Ensure there is null termination

	interface->networkProperties.mask = mask;
	interface->networkProperties.isIPAddressConfigured = true;
	return true;
}

bool_t nodeUnsetInterfaceIPAddress(node_t* node, char* localInterface) {
	return true;
}