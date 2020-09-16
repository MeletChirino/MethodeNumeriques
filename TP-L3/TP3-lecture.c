void lecture(int *n,float a[DIM], float b[DIM])
{
/* A la fin de la lecture, n contient le nombre d'elements de a et de b
DIM est une constante qui doit contenir une valeur sup�rieure aux
nombre de valeur dans le fichier */
    FILE* fic=NULL;

    fic = fopen("puissance.txt","r");
    if (fic == NULL)
    {
        printf("puissance.txt n'existe pas");
        exit(1);
    }

    *n=0;
    while(feof(fic)==0)
    {
        fscanf(fic,"%f %f",&a[*n], &b[*n]);
        (*n)++;
    }

    fclose(fic);
}