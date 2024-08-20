/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//declaraciones de funciones
void parteDecimalFlotante(float num);
void imprimirFecha();


//Recibe un numero y retorna su parte entera y decimal
void parteDecimalFlotante(float num){

    int parte_entera = (int)num;
    float parte_decimal = num - parte_entera;

    printf("Parte entera: %d\n", parte_entera);
    printf("Parte decimal: %.5f\n", parte_decimal); 
    
}

//Imprime la fecha actual
void imprimirFecha(){
    
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    
    printf("Fecha y hora actual: %02d:%02d:%04d %02d:%02d:%02d\n",
           tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, 
           tm.tm_hour, tm.tm_min, tm.tm_sec);

}

int main(int argc, char *argv[])
{
    // valdicion de cantidad de argumentos
    
    if(argc != 2){
        printf("No parameters are given");
        return 1;
    }
    //leemos y convertimos a float

    float valFloat;  
    valFloat = atof(argv[1]);
    
    parteDecimalFlotante(valFloat);
    imprimirFecha();
    
    
    
    return 0;
}