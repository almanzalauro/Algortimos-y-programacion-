/*(matemática) Implementar funciones que reciban un arreglo de números y su longitud y realicen las operaciones detalladas abajo. Utilice notación de punteros exclusivamente.

completar el vector con ceros,

calcular y retornar la suma por la interfaz,

calcular y retornar la media por la interfaz,

calcular y retornar la varianza por la interfaz,

retornar el valor máximo del arreglo por la interfaz,

retornar el valor mínimo del arreglo por la interfaz
*/



#include<stdio.h>

void inicializar_a_cero(int * arreglo, size_t longitud){
	for(size_t i=0; i<longitud;i++){
		arreglo[i]=1;
	}
}

void media(int * arreglo, size_t longitud){

}

/*------------*/
int main(void){
	size_t longit=6;
	int arreglo[longit]={10,25,1,7,3,20}

	inicializar_a_cero(arreglo,longit);
	media(arreglo,longit);
	

	return 0;
}