//Implementar las siguientes funciones

#include<stdio.h>
#include <stdbool.h>

void suma(int a, int b, long int * suma){
	*suma = a+b;
}

void resta(int a, int b, long int * resta){
	*resta = a-b;
}
void producto(int multiplicando, int multiplicador, float * producto){
	*producto = multiplicando*multiplicador;
}

void division(int dividendo, int divisor, double *resultado){
	*resultado=dividendo/divisor;
}

int main (void){
	

	return 0;
}