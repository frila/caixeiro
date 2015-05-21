#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

void troca(int* valor1, int* valor2) {
	int tmp = *valor1;
	*valor1 = *valor2;
	*valor2 = tmp;
}

int main(int argc, char *argv[]) {
	int* caminho;
	int cidade_inicial = 0, ncidades = 0;
	int peso[4][4] = { {999,3,5,4}, {3,999,8,6}, {5,8,999, 1}, {4, 6, 1, 999} };
	int menor_peso = 999;
	
	int i = 1, j, k;

	int* caminho_resposta = caminho;

	char a;
	while((a = getopt(argc, argv, "n:s:")) != -1) {
		switch(a) {
		case 'n': ncidades 			= atoi(optarg); break;
		case 's': cidade_inicial 	= atoi(optarg); break;
		}
	}

	//refatorar isso aqui
	caminho = (int*)malloc(sizeof(int)*ncidades);
	for(j = 0; j < ncidades; j++) caminho[j] = j;

	caminho[0] = cidade_inicial;
	caminho[cidade_inicial] = 0;

	while (i < ncidades) {
		for(j = 1; j < ncidades; j++) j != ncidades - 1 ? troca(&caminho[j], &caminho[j+1]) : troca(&caminho[j], &caminho[1]);

		int peso_caminho = 0;
		for(k = 0; k < ncidades; k++) k != ncidades -1 ? (peso_caminho += peso[caminho[k]][caminho[k+1]]) : (peso_caminho += peso[caminho[k]][caminho[0]]);

		if (peso_caminho < menor_peso) { menor_peso = peso_caminho; caminho_resposta = caminho; }

		i++;
	}

	printf("menor peso: %d\n", menor_peso);

	printf("caminho resposta: [ ");
	for(k = 0; k < ncidades; k++) {
		printf("%d ", caminho_resposta[k]);
	}
	printf("]\n");
}