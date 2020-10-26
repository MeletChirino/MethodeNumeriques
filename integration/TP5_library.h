#ifndef TP5_LIBRARY
#define TP5_LIBRARY
/* Fichier de base pour le sujet de TP 5 */
//
// Les structures suivantes sont imposées
#include <stdio.h>
#include <math.h>

typedef struct{
		double debut;
		double fin;
} structIntervalle;

typedef struct{
		int nombre;
		structIntervalle* tabIntervalle;
} structSubdivision;

typedef struct{
			int taille;
			double* tabZeta;
			double* tabOmega;
} structQuadrature;

typedef struct{
			structQuadrature Quadrature_Echantillonage;
			structSubdivision Subdivision_Echantillonage;
			double** matriceFonctionEchantillonnee;
} structEchantillonage_fonction;

double CalculFonction(double x) // On modifiera ici la fonction Ã  intÃ©grer
{
		double resultat;
		resultat = exp(-x*x/2)/(sqrt(2*3.14159265358979));
		return resultat;
}

double f(double x){
		// f(x) = a;
		//return 4;
		//f(x) = ax + b;
		//return 4*x + 4;
		//f(x) = exp(-x);
		return exp(-x);
}

double CalculIntegrale(structEchantillonage_fonction Echantillonage_fonction){
		int i, j, n, taille_quad;
		double I = 0, a_i, a_i1, sumQuadrature;
		taille_quad = Echantillonage_fonction.Quadrature_Echantillonage.taille;

		n = Echantillonage_fonction.Subdivision_Echantillonage.nombre;
		printf("\nn = %d", n);

		for(i=0; i < n-1; i++){
			a_i = Echantillonage_fonction.Subdivision_Echantillonage.tabIntervalle[i].debut;
			a_i1 = Echantillonage_fonction.Subdivision_Echantillonage.tabIntervalle[i].fin;

			sumQuadrature = 0;
			for(j=0; j<taille_quad; j++)
				sumQuadrature += Echantillonage_fonction.matriceFonctionEchantillonnee[j][i];

			//printf("\nI += (%lf - %lf) * %lf", a_i1, a_i, sumQuadrature);
			I += (a_i1 - a_i) * (sumQuadrature);
		printf("\nI = %lf", I);
		}

		return I;
		//AffichageGnuplot(matriz);
}

structEchantillonage_fonction echantillonage_fonction(structSubdivision subdivision, structQuadrature quadrature){
		//inicialicemos variables para esta funcion
		int i, j = 0, n;
		double a_i, a_i1, w_j, zeta_i, term;
		
		//ahora creamos la matriz donde se van a almacenar nuestra matriz
		structEchantillonage_fonction matrice_final;

		//Vamos a llenar la matriz de todos los valores predeterminados que debe tener
		n = subdivision.nombre;
		matrice_final.Subdivision_Echantillonage.nombre = n;
		matrice_final.Subdivision_Echantillonage.tabIntervalle = (structIntervalle*)malloc(n*sizeof(structIntervalle));
		for(i = 0; i < n; i++){
			matrice_final.Subdivision_Echantillonage.tabIntervalle[i].debut = subdivision.tabIntervalle[i].debut;
			matrice_final.Subdivision_Echantillonage.tabIntervalle[i].fin = subdivision.tabIntervalle[i].fin;
		}
		n = quadrature.taille;
		matrice_final.Quadrature_Echantillonage.taille = n; 
		matrice_final.Quadrature_Echantillonage.tabOmega = (double*)malloc(n*sizeof(double)); 
		matrice_final.Quadrature_Echantillonage.tabZeta = (double*)malloc(n*sizeof(double)); 
		for(i = 0; i < n; i++){
			matrice_final.Quadrature_Echantillonage.tabZeta[i] = quadrature.tabZeta[i]; 
			matrice_final.Quadrature_Echantillonage.tabOmega[i] = quadrature.tabOmega[i]; 
		}
		//finalmente podemos crear l matriz que vendra a ser nuestra matriz de sumatorias que usaremos en un futuro
		matrice_final.matriceFonctionEchantillonnee = (double**)malloc(subdivision.nombre*sizeof(double*));
		for(i = 0; i < quadrature.taille; i++)
			matrice_final.matriceFonctionEchantillonnee[i] = (double*)malloc(quadrature.taille*sizeof(double));

		//ahora se hacen los valores iniciales
		for(i = 0; i < subdivision.nombre - 1; i++){

			a_i = subdivision.tabIntervalle[i].debut;
			a_i1 = subdivision.tabIntervalle[i].fin;
			//printf("\n");

				for(j=0; j < quadrature.taille; j++){

					zeta_i = quadrature.tabZeta[j];
					w_j = quadrature.tabOmega[j];

					term = ((1-zeta_i)*a_i + zeta_i*a_i1)*w_j;

					matrice_final.matriceFonctionEchantillonnee[j][i] = CalculFonction(term);
					//porque es horizontal?
					//printf("%lf \t", CalculFonction(term));
				}
		}
		return matrice_final;
}

void LireQuadrature(structQuadrature* pQuadrature, int type){
		/* fonction pour lire une fichier avec des donnees */
		FILE *file;
		float x_, y_;
		int i, n;
		printf("\nreading Quadrature");

		switch(type){
				case 1:
					file = fopen("m_dt.txt","r");
					break;
				case 2:
					file = fopen("m_pd.txt","r");
					break;
				case 3:
					file = fopen("m_pg.txt","r");
					break;
				case 4:
					file = fopen("m_pm.txt","r");
					break;
		}

		if(file == NULL){
				printf("\nfile does not exist\n");
				exit(0);
		}
		fscanf(file,"%d", &n);

		pQuadrature->taille = n;
		printf("\nQuadrature size = %d", pQuadrature->taille);
		printf("\nInitializing tabs.");

		pQuadrature->tabZeta = (double*)malloc(n*sizeof(double));
		printf(".");
		pQuadrature->tabOmega = (double*)malloc(n*sizeof(double));  
		printf(".\n");

		for(i=0; i<n; i++){
			fscanf(file,"%f %f", &x_, &y_);    
			pQuadrature->tabZeta[i] = x_;
			pQuadrature->tabOmega[i] = y_;
		//	printf("\nline[%d] = %f %f", i, x_, y_);
		}

		fclose(file);
} 

void CalculerSubdivisionReguliere(int n,structIntervalle Intervalle,structSubdivision* pSubdivision){
		int i;
		double h = (Intervalle.fin - Intervalle.debut) / (n);
		pSubdivision->nombre = n;
		pSubdivision->tabIntervalle = (structIntervalle*)malloc(n*sizeof(structIntervalle));
		for(i = 0; i < n; i++){
		pSubdivision->tabIntervalle[i].debut = Intervalle.debut + (double)(i*h);
		pSubdivision->tabIntervalle[i].fin = pSubdivision->tabIntervalle[i].debut + (double)(h);
		 }
}
void show_array(double *array, int n){
		int i;
		for(i = 0; i < n; i++)
        {
				printf("\n Ligne[%d] = %lf",i, array[i]);
		}	

}
void verifSubdivision(structSubdivision Subdivision){
		int i, n = Subdivision.nombre;
		for(i=0; i<n; i++){
				printf("\nintervalle #%d", i+1);
				printf("\ndebut = %lf", Subdivision.tabIntervalle[i].debut);
				printf("\nfin = %lf", Subdivision.tabIntervalle[i].fin);
		}
};

#endif
