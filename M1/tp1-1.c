//Par CHIRINO et NAVARRO le 17-sep-2020
//Compilation method gcc -Wall FILE.c -o temp.o -lm
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	//variables
	int a, b ,c;
	float delta, root[2];


	//saisir les valeurs
	printf("Saisir la valeur de a\n");
	scanf("%d", &a);

	printf("Saisir la valeur de b\n");
	scanf("%d", &b);

	printf("Saisir la valeur de c\n");
	scanf("%d", &c);

	//Calcul de delta
	delta = b*b -4*a*c;

	//Show roots
	if(delta>=0){
		root[0] = (-b + sqrt(delta))/(2*a);
		root[1] = (-b - sqrt(delta))/(2*a);

		if(root[0] != root[1]){
				printf("Les solutions pour l'equation sont:\nX1 = %f\nX2 = %f\n", 
					root[0],
					root[1]
					);
		} else {
				printf("La solution pour l'equation est:\nX = %f",
					root[1]
					);
		}
		
	 } else {
		float iroot[2];

		root[0] = (-b ) / (2*a);
		iroot[0] = sqrt(-1*delta) / (2*a);

		root[1] = (-b ) / (2*a);
		iroot[1] = -1 * sqrt(-1*delta) / (2*a);

		printf("Les solutions pour l'equation sont:\nX1 = %f + (%f)i\nX2 = %f + (%f)i\n", 
			root[0],
			iroot[0],
			root[1],
			iroot[1]
			);
	 }

	return 0;
}

