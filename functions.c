#define DIM 100

typedef float matriz[DIM][DIM];
typedef float vector[DIM];

void addition(matriz m1, matriz m2, matriz resultat, int n){
	int i,j;

	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			resultat[i][j] = m1[i][j] + m2[i][j];
			printf("%0.2f = %0.2f + %0.2f\n", resultat[i][j], m1[i][j], m2[i][j]);
		}
	}
}

void tailleMatrices(int *n){
	printf("Saisir N, taille de matrices (nxn): \n");
	scanf("%d", n);

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

void saisirVector(vector m, int n){
	int j;

	for(j = 0; j < n; j++){
		printf("\nSaisir m[%d] = ", j+1);
		scanf("%f", &m[j]);
	}
}

void showSystem(matriz m, vector v, int n){
	int i,j;

	printf("system = {\n");

	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(m[i][j] >= 0){
				if(j == 0)
					printf("%0.2f*x%d ", m[i][j], j);
				else
					printf("+ %0.2f*x%d ", m[i][j], j);
			} else {
				printf("%0.2f*x%d ", m[i][j], j);
			}
		}
		printf(" = %0.2f \n", v[i]);
	}
	printf("}\n");
}

void showVector(vector v, int n){
	int i;

	printf("solution = {\n");

	for(i = 0; i < n; i++){
		printf("%0.2f, ", v[i]);
		printf("\n");
	}
	printf("}\n");
}

void pivotGauss(matriz m, vector v, int n){
	matriz m2;
	vector v2;
	int linea, i, j;
	float pivot;

	//rellenar la matriz nueva
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			m2[i][j] = m[i][j];
		}
		v2[i] = v[i];
	}

	for(linea = 0; linea < n; linea ++){
		//primero se divide toda la linea entre el indice de linea
		pivot = m2[linea][linea];
		if(pivot == 0){
			printf("Systeme n'a pas solution\n");
			exit(0);
		}
		for(i = linea; i < n; i++){
			m2[linea][i] = m2[linea][i] / pivot;
		}
		v2[linea] = v2[linea] / pivot;
		//ahora hacemos 0 el resto de la columna, modificando asi toda la matriz
		if(linea < n-1){
			for (i = linea + 1; i < n; i++){//bucle de linea
				pivot = m2[i][linea];
				for(j = 0; j < n; j++){//bucle de la columna
					m2[i][j] = - m2[linea][j]*pivot + m2[i][j];
				}
				v2[i] = - v2[linea]* pivot + v2[i];

			}
		}

	}
	//ahora hacemos lo mismo pero hacia arriba
	for(linea = n-1; linea >= 0; linea = linea-1){

		for (i = linea-1; i >= 0; i -= 1){//bucle de linea
			pivot = m2[i][linea];
			for(j = 0; j < n; j++){//bucle de la columna
				m2[i][j] = -m2[linea][j]*pivot + m2[i][j];
			}
			v2[i] = -v2[linea]* pivot + v2[i];
		}

	}
	showVector(v2,n);
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
