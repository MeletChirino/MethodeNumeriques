#include <stdlib.h>
#include <stdio.h>
#include "TP5_library.h"

int main(){
    
		structQuadrature pQuadrature;
              
        //initialisation des tableaux avec la taille de n
    
        LireQuadrature(&pQuadrature); 
        
        printf("X = ");
		show_array(pQuadrature.tabZeta, pQuadrature.taille);
		printf("\n\n");
		printf("Y = ");
		show_array(pQuadrature.tabOmega, pQuadrature.taille);
           
        
        system("PAUSE");
		return 0;
}
