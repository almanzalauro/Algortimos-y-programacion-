/*
a)Definí una estructura punto que contenga las coordenadas de un punto en .

b)Definí un nuevo tipo utilizando la definición de la estructura punto.

c)Implementá una función que reciba dos estructuras punto y calcule la distancia euclídea entre ambos puntos.
d)Implementá la función del inciso c ¡pero validá!
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct {
    float x;
    float y;
} punto;

float distancia_euclidea(punto p1, punto p2){
	return sqrt(pow(p2.x-p1.x,2)+pow(p2.y-p1.y,2));
}


int main(void){
	punto p1;
	punto p2;

	p1.x=2;
	p1.y=3;

	p2.x=5;
	p2.y=8;

	printf("La distancia es: %.2f\n", distancia_euclidea(p1,p2));


}