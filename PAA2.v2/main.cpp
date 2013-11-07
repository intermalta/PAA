#include <iostream>
#include "Graph.h"
#include "Permutacao.h"
#include "Writer.h"
#include "Loader.h"


void geraGraphViz(Graph g)
{
	std::ofstream out;
	out.open("GraphViz.txt", std::ofstream::out); 
	
	out << "digraph g{" << std::endl;

	for(int i=0; i < (int)g.vertices.size(); i++)
	{
		for(int j=0; j < (int)g.vertices[i].vizinhos.size(); j++)
		{
			out << g.vertices[i].id << " -> " << g.vertices[g.vertices[i].vizinhos[j]].id << std::endl;
		}
	}

	for(int i=0; i < (int)g.vertices.size(); i++)
	{
		out << g.vertices[i].id << " [];" << std::endl;
	}

	out << "}" << std::endl;
	out.close();

	std::cout << "Terminou o GraphViz" << std::endl;
}


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

	/* Gera arquivo para o GraphViz */
	//geraGraphViz(g);


	/* 	Tarefa 1
	g.dfs();

	std::vector<ComponentesConexas> componente;

	for(int i = 0; i < (int)g.componentes.size(); i++)
		std::cout << "componentes = " << g.componentes[i].id << " vertices = " << g.componentes[i].vertices << " arestas = " << g.componentes[i].arestas/2 << std::endl;

	g.clearVisited();
	*/

	/* Tarefa 2 
	std::cout << "rodando a bfs" << std::endl;
	int idUltimoVertice = g.bfs(g.vertices[0]); //poderia ter usado o map para achar a config 123456780...

	int distancia = g.vertices[idUltimoVertice].distancia;

	std::cout << "distancia = " << distancia << std::endl;

	std::cout << g.vertices[idUltimoVertice].id << std::endl;

	for (int i = 0; i < distancia; i++)
	{
		for (int j = 0; j < (int)g.vertices[idUltimoVertice].vizinhos.size(); j++)
		{
			
			//procurando o vertice ancestral na bfs
			if (g.vertices[g.vertices[idUltimoVertice].vizinhos[j]].distancia == g.vertices[idUltimoVertice].distancia -1)
			{
				std::cout << g.vertices[g.vertices[idUltimoVertice].vizinhos[j]].id << std::endl;
				idUltimoVertice = g.vertices[g.vertices[idUltimoVertice].vizinhos[j]].index;
				break;
			}
		}
	}
	*/

	/* Tarefa 3 */
	g.FindArticulationPoint();
	system("pause");
	getchar();
	return 0;
}