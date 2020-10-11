//Par CHIRINO et NAVARRO le 12/sep/2020
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fonctions.h"

int main(){
	/* Loi des moindres carres
	 * y a quelque chose qui va pas
	 * */
	struct polynomes poly1 = create_poly();
	coeff_poly(&poly1);

		printf("\n\n\n");

	affichage_polynome(poly1);

	//teste derivee
	struct polynomes poly2 = deriver(poly1);
	printf("\nDerivee = ");
	affichage_polynome(poly2);
	printf("\n\n");

	// teste somme avec la derivee du polynome
	struct polynomes poly3 = somme(poly1, poly2);
	printf("\nSomme = ");
	affichage_polynome(poly3);
	printf("\n\n");

	// teste multiplication avec la derivee du polynome
	struct polynomes poly4 = produit(poly1, poly2);
	printf("\nMultiplication = ");
	affichage_polynome(poly4);
	printf("\n\n");

	//teste multiplication avec un nouvelle polynome
	struct polynomes poly5 = create_poly();
	coeff_poly(&poly5);
	struct polynomes poly6 = produit(poly1, poly5);
	printf("\nMultiplication = ");
	affichage_polynome(poly6);
	printf("\n\n");

	return 0;
}
