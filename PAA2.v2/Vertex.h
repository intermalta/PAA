#ifndef VERTEX_H_
#define VERTEX_H_

#include <string>
#include <vector>

//enum Status {NOT_VISITED, VISITED};
const int TAMANHO = 4;
/*
pos = linha*2+coluna;

a[0] a[1] a[2] a[4]
a[0][0] a[0][1]
a[1][0] a[1][1]

*/
class Vertex
{
public:
	Vertex(int index = -1, std::string id = "") : index(index), id(id)
	{
		if ( id.size() > TAMANHO ) std::cout << "erro" << std::endl;
		else
		{
			visitado = false;
			posicao = id.find_first_of("0");
			//std::cout << "pos do 0 = " << posicao << "id = " << id << std::endl;
		}

	}

	bool visitado;
    int index;
	int posicao;
	int componentesConexas;
	std::string id;
    std::vector<int> vizinhos;
};

#endif