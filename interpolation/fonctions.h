struct polynomes{
		int degree;
		float *coeff;
};

double polynome_eval(double x, struct polynomes poly){
	double result = poly.coeff[poly.degree];
	int i;
	for(i = poly.degree -1; i>=0; i--){
			result = result * x + poly.coeff[i];
	}
	return result;
}

void calcul_polynome(int n, double *ech_x, double *ech_y, struct polynomes poly){
	int i;
	for(i=0; i<n; i++){
			ech_y[i] = polynome_eval(ech_x[i], poly);
	}
}

double polynome_lagrange(int i, int n, double x, double *x_values){
		int j;
		double result = 1;

		//printf("\n\nL_%d ---------------", i);
		for(j=0; j< n; j++){
			if(j != i){
					result *= (x - x_values[j]) / (x_values[i] - x_values[j]); 
			//printf("\n%lf = %lf - %d / %d - %d", result, x, j, i, j);
			}
		}

		return result;
}

void calcul_polynome_lagrange(int n, double *x_values, double *y_values, double *Pm){
		double L[n];
		int i, j;
		//Ahora calcula los Pm
		for(i=0; i<n; i++){
				//initializer le Pm pour le summatoire
				Pm[i] = 0;
				//printf("\n\nPm[%d] =", i);


				for(j=0; j<n; j++){
					//Le calcul des Li pour cet valeur
					L[j] = polynome_lagrange(j, n, x_values[i], x_values);
					
					//printf("\nL_%d = %lf", j, L[j]); 

					//cest la multiplication de Li*yi et il fait la 
					//somme au fur et a mesure quil avance
					Pm[i] += L[j]*y_values[j]; 
					//printf("\n%lf += %lf * %lf ", Pm[i], L[j], y_values[j]);
				}
		}
}


float horner_deriv(struct polynomes poly, float value);

double f(double x){
	return 1/(1+25*x*x);
}

void calcul_fonction(int n, double *ech_x, double *ech_f){
	int i;
	for(i=0; i<n; i++){
		ech_f[i] = f(ech_x[i]);
	}	
}

void sauvegarde_fichier(char *courbe, double *abscisses, double *ordonnees, int n)
{
    int i;
    double xi;
    double yi;
    FILE* fichier;
    fichier = fopen(courbe,"w");

    for(i=0; i <n; i++)
    {
      fprintf(fichier,"%lf %lf \n",abscisses[i],ordonnees[i]);                     
    }               
    fclose(fichier);             
}


void echantillon_reguliere(double min, double max, int n, double *echantillon){
		double pas = (max - min) / (n);
		int i;
		//echantillon = (double*)malloc(n * sizeof(double));
		echantillon[0] = (double)min + (pas / 2);

		for(i = 1; i < n; i++){
				*(echantillon + i) = *(echantillon +i -1) + pas;
				//printf("\nmin = %lf num = %lf", echantillon[i-1], echantillon[i]);
		}
}

void show_array(double *array, int n){
		int i;
		for(i = 0; i < n; i++){
				printf("\n tableau[%d] = %lf",i, array[i]);
		}	

}

float horner(struct polynomes poly, float value){
	float result = poly.coeff[poly.degree];
	int i;
	for(i = poly.degree-1; i >=0; i--){
		result = result * value + poly.coeff[i];
	}
	return result;
}

float horner_deriv(struct polynomes poly, float value){
	float result = poly.coeff[poly.degree], coeff[poly.degree -2];
	int i;
	for(i = poly.degree-1; i >=0; i--){
		result = result * value + poly.coeff[i];
		if(i != 0){
			coeff[i-1]= result;
			//printf("\ncoeff^%d = %0.2f", i-1, coeff[i-1]);
		}

	}
	result = poly.coeff[poly.degree];
	for(i = poly.degree - 2; i >= 0; i--){
		//printf("\n%f * %f + %f", result, value, coeff[i]);
		result = result * value + coeff[i];
	}	
	return result;
}

struct polynomes produit(struct polynomes poly1, struct polynomes poly2){
	int i, j;
	float coeff1, coeff2;
	struct polynomes poly_produit;
	poly_produit.degree = poly1.degree + poly2.degree;
	poly_produit.coeff = (float*)malloc(poly_produit.degree*sizeof(float));
	for(i=0; i<= poly_produit.degree; i++)
		poly_produit.coeff[i] = 0;

	for(i=0; i<= poly1.degree; i++){
		if(poly1.coeff[i]){
			coeff1 = poly1.coeff[i];
			for(j=0; j<= poly2.degree; j++){
				if(poly2.coeff[j]){
					coeff2 = poly2.coeff[j];
					poly_produit.coeff[i+j] += coeff1 * coeff2;
				printf("\n%0.1fx^%d * %0.1fx^%d = %0.1fx^%d",coeff1, i, coeff2, j, poly_produit.coeff[i+j], i+j);
				}
			}

		}
	} 
	return poly_produit;
}

void coeff_poly(struct polynomes *poly){
	int i;
	for(i=0; i < poly->degree + 1; i++){
		printf("\ncoeff[%d] = ",i);
		scanf("%f", &poly->coeff[i]);
	}

}
float higher(float num1, float num2){
	if(num1 >= num2)
		return num1;
	else if(num2 > num1)
		return num2;
}

struct polynomes somme(struct polynomes poly1, struct polynomes poly2){
	int i;
	float coeff1, coeff2;
	struct polynomes poly_somme;
	poly_somme.degree = higher(poly1.degree, poly2.degree);
	poly_somme.coeff = (float*)malloc(poly_somme.degree*sizeof(float));

	for(i = 0; i < poly_somme.degree+1; i++){
		if(!poly1.coeff[i])
			coeff1 = 0;
		else
			coeff1 = poly1.coeff[i];
		if(!poly2.coeff[i])
			coeff2 = 0;
		else
			coeff2 = poly2.coeff[i];
		poly_somme.coeff[i] = coeff1 + coeff2;
	}

	return poly_somme;
}

struct polynomes deriver(struct polynomes poly){
	int taille = poly.degree, i;
	struct polynomes poly_derive;
	poly_derive.degree = taille - 1;
	poly_derive.coeff = (float*)malloc(poly_derive.degree*sizeof(float));
	for(i = 1; i < taille+1; i++){
		poly_derive.coeff[i-1] = i * poly.coeff[i];
		printf("\n%d * %f = %f", i, poly.coeff[i], poly_derive.coeff[i-1]);
	}
	return poly_derive;

}
struct polynomes create_poly(){
	int taille;
	struct polynomes poly;
	printf("\nSaisir la taille du Polynome\n");
	scanf("%d", &taille);

	poly.degree = taille;
	poly.coeff = (float*)malloc(taille*sizeof(float));
	return poly;
}
/*
float poly_evalue(struct polynomes poly1,float valeur){
	int i;
	float resultat = 0;
	for(i = poly1.degree; i >= 0; i-=1){
			resultat += poly1.coeff[i] * pow(valeur, i);
	}
	return resultat;
}
*/
void affichage_polynome(struct polynomes poly1){
	int i;

	for(i = poly1.degree; i >= 0; i-=1){
		if(i != 0)
			printf("%0.2fx^%d + ", poly1.coeff[i], i);
		else
			printf("%0.2f",poly1.coeff[i]);
	}

}

int lecture(float *X, float *Y){
	/* fonction pour lire une fichier avec des donees */
	float x_, y_;
	FILE *file;
	file = fopen("data.dat","r");
	int taille = 0;

	if(file == NULL){
		printf("\nfile does not exist\n");
		return 1;
	}

	while(fscanf(file,"%f %f", &x_, &y_) != EOF){//while not the end
		X[taille] = x_;
		Y[taille] = y_;
		//printf("\n(%2.2f,\t%2.2f)", X[taille], Y[taille]);
		taille++;
	}

	fclose(file);

	return(taille);
}

float y_fonction(float new_val, float a, float b){
		return a*new_val + b;
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

void calcul_coef(float *X, float *Y, int size, float *a, float *b){
	//fonction qui calcule les coeff des moindres carres
	float mean_x, mean_y, mean_xy, mean_x2;

	mean_x = mean(X, size);
	mean_y = mean(Y, size);
	mean_xy = mean_product(X, Y, size);
	mean_x2 = mean_product(X, X, size);

	*a = (mean_xy - mean_x * mean_y)/(mean_x2 - mean_x*mean_x);
	*b = (mean_y * mean_x2 - mean_x * mean_xy)/(mean_x2 - mean_x * mean_x);
}
