#include <stdio.h>
#include <stdlib.h>

float suma(float x, float y){
    float suma;
    suma=x+y;
    return suma;
}

float resta(float x, float y){
    float resta;
    resta=x-y;
    return resta;
}

float producto(float x, float y){
    float producto;
    producto=x*y;
    return producto;
}

float division(float x, float y){
    float division;
    if(y>0){
        division=x/y;
    }
    else{
        printf("\nError, no es posible dividir por 0\n");
    }
    return division;
}

float factorial(float x){
    float factorial=1;
    for (int i=1;i<=x;i++){
        factorial=factorial*i;
    }
    return factorial;
}
