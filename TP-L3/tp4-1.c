#include <stdio.h>
#include <stdlib.h>

#define DIM 100

void lecture(int *n,float a[DIM], float b[DIM]);
float simpson(float x[DIM], float y[DIM], int n);
float sumatoria(float b[DIM], int n, int pair);
float trapeze(float x[DIM], float y[DIM], int n);
float max(float y[DIM], int n)
{
	int i;
	float maximo = -1;
	for(i = 0; i < n; i++){
		if(y[i] > maximo)
			maximo = y[i];
	}
	
	return maximo;
}

int main(){
	float a[DIM], b[DIM];
	int n;
	
	system("clear");
	
	lecture(&n, a, b);
	printf("----------Methode Simpson----------\n");
	printf("Pmoy = \t%0.2f W\n", simpson(a, b, n)/24);
	printf("E = \t%0.2f MW\n", simpson(a, b, n));

	printf("\n----------Methode Trapeze----------\n");
	printf("Pmoy = \t%0.2f W\n", trapeze(a, b, n)/24);
	printf("E = \t%0.2f MW\n", trapeze(a, b, n));
	printf("\n");
	
	printf("Puissance Max = %0.2f W\n\n", max(b, n));
	
	return 0;

}


float trapeze(float x[DIM], float y[DIM], int n)
{
	float h = (x[n-1] - x[0])/n;
	return (h / 2) * (y[0] + y[n-1] + 2 * sumatoria(y, n, 2));
}

float simpson(float x[DIM], float y[DIM], int n)
{
	
	float h = (x[n-1] - x[0])/n;
	return (h / 3) * (y[0] + y[n-1] + 4* sumatoria(y, n, 1) + 2* sumatoria(y, n, 0));
}

float sumatoria(float b[DIM], int n, int pair) //0 => somme des pairs, 1=> somme d'impairs, 2 =>somme total
{
	/*
	los argumentos de par son los sgtes
	0 para la sumatoria par
	1 para la sumatoria impar
	2 para la sumatoria completa
	*/
	int i=0;
	float acum = 0;
	
	if(pair == 0){
		for(i = 0; i<n; i+=2)
		{
			acum += b[i];
		}
	} else if(pair == 1)
	{
		for(i = 1; i<n; i+=2)
		{
			acum += b[i];
		}
	} else if(pair == 2)
	{
		for(i = 1; i<n; i++)
		{
			acum += b[i];
		}
	}
	
	return acum;
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