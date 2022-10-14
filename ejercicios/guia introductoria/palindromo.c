#include<stdio.h>
#include<stdbool.h>
#include<string.h>

int longitud(const char s[]){
	int i=1;
	for(i=1; s[i];i++);
	return i;
}

bool es_palindroma(const char s[]){
	bool flag;
	for(int i=0; s[i];i++){
		for(int j=(longitud(s)-1); j>=0; j--){
			if(s[i]==s[j]){
				flag=true;
			}
			else{
				flag=false;
			}
		}
	}

	return flag;
}



int main(){

	char s[]="somos o no somos";
	printf("%s\n",es_palindroma(s)? "Es palindroma":"No es palindroma");
	//printf("%d\n",longitud(s));
	return 0;
}