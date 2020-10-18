#include <stdlib.h>
#include <stdio.h>
#include "fonctions.h"


void calcul_polynome(int n, double *ech_x, double *ech_y, struct polynomes poly){
	int i;
	for(i=0; i<n; i++){
			ech_y[i] = polynome_eval(ech_x[i], poly);
	}
}

void calcul_polynome_lagrange(int n, double *x_values, double *y_values, double *Pm);
double polynome_lagrange(int i, int n, double x);

int main(){

		int n = 60, i;
		double *x_values, *y_values, *new_values;

		y_values = (double*)malloc(n*sizeof(double));
		x_values = (double*)malloc(n*sizeof(double));
		new_values = (double*)malloc(n*sizeof(double));

		echantillon_reguliere(-1, 1, n, x_values);
		calcul_fonction(n, x_values, y_values);

		for(i=0; i<n; i++){
				printf("\n val[%d] = %f", i, x_values[i]);
		}

		show_array(x_values, n);
		printf("\n\n");
		show_array(y_values, n);

		calcul_polynome_lagrange(n, x_values, y_values, new_values);
		printf("\n\n Pm = \n");
		show_array(new_values, n);

		return 0;
}
void calcul_polynome_lagrange(int n, double *x_values, double *y_values, double *Pm){
		double L[n];
		int i, j;
		//Ahora calcula los Pm
		for(i=0; i<n; i++){
				Pm[i] = 0;

				for(j=0; j<n; j++){
						L[j] = polynome_lagrange(j, n, x_values[i]);
				}

				for(j=0; j<n; j++){
					Pm[i] += L[j]*y_values[j]; 
					printf("\n%lf += %lf * %lf ", Pm[i], L[j], y_values[j]);
				}
		}
}

double polynome_lagrange(int i, int n, double x){
	int j;
	double result = 1;
	
	printf("\n\nL_%d ---------------", i);
	for(j=0; j< n; j++){
			if(j != i){
					result *= (x - j) / (i - j); 
			printf("\n%lf = %lf - %d / %d - %d", result, x, j, i, j);
			}
	}

	return result;
}
