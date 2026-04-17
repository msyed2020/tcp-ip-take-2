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

