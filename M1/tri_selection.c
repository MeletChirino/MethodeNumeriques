//Par Melet CHirino le 16/Sept/2020
#include <stdio.h>
#include <stdlib.h>

#define DIM 20

void tri_selection(int vector[DIM], int n);

int main(){
	int n=4, tab[n]={2, 5, 7, 1};
}

void tri_selection(int vector){
	//La flemm de le finir, le prof a deja done la reponse
	return 0;
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
