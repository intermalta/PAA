#ifndef COMPONENTESCONEXAS_H
#define COMPONENTESCONEXAS_H

class ComponentesConexas
{
public:
	ComponentesConexas(int id = 1) : id(id), vertices(0), arestas(0) {};
	int id;
	int vertices;
	int arestas;
};
#endif