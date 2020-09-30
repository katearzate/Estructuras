#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
	inc_a(1);
	printf("\n");
	inc_b(1);
	printf("\n");
	inc_c(1);
	printf("\n");
	inc_d(1);
	printf("\n");
	inc_e(1);
	printf("\n");
	inc_f(1);
	printf("\n");
	inc_g(1);
	printf("\n");
	inc_i(1);
}


void inc_a(int x){
	int r=(-5*x)+13;
	if(r<-12)
	return;	
	else{
		printf("%d, ", r);
		inc_a(x+1);
	}
}

void inc_b(int x){
	int r= 3*pow(2, x-1);
	if(r>48)
	return;	
	else{
		printf("%d, ", r);
		inc_b(x+1);
	}
}

void inc_c(int x){
	int r=pow(x+1, 2);
	if(r>36)
	return;
	else{
		printf("%d, ", r);
		inc_c(x+1);
	}
}

void inc_d(int x){
	int r=pow(x+1, 2)+1;
	if(r>50)
	return;
	else{
		printf("%d, ", r);
		inc_d(x+1);
	}
}

void inc_e(int x){
	int r=pow(x+1, 2)+2;
	if(r>51)
	return;
	else{
		printf("%d, ", r);
		inc_e(x+1);
	}
}

void inc_f(int x){
	int r=pow(x+1, 2)-1;
	if(r>50)
	return;
	else{
		printf("%d, ", r);
		inc_f(x+1);
	}
}

void inc_g(int x){
	int r=pow(-1, x)*pow(x+1, 2);
	if(r>49)
	return;
	else{
		printf("%d, ", r);
		inc_g(x+1);
	}
}



void inc_i(int x){
//	int r=(3*x-1)/pow(x+1, 2);
	if(r>14/36)
	return;
	else{
		printf("%d, ", r);
		inc_i(x+1);
	}

}



