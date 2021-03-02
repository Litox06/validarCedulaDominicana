#include <stdio.h>
#include <string.h>
#include <stdlib.h>

  // Escribir un programa que pida al usuario su numero de cedula y determine si la misma es correcta o no aplicando el Algoritmo de luhn
  
int main(){

    int arrCaracteres[11], i, sumaDeDigitos, copiaDeVerificacion, copiaConCero;
    int verificacionCedula = 0;
    int numerosDeLuhn[10] = {1,2,1,2,1,2,1,2,1,2};
    numerosDeLuhn[0] = 1;
    
    printf("Digite su cedula SIN GUIONES: \n");
    char string[11];
    scanf("%s", string);

    while(strlen(string) >= 12 || strlen(string) <11){
      printf("Por favor digite su cedula correctamente \n");
      scanf("%s", string);
    }

    for (int i = 0; i < 10; i++){
      int numActual = string[i] - '0';
      arrCaracteres[i] = numActual;
      numerosDeLuhn[i] = (numerosDeLuhn[i] == 0) ? 1 : numerosDeLuhn[i];

      int resultadoMultLuhn = arrCaracteres[i] * numerosDeLuhn[i];

        if ( resultadoMultLuhn >= 10 ) {
          int num1 = 1;
          int num2 = resultadoMultLuhn % 10; 
          sumaDeDigitos = num1 + num2;

        } else {
          sumaDeDigitos = resultadoMultLuhn;
        }
        verificacionCedula += sumaDeDigitos;
    }

    copiaDeVerificacion = verificacionCedula;
    copiaConCero = copiaDeVerificacion - copiaDeVerificacion % 10;

    if (copiaConCero < copiaDeVerificacion ) {
      copiaDeVerificacion = (copiaConCero + 10) - copiaDeVerificacion; 
    }

    if (string[10] - '0' == copiaDeVerificacion) {

      printf("Cedula valida");

    } else {
      printf("Cedula no valida");

    }
   return 0;
}