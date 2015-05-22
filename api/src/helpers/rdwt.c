//
// Created by fausto on 22/05/15.
//

#include <stdlib.h>
#include "rdwt.h"
#include "tour.h"


distance rd_distance(int ncities){
    int i,j;
    int *vector_allocated = (int*) malloc (sizeof(int) * ncities * ncities);
    distance vector = (distance) malloc (sizeof(int*) * ncities);

    for(i = 0; i < n; i++){
        vector[i] = vector_allocated + i * ncities ;
        for(j = 0; j < n; j++)
            scanf("%d", &vector[i][j]);
    }

    return vector;
}