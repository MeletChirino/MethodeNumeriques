#include <stdlib.h>
#include <stdio.h>
#include "fonctions.h"

<<<<<<< HEAD
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
=======
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
		sauvegarde_fichier("courbe.dat", x_values, y_values, n);

		show_array(y_values, n);
		
		sauvegarde_fichier("courbe2.dat", x_values, y_values, n);


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

        system("PAUSE");
		return 0;
}
