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
	float valeur;
	struct polynomes poly1 = create_poly();

	//for(i =0; i< poly1.degree+1; i++){
//		printf("\ncoeff[%d] ",i);
//		scanf("%f", &poly1.coeff[i]);
//	}
	coeff_poly(&poly1);

		printf("\n\n\n");

	affichage_polynome(poly1);

	do{
		printf("\nSaisisez un valeur a calculer avec le polynome trouve\n");
		scanf("%f",&valeur);
		printf("\ny(%0.2f) = %f",valeur, poly_evalue(poly1, valeur));
		
	}while(valeur != -1);


	printf("\n\n");

	return 0;
}
