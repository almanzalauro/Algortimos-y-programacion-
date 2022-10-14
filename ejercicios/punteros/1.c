//SWAP de numeros

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void swap(int *a, int *b){
	int aux=*a;
	*a=*b;
	*b=aux;
}

int main(void){
	
	int a = 1, b = 2;
	swap(&a, &b);
	printf("%d %d\n",a,b);

 
	return 0;

}