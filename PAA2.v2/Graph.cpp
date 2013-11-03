#include "Graph.h"
#include <string>
#include <iostream>


Graph::~Graph()
{
	vertices.clear();
}

void Graph::addVertex(Vertex& v)
{
	vertices.push_back(v);
}

/* Depois de adicionado todos os vertices
* temos que ver quem eh vizinho de quem */
void Graph::construirGrafo(char data[])
{
	std::cout << "Gerando Permutacoes" << std::endl;
	gerarPermutacoes(data,0,9);
	std::cout << "Permutacoes geradas" << std::endl;
	std::cout << "Temos " << vertices.size() << " permutacoes" << std::endl;
	for(int i = 0; i < static_cast<int>(vertices.size()); i++)
	{
		testarConfiguracoes(vertices[i]);
	}
}

void Graph::testarConfiguracoes(Vertex& v)
{
	std::string aux = v.id;

	switch(v.posicao)
	{
		case 0: //posso ir para direita e pra baixo
		{
			aux[0] = aux[1];
			aux[1] = '0'; 
			criarArestaEntreVerticesPorID(v, aux); 
			aux = v.id;
			aux[0] = aux[3];
			aux[3] = '0';
			criarArestaEntreVerticesPorID(v, aux);
			break;
		}
		case 1: //posso ir para esquerda e para baixo e para direita
		{
			aux[1] = aux[0];
			aux[0] = '0';
			criarArestaEntreVerticesPorID(v, aux);
			aux = v.id;
			aux[1] = aux[4];
			aux[4] = '0';
			criarArestaEntreVerticesPorID(v, aux);
			aux = v.id;
			aux[1] = aux[2];
			aux[2] = '0';
			criarArestaEntreVerticesPorID(v, aux);

			break;
		} 
		case 2: //posso ir para baixo e para esquerda
		{
			aux[2] = aux[5];
			aux[5] = '0';
			criarArestaEntreVerticesPorID(v, aux);
			aux = v.id;
			aux[2] = aux[1];
			aux[1] = '0';
			criarArestaEntreVerticesPorID(v, aux);
			break;
		} 
		case 3: //posso ir pra cima para direita e para baixo
		{
			aux[3] = aux[0];
			aux[0] = '0';
			criarArestaEntreVerticesPorID(v, aux);
			aux = v.id;
			aux[3] = aux[4];
			aux[4] = '0';
			criarArestaEntreVerticesPorID(v, aux);
			aux = v.id;
			aux[3] = aux[6];
			aux[6] = '0';
			criarArestaEntreVerticesPorID(v, aux);
			break;
		}
		case 4: //posso ir para cima, baixo, esquerda e direita
		{
			aux = v.id;
			aux[4] = aux[1];
			aux[1] = '0';
			criarArestaEntreVerticesPorID(v, aux);
			aux = v.id;
			aux[4] = aux[7];
			aux[7] = '0';
			criarArestaEntreVerticesPorID(v, aux);
			aux = v.id;
			aux[4] = aux[3];
			aux[3] = '0';
			criarArestaEntreVerticesPorID(v, aux);
			aux = v.id;
			aux[4] = aux[5];
			aux[5] = '0';
			criarArestaEntreVerticesPorID(v, aux);
			break;
		}
		case 5: //posso ir para cima, baixo e esquerda
		{
			aux = v.id;
			aux[5] = aux[2];
			aux[2] = '0';
			criarArestaEntreVerticesPorID(v, aux);
			aux = v.id;
			aux[5] = aux[8];
			aux[8] = '0';
			criarArestaEntreVerticesPorID(v, aux);
			aux = v.id;
			aux[5] = aux[4];
			aux[4] = '0';
			criarArestaEntreVerticesPorID(v, aux);
			break;
		}
		case 6: //posso ir para cima e para a direita
		{
			aux = v.id;
			aux[6] = aux[3];
			aux[3] = '0';
			criarArestaEntreVerticesPorID(v, aux);
			aux = v.id;
			aux[6] = aux[7];
			aux[7] = '0';
			criarArestaEntreVerticesPorID(v, aux);
			break;
		}
		case 7: //posso ir para cima, esquerda e direita
		{
			aux = v.id;
			aux[7] = aux[4];
			aux[4] = '0';
			criarArestaEntreVerticesPorID(v, aux);
			aux = v.id;
			aux[7] = aux[6];
			aux[6] = '0';
			criarArestaEntreVerticesPorID(v, aux);
			aux = v.id;
			aux[7] = aux[8];
			aux[8] = '0';
			criarArestaEntreVerticesPorID(v, aux);
			break;
		}
		case 8: //posso ir para cima e para esquerda
		{
			aux = v.id;
			aux[8] = aux[5];
			aux[5] = '0';
			criarArestaEntreVerticesPorID(v, aux);
			aux = v.id;
			aux[8] = aux[7];
			aux[7] = '0';
			criarArestaEntreVerticesPorID(v, aux);
			break;
		}
	}
}

void Graph::criarArestaEntreVerticesPorID(Vertex& v, std::string id)
{
	int vertice_index = mapaDeVertices[id];

	if ( vertice_index < 0 )
		std::cerr << "Erro no map" << std::endl;

	else
	{
		//uma vez que foi criada a arestas entre os vertices devemos atualizar a lista de arestas dos vertices
		// lembrando que se a eh vizinho de b entao b eh vizinho de a
		if(!findVerticeNaListaDeVizinhos(v, vertices[vertice_index]))
		{
			v.vizinhos.push_back(vertice_index);
			vertices[vertice_index].vizinhos.push_back(v.index);
		}
	}

}

/*
* Retorno verdade se b ja eh vizinho de a
*/
bool Graph::findVerticeNaListaDeVizinhos(Vertex& a, Vertex& b)
{
	//se a lista de a eh vazia entao retorno falso
	if (a.vizinhos.size() == 0)
		return false;
	else
		for (int i = 0; i < static_cast<int>(a.vizinhos.size()); i++)
			if (a.vizinhos[i] == b.index)
				return true;
	return false;
}

void Graph::dfs()
{
	for (int i = 0; i < static_cast<int>(vertices.size()); i++)
	{
		if(!vertices[i].visitado)
		{
			componentes.push_back(i+1);
			dfsVisit(i);
		}
		
	}
}
/*
* Funcao recebe o ID do vertice (para diminuir a pilha de recursao)
* e realiza a visita do vertice e seus vizinhos
*/
void Graph::dfsVisit(int v)
{
	std::cout << v << std::endl;
	vertices[v].visitado = true;
	vertices[v].componentesConexas = componentes.size();
	componentes[componentes.size() - 1].vertices++;

	for (int i = 0; i < static_cast<int>(vertices[v].vizinhos.size()); i++)
	{
		componentes[componentes.size() - 1].arestas++;
		if(!vertices[vertices[v].vizinhos[i]].visitado)
		{
			//insiro aresta na arvore?
			dfsVisit(vertices[v].vizinhos[i]);
		}
	}
}

void Graph::clearVisited()
{
	for (int i = 0; i < static_cast<int>(vertices.size()); i++)
		vertices[i].visitado = false;
}

/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. O(n * n!) */
void Graph::gerarPermutacoes(char data[], int inicio, int tamanho)
{
	if ( inicio == tamanho -1 )
	{
		addVertex(Vertex(vertices.size(), std::string(data)));
		mapaDeVertices[std::string(data)] = vertices.size() - 1;
		//std::cout << data << std::endl;
	}
	else
	{
		for(int j = inicio; j < tamanho; j++)
		{
			troca((data+inicio), (data+j));
			gerarPermutacoes(data, inicio+1, tamanho);
			troca((data+inicio), (data+j)); //backtrack
		}
	}
}

void Graph::troca(char *a, char *b)
{
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

