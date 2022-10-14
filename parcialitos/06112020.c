#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define N 3
/*------- 1 ------
a. Escribir una función
void eliminar_caracter(char s[], char c);
que dada una cadena de caracteres s y un carácter c modifique la cadena eliminando todas
las ocurrencias del carácter c.
Por ejemplo, si se llamara a la función con "algoritmos y programacion" como cadena y
con 'o' como carácter la cadena debe ser modificada a "algritms y prgramacin".
Aclaración: No está permitido el uso de funciones de la biblioteca. Todas las necesarias
deben ser implementadas.
b. Dar un mínimo ejemplo de invocación de la función.
*/


/*------ 2 -----
a. Escribir una función que reciba una matriz M en R
N×N y que devuelva si la matriz recibida
es la matriz identidad.
b. Dar un mínimo ejemplo de invocación de la función
*/


/*------ 3 -----
Los parcialitos de Algoritmos y Programación se puntuan del 0 al 10 y se aprueban con más de 4.
Escribir un programa que deje que el docente ingrese la nota de un parcialito y que le diga si el
alumno aprobó o reprobó.
*/


bool es_identidad(int matriz[][N],size_t n){
	for(size_t i=0;i<n;i++){
		for(size_t j=0; j<n; j++)
			if((matriz[i][j]!=0 && i!=j) || (matriz[i][j]!=1 && i==j))
				return false;
	}
	return true;
}

void eliminar_caracter(char s[], char c){
	size_t i,j=0;
	char aux[256];
	for(i=0; s[i];i++){
		if(s[i]!=c){
			aux[j]=s[i];
			s[j]=aux[j];
			j++;
		}
	}
	s[j]='\0';
}

bool es_aprobado(int nota){
	if(nota >=0 && nota <=10){
		if(nota>=4){
			return true;
		}
		else 
		{ 
			return false;
		}
	}
	return false;
}
int main(void){

	char nota[256];
	printf("Ingrese la nota del parcialito: ");	
	fgets(nota,256,stdin);
	int i=atoi(nota);
	printf("%s\n",es_aprobado(i)? "Aprobado":"Desaprobado");


	//--1--
	//char s[]="me gusta el olor a tetas";
	//eliminar_caracter(s,'a');
	//printf("%s\n",s);
	
	//--2--
	//int m[N][N]={{2,0,0},
	//	   		 {0,1,0},
	//	   		 {0,0,1}};
	//printf("%s\n",es_identidad(m,2)? "Es identidad":"No es identidad");

	//--3--

}