#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <iostream>
#include <unordered_map>
#include "Vertex.h"

class Graph
{
public:
	std::vector<Vertex> vertices;
	std::unordered_map<std::string,int> mapaDeVertices;

	~Graph();
	void addVertex(Vertex& v);
	void clearVisited();
	void construirGrafo();
	void testarConfiguracoes(Vertex& v);
	void criarArestaEntreVerticesPorID(Vertex& v, std::string id);
	bool findVerticeNaListaDeVizinhos(Vertex& a, Vertex& b);
		
};

#endif