#include <stdio.h>
#include <stdlib.h>

#define NCIDADES 4
int caminho[NCIDADES] = { 0, 1, 2, 3 };
int cidade_inicial = 2;

int peso[4][4] = { {999,3,5,4}, {3,999,8,6}, {5,8,999, 1}, {4, 6, 1, 999} };

void troca(int* valor1, int* valor2) {
	int tmp = *valor1;
	*valor1 = *valor2;
	*valor2 = tmp;
}

int main() {
	int i = 1, j, k;
	int menor_peso = 999;
	int* caminho_resposta = caminho;

	//poe a cidade de partida como a cidade inicial
	caminho[0] = cidade_inicial;
	caminho[cidade_inicial] = 0;

	while (i < NCIDADES) {
		for(j = 1; j < NCIDADES; j++) j != NCIDADES - 1 ? troca(&caminho[j], &caminho[j+1]) : troca(&caminho[j], &caminho[1]);

		int peso_caminho = 0;
		for(k = 0; k < NCIDADES; k++) k != NCIDADES -1 ? (peso_caminho += peso[caminho[k]][caminho[k+1]]) : (peso_caminho += peso[caminho[k]][caminho[0]]);

		if (peso_caminho < menor_peso) { menor_peso = peso_caminho; caminho_resposta = caminho; }

		i++;
	}

	printf("menor peso: %d\n", menor_peso);

	printf("caminho resposta: [ ");
	for(k = 0; k < NCIDADES; k++) {
		printf("%d ", caminho_resposta[k]);
	}
	printf("]\n");
}