#include <stdint.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STR 255

typedef uint8_t pixel_t;

typedef struct {
    pixel_t **pixeles;
    size_t ancho, alto;
} imagen_t;


/*-----FUNCIONES-----*/

imagen_t *_imagen_crear(size_t ancho, size_t alto){
	imagen_t * imagen = malloc(sizeof(imagen_t));
	if(imagen==NULL)
		return NULL;

	imagen->alto=alto;
	imagen->ancho=ancho;

	imagen->pixeles=(pixel_t**)malloc(alto*sizeof(pixel_t*));
	if(imagen->pixeles==NULL){
		free(imagen);
		return NULL;
	}

	for(size_t f = 0;f<alto;f++){
		imagen->pixeles[f]=(pixel_t*)malloc(ancho*sizeof(pixel_t));
		if(imagen->pixeles[f]==NULL){
			free(imagen->pixeles);
			free(imagen);
		}
	}
	return imagen;
}

imagen_t *imagen_generar(size_t ancho, size_t alto, pixel_t valor){
	imagen_t*p=_imagen_crear(ancho,alto);
	if(p==NULL)
		return NULL;
	for (size_t f = 0; f < alto; f++)
	{
		for(size_t c=0; c<ancho;c++)
			p->pixeles[f][c]=valor;
	}
	return p;
}




void imagen_destruir(imagen_t *imagen){
	for(size_t f=0; f<(imagen->alto);f++)
		free(imagen->pixeles[f]);
	free(imagen->pixeles);
	free(imagen);
}

char * remover_barra_n(const char*origen){
	size_t i;
	for(i=0; origen[i];i++);

	char *destino =malloc(i*sizeof(char));
	if(destino==NULL)
		return NULL;

   	for(size_t i=0; origen[i]; i++){
		if(origen[i]!='\n')
			destino[i]=origen[i];
	}

	destino[i-1]='\0';
	
	return destino;
}

imagen_t *imagen_leer_pgm(){

	char aux[MAX_STR];

//--Leo y verifico que el encabezado sea P2
	
	fgets(aux,MAX_STR,stdin);
	char * encabezado=remover_barra_n(aux);
	if(encabezado==NULL){
		return NULL;
	}

	if(strcmp(encabezado,"P2") != 0){
		free(encabezado);
		return NULL;
	}

	

	free(encabezado);

//--Leo alto y ancho y lo paso a numero
	char ancho_str[MAX_STR]={0};
	char alto_str[MAX_STR]={0};
	size_t ancho,alto;
	size_t i,j;

	fgets(aux,MAX_STR,stdin);
	char * anchoxalto=remover_barra_n(aux);
	if(anchoxalto==NULL){
		return NULL;
	}

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

	free(anchoxalto);

//--Creo la imagen con el ancho y alto
	imagen_t *imagen =_imagen_crear(ancho,alto);
	if(imagen==NULL){
		return NULL;
	}

//Leo el valor maximo que puede tener un pixel y lo paso a numero
	fgets(aux,MAX_STR,stdin);

	char * pixel_maximo=remover_barra_n(aux);
	if(pixel_maximo==NULL){
		return NULL;
	}

	size_t pixel_max=atoi(pixel_maximo);
	free(pixel_maximo);	

//Leo cada pixel y lo paso a numero
	size_t f,c;

	for(f=0; f<(imagen->alto);f++){	
		for(c=0; c<(imagen->ancho); c++){
			while(fgets(aux,MAX_STR,stdin)!=NULL){
				
				char*pixel_leido=remover_barra_n(aux);
				if(pixel_leido==NULL){
					return NULL; }

				size_t valor_pixel=atoi(pixel_leido);
				if(valor_pixel>pixel_max){
					free(pixel_leido);
					return NULL;
				}

				imagen->pixeles[f][c]=valor_pixel;
				free(pixel_leido);
				break;
			}
		}
	}
	


	return imagen;

}

void imagen_imprimir_pgm(const imagen_t *imagen){
	printf("P2\n%ld %ld\n255\n",imagen->ancho, imagen->alto);
	for(size_t f=0;f<(imagen->alto);f++){
		for(size_t c=0;c<(imagen->ancho);c++)
			printf("%d\n",imagen->pixeles[f][c]);
	}
}

void imagen_pegar(imagen_t *destino, const imagen_t *origen, int x, int y){
	for(size_t f=0; f<(origen->alto); f++){
		for(size_t c=0; c<(origen->ancho);c++)
			if(origen->pixeles[f][c]!=0){
				destino->pixeles[f+y][c+x]=origen->pixeles[f][c];
			}
	}
	
}

imagen_t *imagen_escalar(const imagen_t *origen, size_t ancho_destino, size_t alto_destino){
	
	imagen_t *destino = _imagen_crear(ancho_destino,alto_destino);
	if(destino==NULL){
		return NULL;
	}

	float escalado_alto,escalado_ancho;
    
    escalado_alto=((float)origen->alto)/((float)alto_destino);
    escalado_ancho=((float)origen->ancho)/((float)ancho_destino);

    for(size_t f=0; f<alto_destino;f++){
        for(size_t c=0; c<ancho_destino;c++){
            destino->pixeles[f][c]=(origen->pixeles)[(size_t)(f*escalado_alto)][(size_t)(c*escalado_ancho)];
        }
    }
	
    return destino;
}


/*-----MAIN-----*/
int main(void) {
    imagen_t *imagen = imagen_generar(640, 480, 255);
    assert(imagen != NULL);

    imagen_t *squirtle = imagen_leer_pgm();
    assert(squirtle != NULL);


 /*   imagen_t *squirtle_chico = imagen_escalar(squirtle, 208, 215);
    assert(squirtle_chico != NULL);
*/
    imagen_t *squirtle_grande = imagen_escalar(squirtle, 834, 862);
    assert(squirtle_grande != NULL);
/*
    imagen_pegar(imagen, squirtle, 10, 10);
    imagen_pegar(imagen, squirtle_chico, 380, 20);
    imagen_pegar(imagen, squirtle_grande, 280, 230);
*/
//    assert(imagen_generar(1UL << 62, 10000, 0) == NULL);

    imagen_imprimir_pgm(squirtle_grande);

    imagen_destruir(imagen);
    imagen_destruir(squirtle);
    //imagen_destruir(squirtle_chico);
    imagen_destruir(squirtle_grande);

    return 0;
}
