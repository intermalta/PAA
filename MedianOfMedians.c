#include <limits.h>
#include <time.h>
#include <stdlib.h>

void mergeSort(int *vetor, int esquerdo, int direito)
{
	int meio = (direito + esquerdo)/2;

	if ( DEBUG )
	{
		printf("****MERGESORT****\n");
		imprimirVetor(vetor, (direito - esquerdo)+1);
	}

	if ( direito > esquerdo )
	{
		mergeSort(vetor, esquerdo, meio);
		mergeSort(vetor, (meio + 1), direito);
		mergeVetores(vetor, esquerdo, meio, direito);
	}
}
void mergeVetores(int *vetor, int esquerdo, int meio, int direito)
{
    int i, j, k, *auxVetor;

    auxVetor = malloc( (direito - esquerdo + 1) * sizeof (int));

    i = esquerdo;
    j = meio + 1;
    k = 0;

    if (DEBUG)
    {
        printf("***entrada***\n");
        imprimirVetor(vetor, direito - esquerdo +1);
    }
    while (i <= meio && j <= direito)
    {
        if (vetor[i] < vetor[j])
            auxVetor[k++] = vetor[i++];
        else
            auxVetor[k++] = vetor[j++];
    }

    while (i <= meio)  auxVetor[k++] = vetor[i++];

    while (j <= direito)  auxVetor[k++] = vetor[j++];

    i = esquerdo;
    j = 0;
    while(i <= direito) vetor[i++] = auxVetor[j++];

    if (DEBUG)
    {
        printf("***saida***\n");
        imprimirVetor(vetor, direito - esquerdo + 1);
    }
    free( auxVetor );

}

int kesimoMenorScan(int *vetor, int tamanho,int k)
{
    int i, aux = 1, sentinela = 0, n = tamanho, pos = 0;

    double tInicio, tFim;

    int menor = INT_MAX;

    if ( k >= tamanho  || k < 1)
    {
        printf("boundary problems\n");
        exit(33);
    }

    tInicio = getTime();
    while ( aux <= k )
    {
        for (i = 0; i < n; i++)
        {
            if ( menor > vetor[i] )
            {
                menor = vetor[i];
                sentinela = 1;
                pos = i;
            }
        }
        if (sentinela)
        {
            if ( vetor[n -1] != menor )
            {
                vetor[pos] = vetor[n -1];
                vetor[n - 1] = menor;  //coloco o menor na ultima posicao valida
                menor = INT_MAX;
            }
        }
        tFim = getTime();

        if ( tFim - tInicio > 60 )
        {
            printf("tempo esgotado\n");
            return -1;
        }

        n--;
        aux++;
        sentinela = 0;
        menor = INT_MAX;
    }

    return vetor[tamanho -k];
}

int kesimoMenorMerge(int *vetor, int tamanho,int k)
{
     if ( k >= tamanho  || k < 1)
    {
        printf("boundary problems\n");
        exit(34);
    }
    mergeSort(vetor, 0, tamanho -1);

    return vetor[k-1];
}


int momSelect(int *vet, int l, int r, int k)
{
    int i, cont, mediana, pos, tamMedianas;
    int *vMedianas;
    int tamanho = r - l + 1;

    //Caso básico da recursão
    /*
    if(tamanho < 6)
    {
        mergeSort(vet, l, r);
        return vet[(l+r)/2];
    }*/

    if ( l == r )
        return vet[l];


    tamMedianas = (tamanho+4)/5;
    vMedianas = (int*)malloc(tamMedianas * sizeof(int));

    //Ordena os grupos de 5 elementos e copia as medianas para o vetor de medianas
    int ini, fim; //--
    cont = 0;
    for(i = 0; i < tamMedianas; i++)
    {
        ini = l+i*5; //--
        fim = l+i*5+4; //--
        if(i*5+4+l > r)
        {
            mergeSort(vet, l+(i*5), r);
            vMedianas[cont] = vet[(l+r+(i*5))/2];
        }else{
            mergeSort(vet, l+i*5, l+i*5+4);
            vMedianas[cont] = vet[l+i*5+2];
        }
        cont++;
    }

    mediana = momSelect(vMedianas, 0, cont-1, (cont-1)/2);

    free(vMedianas);

    pos = pivoteamento(vet, l, r, mediana);

    if(pos == k)
        return vet[k];
    else if(pos > k)
        return momSelect(vet, l, pos-1, k);
    else
        return momSelect(vet, pos+1, r, k);


    return 0;
}

int quickSelect(int *vet, int l, int r, int i)
{
    if(l == r)
        return vet[l];

    int q = pivoteamento(vet, l, r, vet[rand()% (r-l) +l]);
    int k = 0; 

    if(i == q) 
        return vet[q];
    else if(i < q) 
        return quickSelect(vet, l, q-1, i);
    else
        return quickSelect(vet, q+1, r, i-k);

}

//14/9/2013


int pivoteamento(int *vet, int l, int r, int pivo)
{
    int i, j, temp;
     //Ajusta as variávies i e j

	//Ajusta as variávies i e j
    i = l; j = r;

    //Inicia o partition
    while(1)
    {
        while((j > i) && (vet[j] > pivo))
            j--;


        while((i < j) && (vet[i] < pivo))
            i++;


        if ( i < j )
        {
            temp = vet[i];
            vet[i] = vet[j];
            vet[j] = temp;
        }

        if(i == j)
            break;

    }

   return i; //compensando a posicao 0 e quando o ponteiro esquerdo nao comeca da posicao 0
}

