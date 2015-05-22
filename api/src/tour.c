#include "tour.h"

tour create_tour(int ncities) {
	tour t = (tour)malloc(sizeof(city)*ncities);
	
	return t;
}

void populate_tour(tour t, int ncities) {
	int i;
	for (i = 0; i < ncities; i++) {
		t[i] = i;
	}
}

int is_shorter(tour t, distance_table dists, int ncities, distance dist) { 
	int i, current_dist = 0;

	for(i = 0; i < ncities; i++) {
		if(i != ncities - 1){
		 	current_dist += get_distance(dists, t[i], t[i+1]);
		} else {
		 	current_dist += get_distance(dists, t[i], t[0]);
		}
	}
	if(current_dist < dist) {
		return current_dist;
	}

	return 0;
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

distance get_distance(distance_table d, city c1, city c2){
	return d[c1][c2];
}