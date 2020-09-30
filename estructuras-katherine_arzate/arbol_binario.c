#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int id;
	struct nodo* izq;
	struct nodo* der;
}nodo;

nodo* push(nodo*, int);
void imprimirPre(nodo*);
void imprimirIn(nodo*);
void imprimirPost(nodo*);
void recorridoManual(nodo*);
	
int main(int argc, char *argv[]) {
	nodo* raiz = NULL;
	raiz = push(raiz, 5);
	raiz = push(raiz, 1);
	raiz = push(raiz, 3);
	raiz = push(raiz, 4);
	raiz = push(raiz, 8);
	raiz = push(raiz, 2);
	raiz = push(raiz, 6);
	printf("Recorrido en pre-orden: ");
	imprimirPre(raiz);
	printf("\n\nRecorrido en in-orden: ");
	imprimirIn(raiz);
	printf("\n\nRecorrido en post-orden: ");
	imprimirPost(raiz);	
	recorridoManual(raiz);
	return 0;
}

nodo* push(nodo* raiz, int dato){
	if(raiz == NULL){
		raiz = (nodo*)malloc(sizeof(nodo));
		if(raiz != NULL){
			raiz->der = NULL;
			raiz->izq = NULL;
			raiz->id = dato;
			return raiz;
		}else{
			printf("ya no hay espacio");
		}		
	}
	else{
		if(dato < raiz->id){
			raiz->izq = push(raiz->izq, dato);
		}
		else if(dato > raiz->id){
			raiz->der = push(raiz->der, dato);
		}
		else{
			printf("Dato repetido");
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
void imprimirIn(nodo* raiz){
	if(raiz != NULL){
		imprimirIn(raiz->izq);
		printf("%d, ", raiz->id);	
		imprimirIn(raiz->der);
	}else{
		return;
	}
}

void imprimirPost(nodo* raiz){
	if(raiz != NULL){
		imprimirPost(raiz->izq);	
		imprimirPost(raiz->der);
		printf("%d, ", raiz->id);
	}else{
		return;
	}
}

void recorridoManual(nodo* raiz){
	int direccion;
	if(raiz->der != NULL || raiz->izq != NULL){
		printf("\n\nTu numero es < o > que %d?\n1: menor \n2: mayor\n", raiz->id);
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
	printf("\ntu numero es %d\n", raiz->id);
	exit(0);
}
