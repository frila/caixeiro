#include "tour.h"

tour create_tour(int ncities) {
	tour t = (int*)malloc(sizeof(int)*ncities);
	return t;
}

int is_shtr(tour t, int dist) { return 1; }

void strt_point(tour t, city c) {}

void swap_cities(tour* t, city c1, city c2) {}