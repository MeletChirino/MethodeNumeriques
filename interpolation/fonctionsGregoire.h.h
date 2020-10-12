
     

//double f(double x)

       
//void echantillon_régulier(double min, double max, int n, double *echantillon)


//void calcul_fonction(int n, double *ech_x, double *ech_f)


void sauvegarde_fichier(char *courbe, double *abscisses, double *ordonnees, int n)
{
    float xi;
    float yi;
    FILE* fichier;
    fichier = fopen("courbe","w");

    while(fscanf(fichier,"%lf %lf",&xi,&yi) != EOF)
    {
      abscisses[n] = xi; 
      ordonnees[n] = yi; 
      n++;                      
    }
    
               
    fclose(fichier);             
}

//double polynome(double x, polynome *poly)*


//void calcul_polynome(int n, double *ech_x, double *ech_poly, polynome *poly)





