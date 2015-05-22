#include "tour.h"

#define NCITIES 5
#define STARTPOINT 2

int main() {
	tour t = create_tour(NCITIES);
	populate_tour(t, NCITIES);
	start_point(t, STARTPOINT);
	swap_cities(t, 3, 4);

	int i;
	for (i = 0; i < NCITIES; i++)
	{
		printf("%d\n", t[i]);
	}


	printf("Hello!\n");

    return 0;
}