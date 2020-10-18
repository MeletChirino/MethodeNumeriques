#include <stdlib.h>
#include <stdio.h>
#include "fonctions.h"

int main(){

		int n = 60;
		double *x_values, *y_values, *new_values;

		//initialisation des tableaux avec la taille de n
		y_values = (double*)malloc(n*sizeof(double));
		x_values = (double*)malloc(n*sizeof(double));
		new_values = (double*)malloc(n*sizeof(double));

		//initialisation des tableaux avec les valeurs de x et y
		echantillon_reguliere(-1, 1, n, x_values);
		calcul_fonction(n, x_values, y_values);

		//Les prochaines lignes sont utilises pour montrer
		//les valeurs de X et Y pour regarder les valeurs
		//enlever les comentaires pour les regarder
		/*
		printf("\nX = \n");
		show_array(x_values, n);
		printf("\n\n");
		printf("\nY = \n");
		show_array(y_values, n);
		*/

		calcul_polynome_lagrange(n, x_values, y_values, new_values);
		printf("\n\n Pm = \n");
		show_array(new_values, n);

		return 0;
}
