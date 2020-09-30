#include <stdio.h>
#include <stdlib.h>
#define PI 3.1416

void areaCuadro(int, int *);
void areaRectan(int, int, int *);
void areaTrian(float, int, float *);
void areaCirc(int, float *);
void areaTrap(float, int, int, float *);

int main(int argc, char *argv[]) {
	int a=3, b=5, c=8, res=0;
	float rest=0, aa=3;
	printf("AREAS\n");
	areaCuadro(a, &res);
	printf("Resultado del cuadrado es = %d\n", res);
	areaRectan(a, b, &res);
	printf("Resultado del rectangulo es = %d\n", res);	
	areaTrian(aa, b, &rest);
	printf("Resultado del triangulo es = %.2f\n", rest);
	areaCirc(a, &rest);
	printf("Resultado del circulo es = %.2f\n", rest);
	areaTrap(aa, b, c, &rest);
	printf("Resultado del trapecio es = %.2f\n", rest);
	
}

	void areaCuadro(int a, int *res){
		*res = a*a;
	}
	
	void areaRectan(int a, int b, int *res){
		*res = a*b;
	}
	
	void areaTrian(float aa, int b, float *rest){
		*rest = aa*b/2;
	}
	
	void areaCirc(int a, float *rest){
		*rest = PI*a*a;
	}
	
	void areaTrap(float aa, int b, int c, float *rest){
		*rest = (b+c)*aa/2;
	}
