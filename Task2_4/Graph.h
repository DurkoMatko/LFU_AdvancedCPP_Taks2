#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <string>
#include <cstdio>
#include "Vertex.h"

class Graph{
	public:
		Graph();
		virtual ~Graph();
		void insert(Vertex v);
		void printGraph();
		void initialize();
	protected:
	private:
		std::vector<Vertex> vertices;
};

#endif // GRAPH_H_INCLUDED