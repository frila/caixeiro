#include "timer.h"
#include "rdwt.h"
#include "tour.h"
#include "def.h"
#include <string.h>

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

int main(int argc, char* argv[]){

    city start_city;
    int ncities = 0, j;
    distance low_distance = INF;
    distance_table t_distance;
    tour path, better_path;

    char a;
    while((a = getopt(argc, argv, "n:s:")) != -1) {
        switch(a) {
            case 'n': rd_distance = atoi(optarg); break;
            case 's': start_city  = atoi(optarg); break;
        }
    }

    path = create_tour(ncities);
    better_path = create_tour(ncities);

    populate_tour(path,ncities);

    start_point(path, start_city);

    t_distance = rd_distance(ncities);

    traveling_salesman(path,1,ncities, t_distance, 0, better_path, &low_distance);

    printf("caminho resposta: [ ");
    for(j = 0; j < ncities; j++) {
        printf("%d ", better_path[j]);
    }
    printf("%d ]\n", start_city);
    printf("menor peso %d\n", low_distance);

    return 0;
}