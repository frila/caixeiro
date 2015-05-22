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

Retorna true caso o tour p seja mais curto que a distância dist

````c
int is_shtr(tour t, int dist);
````
Define a cidade inicial de um tour

````c
void define_strt(tour t, city c);
````