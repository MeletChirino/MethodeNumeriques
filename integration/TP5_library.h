#ifndef TP5_LIBRARY
#define TP5_LIBRARY
/* Fichier de base pour le sujet de TP 5 */
//
// Les structures suivantes sont imposées
#include <stdio.h>
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
	structQuadrature Quadrature_Echantillonnage;
	structSubdivision Subdivision_Echantillonnage;
	double** matriceFonctionEchantillonnee;
} structEchantillonage_fonction;

double f(double x){
		return x*x;
}

structEchantillonage_fonction echantillonage_fonction(structSubdivision subdivision, structQuadrature quadrature){
		//inicialicemos variables para esta funcion
		int i, j = 0;
		double a_i, a_i1, w_j, zeta_i, term;

		structEchantillonage_fonction matrice_final;
		matrice_final.matriceFonctionEchantillonnee = (double**)malloc(quadrature.taille*sizeof(double*));
		for(i = 0; i < subdivision.nombre; i++)
			matrice_final.matriceFonctionEchantillonnee[i] = (double*)malloc(subdivision.nombre*sizeof(double));

		for(i = 0; i < subdivision.nombre - 1; i++){

			a_i = subdivision.tabIntervalle[i].debut;
			a_i1 = subdivision.tabIntervalle[i].fin;
			printf("\n");

				for(j=0; j < quadrature.taille; j++){

					zeta_i = quadrature.tabZeta[j];
					w_j = quadrature.tabOmega[j];

					term = ((1-zeta_i)*a_i + zeta_i*a_i1)*w_j;

					matrice_final.matriceFonctionEchantillonnee[j][i] = f(term);
					printf("%lf \t", f(term));
				}
		}
		return matrice_final;
}


void LireQuadrature(structQuadrature* pQuadrature){
		/* fonction pour lire une fichier avec des donnees */
		FILE *file;
		float x_, y_;
		int i, n;
		printf("\nreading Quadrature");

		file = fopen("m_dt.txt","r");
		fscanf(file,"%d", &n);

		pQuadrature->taille = n;
		printf ("\nQuadrature size = %d", n);

		pQuadrature->tabZeta = (double*)malloc(pQuadrature->taille*sizeof(double));
		pQuadrature->tabOmega = (double*)malloc(pQuadrature->taille*sizeof(double));  

		//while(fscanf(file,"%lf %lf", &x_, &y_) != EOF)
		for(i=0; i<n; i++){
			fscanf(file,"%f %f", &x_, &y_);    
			printf("\nline[%d] = %f %f", i, x_, y_);
			pQuadrature->tabZeta[i] = (double)x_;
			pQuadrature->tabOmega[i] = (double)y_;
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

/* PROPOSITIONS DE FONCTIONS :
void CalculerSubdivisionReguliere(int n, structIntervalle Intervalle, structSubdivision* pSubdivision);



void CalculerEchantillonnage(structQuadrature Quadrature, structSubdivision Subdivision,structEchantillonnage_fonction* pEchantillonnage_fonction);
double CalculIntegrale(structEchantillonnage_fonction Echantillonnage_fonction);
*/


/* FONCTIONS DEJA CODEES DANS LA LIBRAIRIE */
void show_array(double *array, int n);
void LireQuadrature(struct structQuadrature* pQuadrature);
double CalculFonction(double x);
//void AffichageGnuplot(structEchantillonnage_fonction Echantillonnage_fonction);
void SauvegardeCourbe(char * nom_fichier, double * Abscisses, double * Ordonnees, int n);

#endif
