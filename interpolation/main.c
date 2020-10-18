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
double polynome_lagrange(int i, int n, double x, double *x_values);

int main(){

		int n = 60, i;
		double *x_values, *y_values, *new_values;

		y_values = (double*)malloc(n*sizeof(double));
		x_values = (double*)malloc(n*sizeof(double));
		new_values = (double*)malloc(n*sizeof(double));

		echantillon_reguliere(-1, 1, n, x_values);
		calcul_fonction(n, x_values, y_values);

		printf("\nX = \n");
		show_array(x_values, n);
		printf("\n\n");
		printf("\nY = \n");
		show_array(y_values, n);

		calcul_polynome_lagrange(n, x_values, y_values, new_values);
		printf("\n\n Pm = \n");
		show_array(new_values, n);

		return 0;
}
void calcul_polynome_lagrange(int n, double *x_values, double *y_values, double *Pm){
		double L[n];
		int i, j, i_;
		//Ahora calcula los Pm
		for(i=0; i<n; i++){
				//initializer le Pm pour le summatoire
				Pm[i] = 0;
				printf("\n\nPm[%d] =", i);

				//Le calcul des Li pour cet valeur

				for(j=0; j<n; j++){
					L[j] = polynome_lagrange(j, n, x_values[i], x_values);
					
					printf("\nL_%d = %lf", j, L[j]); 


					Pm[i] += L[j]*y_values[j]; 
					printf("\n%lf += %lf * %lf ", Pm[i], L[j], y_values[j]);
				}
		}
}

double polynome_lagrange(int i, int n, double x, double *x_values){
		int j;
		double result = 1;

		printf("\n\nL_%d ---------------", i);
		for(j=0; j< n; j++){
			if(j != i){
					result *= (x - x_values[j]) / (x_values[i] - x_values[j]); 
			//printf("\n%lf = %lf - %d / %d - %d", result, x, j, i, j);
			}
		}

		return result;
}
