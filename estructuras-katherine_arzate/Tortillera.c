#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

typedef struct cliente{
	int kg;
	struct cliente* sig;
}cliente;

// Funcion prioridad para acomodar de mayor a menor conforme van entrando los datos

cliente* agregar(int, cliente*);
cliente* atendido(cliente*);
cliente* prioridad(int, cliente*);
void imprimir(cliente*);


int main(){
	cliente* cola = NULL;	
	srand(time(0));
	int mov, i=0, kgReq;
	printf("TORTILLERIA JUANITA\n");
	printf("Ingresa el numero de movimientos que deseas realizar\n");	
	scanf("%d", &mov);
	printf("	opc1: llegada	opc2: atendido\n");
	for(i=0; i<mov; i++){
		int opc = (rand()% 2)+1;
		kgReq = (rand() % 8) + 1;
		if(opc==1){
			printf("opc1: ");
			cola = agregar(kgReq, cola);			
			Sleep(1000);
			imprimir(cola);	
		}else if(opc==2){
			printf("opc2: ");
			if(cola!=NULL){
				cola = atendido(cola);
				Sleep(1000);
				imprimir(cola);
			}else{
				Sleep(1000);
				imprimir(cola);
			}
		}
		
	}
}

cliente* agregar(int x, cliente* cola){
	cliente* aux = cola;
	cliente* nuevo=(cliente*)malloc(sizeof(cliente));
	if(nuevo!=NULL){	//si hay espacio
		nuevo->kg = x;
		if(cola==NULL){
			cola = nuevo;
			nuevo->sig = NULL;			
		}else{
			while(aux->sig != NULL){
				aux=aux->sig;
			}
			aux->sig=nuevo;
			nuevo->sig=NULL;	
		}
	}
	return cola;
}

cliente* atendido(cliente* cola){
	if(cola!=NULL){
		cliente* aux = cola;	
		cola = aux->sig;
		aux->sig = NULL;
		free(aux);
		return cola;	
	}else{
		return cola;
	}	
}

cliente* prioridad(int x, cliente* cola){	
	cliente* aux = cola;
	cliente* inter = NULL;
	cliente* nuevo=(cliente*)malloc(sizeof(cliente));
	if(nuevo!=NULL){
		nuevo->kg = x;
		if(cola==NULL){
			cola = nuevo;
			nuevo->sig = NULL;			
		}else{
			if(x > aux->kg){
				nuevo->sig = aux;
				cola = nuevo;
			}else{
				while(aux->sig->kg > x && aux->sig != NULL){
					aux=aux->sig;
				}			
				if(aux->sig == NULL){
					aux->sig = nuevo;	
				}
				else{
					inter = aux->sig;
					aux->sig = nuevo;
					nuevo->sig = inter;	
				}
			}
		}
	}
	return cola;
}

void imprimir(cliente* cola){
	cliente* aux = cola;
	if(aux!=NULL){
		while(aux != NULL){
			printf("| %d ", aux->kg);
			aux = aux->sig;
		}
		printf("\n");
	}else{
		printf("- No hay clientes pendientes -\n");
	}
}




