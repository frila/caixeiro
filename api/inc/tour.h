#ifndef __TOURH__
#define __TOURH__

#include <stdio.h>
#include <stdlib.h>

typedef int* tour;
typedef int city;
typedef int distance;
typedef int** distance_table;

//inicializa um tour
tour create_tour(int ncities);

//popula um tour pre-definido com cidades
void populate_tour(tour t, int ncities);

//define a cidade inicial de um tour
void start_point(tour t, city c);

//retorna true se a distancia total do
//tour t for menor que dist
int is_shoter(tour t, int dist);

//inverte a posição de duas cidades no tour
void swap_cities(tour t, int c1, int c2);



#endif