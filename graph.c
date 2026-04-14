// graph.c

// run proj in VS but use VSCode to compile and run

#include "graph.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlist/linkedlist.h"

void insertLinkBetweenTwoNodes(node_t* node1, node_t* node2,
	char* fromIFName, char* toIFName, unsigned int cost) {
	link_t* link = calloc(1, sizeof(link_t));

	strncpy(link->interface1.ifName, fromIFName, IF_NAME_SIZE);
	link->interface1.ifName[IF_NAME_SIZE - 1] = '\0';

	strncpy(link->interface2.ifName, toIFName, IF_NAME_SIZE);
	link->interface2.ifName[IF_NAME_SIZE - 1] = '\0';

	link->interface1.link = link;
	link->interface2.link = link;

	link->interface1.attachedNode = node1;
	link->interface2.attachedNode = node2;
	link->cost = cost;

	int emptyInterfaceSlot;

	emptyInterfaceSlot = getAvailableInterfaceSlot(node1);
	node1->interface[emptyInterfaceSlot] = &link->interface1;

	emptyInterfaceSlot = getAvailableInterfaceSlot(node2);
	node2->interface[emptyInterfaceSlot] = &link->interface2;
}

graph_t* createNewGraph(char *topologyName) {
	graph_t* graph = calloc(1, sizeof(graph_t));
	strncpy(graph->topologyName, topologyName, 32);
	graph->topologyName[31] = '\0';

	init_linkedlist(&graph->nodeList, NULL);
	return graph;
}

node_t* createGraphNode(graph_t* graph, char* nodeName) {
	node_t* node = calloc(1, sizeof(node_t));
	strncpy(node->nodeName, nodeName, NODE_NAME_SIZE);
	node->nodeName[NODE_NAME_SIZE - 1] = '\0';
	linkedlist_add(&graph->nodeList, &node->graphGlue);
	return node;
}

graph_t* buildFirstTopo() {
	graph_t *topo = createNewGraph("Generic Graph");

	node_t* R0_re = createGraphNode(topo, "R0_re");
	
	node_t* R1_re = createGraphNode(topo, "R1_re");

	node_t* R2_re = createGraphNode(topo, "R2_re");

	insertLinkBetweenTwoNodes(R0_re, R1_re, "eth0/0", "eth0/1", 1);

	insertLinkBetweenTwoNodes(R1_re, R2_re, "eth0/2", "eth0/3", 1);

	insertLinkBetweenTwoNodes(R0_re, R2_re, "eth0/4", "eth0/5", 1);

	return topo;
}

