/*
a)Implementá una función que reciba una cadena y retorne una copia de la misma, 
utilizando memoria dinámica, por el nombre. Si por algún motivo no se puede, retornar NULL.

b)Ahora implementá una función equivalente, pero en vez de retornar la copia por el nombre, 
que lo haga por la interfaz, mientras que por el nombre retorna un estado, bool, 
indicando el resultado de la operación.
*/

#include<stdio.h>
#include<stdlib.h>

char * copiar_cadena(const char * origen){

	size_t i;
	char * d=malloc(sizeof(char));
	if (d==NULL)
		return NULL;
	for(i=0; origen[i];i++)
		d[i]=origen[i];
	d[i]='\0';
	return d;
}

int main(void){
	char s[]="Hola pepe como estas";
	char *d=copiar_cadena(s);
	if (d==NULL)
		return 1;
	printf("%s\n",d);

	free(d);
	return 0;
}