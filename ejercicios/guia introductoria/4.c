/*horas,minutos, segundos a segundo*/

#include <stdio.h>

float convertir(int horas, int minutos,int segundos){
	float resultado=0;

	resultado = horas*3600 + minutos*60 + segundos;
	return resultado;
}

int main(){

	printf("%.2f\n",convertir(2,4,45));
	return 0;
}
