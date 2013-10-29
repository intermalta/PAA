#ifndef PERMUTACAO_H
#define PERMUTACAO_H

#include <vector>
#include <iostream>
#include <string>



class Permutacao
{
public:
	std::vector<std::string> permutacoes;
	
	~Permutacao();
	void gerarPermutacoes(char data[], int inicio, int tamanho); 
	void troca(char *a, char *b);
	void imprimirPermutacoes();
};

#endif