#include "Permutacao.h"

/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. O(n * n!) */
void Permutacao::gerarPermutacoes(char data[], int inicio, int tamanho)
{
	if ( inicio == tamanho )
	{
		permutacoes.push_back(std::string(data));
		//std::cout << data << std::endl;
		
	}
	else
	{
		for(int j = inicio; j < tamanho; j++)
		{
			troca((data+inicio), (data+j));
			gerarPermutacoes(data, inicio+1, tamanho);
			troca((data+inicio), (data+j)); //backtracking
		}
	}
}

void Permutacao::troca(char *a, char *b)
{
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void Permutacao::imprimirPermutacoes()
{
	for ( int i = 0; i < static_cast<int>(permutacoes.size()); i++)
		std::cout << permutacoes[i] << std::endl;
}

Permutacao::~Permutacao()
{
	permutacoes.clear();
}