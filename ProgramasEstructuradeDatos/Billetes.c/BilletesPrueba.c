#include <stdio.h>
#include <stdlib.h>

int operacion( int , int); 
int operacionm( int , int );

int main(){
    int Total, faltante;

    printf("\n\n\tIntroduce el numero que deseas descomponer: \n\n");
    scanf("%d", &Total);

    printf("\nEl dinero total a descomponer es: %d", Total);
     printf("\n\n---------------------------------------------------------");
    

    faltante = operacion(1000, Total);

    faltante = operacion(500, faltante); 
    
    faltante = operacion(200, faltante);

    faltante = operacion(100, faltante);

    faltante = operacion(50, faltante);

    faltante = operacion(20, faltante);

    faltante = operacionm(10, faltante);

    faltante = operacionm(5, faltante);

    faltante = operacionm(2, faltante);

    faltante = operacionm(1 , faltante);

    return 0;
}

int operacion( int denominacion, int cambiable){
int Billete, resto;
Billete = cambiable / denominacion;

    printf("\n\n El numero de billetes de %d es: %d", denominacion, Billete);

resto = cambiable - (Billete*denominacion);
return resto;
}

int operacionm( int denominacion, int cambiable){
int Billete, resto;
Billete = cambiable / denominacion;

    printf("\n\n El numero de monedas de %d es: %d", denominacion, Billete);

resto = cambiable - (Billete*denominacion);

return resto;

}