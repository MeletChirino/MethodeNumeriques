//elaborado por Melet Chirino
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DIM 100
typedef float tabla[DIM];

void generevect(float freq, tabla vect, int *valeurs);
void voirTabla(tabla vect, int valeurs);
void remplirVector(tabla temp, tabla vect, int valeurs);
float moyenne(tabla vect, int valeurs);
float ecartType(tabla vect, int valeurs);

int main()
{	
	system("clear");
	tabla temps, tension;
	float valeurMoyenne, ecart;
	int nombreDeValeurs;
	
	//Saisir la frecuence en Hz
	generevect(1000, temps, &nombreDeValeurs);

	//voirTabla(temps);

	remplirVector(temps, tension, nombreDeValeurs);
	
	voirTabla(tension, nombreDeValeurs);
	valeurMoyenne = moyenne(tension, nombreDeValeurs);
	ecart = ecartType(tension, nombreDeValeurs);
	printf("La valeur moyenne est : %fV\nL'ecart est : %fV\n", valeurMoyenne, ecart);
	
	return 0;
}

float ecartType(tabla vect, int valeurs)
{
	//primero se hace la sumatoria
	int i;
	float sumatoria = 0, ecart, valeurMoyenne;
	
	valeurMoyenne = moyenne(vect, valeurs);
	
	for(i = 0; i < valeurs; i++){
		sumatoria += (vect[i] - valeurMoyenne) * (vect[i] - valeurMoyenne);
		//printf("sunatoria = %f\n", sumatoria);
	}
	
	//despues se hace la division
	ecart = sqrt(sumatoria / (valeurs - 1));

	return ecart;
}

float moyenne(tabla vect, int valeurs)
{
	int i;
	float acum = 0;
	
	for(i = 0; i < valeurs; i++)
	{
		acum += vect[i];
	}
	
	return acum / valeurs;
}

void generevect(float freq, tabla vect, int *valeurs)
{	
	//fonction qui genere le vecteur 
	printf("Saisir les valeurs a remplir : ");
	scanf("%d", valeurs);
	
	int i;
	float milis;
	
	milis = 1 / freq;
	
	for(i = 0; i < *valeurs; i++)
	{
		vect[i] = i * milis;
	}	
}

void voirTabla(tabla vect, int valeurs)
{
	int i;
	
	for(i = 0; i < valeurs; i++)
	{
		printf("%f\n", vect[i]);
	}
	printf("\n");
}

void remplirVector(tabla temp, tabla vect, int valeurs)
{

	int i;
	
	for(i = 0; i < valeurs; i++)
	{
		printf("Pour le temp %f saisir la valeur de tension\n", temp[i]);
		scanf("%f", &vect[i]);
	}
	printf("\n");

}