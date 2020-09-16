//Par Melet CHIRINO

#include <stdio.h>
#include <stdlib.h>

#define DIM 20

void mean(float nombres[DIM], int n, float *moyenne){
	int i;
	float sum=0;
	for(i=0;i<n; i++)
	{
		sum+=nombres[i];
	}
	*moyenne = sum/n;
}

int main(){
	int n=12;
	float vect[DIM], moyenne;
	mean(vect[DIM],n,&moyenne);
	printf("\nla valeur de la moyenne est %f", moyenne);
	
}
