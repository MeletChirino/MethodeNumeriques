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
void verifSubdivision(structSubdivision Subdivision){
		int i, n = Subdivision.nombre;
		for(i=0; i<n; i++){
				printf("\nintervalle #%d", i+1);
				printf("\ndebut = %lf", Subdivision.tabIntervalle[i].debut);
				printf("\nfin = %lf", Subdivision.tabIntervalle[i].fin);
		}
};

int main(){
		printf("\nVerification de Subdivision\n");
		structSubdivision Subdivision;
		structIntervalle Intervalle;

		int i, n=60;

		Intervalle.debut = 0;
		Intervalle.fin =5;

		CalculerSubdivisionReguliere(n, Intervalle, &Subdivision);

		verifSubdivision(Subdivision);

    	//Ahora verificamos la quadrature
		structQuadrature Quadrature;

        LireQuadrature(&Quadrature); 

        printf("\n\nX = ");
		show_array(Quadrature.tabZeta, Quadrature.taille);
		printf("\n\n");
		printf("Y = ");
		show_array(Quadrature.tabOmega, Quadrature.taille);
           
		structEchantillonage_fonction matriz = echantillonage_fonction(Subdivision, Quadrature);

		return 0;
}
