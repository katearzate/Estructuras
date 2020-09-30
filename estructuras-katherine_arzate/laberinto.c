#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define COLS 10
#define FILAS 8

void imprimir(char laberinto[][COLS], int, int);
void recorrer(char laberinto[][COLS], int, int);

int main() {
	char laberinto[FILAS][COLS] ={{' ','*',' ','*',' ','*',' ',' ',' ',' '},
								  {' ','*',' ',' ',' ','*',' ','*','*',' '},
								  {' ','*',' ','*',' ',' ',' ','*',' ',' '},
								  {' ','*',' ',' ',' ','*',' ','*',' ',' '},
								  {' ',' ',' ','*',' ','*',' ','*',' ','*'},
								  {' ','*',' ',' ',' ',' ',' ','*',' ','*'},
								  {' ','*','*','*','*',' ',' ','*',' ',' '},
								  {' ',' ',' ',' ','*',' ',' ','*',' ','S'}};
	recorrer(laberinto, 0, 0);

	return 0;
}

void imprimir(char laberinto[][COLS], int f, int c){	
	if(f<FILAS){
		if(c<COLS){
			printf("%c ", laberinto[f][c]);
			imprimir(laberinto, f, c+1);
		}else{
			printf("\n");
			imprimir(laberinto, f+1, c=0);
		}		
	}
	else{
		return;
	}
}

void recorrer(char laberinto[][COLS], int f, int c){
	if(laberinto[f][c] == 'S'){
		imprimir(laberinto, 0, 0);
		Sleep(500);
		laberinto[f][c] = 'o';
		system("cls");
		imprimir(laberinto, 0, 0);
		printf("\n\n HA LLEGADO AL DESTINO\n");
		exit(0);
	}else{
		if(laberinto[f][c] == ' ' && 0<=f && 0<=c && f<FILAS && c<COLS){
			imprimir(laberinto, 0, 0);	
			laberinto[f][c] = 'o';		
			Sleep(500);
			system("cls");
			recorrer(laberinto, f, c+1);							
			recorrer(laberinto, f+1, c);							
			recorrer(laberinto, f-1, c);
			recorrer(laberinto, f, c-1);							
		}
	}
}

