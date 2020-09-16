//Par Melet Chirino 26-Fev
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double f(double R);
double df(double R);
float newton(double depart);
double e(float number);
double ln(double number);
double dicotomie(double intervalle[2]);

int main()
{
	double e = 2.71828182845904523536;
	printf("\nlog(%lf)",log(e));
	printf("\nln(%lf)\n-----\n",ln(e));
	
	double R;

	printf("Saissir R = \n");
	double inter[2] = {6000, 10000};

	printf("\nEl resultado es %f", dicotomie(inter));
	
	printf("\nEl resultado es %f", newton(1000));
	printf("\n");
	return 0;
}
double dicotomie(double intervalle[2]){
	double millieu, eps = 20;
	
	do{
		millieu = (intervalle[0] + intervalle[1]) / 2;
		printf("\n\n---\nmillieu = %lf", millieu);
	
		printf("\nintervalo de la derecha = %lf ==>%d",
			f(intervalle[0]) * f(millieu) ,
			f(intervalle[1]) * f(millieu) <= 0);
	
		if(f(intervalle[0]) * f(millieu) <= 0){
			intervalle[1] = millieu;
		}
	
	
		printf("\nintervalo de la derecha = %lf ==>%d", f(intervalle[1]) * f(millieu) ,
			f(intervalle[1]) * f(millieu) < 0);
			
		if(f(intervalle[1]) * f(millieu) < 0){
			intervalle[0] = millieu;
		}

		eps = sqrt(pow(intervalle[0] - intervalle[1],2));
		printf("\n eps actual = %lf", eps);
	}while(eps > 0.001);
	
	return millieu;
}


float newton(double depart){
/* esta funcion me ayuda mucho para lograr una
pequenha modularidad en la que me puedo apoyar 
mas adelante
*/
	double x1 = depart, x2 = depart, eps;
	int trys = 0;

	printf("Saissir la precision desire\n");
	scanf("%lf", &eps);
	do{
		x1 = x2;
		printf("\n f(x) = %lf\n", f(x1));
		printf("\n df(x) = %lf\n", df(x1));
		x2 = x1 - f(x1)/df(x1);
		printf("\n x2 = %lf\n eps actual = %lf", x2, sqrt(pow(x2 - x1,2)));
		trys += 1;
	}while(abs(x2 - x1) > eps || trys > 1000);

	return x2;
}


double ln(double number){
  double e = 2.71828182845904523536;
  return log(number)/log(e);
}

double df(double R){
	// derivada de la funcion f
	return (2.34 * e(-4) + ( 8.78 * e(-8) * (3.0 * log(R)*log(R) )) / R);
}

double f(double R){
	// funcion que da el resultado de la ecuacion que buscamos
	return 1.29*e(-3) + ((2.34 * e(-4) * log(R))) + ((8.78 * e(-8) * 
		(log(R)*log(R)*log(R)))) - (1.0/(20 + 273));
}

double e(float number){
	// funcion de apoyo para las potencias de 10
	return pow(10, number);
}
