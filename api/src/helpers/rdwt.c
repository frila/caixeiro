//
// Created by fausto on 22/05/15.
//

#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>

#include "rdwt.h"

distance_table rd_distance(int ncities){
    int i,j;
    distance *vector_allocated = (distance*) malloc (sizeof(distance) * ncities * ncities);
    distance_table vector = (distance_table) malloc (sizeof(distance*) * ncities);

    for(i = 0; i < ncities; i++){
        vector[i] = vector_allocated + i * ncities ;
        for(j = 0; j < ncities; j++)
            scanf("%d", &vector[i][j]);
    }

    return vector;
}

void pt_betterpath(tour t, city start_city, int ncities, distance low_distance){
    int j;
    printf("caminho resposta: [ ");
    for(j = 0; j < ncities; j++) {
        printf("%d -> ", t[j]);
    }
    printf("%d ]\n", start_city);
    printf("menor distancia %d\n", low_distance);
}


void get_input(int argc, char* argv[], int* ncities, city* start_city, int *nthreads) {
	char a;
	while((a = getopt(argc, argv, "n:s:t:")) != -1) {
		switch(a) {
		case 'n': *ncities 		= atoi(optarg); break;
		case 's': *start_city 	= atoi(optarg); break;
		case 't': if ( nthreads ) *nthreads = atoi(optarg); break;
		}
	}

    if ( start_city < 0 || start_city >= ncities ){
        perror("Número da cidade inicial inválido");
        exit(1);
    }

    if ( nthreads ){
        if ( nthreads < 0 || nthreads >= ncities ){
            perror("Número de threads inválido");
            exit(1);
        }
    }


}
