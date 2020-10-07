//Par CHIRINO et NAVARRO le 12/sep/2020
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fonctions.h"

int main(){
	/* Loi des moindres carres
	 * y a quelque chose qui va pas
	 * */
		int taille, i;
		struct polynomes poly1;

		printf("Saisir la taille du tableau\n");
		scanf("%d", &taille);

		poly1.degree = taille;
		poly1.coeff = (float*)malloc(taille*sizeof(float));
		//poly1.coeff = ptr;

		for(i =0; i< taille+1; i++){
			printf("\ncoeff[%d]",i);
			scanf("%f", &poly1.coeff[i]);
		}

			printf("\n\n\n");

		affichage_polynome(poly1);

		printf("%f",poly_evalue(poly1, 2));


		printf("\n\n\n");
	return 0;
}
