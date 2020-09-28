//Par CHIRINO et NAVARRO le 12/sep/2020
#include <stdio.h>
#include <stdlib.h>

#define N 100

int lecture(float *X, float *Y);
float mean(float *X, int size);
float mean_product(float *X, float *Y, int size);
void calcul_coef(float *X, float *Y, int size, float *a, float *b);

int main(){
	/* Loi des moindres carres
	 * y a quelque chose qui va pas
	 * */
	float x[N], y[N], moyenne, size, a, b;

	size = lecture(x, y) - 1;
	//se restan 2 para ajustar la ultima repeticion y el hecho de que el primer valor del vector empieza en 0 en este caso, no en 1

	calcul_coef(x, y, size, &a, &b);

	printf("\ny = %fx + %f", a, b);
	return 0;
}

void calcul_coef(float *X, float *Y, int size, float *a, float *b){

	float mean_x, mean_y, mean_xy, mean_x2;

	mean_x = mean(X, size);
	mean_y = mean(Y, size);
	mean_xy = mean_product(X, Y, size);
	mean_x2 = mean_product(X, X, size);

	*a = (mean_xy - mean_x * mean_y)/(mean_x2 - mean_x*mean_x);
	*b = (mean_y * mean_x2 - mean_x * mean_xy)/(mean_x2 - mean_x * mean_x);

}

float mean_product(float *X, float *Y, int size){
/* fonction pour calculer la valeur moyenne d'un tableau */
	int i;
	float summation = 0;
	for(i=0; i<size; i++) summation += Y[i]*X[i];
	return summation/size;
}

float mean(float *X, int size){
/* fonction pour calculer la valeur moyenne d'un tableau */
	int i;
	float summation = 0;
	for(i=0; i<size; i++) summation += X[i];
	return summation/size;
}

int lecture(float *X, float *Y){
/* fonction pour lire une fichier avec des donees */
	FILE *file;
	file = fopen("data.dat","r");
	int taille = 0;
	
	//while(!feof(file)){//while not the end
	while(1){//while not the end
		//Porque se repite?
		if(feof(file)) break;
		fscanf(file,"%e %e", &X[taille], &Y[taille]);
		//printf("\n(%2.2f,\t%2.2f)", X[taille], Y[taille]);	
		taille++;

	}

	fclose(file);
		
	//printf("\ni = %d", taille);
	return(taille);
}
