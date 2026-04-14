// graph.c

#include "graph.h"

graph_t* buildFirstTopo() {
	graph_t *topo = createNewGraph("Generic Graph");

	node_t* R0_re = createGraphNode(topo, "R0_re");
	
	node_t* R1_re = createGraphNode(topo, "R1_re");

	node_t* R2_re = createGraphNode(topo, "R2_re");

	insertLinkBetweenTwoNodes(R0_re, R1_re, "eth0/0", "eth0/1", 1);
}