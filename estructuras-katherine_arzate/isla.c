#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define FILA 6
#define COLS 8

void imprimir(char tierra[][COLS], int, int);
void recorrer(char tierra[][COLS], int, int);
void numIslas(char tierra[][COLS], int, int);
int espacios, totEspacios = FILA*COLS, totIslas;

int main(int argc, char *argv[]) {	
		char tierra[FILA][COLS] = { 
			{' ','+',' ',' ',' ',' ',' ',' '},
			{' ','+','+',' ','+','+',' ',' '},
			{' ','+','+',' ',' ','+','+',' '},
			{' ',' ',' ',' ',' ',' ',' ',' '},
			{' ','+',' ','+','+','+',' ',' '},
			{' ','+',' ',' ',' ',' ',' ',' '}									
		};
		recorrer(tierra, 0, 0);
		
	return 0;
}

void imprimir(char tierra[][COLS], int f, int c){	
	if(f<FILA){
		if(c<COLS){
			printf("%c  ", tierra[f][c]);
			imprimir(tierra, f, c+1);
		}else{
			printf("\n\n");
			imprimir(tierra, f+1, c=0);
		}		
	}
	else{
		return;
	}
}

void recorrer(char tierra[][COLS], int f, int c){
	
	if(espacios == totEspacios){
		system("cls");
		imprimir(tierra, 0, 0);
		printf("\nNumero de islas: %d \n", totIslas);
		exit(0);
	}
	
	if(tierra[f][c] == '+' && 0<=f && 0<=c && f<FILA && c<COLS){	
		numIslas(tierra, f, c);
		totIslas++;
	}
	
	if(tierra[f][c] == ' ' && 0<=f && 0<=c && f<FILA && c<COLS){
		espacios++;
		imprimir(tierra, 0, 0);	
		tierra[f][c] = '.';		
		Sleep(100);
		system("cls");			

		recorrer(tierra, f, c+1);							
		recorrer(tierra, f+1, c);							
		recorrer(tierra, f-1, c);
		recorrer(tierra, f, c-1);
	}else return;
}


void numIslas(char tierra[][COLS], int f, int c){
	if(tierra[f][c] == '+' && 0<=f && 0<=c && f<FILA && c<COLS){
		espacios++;
		imprimir(tierra, 0, 0);	
		tierra[f][c] = '*';		
		Sleep(100);
		system("cls");
			
		numIslas(tierra, f, c+1);							
		numIslas(tierra, f+1, c);							
		numIslas(tierra, f-1, c);
		numIslas(tierra, f, c-1);							
	}else return;	
}


