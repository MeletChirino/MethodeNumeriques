Scruter le bit ADCIR ou le bit ADBSY.

Le bit ADCIR appartient au registre ADCIC (registre d'Interruption IT)

Le bit ADBSY appartient au registre ADCON

ADCIR est =0 au départ
Si la conversion est terminée alors ADCIR = 1

Faire une scrutation revient à regarder le contenu de ce bit
de manière répétitive avec un "while"

while (ADBSY==1); etat bloquant

while (ADCIR==0); etat bloquant

=> 
while (SFR_BIT(ADBSY)==1);
ou
while (SFR_BIT(ADCIR)==0);

WAIT_UNTIL_BITCLR(ADBSY); //attente mise à 0 du bit

WAIT_UNTIL_BITSET(ADCIR); //attente mise à 1 du bit

while ((ADCON & 0x0100)==0x0100);
...

while ((ADCIC & 0x80)==0x00);
CLR_SFRBIT(ADCIR); //remise à 0 de ADCIR

ou avec un masque :
ADCIC = ADCIC & 0xFF7F; // masque = 1111 1111 0111 1111

Code de la scrutation (pour conversion unique):

while(1){
CLR_SFRBIT(ADCIR); //remise à 0 de ADCIR
SET_SFRBIT(ADST);
WAIT_UNTIL_BITSET(ADCIR); //attente mise à 1 du bit
val = ADDAT & 0x3FF;
}



/* Programme complet par scrutation */

#include <c167.h>

void main()
{
	unsigned int val;
	unsigned int canal;
	
	/* initialisation de ADCON */
	ADCON = 0x32; // conversion répétitive sur plusieurs canaux
	
	SET_SFRBIT(ADST);
	
	while(1){
		CLR_SFRBIT(ADCIR); //remise à 0 de ADCIR
		WAIT_UNTIL_BITSET(ADCIR); //attente mise à 1 du bit
		val = ADDAT & 0x3FF;
		canal = ADDAT >> 12; //(ADDAT & 0xF000) >> 12
	}

}


/* Programme complet par interruption */

#include <c167.h>
#include <gnutrap.h>

	unsigned int val;
	unsigned int canal;
	
	unsigned int val_lue[3]={0,0,0};
	unsigned int nb_acq[3]={0,0,0};
	float val_moy[3]={0,0,0};
	
	TRAP(0x28,lecture_AD);
	
void lecture_AD()
{
		val = ADDAT & 0x3FF;
		canal = ADDAT >> 12; //(ADDAT & 0xF000) >> 12
		
		if (nb_acq[canal]<50){
			val_lue[canal] = val_lue[canal] + val;
			nb_acq[canal]++;
		}
}

void main()
{
	unsigned int booleen_deja_fait = 0;
	/* initialisation de ADCON */
	ADCON = 0x32; // conversion répétitive sur plusieurs canaux
	
	/* initialisation de ADCIC niveau 1 groupe 0 */
	//ADCIC = 0x44;
	/* initialisation de ADCIC niveau 5 groupe 0 */
	ADCIC = 0x54;
	
	SET_SFRBIT(IEN); //mise à 1 du bit IEN
	
	
	SET_SFRBIT(ADST); //mise à 1 du bit ADST
	
	while(1){
		if ((nb_acq[0]==50)&&(nb_acq[1]==50)&&(nb_acq[2]==50)&&(booleen_deja_fait==0))
		{
			val_moy[0]=val_lue[0]/50.;
			val_moy[1]=val_lue[1]/50.;
			val_moy[2]=val_lue[2]/50.;
			booleen_deja_fait =1;
			
			CLR_SFRBIT(ADST); //arret du convertisseur ou ADCON = ADCON & 0xFF7F;
			//CLR_SFRBIT(ADCIE);
