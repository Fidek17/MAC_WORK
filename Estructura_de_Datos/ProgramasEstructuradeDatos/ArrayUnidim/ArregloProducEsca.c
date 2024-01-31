#include <stdio.h>

int main(){
    int vector1[5], vector2[5], k1, mult, suma=0;

    for(k1=0; k1<5; k1++){
        printf("\n\nDame el valor %d del vector 1: ", k1);
        scanf("%d", &vector1[k1]);
    }
    for(k1=0; k1<5; k1++){
        printf("\n\nDame el valor %d del vector 2: ", k1);
        scanf("%d", &vector2[k1]);
    }

    for(k1=0; k1<5; k1++){

    mult = vector1[k1]*vector2[k1]; 

    suma = mult + suma;

    mult = 0;

}
printf("\n\nEl resultado del producto escalar es: %d", suma);
    return 0; 
}