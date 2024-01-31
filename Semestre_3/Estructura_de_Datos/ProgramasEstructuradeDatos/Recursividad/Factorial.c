#include <stdio.h>

float factorial(float);

int main(){
    float n, final;
    printf("\n\nPrograma para calular el Factorial");
    printf("\n\nDe que numero deseas calcular el factorial: ");
    scanf("%f", &n);

    final = factorial(n); 
    printf("\n\nEl factorial de %f es: %f", n, final);


    return 0;
}

float factorial(float numero){
    float resul;
    if(numero>1){
        resul = numero * factorial (numero - 1);
    }else{
        resul = 1;
    }

    return resul; 
}