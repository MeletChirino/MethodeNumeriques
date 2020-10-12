#include <stdlib.h>
#include <stdio.h>
#include "fonctions.h"


void echantillon_reguliere(double min, double max, int n, double *echantillon);
void show_array(double *array, int n);

int main(){

		int n = 60, i;
		double *x_values, *y_values;

		y_values = (double*)malloc(n*sizeof(double));
		x_values = (double*)malloc(n*sizeof(double));

		echantillon_reguliere(-1, 1, n, x_values);
		calcul_fonction(n, x_values, y_values);

		for(i=0; i<n; i++){
				printf("\n val[%d] = %f", i, x_values[i]);
		}
		show_array(x_values, n);
		printf("\n\n");
		show_array(y_values, n);

		return 0;
}

