#include <stdint.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STR 255



char* remover_barra_n(const char*origen){
	size_t i;
	for(i=0; origen[i];i++);
	char * destino = malloc(sizeof(char)*i);
	if(destino==NULL)
		return NULL;
   	for(size_t i=0; origen[i];i++){
		if(origen[i]!='\n')
			destino[i]=origen[i];
	}
	destino[i-1]='\0';
	return destino;

}


int main (void){

	char aux[MAX_STR];

	fgets(aux,MAX_STR,stdin);
	char * encabezado=remover_barra_n(aux);

	printf("resultado: %d\n", strcmp(encabezado,"P22"));

	free(encabezado);
	return 0;
}


/*
int main(void){
	char aux[MAX_STR];

//LEO EL ENCABEZADO
	fgets(aux,MAX_STR,stdin);
	char * encabezado=remover_barra_n(aux);
	if(encabezado==NULL){
		return NULL;
	}

	if(strcmp(encabezado,"P2")!=0){
		free(encabezado);
		return NULL;
	}
	
	free(encabezado);





//LEO ANCHO Y ALTO
	char ancho_str[MAX_STR]={0};
	char alto_str[MAX_STR]={0};
	size_t ancho,alto;
	size_t i,j;

	fgets(aux,MAX_STR,stdin);
	char * anchoxalto=remover_barra_n(aux);
	printf("%s\n",anchoxalto);

	
	for(i=0; anchoxalto[i]!=' '; i++){
		ancho_str[i]=anchoxalto[i];
	}
	ancho_str[i]='\0';

	for(j=i+1;anchoxalto[j];j++){
		alto_str[j-i-1]=anchoxalto[j];
	}
	alto_str[j]='\0';

	alto=atoi(alto_str);
	ancho=atoi(ancho_str);
	printf("%ld\n%ld\n",ancho,alto);

	free(anchoxalto);
	
//LEO EL MAXIMO PIXEL POSIBLE
	fgets(aux,MAX_STR,stdin);
	char * pixel_maximo=remover_barra_n(aux);

	size_t pixel_max=atoi(pixel_maximo);

	printf("Pixel max: %ld\n",pixel_max);
	free(pixel_maximo);
	return 0;

}*/