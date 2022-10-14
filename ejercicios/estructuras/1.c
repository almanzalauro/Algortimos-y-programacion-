/*1.
A) Una estructura para manejar inventarios que contenga un campo para la descripción 
del producto (máximo 30 caracteres), 
un número para el número de parte en el inventario, 
un punto flotante para el precio, 
un entero para la cantidad que hay en el almacén 
y un entero para el lugar donde se almacena.

B) Una estructura para manejar una dirección física que contiene arreglos para 
el país (máximo 40 caracteres), 
la provincia (máximo 30 caracteres), 
la ciudad (máx. 20)
la dirección (máx. 30) 
y el código postal (10).
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct {
	char descripcion[30];
	size_t num_inventario;
	float precio;
	int cantidad;
	int lugar_almacenamiento;
}inventario_t;

typedef struct{
	char * pais;
	char * provincia;
	char * ciudad;
	char * direccion;
	char * cod_postal;
}direccion_fisica_t;

void ingresar_cadena(char * ciudad,size_t tamanio){
	fgets(ciudad,tamanio,stdin);
}

direccion_fisica_t * crear_direccion(){
	direccion_fisica_t * d=malloc(sizeof(direccion_fisica_t));
	if(d==NULL)
		return NULL;

	d->pais = malloc(40 * sizeof(char));
	if(d->pais == NULL){
		free(d);
		return NULL;
	}

	d->provincia = malloc(30 * sizeof(char));
	if(d->provincia==NULL){
		free(d->pais);
		free(d);
		return NULL;
	}	

	d->ciudad = malloc(20 * sizeof(char));
	if(d->ciudad==NULL){
		free(d->provincia);
		free(d->pais);
		free(d);
		return NULL;
	}	

	d->direccion = malloc(30 * sizeof(char));
	if(d->direccion==NULL){
		free(d->provincia);
		free(d->pais);
		free(d);
		return NULL;
	}	
	
	d->cod_postal = malloc(10 * sizeof(char));
	if(d->direccion==NULL){
		free(d->direccion);
		free(d->provincia);;
		free(d->pais);
		free(d);
		return NULL;
	}	

	return d;
}


int main(void){

	direccion_fisica_t * d = crear_direccion();
	ingresar_cadena(d->pais,40);
	ingresar_cadena(d->provincia,30);
	ingresar_cadena(d->ciudad,20);
	ingresar_cadena(d->direccion,30);
	ingresar_cadena(d->cod_postal,10);

	printf("\n%s%s%s%s%s",d->pais,d->provincia,d->ciudad,d->direccion,d->cod_postal);
	free(d->cod_postal);
	free(d->direccion);
	free(d->ciudad);
	free(d->provincia);	
	free(d->pais);
	free(d);

	return 0;
}

