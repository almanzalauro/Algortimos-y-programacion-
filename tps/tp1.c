#include <stdio.h>
#include <math.h>


#define ANCHO 640
#define ALTO 480

#define MAXIMO 255

#define X0 (ANCHO / 2)
#define Y0 (ALTO / 2)

#define FRECUENCIA 0.02

double PI = 3.1415926535897932;


double distancia(float x0, float y0, float x1, float y1){
	return sqrt(pow(x0 - x1, 2) + pow(y0 - y1, 2));	
}


int seno_escalado(double t, float f, int max){
	return (max/2)*(sin(2*PI*f*t) + 1);
}

int main()
{	
	
	printf("P2\n%d %d\n%d\n",ANCHO,ALTO,MAXIMO);

	for(size_t y = 0; y < ALTO; y++){
		for(size_t x = 0; x < ANCHO; x++){
			printf("%d\n", seno_escalado(distancia(X0, Y0, x, y),FRECUENCIA,MAXIMO));
		}
		
	}

	return 0;
}
