#include "Graph.h"
#include "Vertex.h"
#include <iostream>

Graph::Graph()
{
    //ctor
}

Graph::~Graph()
{
	//dtor
}

void Graph::insert(Vertex v){
	vertices.push_back(v);
}

void Graph::printGraph(){
	for(auto& oneVertex : vertices){		//range based loop
		oneVertex.printEdges();
	}
}

void Graph::initialize(){

	const char* const names[] = {"A", "B", "C", "D", "E", "F", "G", "H"};
	int a =0;
	std::vector<Vertex> temp;
	for(auto& i : names){
		temp.push_back(Vertex(i));
	}

	/// directed graph (one way edges)
	temp[0].addEdge(*(&temp[1]), 100);
	temp[0].addEdge(*(&temp[5]), 20);
	temp[1].addEdge(*(&temp[0]), 100);
	temp[2].addEdge(*(&temp[0]), 30);
	temp[2].addEdge(*(&temp[3]), 10);
	temp[2].addEdge(*(&temp[6]), 20);
	temp[3].addEdge(*(&temp[4]), 15);
	temp[4].addEdge(*(&temp[0]), 10);
	temp[5].addEdge(*(&temp[0]), 20);
	temp[7].addEdge(*(&temp[6]), 45);

	//vertices = temp;
	vertices.swap(temp);
	std::cout << "My size is " << vertices.size() << std::endl;
}