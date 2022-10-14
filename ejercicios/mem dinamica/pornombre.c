/*CREAR MATRIZ */
#include<stdio.h>
#include<stdlib.h>


//no hace falta usar el ancho
void destruir_matriz(float **m,/*size_t ancho,*/ size_t alto){
	for(size_t i=0; i<alto; i++)
		free(m[i]);
	free(m);

}

float ** crear_matriz(size_t ancho, size_t alto){
	float **m=malloc(alto*sizeof(float*));
	if(m==NULL)
		return NULL;

	//Pido memoria para cada ancho
	for(size_t i=0; i<alto;i++){
		m[i]=malloc(ancho*sizeof(float));
		//si en algun ancho, no pudo asignar, voy liberando lo que fue creado
		if(m[i]==NULL){
			destruir_matriz(m,i);
			return NULL;
		}
	}

	return m;
}

int main(void){
	float **m=crear_matriz(10,20);
	if(m==NULL)
		return 1;

	for(size_t f=0;f<20;f++)
		for(size_t c=0; c<10; c++)
			m[f][c]=f*c;

	destruir_matriz(m,10);
	return 0;
}