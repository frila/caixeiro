#include "tour.h"
#include "rdwt.h"
#include "def.h"
#include "timer.h"
#include <string.h>
#include <omp.h>

void traveling_salesman2(tour path, int k, int ncities, distance_table t_distance,
                         distance aggregate, tour better_path, distance *low_distance);

void traveling_salesman(tour* path, int k, int ncities, distance_table t_distance,
                         distance aggregate, tour* better_path, distance* low_distance, int nthreads)
{
    int i;
    if (k == ncities) {
       low_distance[0] = t_distance[0][1] + t_distance[1][0];
       memcpy(better_path[0], path[0], sizeof(city)*ncities);

    } else {
        distance aggregate_local;

        #pragma omp parallel for
        for (i = k; i < ncities; i++) {
            int rank = omp_get_thread_num();
            swap_cities(path[rank], k, i);
            aggregate_local = aggregate + get_distance(t_distance, path[rank][k-1], path[rank][k]);
            if (aggregate_local < *low_distance ) {
                traveling_salesman2(path[rank], k + 1,ncities, t_distance, aggregate_local, better_path[rank], &low_distance[rank]);
            }
            swap_cities(path[rank], i, k);
        }

        int lower_distance_index = 0;
        i = 0;
        do {
            if(low_distance[lower_distance_index] > low_distance[i]) {
                lower_distance_index = i;
                memcpy(better_path[0], path[lower_distance_index], sizeof(city)*ncities);
            }
            i++;
        } while(i < nthreads);
    }
}

void traveling_salesman2(tour path, int k, int ncities, distance_table t_distance,
                         distance aggregate, tour better_path, distance *low_distance)
{
    int i;

    if (k == ncities) {
        aggregate += t_distance[path[k-1]][path[0]];
        if (*low_distance > aggregate) {
            *low_distance = aggregate;
            memcpy(better_path, path, sizeof(city)*ncities);
        }

    } else {
        distance aggregate_local;
        for (i = k; i < ncities; i++) {
            swap_cities(path, k, i);
            aggregate_local = aggregate + get_distance(t_distance, path[k-1], path[k]);
            if (aggregate_local < *low_distance ){
                traveling_salesman2(path, k + 1,ncities, t_distance, aggregate_local, better_path, low_distance);
            }
            swap_cities(path, i, k);
        }
    }
}

int main(int argc, char* argv[]){
    int i;
    city start_city;
    int ncities = 0, nthreads = 0;
    distance* low_distance;
    distance_table t_distance;
    tour* path, *better_path;

    get_input(argc, argv, &ncities, &start_city, &nthreads);

    path = (tour*)malloc(sizeof(tour)*nthreads);
    better_path = (tour*)malloc(sizeof(tour)*nthreads);
    low_distance = (distance*)malloc(sizeof(distance)*nthreads);

    for(i = 0; i < nthreads; i++) {
        path[i] = create_tour(ncities);
        populate_tour(path[i],ncities);
        better_path[i] = create_tour(ncities);
        start_point(path[i], start_city);
        low_distance[i] = INF;
    }


    t_distance = rd_distance(ncities);

    double time_ini;
    GET_TIME(time_ini);

    traveling_salesman(path, 1, ncities, t_distance, 0, better_path, low_distance, nthreads);

    double time_end;
    GET_TIME(time_end);


    pt_betterpath(better_path[0], start_city, ncities, low_distance[0]);

    printf("tempo de execução: %0.12lf\n", time_end - time_ini);
    
    return 0;
}