/*
Implementá una función similar a la del ejercicio anterior, 
pero en lugar de retornar un nuevo vector, modifica el primero pegándole el segundo.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

bool concatenar_vectores(int * v1, const int * v2,size_t max_v,size_t max_b){
	size_t i;

	int * aux =realloc(v1,max_b);
	if(aux==NULL)
		return false;

	v1=aux;

	for(i=max_v;i<max_b;i++)
		v1[i]=v2[i-max_v];
	v1[i]='\0';
	return true;
}

void mostrar_vector(int*v,int n){
	int i;
	
	for(i=0; i<n; i++){
		printf("%d\t", v[i]);
	}
	printf("\n");
}
int main(void){
	int v[3]={1,2,3};
	int b[5]={4,5,6,7,9};

	if(concatenar_vectores(v,b,3,5)==false)
		return 1;
	mostrar_vector(v,strlen(*v));
	free(v);
	return 0;
}