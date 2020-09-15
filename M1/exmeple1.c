#include <stdio.h>
int main()
{
	float x;
	float* px;

	x=0.5;
	px=&x;
	x/=2.0;
	printf("%f %f \n", x, *px);
	return 0;
}
