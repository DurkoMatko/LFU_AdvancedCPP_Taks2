#include "Edge.h"
#include "Graph.h"
#include "Graph.cpp"
#include "Vertex.h"
#include <iostream>

int main(){

	Graph g;
	g.initialize();
	g.printGraph();
	g.deallocateGraph();
	
	return EXIT_SUCCESS;
}