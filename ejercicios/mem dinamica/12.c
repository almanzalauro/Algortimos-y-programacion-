/*Implementá una función que reciba dos vectores de números y 
retorne un nuevo vector con los números de ambos vectores concatenados.*/
#include<stdio.h>
#include<stdlib.h>

int * concatenar_vectores(int * v1, int * v2,size_t max_v,size_t max_b){
	size_t i,j;

	int * aux =malloc(sizeof(int)*(max_v+max_b));
	if(aux==NULL)
		return NULL;

	for(i=0; i<max_v; i++)
		aux[i]=v1[i];

	for(j=0;j<max_b;j++)
		aux[i+j]=v2[j];

	return aux;
}


int main(void){
	int v[3]={1,2,3};
	int b[5]={4,5,6,7,9};

	int * resul = concatenar_vectores(v,b,3,5);
	if(resul==NULL)
		return 1;

	for(size_t i=0; i<(3+5);i++)
		printf("%d  ",resul[i]);
	printf("\n");
	free(resul);
	return 0;
}