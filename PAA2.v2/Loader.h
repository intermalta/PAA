#ifndef LOADER_H_
#define LOADER_H_

#include <iostream>
#include <fstream>
#include <string>
#include "Graph.h"
#include "Vertex.h"

class Loader
{
public:
    Loader(const std::string& file_name);
    ~Loader();
    
    bool load(Graph& g);
private:
    std::ifstream in;
};

#endif