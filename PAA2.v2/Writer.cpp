#include "Writer.h"



Writer::Writer(const std::string& file_name)
{
    out.open(file_name, std::ofstream::out); 
}

Writer::~Writer()
{
    out.close();
}

bool Writer::save(Graph& g)
{
	out << g.vertices.size() << std::endl;
    for (int v = 0; v < static_cast<int>(g.vertices.size()); v++)
	{
		out << g.vertices[v].id << std::endl;
		out << g.vertices[v].vizinhos.size() << std::endl;
		for (int adjacentes = 0; adjacentes < static_cast<int>(g.vertices[v].vizinhos.size()); adjacentes++)
			out << g.vertices[v].vizinhos[adjacentes] << " ";

		out << std::endl;
	}
        
    return true;
}
