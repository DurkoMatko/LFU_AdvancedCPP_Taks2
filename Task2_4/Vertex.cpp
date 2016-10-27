#include "Vertex.h"
#include "Edge.h"
#include <iostream>

Vertex::Vertex(std::string Name):name(Name)
{

}

Vertex::~Vertex()
{
    //dtor
}

std::string Vertex::getName() {
	return name;
} 

std::vector<Edge> Vertex::getEdges(){
	return edges;
}

void Vertex::addEdge(Vertex &v, int dist)
    {
        Edge newEdge(*this, v, dist);           //reference of this, reference of another Vertex, distance
        edges.push_back(newEdge);
    }

void Vertex::printEdges(){
    std::cout << this->name << ":" << std::endl;
    for (auto& edge : edges){
    	std::cout << edge.getDestination().getName() << " - " << edge.getDistance() << std::endl;
    }
    std::cout << std::endl;
}
