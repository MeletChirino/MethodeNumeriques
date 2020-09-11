//Elabore par Melet Chirino le 29/01/2020
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ANGLES "rad"

typedef float complex[2];

//void sommeImaginaire(float resultat, )
void saisirValeurs(complex Z);
void affichage(complex Z);
float module(complex Z);
float argument(complex Z);
void sommeParalle(complex Z1, complex Z2);

int main()
{
	float mean, arg;
	system("clear");
	complex Z_1, Z_2;
	
	
	saisirValeurs(Z_1);
	affichage(Z_1);
	
	mean = module(Z_1);

//	printf(ANGLES);
	
	saisirValeurs(Z_2);
	affichage(Z_2);
	printf("resultat\n");
	sommeParalle(Z_1, Z_2);
	
	//printf("\nquadrant = %1.0f\n", quadrant(Z_1));
	return 0;

}

void sommeParalle(complex Z1, complex Z2)
{
	complex resultat;
	float R1 = Z1[0], R2 = Z2[0], X1 = Z1[1], X2 = Z2[1];
	
	affichage(Z1);
	affichage(Z2);
	//parte real
	resultat[0] = (((R1*R2 - X1*X2) * (R1 + R2)) + ((X1*R2 + X2*R1) * (X1 + X2))) /
	((R1 + R2)*(R1 + R2) + (X1 + X2)*(X1 + X2));
	
	//parte imaginaria
	resultat[1] = ((X1*R2 + X2*R1) * (R1 + R2) - (R1*R2 - X1*X2) * (X1 + X2)) /
		((R1 + R2)*(R1 + R2) + (X1 + X2)*(X1 + X2));
	
	affichage(resultat);
}

float argument(complex Z)
{
	int pi = 3.1416;
	float angle;
	
	if(ANGLES == "deg"){
		angle = atan(Z[1]/Z[0])*(180/pi);
		pi = 180;
	}else if(ANGLES == "rad"){
		angle = atan(Z[1]/Z[0]);
	}else{
		printf("Parametres acceptees sont \"deg\" ou \"rad\"");
		return -1;
	}
	
	//correction de angle
	if(Z[0] > 0 && Z[1] > 0){
		//printf("quadrant 1\n");
		return angle;//quadrant 1
	}else if(Z[0] < 0 && Z[1] > 0){
		//printf("quadrant 2\n");
		return pi - angle;//quadrant2
	}else if(Z[0] < 0 && Z[1] < 0){
		//printf("quadrant 3\n");
		return pi + angle;//quadrant 3
	}else if(Z[0] > 0 && Z[1] < 0){
		//printf("quadrant 4\n");
		return -1 * angle;//quadrant 4
	}
}

float module(complex Z)
{
	return sqrt(Z[0]*Z[0] + Z[1]*Z[1]);
}

void saisirValeurs(complex Z)
{
	printf("Saisir la valeur Reel ");
	scanf("%f", &Z[0]);
	
	printf("Saisir la valeur Imaginaire ");
	scanf("%f", &Z[1]);


}

void affichage(complex Z)
{
	printf("%2.2f + j%2.2f\n", Z[0], Z[1]);
}
