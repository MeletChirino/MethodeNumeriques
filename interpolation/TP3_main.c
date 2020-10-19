#include <stdio.h>
#include <stdlib.h>
#include "TP3_sp.h"

#define N 10

int main()
{
  int result, i, n;
  double x, y;
  char fichier;
  
  sauvegarde_fichier(&fichier, &x, &y, n);
  
  printf("result : %d \n",result);
  
  for(i=0; i<result; i++)
  {
   printf("%f %f \n",x,y);        
  }  
    
  
  system("PAUSE");	
  return 0;
}

