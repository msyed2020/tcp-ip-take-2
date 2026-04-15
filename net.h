#ifndef __NET__
#define __NET__

// IP Address struct
typedef struct ipAddress {
	char ipAddr[16];
} ipAddress_t;

// MAC Address struct
typedef struct macAddress {
	char macAddr[8];
} macAddress_t;

// struct to define network properties of a graph node, such as loopback address

// A loopback address is a distinct reserved IP address range that starts from 127.0.0.0 and ends at 127.255.255.255

// The loopback addresses are built into the IP domain system, enabling devices to transmit and receive data packets

// The loopback address 127.0.0.1 is generally known as localhost

// TCP/IP protocol manages all the loopback addresses in the operating system

typedef struct nodeNetworkProperties {
	bool_t isAddressLoopback;
	ipAddress_t loopbackAddress;
} nodeNetworkProperties_t;

static inline void initNodeNetworkProperties(nodeNetworkProperties_t* properties) {

	properties->isAddressLoopback = false;
	memset(properties->loopbackAddress.ipAddr, 0, 16);

}

typedef struct intfNetworkProperties {
	macAddress_t macAddress;

	bool_t isIPAddressConfigured;
	ipAddress_t ipAddress;
	char mask;
	
} intfNetworkProperties_t;

static inline void initIntfNetworkProperties(intfNetworkProperties_t* properties) {
	memset(properties->macAddress.macAddr, 0, 48);
	properties->isIPAddressConfigured = false;
	memset(properties->ipAddress.ipAddr, 0, 16);
	properties->mask = 0;
}

// macros to access networking properties of nodes and interfaces

#define IF_MAC(intf_ptr) ((intf_ptr)->networkProperties.macAddress.macAddr)
#define IF_IP(intf_ptr) ((intf_ptr)->networkProperties.ipAddress.ipAddr)
#define NODE_LO_ADDR(node_ptr) (node_ptr->->nodeNetworkProperties.loopbackAddress.ipAddr)

// functions to set network node properties

bool_t nodeSetLoopbackAddress(node_t* node, char* ipAddr);
bool_t nodeSetInterfaceIPAddress(node_t* node, char* localInterface, char* ipAddr, char mask);

#endif /* __NET__ */