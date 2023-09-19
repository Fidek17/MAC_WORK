#include <stdio.h>
#include <stdlib.h>

int main(){

    int n; 
    printf("Dame el valor de cuantos valores enteros deseas alamcenar:");
    scanf("%d", &n);

    int *numeros;

    numeros = (int *)malloc(n* sizeof(int));

        printf("Ingrese %d valores enteros:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numeros[i]);
    }

        printf("Valores ingresados:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");



    return 0; 
}