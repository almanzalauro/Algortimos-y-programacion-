#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

//creo la estructura vector 
struct vector {
    int *v;
    size_t n;
};

typedef struct vector vector_t;

/*
typedef struct {
    int *v;
    size_t n;
} vector_t;*/

bool inicializar_vector(vector_t *vector, size_t tamagno) {
    vector->n = tamagno;
    vector->v = malloc(tamagno * sizeof(int));
    if(vector->v == NULL)
        return false;

    return true;
}

void liberar_vector(vector_t *vector) {
    free(vector->v);
}

float promediar_vector(vector_t *vector) {
    int suma = 0;
    for(size_t i = 0; i < vector->n; i++)
        suma += vector->v[i];
    return (float)suma / vector->n;
}

int main(void) {
    vector_t notas;

    if(! inicializar_vector(&notas, 10))
        return 1;

    float promedio = promediar_vector(&notas);
    printf("%.2f\n",promedio);
    liberar_vector(&notas);

    return 0;
}