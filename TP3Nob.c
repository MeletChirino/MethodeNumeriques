//Nobile Kevin 13/02/2020 TP3


#include<stdio.h>
#include<stdlib.h>
#include<math.h>


#define max 1000
#define pi 3.141592654f 


typedef struct { float re, im;}complex;

//									Rappels de langage
/*
fopen( "chemin d'accès au fichier","mode"); // retourne une adresse de type FILE *
fprintf( variable_de_type_FILE, "chaine de format", liste de variables ) ;
fscanf( variable_de_type_FILE, "chaine de format", liste d'adresses de variables ) ;
feof( variable_de_type_FILE ) ;
fclose( variable_de_type_FILE) ;
*/
// 										Prototypes

//----------------------------------------------------------------------------------------
void c_aff (complex);
//----------------------------------------------------------------------------------------
complex c_saisie (complex z);
//----------------------------------------------------------------------------------------
float c_mod (complex z);
//----------------------------------------------------------------------------------------
complex c_opp (complex z);
//----------------------------------------------------------------------------------------
complex_ c_inv (complex z);
//----------------------------------------------------------------------------------------
float c_angle (complex z);
//----------------------------------------------------------------------------------------
float c_angle2 (complex z);
//----------------------------------------------------------------------------------------
complex c_log (complex z);
//----------------------------------------------------------------------------------------
complex c_add (complex z1,complex z2);
//----------------------------------------------------------------------------------------
complex c_sous(complex z1,complex z2);
//----------------------------------------------------------------------------------------
complex c_mul(complex z1,complex z2);
//----------------------------------------------------------------------------------------
complex c_div(complex z1,complex z2);
//----------------------------------------------------------------------------------------

// 										Fonctions

//----------------------------------------------------------------------------------------
void c_aff (complex)
{
	printf("\tz = %8.3f+\t%8.3fj",z.re,z.im);
}
//----------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------
comp c_saisie (complex)
{
	printf("\nSaisir la partie réelle\n");
	scanf("%f", & z.re);
	
	printf("\nSaisir la partie réelle\n");
	scanf("%f", & z.im);
	
	return z;
}
//----------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------
float c_mod (complex z) /* Module d'un complexe */
{
	float sol;
	
	sol=sqrt(z.re*z.re + z.im*z.im);
	return sol;

}
//----------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------

complex c_conj (complex z) /* Conjugué d'un complexe */
{
	complex sol;
	sol = 
	return sol;

}
//----------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------

complex c_inv (complex z) /* Opposé d'un complexe */
{
	float mod_z;
	complex conj_z;
	complex sol;
	sol = conj_z
	return sol;

}
//----------------------------------------------------------------------------------------

//								Programme Principal
int main(void)
{ 

	comp z;
	
	c_saisie (z);
	
	c_aff(z);
	
	printf("\n\t\tFin de Programme\n");
	return 0;
}