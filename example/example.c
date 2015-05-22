#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

void troca(int* valor1, int* valor2) {
	int tmp = *valor1;
	*valor1 = *valor2;
	*valor2 = tmp;
}

void print_matriz(int **m, int n){
	int i,j;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++)
			printf("%d ", m[i][j]);
		printf("\n");
	}
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


int main(int argc, char *argv[]) {
	int* caminho, *caminho_resposta;
	int cidade_inicial = 0, ncidades = 0;
	int **peso;
	int menor_peso = 999;
	
	int i = 1, j, k;


	char a;
	while((a = getopt(argc, argv, "n:s:")) != -1) {
		switch(a) {
		case 'n': ncidades 			= atoi(optarg); break;
		case 's': cidade_inicial 	= atoi(optarg); break;
		}
	}

	peso = le_entrada(ncidades);
	print_matriz(peso,ncidades);
	// exit(1);

	//refatorar isso aqui
	caminho = (int*)malloc(sizeof(int)*ncidades);
	caminho_resposta = (int*)malloc(sizeof(int)*ncidades);

	for(j = 0; j < ncidades; j++) caminho[j] = j;

	caminho[0] = cidade_inicial;
	caminho[cidade_inicial] = 0;

	for (i = 1; i < ncidades; i++) {
		for(j = 1; j < ncidades; j++) j != ncidades - 1 ? troca(&caminho[j], &caminho[j+1]) : troca(&caminho[j], &caminho[1]);

		int peso_caminho = 0;
		for(k = 0; k < ncidades; k++) k != ncidades - 1 ? (peso_caminho += peso[caminho[k]][caminho[k+1]]) : (peso_caminho += peso[caminho[k]][caminho[0]]);

		if (peso_caminho < menor_peso) { 
			menor_peso = peso_caminho;
			memcpy(caminho_resposta, caminho, sizeof(int) * ncidades);
		}
	}

	printf("menor peso: %d\n", menor_peso);

	printf("caminho resposta: [ ");
	for(k = 0; k < ncidades; k++) {
		printf("%d ", caminho_resposta[k]);

	}
	printf("%d ]\n", cidade_inicial);
}