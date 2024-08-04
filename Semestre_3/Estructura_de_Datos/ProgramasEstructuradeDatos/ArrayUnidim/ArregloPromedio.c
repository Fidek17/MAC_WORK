#include <stdio.h>
#include <math.h>

float promedio(float [], int);
float desestandar(float [], float, int);


int main(){
float calif[4], res1, res2;
int k1;

int nu = 5; 

for(k1=0; k1<nu; k1++ ){
printf("\n\nIngresa la calificacion numero %d: ", k1); 
scanf("%f", &calif[k1]);
}

res1 = promedio(calif, nu);
printf("\n\nEl resultado del promedio es: %f", res1);

res2 = desestandar(calif, res1, nu); 

printf("\n\nEl valor final de la desviacion estandar es: %f", res2); 

    return 0;
}

float promedio(float calif[4], int n){
    int k1;
    float suma=0, resultado;
    for(k1=0; k1<n; k1++ ){
    suma = suma + calif[k1];
    }
    resultado = suma/n;
return resultado;
}

float desestandar(float calif[4], float media, int n){
int k1;
float distancia, suma, division, raizcua;
    for(k1=0; k1<n; k1++){
        distancia = calif[k1] - media; 
        distancia = distancia * distancia; 
        suma = distancia + suma;
        distancia = 0; 
    }
division = suma/n; 
raizcua = sqrt(division); 
 
return raizcua; 
}