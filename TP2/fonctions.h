struct polynomes{
		int degree;
		float *coeff;
};
float poly_evalue(struct polynomes poly1,float valeur){
		int i;
		float resultat = 0;
		for(i = poly1.degree; i >= 0; i-=1){
				resultat += poly1.coeff[i] * pow(valeur, i);
		}
		return resultat;
}
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
