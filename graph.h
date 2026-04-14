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

	linkedlist_node_t* linkedlistNode;
	linkedlist_t* nodeList = &topo->nodeList;
	ITERATE_LINKEDLIST_BEGIN(nodeList, linkedlist_node_t, linkedlistNode) {
		node_t* node = get_node_from_linkedlist(linkedlistNode); // look into making this func
		if (node && memcmp(node->nodeName, nodeName, NODE_NAME_SIZE) == 0)
			return node;
	} ITERATE_LINKEDLIST_ENDS;
	return NULL;
}