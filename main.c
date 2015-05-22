#include "tour.h"

#define NCITIES 5

int main() {
	tour t = create_tour(NCITIES);

	int i;
	for (i = 0; i < NCITIES; i++)
	{
		printf("%d\n", t[i]);
	}

	printf("Hello!");

    return 0;
}