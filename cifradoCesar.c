/*
 * Implementación de Cifrado de César
 * 
 */

//chr recibe un numero en ascii y lo convierte a su caracter correspondiente

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define max 100
#define long_alfabeto 26
#define inicio_ascii_mayusculas 65
#define inicio_ascii_minusculas 97
#define MOD(i, n) (i % n + n) % n //modulo positivo
			      
const char *alfMinusculas = "abcdefghijklmnopqrstuvwxyz",
           *alfMayusculas = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


void encriptar(char *mensaje, char *resultado, int saltos);
void desencriptar(char *mensaje, char *resultado,int saltos);



void encriptar(char *mensaje, char *resultado, int saltos) {
  //printf("El mensaje encriptado es: ");
  int i = 0;
  while (mensaje[i]) {
    char caracterActual = mensaje[i];
    int posicionOriginalAscii = (caracterActual);	
    if (!isalpha(caracterActual)) {		//isalpha: corresponde a alguna letra
      resultado[i] = caracterActual;
      i++;
      continue; // siguiente iteración.
    }
    if (isupper(caracterActual)) {		//isupper: letra mayuscula
      resultado[i] =
          alfMayusculas[(posicionOriginalAscii - inicio_ascii_mayusculas +
                              saltos) %
                             long_alfabeto];
    } 
    else if (islower(caracterActual)) { //islower: letra minuscula 

      resultado[i] =
          alfMinusculas[(posicionOriginalAscii - inicio_ascii_minusculas +
                              saltos) %
                             long_alfabeto];
    }
    
    //printf("%c", (resultado[i]));
    i++;
  }
}

void desencriptar(char *mensaje, char *resultado, int saltos) {
  int i = 0;
  while (mensaje[i]) {
    char caracterActual = mensaje[i];
    int posicionOriginalAscii = (caracterActual);
    if (!isalpha(caracterActual)) {
      resultado[i] = caracterActual;
      i++;
      continue; 
    }
    if (isupper(caracterActual)) {		//es mayuscula
      resultado[i] = alfMayusculas[MOD(
          posicionOriginalAscii - inicio_ascii_mayusculas - saltos,
          long_alfabeto)];
    } else if (islower(caracterActual)) { 	//es minuscula
      resultado[i] = alfMinusculas[MOD(
          posicionOriginalAscii - inicio_ascii_minusculas - saltos,
          long_alfabeto)];
    }
    i++;
  }
}

int main(){
	char mensaje[max], mensajeCifrado[max], mensajeDescifrado[max];
	int saltos;
	
	printf(" ********** CIFRADO DE CESAR ************ \n");
	printf("Escribe el mensaje para cifrar: ");
	fgets(mensaje, max, stdin);
    mensaje[strcspn(mensaje, "\r\n")] = 0;		//strcspn: devuelve la longitud de la cadena 	
	printf("Número de saltos: ");
	scanf("%d", &saltos);
	
	encriptar(mensaje, mensajeCifrado, saltos);
	printf("\nEl mensaje encriptado es: %s\n", mensajeCifrado);
	
    desencriptar(mensaje, mensajeDescifrado, saltos);
    printf("\nEl mensaje desencriptado es: %s\n", mensajeDescifrado);
	
    
    //printf("%d", mensaje[0]); //muestra codigo ascii
	printf("\n * \n * \n * \n\n");
	main();
	
}
