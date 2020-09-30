
#include <stdio.h>
#include <stdlib.h>

int fibo(int x);
int fact(int x);

int main() {
	
	printf("\nEscoja la operacion:\n");
	printf("Opc 1: Factorial\n");
	printf("Opc 2: Sucesion Fibonacci\n");
	printf("Opc 3: Salir: \n");
	int opc, x, y=1, i=1, xx=0, yy=1, z, j=0, fibo=1;
		scanf("%d", &opc);
		switch(opc){
		case 1: 
			printf("El factorial de: \n");
			scanf("%d", &x);
			printf("%d ! = ", x);
			for(i=1; i<(x+1); i++){				
				printf("%d *", i);
				y*=i;
			}
			printf(" = %d\n", y);
		break;
		
		case 2:
			printf("\nNumero de posicion en la sucesion fibonacci: ");
			scanf("%d", &z);
			for(j=0; j<z; j++){
				printf("%d ", fibo);
				fibo=xx+yy;		
				xx=yy;
				yy=fibo;
			}
			printf("\n");
		break;
	
		case 3:
		exit(0);
		default:
			printf("¡numero incorrecto!\n");
			
		}main();

	return 0;
}

//solucion en forma recursiva!
int fibo(int x){
	x=>2? 1: fibo(x-1)+fibo(x-2);
}

int fact (int x){
		if (x==0)
		return 1;		
		else
		return x*fact(x-1);
	}
