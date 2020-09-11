//Par Melet chirino 11-mars
#include <stdio.h>
#include <stdlib.h>

#define DIM 100


void tri_par_extraction(int vector[DIM], int n);
void voirVector(int vector[DIM], int n);
void tri_a_bulle(int vector[DIM], int n);
void saisir(int vector[DIM], int *n);

int main(){

	int vect[DIM], n;

	printf("\n---\nPar tri a bulle\n");
	saisir(vect, &n);
	
	voirVector(vect, n);

	tri_a_bulle(vect, n);

	voirVector(vect, n);
	
	
	printf("\n\n---\n\nPar tri a extraction\n");
	
	saisir(vect, &n);
	
	voirVector(vect, n);

	tri_a_bulle(vect, n);

	voirVector(vect, n);
	
	return 0;
}

void saisir(int vector[DIM], int *n){
	int i;
	
	printf("Saisir combien numeros\n");
	scanf("%d", n);
	
	printf("Saisir les numeros = \n");
	for(i = 0; i < *n; i++){
		printf("\nSaisir vect[%d] = ", i);
		scanf("%d", &vector[i]);
	}
}

void tri_a_bulle(int vector[DIM], int n){
	int i, flag, aux;
	do{
		flag = 0;
		for(i = 0; i < n-1; i++){

				if(vector[i] > vector[i+1]){
					aux = vector[i+1];
					vector[i+1] = vector[i];
					vector[i] = aux;
					flag++;
				}

		}
	}while(flag != 0);
		
	
}

void tri_par_extraction(int vector[DIM], int n){
	int i, flag, aux, j;

	for(i = 0; i < n; i++){
		do{
			for(j = 0; j < n; j++){
				flag = 0;
				if(vector[j] > vector[i]){
					aux = vector[i];
					vector[i] = vector[j];
					vector[j] = aux;
					flag++;
				}
			}
		}while(flag != 0);
	} 
		

}

void voirVector(int vector[DIM], int n){
	int i;
	printf("\n----\nvector = ");
	for(i = 0; i < n; i++){
		printf(" %d", vector[i]);
	
	}
	printf("\n----\n");
}
