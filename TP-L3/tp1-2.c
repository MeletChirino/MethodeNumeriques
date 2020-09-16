//Por Melet Chirino
#include <stdio.h>
#include <stdlib.h>

//utiliza el compilador gcc -Wall

int main(){

	//variables
	float candidat1;

	//programa
	printf("Saisir le percentage de sufrfage du 1 candidat\n");
	scanf("%f", &candidat1);

	printf("Saisir le percentage de sufrfage du 2 candidat\n");
	scanf("%f", &candidat2);

	printf("Saisir le percentage de sufrfage du 3 candidat\n");
	scanf("%f", &candidat3);

	printf("Saisir le percentage de sufrfage du 4 candidat\n");
	scanf("%f", &candidat4);

	//verification des donnes
	if(candidat1 < 0 || candidat1 > 100){
	
		printf("Saisir un valeur entre 0 et 100\n");
		return 0;
	
	}
	
	if(candidat1 + candidat2 + candidat3 + candidat4 > 100)
	{
		//solo para verificar que se metieron bien los valores
		printf("Saisir un valeur entre 0 et 100\n");
		return 0;
	
	}


	//debut du program

	if (candidat2 > 50 || candidat3 > 50 || candidat4 > 50 || candidat1 < 12.5)
	{	//si quelque autre cnadidat obtient plus de 50%
		printf("Candidat 1 est batu avec %0.1f%%\n", candidat1);
		return 0;
	}
	
	//si ningun otro candidato gano la contienda significa que hay esperanza, 
	//verifiquemos nuestros numeros
	if(candidat1 > 50){
	
		printf("Candidat 1 est elu avec %0.1f%%\n", candidat1);
	
	} else if(candidat1 <= 50 && candidat1 >= 12.5){
		
		printf("Candidat 1 va au deuxieme tour avec %0.1f%%\n", candidat1);
		
	
	}
	
	return 0;
}