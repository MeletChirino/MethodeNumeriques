//Par CHIRINO et NAVARRO le 12/sep/2020
#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

#define N 100

int main(){
	/* Loi des moindres carres
	 * y a quelque chose qui va pas
	 * */
	float x[N], y[N], moyenne, size, a, b, valeur;

	size = lecture(x, y);
	//se restan 2 para ajustar la ultima repeticion y el hecho de que el primer valor del vector empieza en 0 en este caso, no en 1

	calcul_coef(x, y, size, &a, &b);

	printf("\ny = %fx + %f", a, b);

	valeur = 0;
	do{
		printf("\nSaisisez un valeur pour calculer la valeur de y\n sinon saisisez -1\n");
		scanf("%f", &valeur);
		if(valeur == -1){
				printf("Bye!!");
				break;
		}
		else
				printf("y(%0.2f) = %f", valeur, y_fonction(valeur, a, b)); 
	}while(valeur != -1);

	return 0;
}

