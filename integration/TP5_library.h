#ifndef TP5_LIBRARY
#define TP5_LIBRARY
/* Fichier de base pour le sujet de TP 5 */

// Les structures suivantes sont imposées
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
} structEchantillonnage_fonction;


/* PROPOSITIONS DE FONCTIONS :
void CalculerSubdivisionReguliere(int n, structIntervalle Intervalle, structSubdivision* pSubdivision);
void LireQuadrature(structQuadrature* pQuadrature);
void CalculerEchantillonnage(structQuadrature Quadrature, structSubdivision Subdivision,structEchantillonnage_fonction* pEchantillonnage_fonction);
double CalculIntegrale(structEchantillonnage_fonction Echantillonnage_fonction);
*/


/* FONCTIONS DEJA CODEES DANS LA LIBRAIRIE */
double CalculFonction(double x);
void AffichageGnuplot(structEchantillonnage_fonction Echantillonnage_fonction);
void SauvegardeCourbe(char * nom_fichier, double * Abscisses, double * Ordonnees, int n);

#endif
