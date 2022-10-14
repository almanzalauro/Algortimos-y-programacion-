#include <stdio.h>
#include <stdbool.h>

bool cadenas_iguales(const char s1[], const char s2[]){

	for(size_t i=0; s1[i] && s2[i];i++){
		if(s1[i]!=s2[i]){
			return false;
		}
	}
	return true;
}


int main(void)
{
	char s1[]="hola pepe";
	char s2[]="hola pepe";
	printf("%s\n",cadenas_iguales(s1,s2)? "Son iguales":"No son iguales");
	return 0;
}