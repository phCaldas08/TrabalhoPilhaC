#include<stdio.h>
#include<string.h>

#define TAMANHO_INFIXA 30

int main(){
	char formulaInfixa[TAMANHO_INFIXA], formulaPosfixa[TAMANHO_INFIXA], pilhaOperadores[TAMANHO_INFIXA], ultimoOperador = ' ';
	int i, indexOperadores = 0, indexPosfixa = 0;
	
	gets(formulaInfixa);
	
	for(i = 0; i < strlen(formulaInfixa); i++){		
		if(isdigit(formulaInfixa[i]))
			formulaPosfixa[indexPosfixa++] = formulaInfixa[i];
		else{
			switch(formulaInfixa[i]){
				case '+':
				case '-':
					while(indexOperadores != 0){
						ultimoOperador = pilhaOperadores[--indexOperadores];
						formulaPosfixa[indexPosfixa++] = ultimoOperador;						
					}
					break;
					
				case '/':
				case '*':
					if(indexOperadores != 0){	
						ultimoOperador = pilhaOperadores[--indexOperadores];
												
						if(ultimoOperador != '+' && ultimoOperador != '-')						
							formulaPosfixa[indexPosfixa++] = ultimoOperador;						
						else
							pilhaOperadores[indexOperadores++] = ultimoOperador;
					}					
					break;
			}			
			pilhaOperadores[indexOperadores ++] = formulaInfixa[i];
		}		
	}	
	
	if(strlen(pilhaOperadores) > 0)
		for(i = strlen(pilhaOperadores) - 1; i >= 0 ; i--)
			formulaPosfixa[indexPosfixa++] = pilhaOperadores[i];		
	
	printf("%s", formulaPosfixa);			
}
