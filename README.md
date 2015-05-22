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
int is_shtr(tour t, int dist);
void define_strt(tour t, city c);
````