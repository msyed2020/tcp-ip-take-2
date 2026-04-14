// graph.c

#include "graph.h"

graph_t* buildFirstTopo() {
	graph_t *topo = createNewGraph("Generic Graph");

	node_t* R0_re = createGraphNode(topo, "R0_re");
	
	node_t* R1_re = createGraphNode(topo, "R1_re");

	node_t* R2_re = createGraphNode(topo, "R2_re");

	insertLinkBetweenTwoNodes(R0_re, R1_re, "eth0/0", "eth0/1", 1);

	insertLinkBetweenTwoNodes(R1_re, R2_re, "eth0/2", "eth0/3", 1);

	insertLinkBetweenTwoNodes(R0_re, R2_re, "eth0/4", "eth0/5", 1);
}