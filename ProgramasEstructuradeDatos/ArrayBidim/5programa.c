#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void escribirMatriz(float matriz[10][10][10], int n, int m, int p);
void imprimirMatriz(float matriz[10][10][10], int n, int m, int p);
void promedioMatriz(float matriz[10][10][10], int n, int m, int p);

int main(){
    float matrix[10][10][10], sumasPricSec;
    /*La suma en cada diagonal? 
    O la suma de ambas diagonales*/

        escribirMatriz(matrix, 3, 4, 2);
        printf("\n");
        promedioMatriz(matrix,3,4,2);
        printf("\n");

    
    return 0;
}

void escribirMatriz(float matriz[10][10][10], int n, int m, int p){
    int i,j,k;
    printf("\n");
    srand(time(NULL)); //Semilla para generar un numero random
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            for (k = 0; k < p; k++){
                // printf(" a%d%d: ", i+1, j+1);
                // scanf("%f", &matriz[i][j]);
                matriz[i][j][k] = rand() % 24;
            }
            
        }
        printf("\n");
    }
    imprimirMatriz(matriz, n, m, p);
}

void imprimirMatriz(float matriz[10][10][10], int n, int m, int p){
    int i,j, k  ;
    for(i=0; i<n; i++){
        printf("\n|");
        for(j=0; j<m; j++){
            for (k = 0; k < p; k++){
                printf("\n");
                printf("\t %.2f :: a%d%d%d", matriz[i][j][k], i,j,k);
            }
                printf("\t-:: Esc[%d]alumno[%d] --calif[%.2f :: %.2f]", i,j,matriz[i][j][0],matriz[i][j][1]);
            printf("\n\n");
        }
        printf("\n\n|");
    }
}

void promedioMatriz(float matriz[10][10][10], int n, int m, int p){
    int i, j, k;
    float suma=0, promedio=0, promedioalum;

    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            for(k=0; k<p; k++){
                suma += matriz[i][j][k];
            }
        printf("\n%f", suma);
            
         }
    }

    promedio = suma/(n*m*p);
    printf("\n\nEl promedio es: %.2f", promedio);

}