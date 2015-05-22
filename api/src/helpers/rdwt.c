//
// Created by fausto on 22/05/15.
//

#include <stdlib.h>
#include "rdwt.h"

distance rd_distance(int ncities){
    int i,j;
    int *vector_allocated = (int*) malloc (sizeof(int) * ncities * ncities);
    distance vector = (distance) malloc (sizeof(int*) * ncities);

    for(i = 0; i < ncities; i++){
        vector[i] = vector_allocated + i * ncities ;
        for(j = 0; j < ncities; j++)
            scanf("%d", &vector[i][j]);
    }

    return vector;
}