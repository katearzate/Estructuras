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
//void desencriptar(char mensaje[max],int saltos);



//Funcion para cifrar el mensaje
void encriptar(char *mensaje, char *resultado, int saltos) {
  int i = 0;
  while (mensaje[i]) {
    char caracterActual = mensaje[i];
    int posicionOriginalAscii = (caracterActual);	//ord: numero de codigo ascii del caracter
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
    i++;
  }
}

int main(){
	char mensaje[max], mensajeCifrado[max];
	int saltos;
	
	printf(" ********** CIFRADO DE CESAR ************ \n");
	
	printf("Escribe un mensaje para cifrar: \n");
	fgets(mensaje, max, stdin);
    mensaje[strcspn(mensaje, "\r\n")] = 0;		//strcspn: devuelve la longitud de la cadena 
	
	printf("Número de saltos: \n");
	scanf("%d", &saltos);
	
	printf("El mensaje original es: %s\n", mensaje);
	encriptar(mensaje, mensajeCifrado, saltos);
	
	//printf("%d", mensaje[0]); //muestra codigo ascii
}
