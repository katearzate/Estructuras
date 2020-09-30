#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	struct nodo* izq;
	struct nodo* der;
	char* pg[60];
	int id;
}nodo;

void menu();
nodo* importa(nodo*, int);
void exporta(nodo*);
void exporta_rec(FILE*, nodo*);
nodo* push(nodo*, int, char*);
void imprimirPre(nodo*);
void recorridoManual(nodo*);

int main(int argc, char *argv[]) {
	menu();
	//imprimirPre(raiz);
	return 0;
}

void menu(){
	nodo* raiz = NULL;
	int op; 
	printf("---------------- AKINATOR -----------------\n\n");
    printf("1. Cargar del universo de Marvel \n");
    printf("2. Cargar de Pokemon \n");
    printf("3. Jugar \n");
    printf("4. Salir \n");
	printf("---------------------------------------------\n");    
	MENUCITO:
	scanf("%d", &op);
		switch(op){
			case 1:
				raiz = importa(raiz, 1);
				goto MENUCITO;
				break;
			case 2:
				raiz = importa(raiz, 2);
				goto MENUCITO;
				break;
			case 3:
				if(raiz == NULL)
					printf("No se ha cargado ningun archivo");
				recorridoManual(raiz);
				goto MENUCITO;
				break;
			case 4:
				exit(1);
				break;
			default:
				while(getchar() != '\n');
				menu();
				break;
		}	
}

nodo* push(nodo* raiz, int dato, char* pregunta){
	if(raiz == NULL){
		raiz = (nodo*)malloc(sizeof(nodo));
		if(raiz != NULL){
			strncpy(raiz->pg, pregunta, 50);
			raiz->id = dato;
			raiz->der = NULL;
			raiz->izq = NULL;
			return raiz;
		}else{
			printf("ya no hay espacio");
		}		
	}
	else{
		if(dato < raiz->id){
			raiz->izq = push(raiz->izq, dato, pregunta);
			return raiz;
		}
		else if(dato > raiz->id){
			raiz->der = push(raiz->der, dato, pregunta);
			return raiz;
		}
	}
	return raiz;	
}

void recorridoManual(nodo* raiz){
	int direccion;
	if(raiz->der != NULL || raiz->izq != NULL){	
		printf("%s", raiz->pg);
		printf("	1: si	2: no\n   3: salir\n"); 
		scanf("%d", &direccion);
		switch(direccion){
			case 1:
				recorridoManual(raiz->izq);
				break;
			case 2:
				recorridoManual(raiz->der);
				break;
			case 3: 
				return;
				break;
			default:
				while(getchar() != '\n');
				printf("Dato erroneo! ingrese 1 o 2\n\n");
				recorridoManual(raiz);
				break;
		}	
	}		
	printf("\ntu personaje es %s\n", raiz->pg);
	exit(0);
}


void imprimirPre(nodo* raiz){
	exporta(raiz);
	if(raiz != NULL){
		printf("%d, ", raiz->id);
		imprimirPre(raiz->izq);	
		imprimirPre(raiz->der);
	}else{
		return;
	}
}

void exporta(nodo* raiz){
	FILE *archivo;
	char nombre[50];
	int id;
	archivo = fopen("marvel.txt", "w+");
	while(!feof(archivo)){	
		fscanf(archivo, "%d\n", &id);
		fgets(nombre, 60, archivo);
		printf("%d %s", id, nombre);
		
	}
	fclose(archivo);
}


void exporta_rec(FILE* archivo, nodo* raiz){
    if(raiz!=NULL)
    {
		fprintf(archivo, "%d %s\n", raiz->id, raiz->pg);
        exporta_rec(archivo, raiz->izq);
        exporta_rec(archivo, raiz->der);
    }
}

nodo* importa(nodo* raiz, int x){
	FILE* archivo;
	char nombre[60];
	int id;
	switch(x){
		case 1:
			archivo = fopen("marvel.txt", "r+");
			break;
		case 2: 
			archivo = fopen("pokemon.txt", "r+");
			break;
		default:
			break;
	}
	while(!feof(archivo)){	
		fscanf(archivo, "%d\n", &id);
		fgets(nombre, 60, archivo);
		raiz = push(raiz, id, nombre);
	}
	fclose(archivo);
	return raiz;
}



