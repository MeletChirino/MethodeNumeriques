#include <stdlib.h>
#include <stdio.h>
#include "fonctions.h"


void calcul_polynome(int n, double *ech_x, double *ech_y, struct polynomes poly){
	int i;
	for(i=0; i<n; i++){
			ech_y[i] = polynome_eval(ech_x[i], poly);
	}
}

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

		struct polynomes poly1 = create_poly();
		coeff_poly(&poly1);

		calcul_polynome(n, x_values, y_values, poly1);
		show_array(y_values, n);

		return 0;
}

