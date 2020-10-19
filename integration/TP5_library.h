#ifndef TP5_LIBRARY
#define TP5_LIBRARY
/* Fichier de base pour le sujet de TP 5 */
//
// Les structures suivantes sont imposées
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

void LireQuadrature(struct structQuadrature *pQuadrature){

}

void CalculerSubdivisionReguliere(int n,struct structIntervalle Intervalle, struct structSubdivision* pSubdivision){
	int i;
	double h = (Intervalle.fin - Intervalle.debut) / (n+1);
	pSubdivision->nombre = n;
	pSubdivision->tabIntervalle = (struct structIntervalle*)malloc(n*sizeof(struct structIntervalle));
	for(i = 0; i < n; i++){
		pSubdivision->tabIntervalle[i].debut = Intervalle.debut + (i*h);
		pSubdivision->tabIntervalle[i].fin = pSubdivision->tabIntervalle[i].debut + (h*i);
	}

}


/* PROPOSITIONS DE FONCTIONS :
void CalculerSubdivisionReguliere(int n, structIntervalle Intervalle, structSubdivision* pSubdivision);



void CalculerEchantillonnage(structQuadrature Quadrature, structSubdivision Subdivision,structEchantillonnage_fonction* pEchantillonnage_fonction);
double CalculIntegrale(structEchantillonnage_fonction Echantillonnage_fonction);
*/


/* FONCTIONS DEJA CODEES DANS LA LIBRAIRIE */
void show_array(double *array, int n);
void LireQuadrature(structQuadrature* pQuadrature);
double CalculFonction(double x);
//void AffichageGnuplot(structEchantillonnage_fonction Echantillonnage_fonction);
void SauvegardeCourbe(char * nom_fichier, double * Abscisses, double * Ordonnees, int n);

#endif
