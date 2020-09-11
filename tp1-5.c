//elaborado por Melet Chirino
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DIM 11
typedef float tabla[DIM];

void generevect(float freq, tabla vect);
void voirTabla(tabla vect);
void remplirVector(tabla temp, tabla vect);
float moyenne(tabla vect);
float ecartType(tabla vect);

int main()
{	
	tabla temps, tension;
	float valeurMoyenne, ecart;
	
	generevect(1000, temps);

	//voirTabla(temps);

	remplirVector(temps, tension);
	
	voirTabla(tension);
	valeurMoyenne = moyenne(tension);
	ecart = ecartType(tension);
	printf("La valeur moyenne est : %fV\nL'ecart est : %fV\n", valeurMoyenne, ecart);
	
	return 0;
}

float ecartType(tabla vect)
{
	//primero se hace la sumatoria
	int i;
	float sumatoria = 0, ecart, valeurMoyenne;
	
	valeurMoyenne = moyenne(vect);
	
	for(i = 0; i < DIM; i++){
		sumatoria += (vect[i] - valeurMoyenne) * (vect[i] - valeurMoyenne);
		//printf("sunatoria = %f\n", sumatoria);
	}
	
	//despues se hace la division
	ecart = sqrt(sumatoria / (DIM - 1));

	return ecart;
}

float moyenne(tabla vect)
{
	int i;
	float acum = 0;
	
	for(i = 0; i < DIM; i++)
	{
		acum += vect[i];
	}
	
	return acum / DIM;
}

void generevect(float freq, tabla vect)
{	
	//fonction qui genere le vecteur 
	int i;
	float milis;
	
	milis = 1 / freq;
	
	for(i = 0; i < DIM; i++)
	{
		vect[i] = i * milis;
	}	
}

void voirTabla(tabla vect)
{
	int i;
	
	for(i = 0; i < DIM; i++)
	{
		printf("%f\n", vect[i]);
	}
	printf("\n");
}

void remplirVector(tabla temp, tabla vect)
{

	int i;
	
	for(i = 0; i < DIM; i++)
	{
		printf("Pour le temp %f saisir la valeur de tension\n", temp[i]);
		scanf("%f", &vect[i]);
	}
	printf("\n");

}