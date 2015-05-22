# Problema do caixeiro viajante

## API

A API implementa alguns métodos para resolver o problema do caixeiro viajante

### tour.h

#### defines

Esse arquivo define um tour e uma cidade

````c
#define tour int*
#define city int
````

#### functions

Esse arquivo define **helpers** para serem usados em um tour

````c
//initializes a new tour
tour create_tour(int ncities);

//returns true if the tour t is shorter than
//a distance indicated by dist 
int is_shtr(tour t, int dist);

//defines the starter point of a tour
void strt_point(tour t, city c);

//defines a new tour changing the order of two cities
void swap_cities(tour* t, city c1, city c2);
````