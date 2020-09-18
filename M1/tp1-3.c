//Fait par CHIRINO et NAVARRO le 18-sep-2020
#include <stdio.h>
#include <stdlib.h>

#define N 100

float somme(float *nombres, int n);
float moyenne(float *nombres, int n);
float min(float *nombres, int n);
float max(float *nombres, int n);

int main(){
	int n = 0;
	float nombres[N];

	do{
			printf("Saisir la %d valeur", n+1);
			scanf("%f", &nombres[n]);
			n+=1;
	}while(nombres[n-1] != -1);
	n -= 1;

	printf("il y a %d valeurs\n", n);

	return 0;
}
float somme(float *nombres, int n){
		 int i;
		float result=0;
		for(i=0; i<n; i++){
				result += nombres[i];
		}

		return result;
}
float moyenne(float *nombres, int n){
		float sum;
		sum = somme(nombres, n);
		return sum/n;
}
float min(float *nombres, int n){
		int i;
		float min = nombres[n-1];
		for(i = 0; i < n; i++){
				if(min>nombres[i]) min = nombres[i];
		}
		return min;
}
float max(float *nombres, int n){
		int i;
		float max = nombres[n-1];
		for(i=0; i<n; i++){
				if(nombres[i]>max) max = nombres[i];
		}
		return max;
}
