#include "graph.h"
#include <memory.h>
#include "utils.h"
#include <stdio.h>

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


	return true;
}