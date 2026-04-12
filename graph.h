// Header file for graph


typedef struct interface {
	char interfaceName[INTERFACE_NAME_SIZE];
	struct node *attrNode;
	struct link *link;
} interface_t;

typedef struct graph {
	char topologyName[32];
	linkedlist_t nodeList; // implement this as glued linked list in separate files
};