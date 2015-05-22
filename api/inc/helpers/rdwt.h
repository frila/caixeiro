//
// Created by fausto and bernardo on 22/05/15.
//

#ifndef CAIXEIRO_RDWT_H
#define CAIXEIRO_RDWT_H

#include "tour.h"
#include <unistd.h>
#include <ctype.h>
#include <string.h>


// Lê as distancias entre as cidades da entrada padrão
distance_table rd_distance(int ncities);

// Print o melhor caminho e o custo
void pt_betterpath(tour t, city start_city, int ncities);
void get_input(int argc, char* argv[], int* ncities, int* start_city);

#endif //CAIXEIRO_RDWT_H
