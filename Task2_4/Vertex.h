#ifndef VERTEX_H_INCLUDED
#define VERTEX_H_INCLUDED

#include <vector>
#include <string>
#include <cstdlib>

#include "Edge.h"

class Vertex{
	public:
		Vertex(std::string Name);
		virtual ~Vertex();
		std::string getName();
		std::vector<Edge> getEdges();
		void addEdge(Vertex& v, int dist);
		void printEdges();
	protected:
	private:
		std::string name;
		std::vector<Edge> edges;
};

#endif // VERTEX_H_INCLUDED