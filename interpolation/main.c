#include <stdlib.h>
#include <stdio.h>
#include "fonctions.h"

void echantillon_reguliere(double min, double max, int n, double *echantillon);
void show_array(double *array, int n);
void sauvegarde_fichier(char *courbe, double *abscisses, double *ordonnees, int n);

void calcul_polynome(int n, double *ech_x, double *ech_y, struct polynomes poly){
	int i;
	for(i=0; i<n; i++){
			ech_y[i] = polynome_eval(ech_x[i], poly);
	}
}


int main(){

		int n = 1000, i;
		char fichier;
		double *x_values, *y_values;

		y_values = (double*)malloc(n*sizeof(double));
		x_values = (double*)malloc(n*sizeof(double));

		echantillon_reguliere(-1, 1, n, x_values);
		calcul_fonction(n, x_values, y_values);
		sauvegarde_fichier("courbe.dat", x_values, y_values, n);
		
		struct polynomes poly1 = create_poly();
		coeff_poly(&poly1);

		calcul_polynome(n, x_values, y_values, poly1);
		show_array(y_values, n);
		
		sauvegarde_fichier("courbe2.dat", x_values, y_values, n);

        system("PAUSE");
		return 0;
}

