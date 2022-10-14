/*------ 1 ------
 a. Escribir una función
void left_trim(char cadena[]);
que elimine todos los caracteres de espacio que haya al comienzo de la cadena. 
Por ejemplo, si se le pasara la cadena " hola mundo " después de ejecutar la función la misma deberá 
ser "hola mundo ".
No se permite el uso de funciones de biblioteca en este ejercicio. Todo lo necesario debe ser implementado.
b. Con un pequeño código de ejemplo mostrar cómo utilizar a la función con las cadenas del ejemplo
anterior.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

/* BORRA TODOS LOS ESPACIOS
void left_trim(char cadena[]){
	char aux[256];
	size_t j=0,i;

	for (i=0; cadena[i];i++){
		if(cadena[i]==' ')
			continue;
		else
			{
				aux[j]=cadena[i];
				cadena[j]=aux[j];
				j++;
			}
	}
	cadena[j]='\0';
}*/

void left_trim(char cadena[]){
	size_t i,j;

	for(i=0; cadena[i]==' ';i++);

	for(j=0;cadena[i];j++){
		cadena[j]=cadena[i];
		i++;
	}
	cadena[j]='\0';
}

/*------ 2 ------
Una matriz cuadrada es triangular superior si todos los elementos debajo de su diagonal principal son iguales
a cero.

a. Escribir una función es_triangular_superior que reciba una matriz de flotantes de tamaño N×N y
que retorne si es triangular superior o no.
b. Teniendo #define N 3 escribir un pequeño ejemplo de código que declare y defina una matriz, llame a
la función del punto anterior e imprima un mensaje para el usuario según el resultado.
*/


#define N 2
bool es_triangular_superior(float matriz[][N]){
	bool es_triangular_superior=true;
	size_t i,j;

	for(i=0;i<N;i++){
		for(j=0; j<N; j++){
			if(matriz[i][j]!=0 && i>j)
				return !es_triangular_superior;
		}
	}
	return es_triangular_superior;
}


/*------ 3 ------
Escribir un programa que le pida un número al usuario y que,
de ser posible, le muestre su raíz cuadrada.


char s[256];
	float num;
	
	printf("Ingrese un numero: ");
	fgets(s,256,stdin);
	num=atof(s);
	if (num >= 0)
		printf("La raiz cuadrada es %.2f\n",sqrt(num));
	else printf("La raiz de un negativo no es valida.\n");

*/



int main(void){
	
	/*--3
	float matriz[][N]={{1.2,2.56},{0,0}};
	printf("%s\n",(es_triangular_superior(matriz)?"Es triangular":"No es triangular"));*/
	
	return 0;
}