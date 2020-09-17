#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	//variables
	int a, b ,c;
	float delta;


	//saisir les valeurs
	printf("Saisir la valeur de a\n");
	scanf("%d", &a);

	printf("Saisir la valeur de b\n");
	scanf("%d", &b);

	printf("Saisir la valeur de c\n");
	scanf("%d", &c);
	//Calcul de delta
	delta = b*b -4*a*c;
	printf("\n\nDelta = %2.3f", delta);
}

