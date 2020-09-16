//Par Melet Chirino 11-mars
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define DIM 100

typedef float matriz[DIM][DIM];
//typedef char string_[DIM];

//variables
void saisir(matriz m, int n);
void showMatrix(matriz m, int n);
void tailleMatrices(int *n);
float traceMatrix(matriz m, int n);
void addition(matriz m1, matriz m2, matriz resultat, int n);
void productMatrix(matriz m1, matriz m2, matriz resultat, int n);
void productScalar(matriz m1, float scalar, matriz resultat, int n);

int main(){
	matriz espace[DIM];
	int matrix_index = 0, n, menu_index = 0, matrix_selector, operation_1, operation_2;
	/*string_ options[DIM];
	options[] = {
		"Saisir une nouvelle matriz", //1
		"Modifier une matriz", //2
		"Montrer une matriz", //3
		"Calculer trace", //4
		"Addition de deux matrices", //5
		"Product entre deux matrices", //6
	};*/


	tailleMatrices(&n);

	while(1){
		printf("Hay %d matrices disponibles\n", matrix_index);
		printf("--------------------> Menu <--------------------\n1. Saisir une nouvelle matriz\n");
		if(matrix_index >= 1)
			printf("2.modifier une matriz déjà fait\n3.Montrer une matriz\n4.Calculer trace d'une matriz\n5.Multiplier matrix par scalaire\n");
		if(matrix_index >= 2)
			printf("6.Addition de deux matrices\n7.Product entre deux matrices\n");

		printf("\n99.Exit\n");
		scanf("%d", &menu_index);

		if(isdigit(menu_index) || menu_index > 100)
			menu_index = 150;

		switch(menu_index){

			case 1:// ---------------------- llenar una matriz nueva
				saisir(espace[matrix_index], n);
				matrix_index++;
				break;

			case 2:// ---------------------- modificar una matriz
				printf("Quelle matriz voulez vous modifier?\n");
				scanf("%d", &matrix_selector);

				while(!(matrix_selector < matrix_index && matrix_selector >= 0)){
					printf("Matrix %d n'existe pas, resaisir la matrix que vous voulez moidifier\n", matrix_selector);
					scanf("%d", &matrix_selector);
				}

				showMatrix(espace[matrix_selector], n);
				saisir(espace[matrix_selector], n);
				break;

			case 3:// ---------------------- mirar una matriz
			printf("Quelle matriz voulez vous afichier?\n");
			scanf("%d", &matrix_selector);
			while(!(matrix_selector < matrix_index && matrix_selector >= 0)){
				printf("Matrix %d n'existe pas, resaisir la matrix que vous voulez affichier\n", matrix_selector);
				scanf("%d", &matrix_selector);
			}
			showMatrix(espace[matrix_selector],n);
			break;

			case 4:// ---------------------- trace d'una matriz
				printf("Quelle matriz voulez vous calciler le trace?\n");
				scanf("%d", &matrix_selector);

				//verification
				while(!(matrix_selector < matrix_index && matrix_selector >= 0)){
					printf("Matrix %d n'existe pas, resaisir la matrix que vous voulez moidifier\n", matrix_selector);
					scanf("%d", &matrix_selector);
				}

				showMatrix(espace[matrix_selector], n);
				printf("Trace  = %f\n",traceMatrix(espace[matrix_selector], n));
				break;

			case 5:// ---------------------- multiply matrix by scalar number
				printf("Selectionez une matriz?\n");
				scanf("%d", &matrix_selector);

				//verification
				while(!(matrix_selector < matrix_index && matrix_selector >= 0)){
					printf("Matrix %d n'existe pas, resaisir la matrix que vous voulez moidifier\n", matrix_selector);
					scanf("%d", &matrix_selector);
				}

				showMatrix(espace[matrix_selector], n);

				printf("Saissir le scalaire\n");
				scanf("%d", &operation_1);

				productScalar(espace[matrix_selector], operation_1, espace[matrix_index], n);
				showMatrix(espace[matrix_index], n);
				matrix_index++;
				break;

			case 6:// ---------------------- Addition de deux matrices
				printf("Selectionez une matriz?\n");
				scanf("%d", &matrix_selector);

				//verification
				while(!(matrix_selector < matrix_index && matrix_selector >= 0)){
					printf("Matrix %d n'existe pas, resaisir la matrix que vous voulez moidifier\n", matrix_selector);
					scanf("%d", &matrix_selector);
				}
				operation_1 = matrix_selector;
				showMatrix(espace[operation_1], n);

				printf("Selectionez la matrices à additioner?\n");
				scanf("%d", &matrix_selector);

				//verification
				while(!(matrix_selector < matrix_index && matrix_selector >= 0)){
					printf("Matrix %d n'existe pas, resaisir la matrix que vous voulez moidifier\n", matrix_selector);
					scanf("%d", &matrix_selector);
				}
				operation_2 = matrix_selector;
				showMatrix(espace[operation_2], n);

				addition(espace[operation_1], espace[operation_2], espace[matrix_index], n);
				showMatrix(espace[matrix_index], n);
				matrix_index++;
				break;

			case 7:
				printf("Selectionez une matriz?\n");
				scanf("%d", &matrix_selector);

				//verification
				while(!(matrix_selector < matrix_index && matrix_selector >= 0)){
					printf("Matrix %d n'existe pas, resaisir la matrix que vous voulez moidifier\n", matrix_selector);
					scanf("%d", &matrix_selector);
				}
				operation_1 = matrix_selector;
				showMatrix(espace[operation_1], n);

				printf("Selectionez la matrices à additioner?\n");
				scanf("%d", &matrix_selector);

				//verification
				while(!(matrix_selector < matrix_index && matrix_selector >= 0)){
					printf("Matrix %d n'existe pas, resaisir la matrix que vous voulez moidifier\n", matrix_selector);
					scanf("%d", &matrix_selector);
				}
				operation_2 = matrix_selector;
				showMatrix(espace[operation_2], n);

				productMatrix(espace[operation_1], espace[operation_2], espace[matrix_index], n);
				showMatrix(espace[matrix_index], n);
				matrix_index++;
				break;

			case 99:
				printf("Merci beaucoup pour utiliser ce program\n");
				return 0;

			default:// ---------------------- Eres una hueva y colocaste algo que no funciona
				printf("Option %d n'existe pas, resaisir la matrix que vous voulez affichier\n", menu_index);
				break;
		}
	}

	return 0;
}
/*void displayMenu(string_ options[DIM], int menu_options){
	int i;
	for(i = 0; i < menu_options; i++){
		printf(options[i]);
	}
}*/

void addition(matriz m1, matriz m2, matriz resultat, int n){
	int i,j;

	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			resultat[i][j] = m1[i][j] + m2[i][j];
			printf("%0.2f = %0.2f + %0.2f\n", resultat[i][j], m1[i][j], m2[i][j]);
		}
	}
}

void saisir(matriz m, int n){
	int i,j;

	printf("Saisir les numeros : \n");
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("\nSaisir m[%d,%d] = ", i+1, j+1);
			scanf("%f", &m[i][j]);
		}

	}

}

void tailleMatrices(int *n){
	printf("Saisir N, taille de matrices (nxn): \n");
	scanf("%d", n);

}

void showMatrix(matriz m, int n){
	int i,j;

	printf("matrix = {\n");

	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("%0.2f, ", m[i][j]);
		}
		printf("\n");
	}
	printf("}\n");
}

float traceMatrix(matriz m, int n){
	int i;
	float trace = 0;
	for(i = 0; i < n; i++){
		trace += m[i][i];
	}
	return trace;
}

void productMatrix(matriz m1, matriz m2, matriz resultat, int n){
	int i,j,k;

	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			resultat[i][j] = 0;
				for(k = 0; k < n; k++){
					resultat[i][j] += m1[i][k] * m2[k][j];
				}
		}
	}
}

void productScalar(matriz m1, float scalar, matriz resultat, int n){
	int i,j;

	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			resultat[i][j] = m1[i][j] * scalar;
		}
	}
}
