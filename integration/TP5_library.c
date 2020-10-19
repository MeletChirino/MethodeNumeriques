#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "TP5_library.h"

/*  Fichier de base pour le sujet de TP 5 

--------COMPILATION--------
   gcc -Wall -c TP5_library.c -lm
*/




/* FONCTIONS DEJA CODEES DANS LA LIBRAIRIE : */


double CalculFonction(double x) // On modifiera ici la fonction à intégrer
{
	double resultat;
	resultat = exp(-x*x/2)/(sqrt(2*3.14159265358979));
	return resultat;
}

// Fonction créant deux fichiers de données exploitables pour un tracé sur Gnuplot
void AffichageGnuplot(structEchantillonnage_fonction Echantillonnage_fonction)
{
	int n = (Echantillonnage_fonction.Subdivision_Echantillonnage).nombre;
	int p = (Echantillonnage_fonction.Quadrature_Echantillonnage).taille;
	int m = 1000;
	int j,k;
	double debut,fin,pointQuadrature,SommeZetaQuadrature;

	double * Ordonnees_f_x;
	double * Abscisses_x;
	double * Ordonnees_fboxes_x;
	double * Abscisses_boxes;
	Abscisses_x = (double*) malloc(m*sizeof(double));
	Ordonnees_f_x = (double*) malloc(m*sizeof(double));
	Abscisses_boxes = (double*) malloc((2*p*n+1)*sizeof(double));
	Ordonnees_fboxes_x = (double*) malloc(2*p*n*sizeof(double));

	Abscisses_boxes[0]=((Echantillonnage_fonction.Subdivision_Echantillonnage).tabIntervalle)[0].debut;
	for(j=0;j<n;j++)
	{
		debut = ((Echantillonnage_fonction.Subdivision_Echantillonnage).tabIntervalle)[j].debut;
		fin = ((Echantillonnage_fonction.Subdivision_Echantillonnage).tabIntervalle)[j].fin;
		SommeZetaQuadrature=0;
		for(k=0;k<p;k++)
		{
			pointQuadrature = ((Echantillonnage_fonction.Quadrature_Echantillonnage).tabZeta)[k];
			SommeZetaQuadrature += ((Echantillonnage_fonction.Quadrature_Echantillonnage).tabOmega)[k];
			//printf("%lf\n",SommeZetaQuadrature);
			Ordonnees_fboxes_x[2*(p*j+k)] = (Echantillonnage_fonction.matriceFonctionEchantillonnee)[k][j];
			Ordonnees_fboxes_x[2*(p*j+k)+1] = (Echantillonnage_fonction.matriceFonctionEchantillonnee)[k][j];
			Abscisses_boxes[2*(p*j+k)+1] = (1-SommeZetaQuadrature) * debut + SommeZetaQuadrature * fin; 
			Abscisses_boxes[2*(p*j+k)+2] = (1-SommeZetaQuadrature) * debut + SommeZetaQuadrature * fin; 
		}
	}

	debut = ((Echantillonnage_fonction.Subdivision_Echantillonnage).tabIntervalle)[0].debut;
	fin = ((Echantillonnage_fonction.Subdivision_Echantillonnage).tabIntervalle)[n-1].fin;
	for(j=0;j<m;j++)
	{
		Abscisses_x[j] = debut * (m-j-0.5) / m + fin * (j+0.5) / m;
		Ordonnees_f_x[j] = CalculFonction(Abscisses_x[j]);
	}

	SauvegardeCourbe("courbe_ligne.dat", Abscisses_x, Ordonnees_f_x, m);
	SauvegardeCourbe("courbe_integration_boxes.dat", Abscisses_boxes, Ordonnees_fboxes_x, 2*p*n);

	free(Ordonnees_fboxes_x);
	free(Abscisses_x);
	free(Ordonnees_f_x);
	free(Abscisses_boxes);
}

// Fonction générique de sauvegarde de données pour le tracé d'une courbe sur Gnuplot
void SauvegardeCourbe(char * nom_fichier, double * Abscisses, double * Ordonnees, int n)
{
	FILE* fichier = NULL;
	int k;
 
	fichier = fopen(nom_fichier, "w");
 
	if (fichier != NULL)
	{
		for(k=0;k<n;k++)
		{
			fprintf(fichier, "%f\t%f\n", Abscisses[k],Ordonnees[k]);
		}
		fclose(fichier);
	}
}

