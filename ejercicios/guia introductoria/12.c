/*---- 12 ----
(búsqueda) Implementar una función que reciba:
	un vector
	su longitud
	un número objetivo a buscar
y retorne un valor booleano indicando si el mismo se encuentra o no.
*/

#include <stdio.h>
#include<stdbool.h>

bool se_encuentra(int vector[],size_t longitud, int num_x){
	size_t contador=0;
	for(size_t i=0; i<longitud;i++){
		if(vector[i]==num_x){
			contador=1;
			continue;
		}		
	}
	return (contador?true:false);
}

int main(void){

	int vector[5]={1,2,3,4,5};
	printf("SE ENCUENTRA=1\nNO SE ENCUENTRA=0\n");
	printf("%d\n",se_encuentra(vector,5,2));
	return 0;
}
