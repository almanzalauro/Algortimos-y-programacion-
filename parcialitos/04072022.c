#include <stdio.h>
#include <stdbool.h>
#include<ctype.h>
/*------1------.
a. Escribir una función
	bool extraer_columna_csv(const char csv[], char sep, size_t ncol, char col[]);

que dada una cadena de caracteres csv (CSV), separada por el separador sep y un número de
columna ncol guarde en la cadena col la columna que corresponda a ese número.
La función devuelve true en caso de funcionar bien, false en caso de falla.
Ejemplo, si se llama a la función con "papas|2kg|55.75" como csv, '|' como sep y 1 como col deberá
devolver "2kg".
Aclaración: No está permitido el uso de funciones de la biblioteca. Todas las necesarias deben ser
implementadas.
b. Dar un mínimo ejemplo de invocación de la función.

papas|2kg|55.75 
ncol=1

*/

bool extraer_columna_csv(const char csv[], char sep, size_t ncol, char col[]){
	
	size_t cant_sep=0, columna=0,j=0;
	/*controlo cuantos sep hay en la cadena, y compruebo que sea menor al numero de columnas*/
	for(size_t i=0; csv[i]!='\0';i++){
		if(csv[i]==sep)
			cant_sep++;
	}

	if(cant_sep<ncol)
		return false;

	for(size_t i=0; csv[i]!='\0';i++){
		if(csv[i]==sep){
			columna++;
			i++;
		}
		if(ncol==columna){
			col[j]=csv[i];
			j++;
		}
	}

	col[j]='\0';
	return true;
}

/*------2-------
a. Escribir una función combinar_filas que reciba:
 una matriz de flotantes de tamaño N×M, 
 dos índices y
 un multiplicador flotante.
La función debe sumarle a la fila indicada por el primer índice, los elementos
de la fila indicada por el segundo índice multiplicados por el multiplicador.
b. Teniendo #define N 3 y #define M 3 escribir un pequeño ejemplo de código que declare y defina una
matriz, y llame a la función del punto anterior.
*/
#define N 2
void combinar_filas(float matriz[][N],size_t indice1,size_t indice2, float multi){
	for (size_t i = 0; i < N; i++)
		matriz[indice1][i]+=matriz[indice2][i]*multi;
	
}


/*-----3------
3. Escribir un programa que cuente la cantidad de caracteres blancos ingresados por stdin. 
Al detectar que no hay más datos a ser leídos se deberá imprimir la cantidad. 
(Nota: para determinar si un carácter es blanco
puede utilizarse la función int isspace(int); de la biblioteca <ctype.h>.)
*/


int main(void){

	char caracter;
	size_t contador=0;

	do
	{	caracter=getchar();
		if(caracter==' ')
		{
			contador++;
		}

	}while(caracter!='0');

	printf("La cantidad de caracteres es: %ld\n",contador);
	
	

	/*1
	char csv[]="papa|2kg|55.75|pera|2kg|12.0";*/
	//char col[]={0};
	//printf("%s\n",extraer_columna_csv(csv,'|',5,col)? col:"error");

	/*2
	float matriz[N][N]={{3,5},
						{1,2}};
	combinar_filas(matriz,1,0,0.5);
	
	for(size_t i=0;i<N;i++){
		for(size_t j=0; j<N;j++){
			printf("%.2f ",matriz[i][j]);
		}
		printf("\n");
	}*/

	return 0;
}