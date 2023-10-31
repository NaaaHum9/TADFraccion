#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fraccion.h"

void manejaMsg(int);
FRACCION crearFraccion(void){
    FRACCION F;
    F = (FRACCION)malloc(sizeof(Fraccion));
        if( F == NULL){
            manejaMsg(0);
            exit(0);
        }
    return F;
}
void asignaNum(FRACCION F,  int n){
    F -> numerador = n;
}

void asignaDenom(FRACCION F, int d){
    F -> denominador = d;
}

int obtenNum(FRACCION F){
   return ( F -> numerador);
}

int obtenDenom(FRACCION F){
    return ( F -> denominador);
}

FRACCION producto(FRACCION F1, FRACCION F2){
    FRACCION F3 =  crearFraccion();
    asignaNum( F3, obtenNum(F1) * obtenNum(F2) );
    asignaDenom( F3, obtenDenom(F1) * obtenDenom(F2) );
    return F3;
}

FRACCION division(FRACCION F1, FRACCION F2){
    FRACCION F4 = crearFraccion();
    asignaNum(F4, obtenNum(F1) * obtenDenom(F2));
    asignaDenom( F4, obtenDenom(F1) * obtenNum(F2));
    return F4;
}

int propia(FRACCION F1){
    int pro;

    if (obtenNum(F1) > obtenDenom(F1)){
        pro = 1;
    }else{
        pro = 0;
    }
    return pro;
}

/*FRACCION propia(FRACCION F1){
    FRACCION F5 = crearFraccion();
    asignaNum(F5, if(obtenNUM(F1)>obtenDenom(F1)){
        
    })
    
}*/

FRACCION potencia(FRACCION F1, int n){
    FRACCION F6 = crearFraccion();
    asignaNum(F6, pow(obtenNum(F1), n));
    asignaDenom(F6, pow(obtenDenom(F1), n));
    return F6;
}