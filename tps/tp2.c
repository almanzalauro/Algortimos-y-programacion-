#include <stdio.h>
#include <stdint.h>

#define MAXIMO 15

typedef uint8_t pixel_t;

#define ANCHO_IMAGEN 160
#define ALTO_IMAGEN 120

#define ANCHO_PEPE 46
#define ALTO_PEPE 38

/*----PROTOTIPOS DE FUNCIONES----*/
void inicializar_imagen(size_t ancho, size_t alto, pixel_t imagen[alto][ancho], pixel_t valor){
    for(size_t i=0; i<alto;i++){
        for(size_t j=0; j<ancho;j++){
            imagen[i][j]=valor;
        }
    }
}

void imprimir_pgm(size_t ancho, size_t alto, pixel_t imagen[alto][ancho]){
    printf("P2\n%zd %zd\n%d\n",ancho,alto,MAXIMO);
    for(int i=0; i<alto;i++){
        for(int j=0; j<ancho;j++){
            printf("%d\n",imagen[i][j]);
        }
    
    }   
}


void pegar_imagen(
        size_t ancho_destino, size_t alto_destino, pixel_t destino[alto_destino][ancho_destino],
        size_t ancho_origen, size_t alto_origen, pixel_t origen[alto_origen][ancho_origen],
        int x, int y){

    for(int i=0; i<alto_origen; i++){
        for(int j=0; j<ancho_origen;j++){
            
            if(origen[i][j]!=0){
                if((i+y)>=0 && (j+x)>=0){
                    destino[i+y][j+x]=origen[i][j];
                }
            }
        }
    }
}

void escalar_imagen(
        size_t ancho_destino, size_t alto_destino, pixel_t destino[alto_destino][ancho_destino],
        size_t ancho_origen, size_t alto_origen, pixel_t origen[alto_origen][ancho_origen]){
        
    float escalado_alto,escalado_ancho;
    
    escalado_alto=((float)alto_origen)/((float)alto_destino);
    escalado_ancho=((float)ancho_origen)/((float)ancho_destino);
    
    for(size_t i=0; i<alto_destino;i++){
        for(size_t j=0; j<ancho_destino;j++){
            destino[i][j]=origen[(size_t)(i*escalado_alto)][(size_t)(j*escalado_ancho)];
        }
    }
    
}

pixel_t pepe[ALTO_PEPE][ANCHO_PEPE] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 6, 6, 6, 6, 6, 6, 2, 3, 0, 0, 0, 0, 2, 2, 6, 6, 6, 2, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 3, 0, 0, 3, 6, 6, 6, 6, 6, 6, 6, 6, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 2, 2, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 3, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 1, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 2, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 1, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 2, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 1, 6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 3, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 1, 1, 1, 1, 1, 1, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 3, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 3, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 1, 1, 1, 6, 6, 6, 6, 6, 1, 6, 6, 6, 6, 1, 1, 1, 1, 1, 1, 1, 6, 6, 3, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 2, 6, 6, 8, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 1, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 1, 1, 6, 3, 0, 0},
    {0, 0, 0, 0, 0, 0, 2, 2, 6, 6, 6, 9, 6, 6, 6, 6, 6, 6, 6, 6, 6, 2, 2, 2, 2, 2, 2, 2, 2, 6, 6, 6, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 6, 6, 2, 0},
    {0, 0, 0, 0, 0, 3, 6, 6, 6, 6, 6, 9, 6, 6, 6, 6, 6, 6, 6, 2, 3, 12, 12, 12, 12, 12, 12, 12, 12, 2, 2, 2, 12, 12, 12, 12, 12, 12, 12, 12, 12, 2, 2, 2, 2, 0},
    {0, 0, 0, 0, 2, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 2, 2, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 3, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 3, 0},
    {0, 0, 0, 0, 2, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 2, 12, 12, 12, 12, 12, 12, 2, 2, 12, 12, 12, 12, 12, 3, 12, 13, 13, 13, 13, 13, 12, 2, 2, 12, 13, 13, 12, 12, 3},
    {0, 0, 0, 3, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 2, 12, 12, 12, 12, 12, 12, 2, 2, 12, 12, 12, 12, 12, 2, 12, 13, 13, 13, 13, 13, 12, 2, 2, 12, 13, 13, 12, 12, 3},
    {0, 0, 0, 2, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 2, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 3, 12, 13, 13, 13, 13, 13, 13, 12, 12, 13, 13, 13, 12, 4, 0},
    {0, 0, 2, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 3, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 3, 12, 12, 12, 13, 13, 13, 13, 13, 13, 13, 12, 12, 12, 4, 0, 0},
    {0, 0, 2, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 2, 2, 2, 12, 12, 12, 12, 12, 12, 12, 12, 1, 2, 2, 2, 12, 12, 12, 12, 12, 12, 12, 2, 2, 3, 0, 0, 0},
    {0, 2, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 2, 2, 2, 2, 2, 2, 1, 1, 1, 6, 6, 6, 2, 2, 2, 2, 2, 2, 2, 5, 2, 0, 0, 0, 0},
    {0, 2, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 1, 1, 6, 6, 1, 6, 6, 6, 6, 6, 6, 6, 5, 3, 0, 0, 0, 0, 0},
    {2, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 1, 1, 6, 6, 6, 6, 6, 1, 1, 1, 1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0},
    {2, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 8, 6, 6, 6, 6, 6, 6, 6, 1, 1, 1, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 3, 0, 0, 0, 0, 0},
    {2, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 9, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 3, 0, 0, 0, 0},
    {2, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 9, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 2, 0, 0, 0, 0},
    {2, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 9, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 3, 0, 0, 0},
    {2, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 2, 0, 0, 0},
    {2, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 1, 2, 0, 0, 0},
    {2, 6, 6, 6, 8, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 1, 1, 1, 1, 1, 1, 1, 1, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 1, 1, 1, 7, 7, 3, 0, 0},
    {0, 2, 6, 6, 9, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 1, 6, 6, 6, 6, 6, 6, 6, 6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 6, 6, 7, 7, 7, 3, 0, 0},
    {0, 2, 6, 6, 9, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 1, 7, 1, 1, 1, 1, 1, 1, 1, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 1, 1, 1, 3, 0, 0, 0},
    {0, 0, 3, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 1, 6, 7, 7, 7, 7, 7, 7, 6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 6, 6, 2, 0, 0, 0, 0},
    {0, 0, 0, 3, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 1, 1, 1, 1, 1, 1, 1, 1, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 2, 0, 0, 0, 0},
    {0, 0, 0, 0, 2, 2, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 3, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 3, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 3, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 2, 2, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 1, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};


int main(void) {
    pixel_t imagen[ALTO_IMAGEN][ANCHO_IMAGEN];

    inicializar_imagen(ANCHO_IMAGEN, ALTO_IMAGEN, imagen, MAXIMO);

    pegar_imagen(ANCHO_IMAGEN, ALTO_IMAGEN, imagen, ANCHO_PEPE, ALTO_PEPE, pepe, 60, 40);
    pegar_imagen(ANCHO_IMAGEN, ALTO_IMAGEN, imagen, ANCHO_PEPE, ALTO_PEPE, pepe, 140, 40);
    pegar_imagen(ANCHO_IMAGEN, ALTO_IMAGEN, imagen, ANCHO_PEPE, ALTO_PEPE, pepe, -20, 40);
    pegar_imagen(ANCHO_IMAGEN, ALTO_IMAGEN, imagen, ANCHO_PEPE, ALTO_PEPE, pepe, 60, 100);
    pegar_imagen(ANCHO_IMAGEN, ALTO_IMAGEN, imagen, ANCHO_PEPE, ALTO_PEPE, pepe, 60, -20);

    pixel_t escalada1[19][23];
    escalar_imagen(23, 19, escalada1, ANCHO_PEPE, ALTO_PEPE, pepe);
    pegar_imagen(ANCHO_IMAGEN, ALTO_IMAGEN, imagen, 23, 19, escalada1, 10, 10);

    pixel_t escalada2[60][60];
    escalar_imagen(60, 60, escalada2, ANCHO_PEPE, ALTO_PEPE, pepe);
    pegar_imagen(ANCHO_IMAGEN, ALTO_IMAGEN, imagen, 60, 60, escalada2, 100, 80);

    imprimir_pgm(ANCHO_IMAGEN, ALTO_IMAGEN, imagen);

    return 0;
}