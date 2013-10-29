#include "Graph.h"
#include <string>


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
void Graph::construirGrafo()
{
	for(int i = 0; i < static_cast<int>(vertices.size()); i++)
	{
		//vertices[i].visitado = true;
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
			aux[0] = aux[2];
			aux[2] = '0';
			criarArestaEntreVerticesPorID(v, aux);
			break;
		}
		case 1: //posso ir para esquerda e para baixo
		{
			aux[1] = aux[0];
			aux[0] = '0';
			criarArestaEntreVerticesPorID(v, aux);
			aux = v.id;
			aux[1] = aux[3];
			aux[3] = '0';
			criarArestaEntreVerticesPorID(v, aux);
			break;
		} 
		case 2: //posso ir para cima e para direita
		{
			aux[2] = aux[0];
			aux[0] = '0';
			criarArestaEntreVerticesPorID(v, aux);
			aux = v.id;
			aux[2] = aux[3];
			aux[3] = '0';
			criarArestaEntreVerticesPorID(v, aux);
			break;
		} 
		case 3: //posso ir pra cima para esquerda
		{
			aux[3] = aux[1];
			aux[1] = '0';
			criarArestaEntreVerticesPorID(v, aux);
			aux = v.id;
			aux[3] = aux[2];
			aux[2] = '0';
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
		
		//caso ainda nao tenha sido adicionado nenhum vizinho
		if(!findVerticeNaListaDeVizinhos(v, vertices[vertice_index]))
			v.vizinhos.push_back(vertice_index);
		if (!findVerticeNaListaDeVizinhos(vertices[vertice_index], v))
			vertices[vertice_index].vizinhos.push_back(v.index);
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

