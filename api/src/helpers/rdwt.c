//
// Created by fausto on 22/05/15.
//

#include <stdlib.h>
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