//Elaborado por Melet Chirino el 22/01/2020
#include <stdio.h>
#include <stdlib.h>

void saisir(int *n);
int somme(int n);

int main()
{
	//variables
	int n, reponse;
	
	//saisir les valeurs
	saisir(&n);
	

	//program
	reponse = somme(n);
	
	//afficher les resultats
	printf("La reponse est %d\n", reponse);
	
	return 0;
}

void saisir(int *n)
{
	
	printf("saisir la valeur de n\n");
	scanf("%d", n);
}

int somme(int n)
{
	int i, reponse = 0;


	for(i=0; i <= n; i++)
	{
		reponse += i;
	}
	
	return reponse;
}