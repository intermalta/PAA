#include <iostream>
#include "Graph.h"
#include "Permutacao.h"

int main ()
{
	char data[] = "1230";

	Permutacao p;
	p.gerarPermutacoes(data, 0, 4);
//	p.imprimirPermutacoes();
	Graph g;
	for (int i = 0; i < static_cast<int>(p.permutacoes.size()); i++)
	{
		g.addVertex(Vertex(i,p.permutacoes[i]));
		g.mapaDeVertices[p.permutacoes[i]] = i;
	}


	g.construirGrafo();

	std::cout << "configuracao inicial " << g.vertices[0].id << std::endl;
	for (int i = 0; i < static_cast<int>(g.vertices[0].vizinhos.size()); i++)
		std::cout << "--- " << g.vertices[g.vertices[0].vizinhos[i]].id << std::endl ;
	//std::cout << "vertices = " << g.vertices.size() << std::endl;



	getchar();
	return 0;
}