#include <iostream>
#include "Graph.h"
#include "Permutacao.h"
#include "Writer.h"
#include "Loader.h"

int main ()
{
	/*
	char data[] = "123456780";
	Permutacao p;
	std::cout << "Gerando permutacoes" << std::endl;
	p.gerarPermutacoes(data, 0, 9);
	std::cout << "Permutacoes geradas" << std::endl;
//	p.imprimirPermutacoes();
	Graph g;
	for (int i = 0; i < static_cast<int>(p.permutacoes.size()); i++)
	{
		g.addVertex(Vertex(i,p.permutacoes[i]));
		g.mapaDeVertices[p.permutacoes[i]] = i;
	}

	p.~Permutacao();
	

	Graph g;

	std::cout << "Construindo o grafo" << std::endl;
	g.construirGrafo(data);
	std::cout << "Grafo pronto" << std::endl;
	Writer s = Writer("grafo.txt");
	s.save(g);
	std::cout << "grafo salvo" << std::endl;
	s.~Writer();
	
	std::cout << "Rodando a dfs" << std::endl;
	g.dfs();
	std::cout << "Fim dfs" << std::endl;

	for(int i = 0; i < g.vertices.size(); i++)
		std::cout << "config " << g.vertices[i].id << " estah na componente "<< g.vertices[i].componentesConexas << std::endl;

	//std::cout << "configuracao inicial " << g.vertices[0].id << std::endl;
	//for (int i = 0; i < static_cast<int>(g.vertices[0].vizinhos.size()); i++)
	//	std::cout << "--- " << g.vertices[g.vertices[0].vizinhos[i]].id << std::endl ;
	//std::cout << "vertices = " << g.vertices.size() << std::endl;


	*/


	Graph g;
	std::cout << "Lendo o Grafo" << std::endl;
	Loader l = Loader("grafo.txt");
	l.load(g);
	l.~Loader();
	std::cout << "Fim da leitura" << std::endl;



	g.dfs();

	std::vector<ComponentesConexas> componente;

	for(int i = 0; i < (int)g.componentes.size(); i++)
		std::cout << "componentes = " << g.componentes[i].id << " vertices = " << g.componentes[i].vertices << " arestas = " << g.componentes[i].arestas/2 << std::endl;


	getchar();
	return 0;
}