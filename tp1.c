// par : Melet CHIRINO

#include <stdio.h>
#include <stdlib.h>

float calculer_valeur(int numero_de_copias){

	float precio_total;

	if(numero_de_copias <= 10){
	
		precio_total += numero_de_copias * 0.1; 
		
	} else if(numero_de_copias > 10 && numero_de_copias <=30){
	
		precio_total += 10 * 0.1;
		numero_de_copias -= 10;
		precio_total += numero_de_copias * 0.09;
		
	} else if(numero_de_copias >30){
	
		precio_total += 10 * 0.1;
		numero_de_copias -= 10;
		precio_total += 20 * 0.09;
		numero_de_copias -= 20;
		precio_total += numero_de_copias * 0.08;
		
	}
	return precio_total;
}

int main(){

	//variables
	float precio_total = 0;
	int numero_de_copias = 0;

	//program
	
	printf("escribe el numero de copias\n");
	scanf("%d", &numero_de_copias);
	printf("Usted ha pedido %d copias\n", numero_de_copias);

	precio_total = calculer_valeur(numero_de_copias);	
	
	printf("El precio total es %0.2f por %d copias\n", precio_total, numero_de_copias);

}

