//elaborado por Melet Chirino el 22/01/2020
#include <stdio.h>
#include <stdlib.h>

void saisir(int *n, int again);
int productoire(int n);

int main()
{
	//variables
	int n, reponse, resaisir = 0;
	
	//saisir les valeurs
	do
	{
		saisir(&n, resaisir);
		resaisir = 1;
		//recuerda que no puedes meter valores que no sean integer, 
		//sino tu programa va a explotar
	}
	while(n < 1);

	//program
	reponse = productoire(n);
	
	//afficher les resultats
	printf("La reponse est %d\n", reponse);
	
	return 0;
}

void saisir(int *n, int again)
{
	if(again)
	{
		printf("resaisir la valeur de n\n");
		scanf("%d", n);
	}
	else
	{
		printf("saisir la valeur de n\n");
		scanf("%d", n);
	}	
		

}

int productoire(int n)
{
	int i, reponse = 1;


	for(i=1; i <= n; i++)
	{
		reponse *= i;
	}
	
	return reponse;
}