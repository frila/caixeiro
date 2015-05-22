#include "tour.h"
#include "rdwt.h"
#include "def.h"
#include <string.h>

int main(int argc, char *argv[]) {
    //definindo variáveis auxiliares
    int ncities, nthread, i, j;
    city start_city;
    distance_table distances;
    distance shorter_distance = INF;

    //lendo input: número de cidades e cidade inicial
    get_input(argc, argv, &ncities, &start_city, &nthread);
    //lendo input: matriz de distancias
    distances = rd_distance(ncities);

    //inicializando tour
    tour t = create_tour(ncities);
    populate_tour(t, ncities);
    start_point(t, start_city);

    //inicializando o tour que vai guardar o melhor caminho
    tour better_tour = create_tour(ncities);

    //executando o algoritmo de permutação e comparando os pesos dos caminhos
	for(i = 1; i < ncities; i++) {
		for(j = 1; j < ncities; j++) { 
            if(j != ncities - 1) {
                swap_cities(t, j, j+1);
            } else {
                swap_cities(t, j, 1);
            }
        }

        distance sh;
        if((sh = is_shorter(t, distances, ncities, shorter_distance))) {
            shorter_distance = sh;
            memcpy(better_tour, t, sizeof(city)*ncities);
        }
    }

    pt_betterpath(better_tour, start_city, ncities, shorter_distance);

    return 0;
}