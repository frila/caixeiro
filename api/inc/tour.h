#ifndef __TOURH__
#define __TOURH__

#include <stdio.h>
#include <stdlib.h>

#define tour int*
#define city int

//initializes a new tour
tour create_tour(int ncities);

//returns true if the tour t is shorter than
//a distance indicated by dist 
int is_shtr(tour t, int dist);

//defines the starter point of a tour
void strt_point(tour t, city c);

//defines a new tour changing the order of two cities
void swap_cities(tour* t, city c1, city c2);

#endif