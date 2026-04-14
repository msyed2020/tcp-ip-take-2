// Header file for graph

// INSTALL GCC AND MAKE OR UNIX TO RUN PROGRAMS

// #include "linkedlist.h" (for linkedlist file when we make that)

#define INTERFACE_NAME_SIZE 16
#define NODE_NAME_SIZE 16
#define MAX_INTERFACE_PER_NODE 10
 
typedef struct node node_t;
typedef struct link link_t;

typedef struct interface {
	char interfaceName[INTERFACE_NAME_SIZE];
	struct node *attachedNode;
	struct link *link;
} interface_t;

struct link {
	interface_t interface1;
	interface_t interface2;
	unsigned int cost;
};

struct node {
	char nodeName[NODE_NAME_SIZE];
	interface_t* interface[MAX_INTERFACE_PER_NODE];
	linkedlist_t graphGlue;
};

typedef struct graph {
	char topologyName[32];
	linkedlist_t nodeList; // implement this as glued linked list in separate files
};

static inline node_t* getNBRNode(interface_t* interface) {
	return interface->attachedNode;
}

static inline int getAvailableInterfaceNode(node_t* node) {
	for (int i = 0; i < MAX_INTERFACE_PER_NODE; i++) {
		if (node->interface[i] == NULL) {
			return i;
		}
	}
	return -1;
}

static inline interface_t* getNodeInterfaceByName(node_t* node, char* interfaceName) {
	for (int i = 0;i < MAX_INTERFACE_PER_NODE;i++) {
		if (node->interface[i] == NULL)
			continue;
		if (memcmp(node->interface[i]->interfaceName, interfaceName, INTERFACE_NAME_SIZE) == 0)
			return node->interface[i];
	}
	return NULL;
}

static inline node_t* getNodeByNodeName(graph_t* topo, char* nodeName) {
	if (!topo || !nodeName) {
		return NULL; 
	}

	node_t* currentNode = NULL;

	// Iterate through the nodes in the graph
	ITERATE_GRAPH_NODES_BEGIN(topo, currentNode) {
		if (strcmp(currentNode->nodeName, nodeName) == 0) {
			return currentNode; 
		}
	} ITERATE_GRAPH_NODES_END;

	return NULL; 
}