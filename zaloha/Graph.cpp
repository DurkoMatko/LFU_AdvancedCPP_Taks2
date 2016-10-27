#include "Graph.h"
#include "Vertex.h"

Graph::Graph()
{
    //ctor
}

Graph::~Graph()
{
    this->deallocateGraph();
}

void Graph::insert(Vertex *v){
	vertices.push_back(v);
}

void Graph::printGraph(){
	for(auto& oneVertex : vertices){		//range based loop
		oneVertex->printEdges();
	}
}

void Graph::initialize(){

	Vertex* v1 = new Vertex("A");
	Vertex* v2 = new Vertex("B");
	Vertex* v3 = new Vertex("C");
	Vertex* v4 = new Vertex("D");
	Vertex* v5 = new Vertex("E");
	Vertex* v6 = new Vertex("F");
	Vertex* v7 = new Vertex("G");
	Vertex* v8 = new Vertex("H");


	/// directed graph (one way edges)
	v1->addEdge(v2, 100);
	v1->addEdge(v6, 20);
	v2->addEdge(v1, 100);
	v3->addEdge(v1, 30);
	v3->addEdge(v4, 10);
	v3->addEdge(v7, 20);
	v4->addEdge(v5, 15);
	v5->addEdge(v1, 10);
	v6->addEdge(v1, 20);
	v8->addEdge(v7, 45);


	this->insert(v1);
	this->insert(v2);
	this->insert(v3);
	this->insert(v4);
	this->insert(v5);
	this->insert(v6);
	this->insert(v7);
	this->insert(v8);
}

void Graph::deallocateGraph(){
	for(auto& oneVertex : vertices){		//range based loop
		delete oneVertex;
	}
}