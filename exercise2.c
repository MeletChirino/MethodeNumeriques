//Par : Melet Chirino
#include <stdio.h>
#include <stdlib.h>

void decoupeMinutes(int *fheures, int *fminutes){

	*fheures = *fminutes / 60;
	*fminutes = *fminutes % 60;
	printf("dans la fonction:\n %d heures et %d minutes\n", *fheures, *fminutes);
	
}

int main(){
	int heures = 0, minutes = 90;
	printf("dans main la fonction\n %d heures et %d minutes\n",heures, minutes);
	decoupeMinutes(&heures, &minutes);
	printf("dans main apres la fonction:\n %d heures et %d minutes\n", heures, minutes);
	return 0;

}
