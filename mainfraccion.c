#include <stdio.h>
#include <stdlib.h>
#include "fraccion.h"

void manejaMsg(int);
void darFracciones(FRACCION, FRACCION);
int numPotencia();
int pro1(int);//aqui llega pro de fraccion.c
void mostrarFraccion(FRACCION, FRACCION, FRACCION, FRACCION, FRACCION);
void liberarMem(FRACCION, FRACCION, FRACCION, FRACCION, FRACCION);

void main( ){
    int n;
    int pro;
    FRACCION F1, F2, F3, F4, F6;
    F1 = crearFraccion();
    F2 = crearFraccion ();
    F3 = crearFraccion ();
    darFracciones(F1, F2);
    F3 = producto(F1, F2);
    F4 = division(F1, F2);
    pro = propia(F1);
    n = numPotencia();
    F6 = potencia(F1,n);
    mostrarFraccion(F1, F2, F3, F4, F6);
    pro1(pro);
    liberarMem(F1, F2, F3, F4, F6);
}


void darFracciones(FRACCION F1, FRACCION F2){
    int n, d;
    printf("Dar el numerador de la fraccion 1\n");
    scanf("%d", &n);
    asignaNum(F1, n);
    printf("Dar el denominador de la fraccion 1\n");
    scanf("%d", &d); 
    asignaDenom(F1, d);
    printf("Dar el numerador de la fraccion 2\n");
    scanf("%d", &n);
    asignaNum(F2, n);
    printf("Dar el denominador de la fraccion 2\n");
    scanf("%d", &d); 
    asignaDenom(F2, d);
}

int numPotencia(){
    int n;
    printf("Ingrese el numero de la potencia: \n");
    scanf("%i", &n);
    return n;
}

void mostrarFraccion(FRACCION F1, FRACCION F2, FRACCION F3, FRACCION F4, FRACCION F6){
    printf("Fraccion 1  %d/%d \n", obtenNum(F1), obtenDenom(F1) );
    printf("Fraccion 2  %d/%d \n", obtenNum(F2), obtenDenom(F2) ); 
    printf("El producto es %d/%d \n", obtenNum(F3), obtenDenom(F3));
    printf("La divicion es %d/%d \n", obtenNum(F4), obtenDenom(F4));
    //printf("La fracion es %i", pro);
    //printf("1-Si es propia o 0-Si es impropia: %i \n", pro);
    printf("Potencia de la fraccion 1: %d/%d \n", obtenNum(F6), obtenDenom(F6));
}

int pro1(int pro){
    if (pro == 0){
        printf("La fraccion 1 es Propia\n");
    }else{
        printf("La fraccion 1 es Impropia\n");
    }
}

void manejaMsg(int msg){
    char * mensajes[] = {"No hay memoria disponible . . .", "Se ha liberado la memoria . . .  "};
    printf("%s", mensajes[msg] );
}

void liberarMem(FRACCION F1, FRACCION F2, FRACCION F3, FRACCION F4, FRACCION F6){
    free(F1);
    free(F2); 
    free(F3);
    free(F4);
    free(F6);
    manejaMsg(1);
}
