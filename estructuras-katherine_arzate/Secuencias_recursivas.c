#include <stdio.h>
#include <stdlib.h>


void uno(int);
void dos(int);
void tres(int);

int main(int argc, char *argv[]) {
	uno(1);
	printf("\n\n");
	dos(1);
	printf("\n\n");
	tres(1);
	
	return 0;
}

void tres(int x){
	if(3*x>18)
	return;	
	else{
		printf("%d, ", 3*x);
		tres(x+1);
	}
}

void dos(int x){
	if(2*x>16)
	return;
	else{
		printf("%d, ", 2*x);
		dos(x+1);		
	}
}


void uno(int x){
	if(x>100)
	return;
	else{
		printf("%d, ", x);
		uno(x+1);
	}
}



/*
void serie(int x, int fin){
if(fin>x)
return;
else
	printf("%d ", x) 	en la posicion de x se pone la formula
	serie(2x+4, 1000);
*/
 


