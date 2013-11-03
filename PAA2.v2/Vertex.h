#ifndef VERTEX_H_
#define VERTEX_H_

#include <string>
#include <vector>

const int TAMANHO = 9;

class Vertex
{
public:
	Vertex(int index = -1, std::string id = "") : index(index), id(id)
	{
		if ( id.size() > TAMANHO ) std::cout << "erro" << std::endl;
		else
		{
			visitado = false;
			if (id.size())
				posicao = id.find_first_of("0");
		}

	}

	bool visitado;
    int index;
	int posicao;
	int componentesConexas;
	int distancia; //para ser usada na bfs
	std::string id;
    std::vector<int> vizinhos;
};

#endif