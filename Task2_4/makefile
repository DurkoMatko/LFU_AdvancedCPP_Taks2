all : GraphImplementation

GraphImplementation: Edge.o Vertex.o Graph.o MyMain.o
	g++ -o GraphImplementation Edge.o Vertex.o MyMain.o 

MyMain.o: main.cpp
	g++ -c main.cpp -o MyMain.o -std=c++11

Vertex.o: Vertex.cpp
	g++ -c -o Vertex.o Vertex.cpp -std=c++11

Edge.o: Edge.cpp
	g++ -c -o Edge.o Edge.cpp

Graph.o: Graph.cpp
	g++ -c -o Graph.o Graph.cpp -std=c++11


clean:
	rm GraphImplementation Vertex.o Edge.o Graph.o MyMain.o



