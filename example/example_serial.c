#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

#define INIFINITO 999999

void print_matriz(int **m, int n){
	int i,j;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++)
			printf("%d ", m[i][j]);
		printf("\n");
	}
}

void print(int v[], int N)
{
  int i = 0;
  for(i = 0; i < N; i++)
  {
    printf("%d ", v[i]);
  }
  printf("\n");
}

int **le_entrada(int n) {
	int i,j;
	int *vetor_alocado = (int*) malloc (sizeof(int) * n * n);
	int **vetor = (int**) malloc (sizeof(int*) * n);

	for(i = 0; i < n; i++){
		vetor[i] = vetor_alocado + i * n ;
		for(j = 0; j < n; j++)
			scanf("%d", &vetor[i][j]);
	}

	return vetor;
}

void troca( int* vetor, int p1, int p2)
{
   int tmp;
   tmp = vetor[p1]; 
   vetor[p1] = vetor[p2]; 
   vetor[p2] = tmp;
}

int recursivo( int* vetor, int k, int ncidades, int **peso, int acumulado, int *melhor_caminho, int menorPeso)
{
   int i;

   for( i = 0; i < k; i++)
   	printf("\t");
   printf("%d - %d\n", vetor[k], acumulado);

   if (k == ncidades) {
   		acumulado += peso[vetor[k-1]][vetor[0]];
   		if ( menorPeso > acumulado ) {
   			menorPeso = acumulado;
   			memcpy(melhor_caminho, vetor, sizeof(int)*ncidades);
   		}
   		
		return menorPeso;
   
   } else {
      acumulado += peso[vetor[k-1]][vetor[k]];	
      for (i = k; i < ncidades; i++) {
         troca( vetor, k, i);
         menorPeso = recursivo( vetor, k + 1,ncidades, peso, acumulado, melhor_caminho, menorPeso);
         troca( vetor, i, k);
      }
      return menorPeso;
   }
}

int main( int argc, char *argv[])
{	
	int cidade_inicial = 0, ncidades = 0;
	int j;
	int *caminho, *melhor_caminho;

	char a;
	while((a = getopt(argc, argv, "n:s:")) != -1) {
		switch(a) {
		case 'n': ncidades 			= atoi(optarg); break;
		case 's': cidade_inicial 	= atoi(optarg); break;
		}
	}

	caminho = (int*)malloc(sizeof(int)*ncidades);
	melhor_caminho = (int*)malloc(sizeof(int)*ncidades);

	for(j = 0; j < ncidades; j++) caminho[j] = j;

	caminho[0] = cidade_inicial;
	caminho[cidade_inicial] = 0;

	int **peso = le_entrada(ncidades);
	print_matriz(peso, ncidades);
	int menorPeso = recursivo(caminho,1,ncidades, peso, 0, melhor_caminho, INIFINITO);

	printf("caminho resposta: [ ");
	for(j = 0; j < ncidades; j++) {
		printf("%d ", melhor_caminho[j]);
	}
	printf("%d ]\n", cidade_inicial);
	printf("menor peso %d\n", menorPeso);

	return 0;
}