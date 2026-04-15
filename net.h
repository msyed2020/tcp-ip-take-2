#ifndef __NET__
#define __NET__

typedef struct ipAddress {
	char ipAddr[16];
} ipAddress_t;

typedef struct macAddress {
	char macAddr[8];
} macAddress_t;

typedef struct nodeNetworkProperties {
	bool_t isAddressLoopback;
	ipAddress_t loopbackAddress;
} nodeNetworkProperties_t;

static inline void initNodeNetworkProperties(nodeNetworkProperties_t* properties) {

	properties->isAddressLoopback = false;
	memset(properties->loopbackAddress.ipAddr, 0, 16);
}