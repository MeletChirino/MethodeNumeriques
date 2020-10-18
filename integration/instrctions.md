# Instrucciones de TP
## Calculo de subdiviosn de intervalos
Pra esta primera parte debes hacer una funcion que divida un intervalo en n partes iguales. Esta funcion tomara un valor minimo y un maximo y al final reescribira un vector con los valores de cada intervalo. Ademas se nos impone usar los structs siguientes:
```c
typedef struct{
	double debut;
	double fin;
} structIntervalle;

typedef struct{
	int nombre;
	structIntervalle* tabIntervalle;
} structSubDivision;
```
La funcion que tengo pensado es la sgte:
```c
void subdivision(structIntervalle, structSubDivision);
```
## Definicion y lectura d'une quadratura


### Methode des rectangels a gauche et droite

### Methode du point milieu

### Methode des trapezes

## Calcul de l'echantillonage d'une fonction sur une subdivision pour une formule de quadrature

## Calcul de l'integrale d'une function d entre a et b

## Ordre d'une quadrature

## Quelques methodes de quadrature plus evoluees

### Methode simpson

### Methode de Gauss-Tchevychev

## Application a l'etude de la densite de la probabilite d'une loi normale
