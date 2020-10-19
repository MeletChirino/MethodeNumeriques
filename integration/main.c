#include <stdio.h>
#include <stdlib.h>
#include "TP5_library.h"

void show_array(double *array, int n){
		int i;
		for(i = 0; i < n; i++)
        {
				printf("\n Ligne[%d] = %lf",i, array[i]);
		}	

}

int main(){
    
		struct structQuadrature pQuadrature;
              
        //initialisation des tableaux avec la taille de n
    
        LireQuadrature(&pQuadrature); 
        
        printf("X = ");
		show_array(pQuadrature.tabZeta, pQuadrature.taille);
		printf("\n\n");
		printf("Y = ");
		show_array(pQuadrature.tabOmega, pQuadrature.taille);
           
		printf("\nVerification de Subdivision\n");
		struct structSubdivision Subdivision;
		struct structIntervalle Intervalle;

		int i, n=5;

		Intervalle.debut = 0;
		Intervalle.fin =5;

		CalculerSubdivisionReguliere(n, Intervalle, &Subdivision);

		for(i=0; i<n; i++){
				printf("\nintervalle #%d", i+1);
				printf("\ndebut = %lf", Subdivision.tabIntervalle[i].debut);
				printf("\nfin = %lf", Subdivision.tabIntervalle[i].fin);
		
		}


		return 0;
}
