//elaborado por Melet Chirino
#include <stdio.h>
#include <stdlib.h>

#define DIM 11
typedef float tabla[DIM];

int suma(tabla vector);

int main()
{

	tabla temps;
	int a;
	temps[0] = 0;
	temps[2] = 2;
	a = sizeof(temps) / 4;//No se exactamente hay que hacer esto, pero me dio resultado
	
	suma(temps);
	printf("\n%f\n%d\n", temps[2], DIM);

	return 0;
}

int suma(tabla vector)
{
	vector[2] = 9;
	return 0;
}