#include "tour.h"

tour create_tour(int ncities) {
	tour t = (int*)malloc(sizeof(int)*ncities);
	
	return t;
}

void populate_tour(tour t, int ncities) {
	int i;
	for (i = 0; i < ncities; i++) {
		t[i] = i;
	}
}

int is_shorter(tour t, int dist) { 
	// int current_dist = 0;

	return 1;
}

void start_point(tour t, city c) {
	t[0] = c;
	t[c] = 0;
}

void swap_cities(tour t, city c1, city c2) {
	city tmp = t[c1];
	t[c1] = t[c2];
	t[c2] = tmp; 
}