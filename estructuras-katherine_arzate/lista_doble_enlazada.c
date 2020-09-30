#include <stdio.h>
#include <stdlib.h>

typedef struct nodos {
	int id;
	struct nodo* sig;
	struct nodo* ant;
}nodo;

nodo* altaI(int, nodo*);
nodo* altaF(int, nodo*);
nodo* altaM(int, nodo*);
void imprimirSig(nodo*);
void imprimirAnt(nodo*);

int main(int argc, char *argv[]) {
	nodo* raiz = NULL;
	raiz = altaI(8, raiz);	
	raiz = altaI(3, raiz);
	raiz = altaI(6, raiz);
	raiz = altaI(4, raiz);
	raiz = altaF(2, raiz);
	imprimirSig(raiz);
	imprimirAnt(raiz);
	
	
	return 0;
}


nodo* altaI(int x, nodo* raiz){
	nodo* nuevo= (nodo*)malloc(sizeof(nodo));
	if(nuevo!=NULL){
		nuevo->id=x;
		if(raiz==NULL){
			raiz=nuevo;		
			nuevo->sig=NULL;
			nuevo->ant=NULL;
		}else if(raiz!=NULL){
			nuevo->sig=raiz;
			raiz->ant=nuevo;
			raiz=nuevo;
		}
	}
	return raiz;	
}

nodo* altaF(int x, nodo* raiz){
	nodo* aux=raiz;
	if(raiz==NULL){
		raiz = altaI(x, raiz);
		return raiz;
	}
	while(aux->sig!=NULL){
		aux=aux->sig;
	}
	nodo* nuevo=(nodo*)malloc(sizeof(nodo));
	if (nuevo!=NULL){
		nuevo->id=x;
		nuevo->ant=aux;
		aux->sig=nuevo;
		nuevo->sig=NULL;	
	}
	return raiz;
}


void imprimirSig(nodo* raiz){
	nodo* aux=raiz;
	while(aux!=NULL){
		printf("|%d| - ", aux->id);
		aux=aux->sig;
	}
	printf("\n");
}

void imprimirAnt(nodo* raiz){
	nodo* aux=raiz;
	while(aux->sig!=NULL){
		aux=aux->sig;		
	}
	while(aux->ant!=NULL){
		printf("|%d| - ",aux->id);
		aux=aux->ant;
	}		
	printf("\n");
}


//if(aux->sig->id > elemento && aux->id < elemento)
//nuevo->sig = aux->sig

