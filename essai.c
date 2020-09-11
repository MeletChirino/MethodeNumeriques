#include <stdio.h>
#include <stdlib.h>

int  main(){
int a;
int *p;

//variables
a = 1;
*p = NULL;//esto se agrega para decir que el puntero apunta a null part

//program
printf("hello world\n");

printf("la valeur de a est %d\n", a);
printf("la valeur de a est %p\n", &a);

p = &a;

printf("laddresse de p est %p\n", &p);
printf("ladresse de la variable vers laquelle p pointe est %p\n", p);
printf("la valeur de la variable vers laquelle pointe est %d\n", *p);

return 0;
} 

//la maldita vieja la viejaaa la maldita vieja la maldita vieja la maldita vieja