#include <stdio.h>
#include <stdlib.h>

#define NCIDADES 4
int caminho[NCIDADES] = { 0, 1, 2, 3 };
int cidade_inicial = 2;

int peso[4][4] = { {999,3,5,4}, {3,999,8,6}, {5,8,999, 1}, {4, 6, 1, 999} };

int main() {
	int i = 1, j, k;
	int menor_peso = 999;

	caminho[0] = cidade_inicial;
	caminho[cidade_inicial] = 0;

	while (i < NCIDADES) {
		for(j = 1; j < NCIDADES; j++) {
			if(j == NCIDADES - 1) {
				int tmp;
				tmp = caminho[j];
				caminho[j] = caminho[1];
				caminho[1] = tmp;			
			} else {
				int tmp;
				tmp = caminho[j];
				caminho[j] = caminho[j+1];
				caminho[j+1] = tmp;
			}
			int peso_total = 0;
			for(k = 0; k < NCIDADES; k++) {
				if(k == NCIDADES - 1) { 
					peso_total += peso[caminho[k]][caminho[0]];
					printf("] ===> peso_total: %d\n", peso_total);
					if(peso_total < menor_peso) { 
						menor_peso = peso_total;
					}
				} 
				else { 
					peso_total += peso[caminho[k]][caminho[k+1]];
					printf("%d", caminho[k]);
				}
			}
			printf("\n");
		}
		i++;
	}

	printf("%d\n", menor_peso);
}