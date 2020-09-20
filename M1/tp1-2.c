//Fait par CHIRINO et NAVARRO le 18-sep-2020
#include <stdio.h>
#include <stdlib.h>

#define N 100

void func_y(int a, int b, int c, float *x, float *y);
void show(float x[N], float y[N]);
void find_min(float x[N], float y[N], float point[2]);
void find_max(float x[N], float y[N], float point[2]);

int main(){
			int a, b, c, i;
			float y[N], delta, x[N], x_min, x_max, point[2];

			//saisir les valeurs
			printf("Saisir la valeur de a\n");
			scanf("%d",&a);
			printf("Saisir la valeur de b\n");
			scanf("%d",&b);
			printf("Saisir la valeur de c\n");
			scanf("%d",&c);

			do
			{
					printf("Saisir la valeur de X min\n");
					scanf("%f",&x_min);
					printf("Saisir la valeur de X max\n");
					scanf("%f",&x_max);

					if(x_max <= x_min) printf("rentrez des valeurs coherents");

			}while(x_max <= x_min);

			//Calcul des caleurs de x
			delta = (x_max - x_min)/(N-1);
			x[0] = x_min;
			for(i=1; i<N; i++) x[i] = x[i-1] + delta;

			//calcul de y
			func_y(a, b, c, x, y);

			//Affichage
			printf("\nTableaux de valeurs\n");
			show(x, y);

			//trouver le y min
			find_min(x, y, point);
			printf("Le point minimum est [%2.1f, %2.1f]\n", point[0], point[1]);
			//trouver le y max
			find_max(x, y, point);
			printf("Le point maximum est [%2.1f, %2.1f]\n", point[0], point[1]);
			return 0;
}
void find_min(float *x, float *y, float *point){
			int i;
			float min=*(y+N-1), xmin;
			for(i=0; i<N; i++){
				if(y[i]<min)
				{
					min=*(y+i);
					xmin = *(x+i);
				}
			}
			*point = xmin;
			*(point+1) = min;
}
void find_max(float *x, float *y, float *point){
			int i;
			float max=*(y+N-1), xmax;
			for(i=0; i<N; i++){
				if(y[i]>max)
				{
					max=*(y+i);
					//printf("new min = %f", min);
					xmax = *(x+i);
				}
			}
			*point = xmax;
			*(point+1) = max;
}

void func_y(int a, int b, int c, float *x, float *y){
		int i;
		for(i=0; i<N; i++){
				*(y+i) = a*(*(x+i)* *(x+i)) + b* *(x+i) + c;
		}
}
void show(float x[N], float y[N]){
			int i;
			printf("-----------------------------------\n");
			for(i=0; i<N; i++) printf("|%2.3f\t\t\t|%2.1f\t\t\t|\n", x[i], y[i]);
			printf("-----------------------------------\n");
}
