// Header file for graph

 
typedef struct node node_t;
typedef struct link link_t;

typedef struct interface {
	char interfaceName[INTERFACE_NAME_SIZE];
	struct node *attrNode;
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