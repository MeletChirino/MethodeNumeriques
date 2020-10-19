#ifndef TP5_LIBRARY
#define TP5_LIBRARY
/* Fichier de base pour le sujet de TP 5 */
//
// Les structures suivantes sont imposées
#include <stdio.h>
struct structIntervalle{
	double debut;
	double fin;
};

struct structSubdivision{
	int nombre;
	struct structIntervalle* tabIntervalle;
};

struct structQuadrature{
	int taille;
	double* tabZeta;
	double* tabOmega;
};

struct structEchantillonage_fonction{
	struct structQuadrature Quadrature_Echantillonnage;
	struct structSubdivision Subdivision_Echantillonnage;
	double** matriceFonctionEchantillonnee;
};

void LireQuadrature(struct structQuadrature* pQuadrature){
	/* fonction pour lire une fichier avec des donnees */
	FILE *file;
	int x_, y_;
	int i, n;
	
	file = fopen("m_pm.txt","r");
	fscanf(file,"%d", &n);
	
	pQuadrature->taille = n;
	
	pQuadrature->tabZeta = (double*)malloc(pQuadrature->taille*sizeof(double));
    pQuadrature->tabOmega = (double*)malloc(pQuadrature->taille*sizeof(double));  

	//while(fscanf(file,"%lf %lf", &x_, &y_) != EOF)
    for(i=0; i<n; i++)
    {
        fscanf(file,"%d %d", &x_, &y_);    
        printf("%d %d", x_, y_);
		pQuadrature->tabZeta[i] = (double)x_;
		pQuadrature->tabOmega[i] = (double)y_;
	}

	fclose(file);
}

void CalculerSubdivisionReguliere(int n,struct structIntervalle Intervalle, struct structSubdivision* pSubdivision){
	int i;
	double h = (Intervalle.fin - Intervalle.debut) / (n);
	pSubdivision->nombre = n;
	pSubdivision->tabIntervalle = (struct structIntervalle*)malloc(n*sizeof(struct structIntervalle));
	for(i = 0; i < n; i++){
		pSubdivision->tabIntervalle[i].debut = Intervalle.debut + (double)(i*h);
		pSubdivision->tabIntervalle[i].fin = pSubdivision->tabIntervalle[i].debut + (double)(h);
	}

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
