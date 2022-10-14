//SEGUNDOS A HORAS MINUTOS Y SEGUNDOS
 
#include<stdio.h>

void a_hms(int segundos, int*hr,int *min, int *seg){

	*hr = segundos/3600;
	*min = (segundos%3600)/60;
	*seg = (segundos%3600)%60;
}

int main(void){

	int horas,minutos,segundos;
	int seg=10000;
	a_hms(seg,&horas,&minutos,&segundos);
	printf("%d segundos equivalen a %d hrs %d min %d seg\n",seg,horas,minutos,segundos);

}