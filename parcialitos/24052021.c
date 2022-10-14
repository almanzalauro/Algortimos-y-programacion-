/*parcial 24/05/2021*/
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#define N 3
#define M 4
#define MAX_STR 256
/*------- 1 --------
a.Escribir una función int mi_atoi(const char s[]);
que dada una cadena de caracteres s devuelva el número entero contenido en ella. No deben
realizarse validaciones.

Por ejemplo, si se llamara a la función con "75029511" como s, la función devolvería el
entero 75029511.
Aclaración: No está permitido el uso de funciones de la biblioteca. Todas las necesarias
deben ser implementadas.
Ayuda: Para obtener el valor numérico de un char en el rango '0' a '9' puede restársele
al mismo el valor '0' dado que estos caracteres están consecutivos y ordenados en la tabla
ASCII.
b. Dar un mínimo ejemplo de invocación de la función*/

int mi_atoi(const char s[]){
	int numero=0;

	for(size_t i=0; s[i] ;i++)
		numero = numero * 10 + s[i] - '0';
	
	return numero;
}

/*------- 2 --------
Una matriz tiene paridad si los elementos de las posiciones pares son pares y los de las posiciones
impares son impares, donde la posición es la suma de la fila y la columna.
Por ejemplo la matriz

       		4 9 6 7  		00	01	...	0M
  A(nxm)=   5 8 1 8			..	..	...	..
	   		0 2 3 1			N0	N1	...	NM

no tiene paridad porque en la posición (2, 1) que es impar está el 2 que es par y en la posición
(2, 2) que es par está el 3 que es impar.

a. Escribir una función tiene_paridad que reciba una matriz de enteros en Z N×M y que
   devuelva si la matriz recibida tiene paridad.
b. Dar un mínimo ejemplo de invocación de la función.

*/
/*
bool tiene_paridad(int matriz[N][M]){
	bool tiene_paridad =true;

	for(size_t i=0;i<N;i++){
		for(size_t j=0;j<M;j++){


			if( (((i+j)%2==0) && ((matriz[i][j]%2)==0)) || ((i+j)%2!=0 && (matriz[i][j]%2)!=0 ))
				continue;

			else return !tiene_paridad;			
		}
	}
	return tiene_paridad;
}
*/


/*------- 3 --------
El pH de una solución se calcula en función de la concentración de iones hidronio (H3O+) según
la fórmula:
		    1
pH = log ------
	     [H3O+]

Escribir un programa que le pida al usuario una concentración de hidronio y que imprima el pH
correspondiente a dicha concentración.
Realizar todas las validaciones pertinentes.
Ayuda: Para calcular un logaritmo decimal puede usarse la función double log10(double) de
la biblioteca <math.h>
	
double calculo_ph(double concentracion_hidronio){
	
	if(concentracion_hidronio>0){
		return log10(1/concentracion_hidronio);
	}
	else return false;
}
*/



int main(void){

	/*-----EJERCICIO 1-----*/
	/* s[]="4513987";
	printf("El numero es: %d\n",mi_atoi(s));*/

	/*----EJERCICIO 2----*/
	/*matriz1 de paridad FALSE
	  matriz2 de paridad TRUE*/
	/*int matriz1[N][M]={{4,9,6,7},
					  {5,8,1,8},
					  {0,1,3,1}};
	int matriz2[N][M]={{4,9,6,7},
					  {5,8,1,8},
					  {0,1,4,1}};
	printf("La paridad para la matriz 1 es: %d\n",tiene_paridad(matriz1));
	printf("La paridad para la matriz 2 es: %d\n",tiene_paridad(matriz2));*/

	/*------EJERCICIO 3-------*/
	/*char aux[MAX_STR];
	
	float concentracion_hidronio;

	printf("Ingrese la concentracion de hidronios: ");
	fgets(aux,MAX_STR,stdin);

	concentracion_hidronio=atof(aux);
	
	printf("La concentracion de hidronios es: %.2E\n",calculo_ph(concentracion_hidronio));
	*/
}
