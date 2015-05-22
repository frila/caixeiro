# Problema do caixeiro viajante

## API

A API implementa alguns métodos para resolver o problema do caixeiro viajante

### Compilando
Para compilar o projeto faça, primeiramente download do projeto, extraia-o e vá para raíz do projeto e faça
````sh
$ mkdir bin
````
````sh
$ make clean
````
````sh
$ make
````

### Funções

Temos dois arquivos que definem alguns **helpers** para darem suporte aos algoritmos

**tour.h**
*Define funções que interagem diretamente com o tour*

````c
typedef int* tour;
typedef int city;
typedef int distance;
typedef distance** distance_table;

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

//Busca a distancia entre duas cidades
distance get_distance(distance_table d, city c1, city c2);
````

**rdwt.h**
*Controlam entrada e saída do código*

````c
// Lê as distancias entre as cidades da entrada padrão
distance_table rd_distance(int ncities);

// Print o melhor caminho e o custo
void pt_betterpath(tour t, city start_city, int ncities, distance low_distance);

// Read parameters to terminal
void get_input(int argc, char* argv[], int* ncities, int* start_city);
````

### Algoritmos

#### Serial

O objetivo do algoritmo é permutar o entre todas as possibilidades de caminho, construindo uma árvore. De tal maneira, o algoritmo realiza uma busca em profundidade na árvore.
Como forma de otimização, sempre antes de explorar um ramo da árvore, verifico se a distancia acumulada já passou a menos distancia que tenho. Com isso pode ser deixado de explorar diversos ramos da árvore.
````c
void traveling_salesman( tour path, int k, int ncities, distance_table t_distance,
                         distance aggregate, tour better_path, distance *low_distance)
{
    int i;

    if (k == ncities) {
        aggregate += t_distance[path[k-1]][path[0]];
        if ( *low_distance > aggregate) {
            *low_distance = aggregate;
            memcpy(better_path, path, sizeof(int)*ncities);
        }

    } else {
        distance aggregate_local;
        for (i = k; i < ncities; i++) {
            swap_cities( path, k, i);
            aggregate_local = aggregate + get_distance(t_distance, path[k-1], path[k]);
            if ( aggregate_local < *low_distance ){
                traveling_salesman( path, k + 1,ncities, t_distance, aggregate_local, better_path, low_distance);
            }
            swap_cities( path, i, k);
        }
    }
}
````

**Invocando**
````c
traveling_salesman(path,1,ncities, t_distance, 0, better_path, &low_distance);
````

#### Paralelo com OPENMP