#ifndef WRITER_H
#define WRITER_H

#include <iostream>
#include <fstream>
#include <string>
#include "Graph.h"
#include "Vertex.h"

class Writer
{
public:
    Writer(const std::string& file_name);
    ~Writer();
    bool save(Graph& g);
private:
    std::ofstream out;
};

#endif
