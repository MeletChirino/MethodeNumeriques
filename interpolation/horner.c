#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "fonctions.h"

struct polynomes poly_from_roots(float *roots, int length);

int main(){
	/*
	size_t n = sizeof(a)/sizeof(int);
	printf("\ntamanho = %d\n", n);
	*/
	struct polynomes poly1 = create_poly();
	coeff_poly(&poly1);

	//printf("\npoly_eval = %f", poly_evalue(poly1, 3));
	printf("\nhoner = %f", horner(poly1, 3));
	printf("\nhoner_deriv = %f", horner_deriv(poly1, 3));

	float a[] = {1, 2, 3, 4, 5, 6};
	float *roots = a;
	
	poly_from_roots(a);

	return 0;
}
struct polynomes poly_from_roots(float *roots, int length){
		// esta funcion crea un polinomio con las raices
		size_t n = sizeof(roots)/sizeof(float);
		printf("\nsize = %d", get_size_of(roots));
		struct polynomes poly1;
		return poly1;
}

void update_polynome(struct polynomes poly, float *coeff, int degree){
		//esta funcion cambia un polinomio 
		//dependiendo de los coeficientes que se le 
		//den y el nuevo grado. Me sera util para 
		//hacer multiplicaciones sucesivas donde 
		//tenga que multiplicar muchos polinomios 
		//pero sin crear un polinomio nuevo cada vez.
}

