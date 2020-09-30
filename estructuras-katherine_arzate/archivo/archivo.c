#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	FILE *archivo;
	char caracteres[50];
	archivo = fopen("prueba.txt", "r");
	
	printf("Su contenido es: \n\n");
	while(!feof(archivo)){	
		fgets(caracteres, 50, archivo);
		strtok(caracteres, "Ho\n");
		puts(caracteres);
	}
	fclose(archivo);
	
	
	/*
	if(archivo == NULL)
		exit(1);
	else{
		printf("\n El contenido del archivo de prueba es ");
		while(feof(archivo) == 0)
		{
			fgets(caracteres, 50, archivo);
		//	strtok(caracteres, "\n");
			printf("%s", caracteres);
		}
			system("PAUSE");
	}
	fclose(archivo);*/
	return 0;
}
