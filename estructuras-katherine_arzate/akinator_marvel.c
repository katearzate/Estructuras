#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int id;
	char* pg[30];
	struct nodo* izq;
	struct nodo* der;
}nodo;

nodo* push(nodo*, int, char[]);
void imprimirPre(nodo*);
void recorridoManual(nodo*);
	
int main(int argc, char *argv[]) {
	nodo* raiz = NULL;
	raiz = push(raiz, 2, "eres hombre");
	raiz = push(raiz, 1, "ashley");
	raiz = push(raiz, 3, "kate");
	printf("Recorrido en pre-orden: ");
	imprimirPre(raiz);
	//recorridoManual(raiz);
	return 0;
}

nodo* push(nodo* raiz, int dato, char pregunta[30]){
	if(raiz == NULL){
		raiz = (nodo*)malloc(sizeof(nodo));
		if(raiz != NULL){
			raiz->id = dato;
			raiz->pg[0]= pregunta;
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
		else{
			printf("Dato repetido");
			return raiz; 
		}
	}
	return raiz;	
}

void imprimirPre(nodo* raiz){
	if(raiz != NULL){
		printf("%d, ", raiz->id);
		imprimirPre(raiz->izq);	
		imprimirPre(raiz->der);
	}else{
		return;
	}
}

void recorridoManual(nodo* raiz){
	int direccion;
	if(raiz->der != NULL || raiz->izq != NULL){
		printf("%s", *(raiz->pg));
		printf("\n1: si \n2: no"); 
		scanf("%d", &direccion);
		if(direccion == 1){
			recorridoManual(raiz->izq);
		}else {
			recorridoManual(raiz->der);
		}
		if(direccion != 1 || direccion != 2){
			printf("\nnumero incorrecto, ingrese 1 o 2");
			recorridoManual(raiz);	
		}	
	}
	printf("\ntu personaje es %s\n", *(raiz->pg));
	exit(0);
}
