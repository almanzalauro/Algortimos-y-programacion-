/*
Implementá una función que retorne una matriz dinámica, de un tamaño pasado como argumento, 
siendo la misma inicializada con:
	A)ceros,
	B)unos,
	C)la identidad
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

float ** crear_matriz_dinamica(size_t ancho, size_t alto){
	float **m=malloc(alto*sizeof(float*));
	
	if(m==NULL)
		return NULL;

	for(size_t i=0; i<alto; i++){
		m[i]= malloc(ancho*sizeof(float));

		if(m[i]==NULL){
			
			for(size_t i = 0; i < alto; i++)
       			free(m[i]);
   			free(m);
			return NULL;
		}
	}

	return m;
}


void destruir_matriz(float **m, size_t alto) {
    for(size_t i = 0; i < alto; i++)
        free(m[i]);
    free(m);
}


void inicializar_matriz(float **m,size_t ancho, size_t alto,float valor){
	for(size_t f = 0; f < alto; f++)
        for(size_t c = 0; c < ancho; c++)
            m[f][c] = valor;
}


void imprimir_matriz(float**m,size_t ancho, size_t alto){
	for(size_t f = 0; f < alto; f++){
        for(size_t c = 0; c < ancho; c++){
        	printf("%.1f\t",m[f][c]);
        }

    	printf("\n");
	}
}


bool matriz_identidad(float**m,size_t alto,size_t ancho){
	if(alto!=ancho)
		return false;

	for(size_t f=0; f<alto;f++){
		for(size_t c=0; c<ancho;c++)
			if(f==c)
				m[f][c]=1;
			else
				m[f][c]=0;
	}

	return true;

}
int main(void){
	size_t ancho=7, alto=4;
	
	//si quiero inicializar con algun valor especifico
	//float valor=2;
	
	//creo la matriz dinamica y verifico si no me devuelve NULL
	float **m=crear_matriz_dinamica(ancho,alto);
	if(m==NULL)
		return 1;

	//inicializo matriz con valor especifico
	inicializar_matriz(m,ancho,alto,valor);
	
	//incializo la matriz identidad de NxN
	if(matriz_identidad(m,alto,ancho)==false){
		//En caso de ancho!=alto, destruyo la matriz dinamica y cierro programa
		destruir_matriz(m,alto);
		return 1;
	}


	//imprimo y luego destruyo la matriz
	imprimir_matriz(m,ancho,alto);
	destruir_matriz(m,alto);
	return 0;
}