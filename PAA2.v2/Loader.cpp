#include "Loader.h"

Loader::Loader(const std::string& file_name)
{
    in.open(file_name, std::ifstream::in); 
}

Loader::~Loader()
{
    in.close();
}

bool Loader::load(Graph& g)
{
    int v, adj, aux;
	std::string id;
    in >> v;
    
    for (int i = 0; i < v; i++)
	{
		in >> id;
		g.addVertex(Vertex(i,id));
		in >> adj;

		for (int p = 0; p < adj; p++)
		{
			in >> aux;
			g.vertices[i].vizinhos.push_back(aux);
		}

	}
     
	return true;
}
