#include <stdio.h>
#include <stdlib.h>
#define DIM 1000 
 

typedef float datas[DIM];

//functions
void lecture(int *n,float a[DIM], float b[DIM]);
void voirTabla(tabla vect);
 
int main(void)
{ 
	datas heure, puissance;
	int numero;
	
	lecture(&numero, heure, puissance);
	voirTabla(heure);
	
	return 0;
}


void voirTabla(tabla vect)
{
	int i;
	
	for(i = 0; i < DIM; i++)
	{
		printf("%f\n", vect[i]);
	}
	printf("\n");
}

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