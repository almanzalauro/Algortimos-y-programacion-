/*------ 18 ------
Para cada inciso escriba una función que:

A)calcule su traza (suma de los elementos de la diagonal principal), con A NxN

B)dada una matriz NxM y un número, modifique la matriz sumando a cada componente el número recibido,

C)dada una matriz NxM y un número, modifique la matriz mulplicando a cada componente por el número recibido,

D)dada una matriz NxM, modifique dicha matriz cambiándola por su transpuesta,

E)dada una matriz NxM indique si la misma es:
	i) positiva
	ii) no-negativa
	iii) negativa 
	iv) no-positiva. 
Una matriz es positiva (no-negativa) si cumple que todos sus elementos son mayores (mayores o iguales) que cero. Una matriz es negativa (no-positiva) si cumple que todos sus elementos son menores (menores o iguales) que cero

*/
#include<stdio.h>
#include<stdbool.h>
#define N 3
#define M 2

void matriz_transpuesta(int matriz[N][M]){
	for(size_t i=0; i<N; i++){
		for(size_t j=0; j<M; j++){
			if(i!=j){	
				int aux = matriz[j][i];
				matriz[j][i]=matriz[i][j];
				matriz[i][j]=aux;
			}
		}
	}
}

void matriz_transpuesta_2(int matriz[N][M],int matriz_t[M][N]){
	for(size_t i=0; i<N; i++){
		for(size_t j=0; j<M; j++){
			matriz_t[j][i]=matriz[i][j];
		}
	}
}


void imprimir_matriz(int matriz[N][M]){
	for(size_t i=0; i<N;i++){
		for(size_t j=0; j<M; j++){
			printf("%d ",matriz[i][j]);
		}
		printf("\n");
	}
}

void imprimir_matriz_t(int matriz[M][N]){
	for(size_t i=0; i<M;i++){
		for(size_t j=0; j<N; j++){
			printf("%d ",matriz[i][j]);
		}
		printf("\n");
	}
}


int traza_matriz(int matriz[N][M]){
	int suma=0;
	if(N==M){
		for(size_t i=0; i<N; i++){
			for(size_t j=0; j<M; j++){
				if(i==j)
					suma+=matriz[i][j];
			}
		}
	}
	else return 0;
	return suma;
}
void agregar_a_matriz(int matriz[N][M],int num, char operador){

	for(size_t i=0; i<N;i++)
		for(size_t j=0; j<M; j++){
			if(operador=='+'){
				matriz[i][j]+=num;
			}
			else if(operador=='*'){
				matriz[i][j]*=num;	
			} 
		}
}


int main(void){
	int matriz[N][M]={{1,2},
					  {7,5},
					  {9,8}};

	int matriz_t[M][N]={0};
	//printf("La traza es: %d\n",traza_matriz(matriz));
	imprimir_matriz(matriz);
	puts("----");
	matriz_transpuesta_2(matriz,matriz_t);
	imprimir_matriz_t(matriz_t);
}
