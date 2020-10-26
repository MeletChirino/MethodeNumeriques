#include <stdio.h>
#include <stdlib.h>
#include "TP5_library.h"


// Fonction gÃ©nÃ©rique de sauvegarde de donnÃ©es pour le tracÃ© d'une courbe sur Gnuplot
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

// Fonction crÃ©ant deux fichiers de donnÃ©es exploitables pour un tracÃ© sur Gnuplot
void AffichageGnuplot(structEchantillonage_fonction Echantillonage_fonction)
{
			int n = Echantillonage_fonction.Subdivision_Echantillonage.nombre;
			int p = Echantillonage_fonction.Quadrature_Echantillonage.taille;
			int m = 1000;
			int j,k;
			double debut,fin,pointQuadrature,SommeZetaQuadrature;

			double * Ordonnees_f_x;
			double * Abscisses_x;
			double * Ordonnees_fboxes_x;
			double * Abscisses_boxes;
			printf("\nCreating Memory");
			Abscisses_x = (double*) malloc(m*sizeof(double));
			printf(".");
			Ordonnees_f_x = (double*) malloc(m*sizeof(double));
			printf(".");
			Abscisses_boxes = (double*) malloc((2*p*n+1)*sizeof(double));
			printf(".");
			Ordonnees_fboxes_x = (double*) malloc(2*p*n*sizeof(double));
			printf(".");

			Abscisses_boxes[0]=Echantillonage_fonction.Subdivision_Echantillonage.tabIntervalle[0].debut;
			for(j=0;j<n;j++)
			{
				debut = Echantillonage_fonction.Subdivision_Echantillonage.tabIntervalle[j].debut;
				fin = Echantillonage_fonction.Subdivision_Echantillonage.tabIntervalle[j].fin;
				SommeZetaQuadrature=0;
				for(k=0;k<p;k++)
				{
					pointQuadrature = Echantillonage_fonction.Quadrature_Echantillonage.tabZeta[k];
					SommeZetaQuadrature += Echantillonage_fonction.Quadrature_Echantillonage.tabOmega[k];
					//printf("%lf\n",SommeZetaQuadrature);
					Ordonnees_fboxes_x[2*(p*j+k)] = Echantillonage_fonction.matriceFonctionEchantillonnee[k][j];
					Ordonnees_fboxes_x[2*(p*j+k)+1] = Echantillonage_fonction.matriceFonctionEchantillonnee[k][j];
					Abscisses_boxes[2*(p*j+k)+1] = (1-SommeZetaQuadrature) * debut + SommeZetaQuadrature * fin; 
					Abscisses_boxes[2*(p*j+k)+2] = (1-SommeZetaQuadrature) * debut + SommeZetaQuadrature * fin; 
				}
			}

			debut = Echantillonage_fonction.Subdivision_Echantillonage.tabIntervalle[0].debut;
			fin = Echantillonage_fonction.Subdivision_Echantillonage.tabIntervalle[n-1].fin;
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

int main(){
		int n, type;
		double I;

		structSubdivision Subdivision;
		structIntervalle Intervalle;

		printf("\nSaisisez le debut de l'intervalle = ");
		scanf("%lf", &Intervalle.debut);
		printf("\nSaisisez la fin de l'intervalle = ");
		scanf("%lf", &Intervalle.fin);

		printf("\nEcrivez le nombre intervalles = ");
		scanf("%d", &n);
		CalculerSubdivisionReguliere(n, Intervalle, &Subdivision);

		//verifSubdivision(Subdivision);

    	//On lit le type de quadrature
		printf("\nSaisisez le type de quadrature:\n1. Par trapezes\n2. Par Point Droit\n3. Par Point Gauche\n4. Par Point Millieu\n");
		scanf("%d", &type);

		structQuadrature Quadrature;
        LireQuadrature(&Quadrature, type); 

		structEchantillonage_fonction matriz = echantillonage_fonction(Subdivision, Quadrature);
		I = CalculIntegrale(matriz);
		//AffichageGnuplot(matriz);


		return 0;
}
