#include <stdio.h>
#include <stdlib.h>
#define LADO 5

void imprimir(int [][LADO], int, int);
void acomodar(int [][LADO]);

int main(int argc, char *argv[]) {
	int array[LADO][LADO]= {
		{3  ,6  ,5  ,4  ,11 },
		{12 ,1  ,2  ,15 ,10 },
		{91 ,31 ,211,14 ,65 },
		{21 ,13 ,61 ,8  ,9  },
		{16 ,17 ,18 ,271,7  }};
	
	imprimir(array, 0, 0);	
	acomodar(array);		
	printf("\n");		
	imprimir(array, 0, 0);	
	return 0;
}

void imprimir(int array[][LADO], int c1, int c2){
	if(c1<LADO){
		if(c2<LADO){
			printf("%5d", array[c1][c2]);
			imprimir(array, c1, c2+1);
		}else{		
		printf("\n");
		imprimir(array, c1+1, c2=0);
		}
	}else{
		return;
	}
}

void acomodar(int array[][LADO]){
	int i, j, l, k, aux;
	for(l=0; l<LADO; l++){
		for(j=0; j<LADO; j++){
			for(i=0; i<LADO; i++){
				for(k=0; k<LADO; k++){
					if(array[l][j] < array[i][k]){
						aux = array[l][j];
						array[l][j] = array[i][k];
						array[i][k] = aux;					
					}
				}
			}
		}
	}	
}





