#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 4

/*typedef struct tipo_persona{
	char tipo_persona[50];
} tp;*/

typedef struct ejemplo{
	int id;
	char nombre [30];
	struct ejemplo *ptr;			
	//tp tipo;
} nv;

int main(int argc, char *argv[]) {
	nv aux2[TAM], aux1;
	int i, j;
	printf("Ingresa 5 datos: \n\n");
	for (i=0; i<=TAM; i++){
		printf("dame el entero %d\n", i+1);
		scanf("%d", &aux2[i].id);
		printf("dame el nombre %d\n", i+1);
		while (getchar()!='\n');
		fgets(aux2[i].nombre, 20, stdin);
		printf("\n");
	}	
	printf("Registro: \n");
	for(i=0; i<=TAM; i++){
		printf("id = %d | nombre = %s", aux2[i].id, aux2[i].nombre);
	}
	
	for (j=0; j<=TAM-1; j++){
		if(aux2[j].id < aux2[j+1].id){
			aux1 = aux2[j];
			aux2[j] = aux2[j+1];
			aux2[j+1] = aux1;
		}
	}
	printf("\nID acomodados: (mayor a menor)\n");	
	for(i=0; i<=TAM; i++){
		printf("id = %d | nombre = %s", aux2[i].id, aux2[i].nombre);
	}
	
	printf("\nID acomodados: (menor a mayor)\n");		
	for(i=0; i<=TAM; i++){
		printf("id = %d | nombre = %s", aux2[TAM-i].id, aux2[TAM-i].nombre);
	}
	
	return 0;
}
