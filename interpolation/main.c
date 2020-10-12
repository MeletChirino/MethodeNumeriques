#include <stdlib.h>
#include <stdio.h>
#include "fonctions.h"


void echantillon_reguliere(double min, double max, int n, double *echantillon);
void show_array(double *array, int n);
void sauvegarde_fichier(char *courbe, double *abscisses, double *ordonnees, int n);

int main(){

		int n = 1000, i;
		char fichier;
		double *x_values, *y_values;

		y_values = (double*)malloc(n*sizeof(double));
		x_values = (double*)malloc(n*sizeof(double));

		echantillon_reguliere(-1, 1, n, x_values);
		calcul_fonction(n, x_values, y_values);
		sauvegarde_fichier("courbe.dat", x_values, y_values, n);

		
		show_array(x_values, n);
		printf("\n\n");
		show_array(y_values, n);
		
        system("PAUSE");
		return 0;
}

