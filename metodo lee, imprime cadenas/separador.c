/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int longitud(const char*);
char** leeSeparaCadena(char*, int);
void imprimeCadenas(char**, int );



int longitud(const char* cad){
    
    int contador =0;
    while(*cad++) contador++;
    
    return contador;
}


char** leeSeparaCadena( char* cad, int largo) {

    // Inicializar x como un array de punteros a char -> referencia https://es.stackoverflow.com/questions/99538/array-dinamico-en-c
    char **x = (char**)malloc((largo + 1) * sizeof(char*));
    char *p = (char*)malloc((largo + 1) * sizeof(char));

    int countP = 0;
    int countX = 0;

    for (int i = 0; i <= largo; i++) {
        if (cad[i] != ' ' && cad[i] != '\0') {
            p[countP] = cad[i];
            countP++;
        } else {
            p[countP] = '\0'; 
            x[countX] = (char*)malloc((countP + 1) * sizeof(char));
            strcpy(x[countX], p);
            countX++;
            countP = 0;
        
        }
    }
    
    return x;
}



void imprimeCadenas(char** cadena, int largo){
       
    for (int i = 0; i < largo; i++) {
        printf("%s\n", cadena[i]);
        
    }

}

int main()
{
    
    char *input = "Esta es una cadena de prueba";
    char **result = leeSeparaCadena(input, longitud(input));
    imprimeCadenas(result, longitud(input));



    return 0;
}