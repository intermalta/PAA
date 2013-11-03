#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <iostream>
#include <unordered_map>
#include "Vertex.h"
#include "ComponentesConexas.h"

class Graph
{
public:
	std::vector<Vertex> vertices;
	std::unordered_map<std::string,int> mapaDeVertices;
	std::vector<ComponentesConexas> componentes;

	~Graph();
	void addVertex(Vertex& v);
	void clearVisited();
	void construirGrafo(char data[]);
	void testarConfiguracoes(Vertex& v);
	void criarArestaEntreVerticesPorID(Vertex& v, std::string id);
	bool findVerticeNaListaDeVizinhos(Vertex& a, Vertex& b);
	void dfs();
	void dfsVisit(int v);

	void gerarPermutacoes(char data[], int inicio, int tamanho); 
	void troca(char *a, char *b);
	int bfs(Vertex& v);
	
		
};

#endif