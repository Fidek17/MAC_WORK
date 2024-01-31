#include <stdio.h>
#include <stdlib.h>

int potencia(int, int); 

int main(){
    int b,n, final;
    printf("\n\nPrograma para calcular la potencia de un numero con recusividad");
    printf("\n\nEscribe el numero que deseas que deseas que sea la base: ");
    scanf("%d", &b);

    printf("\n\nEscribe el numero que deseas que deseas que sea la potencia: ");
    scanf("%d", &n);
    final = potencia(b, n);
    printf("\n\nEl resultado de la potencia es: %d", final);
    return 0;
}

int potencia(int b, int n){
    int resul; 
    if(n>1){
        resul = b * potencia (b , n-1);
    }else{
        if(n==1){
            resul = b; 
        }else {
           resul = 1; 
        }
    }
    return resul;

}