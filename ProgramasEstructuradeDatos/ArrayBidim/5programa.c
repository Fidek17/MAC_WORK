#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// n = filas; m = columnas; p = "ancho"
void escribirMatriz(float matriz[5][5][5], int n, int m, int p);
void imprimirMatriz(float matriz[5][5][5], int n, int m, int p);
float promedioMatriz(float matriz[5][5][5], int n, int m, int p);
float incisoc(float matriz[5][5][5], int m);
float incisoD(float matriz[5][5][5]);
void idEscuela(int escuela);

int main(){
    float matrix[5][5][5], promediosGlobEs, suma;

        escribirMatriz(matrix, 3, 4, 2);
        promediosGlobEs = promedioMatriz(matrix,3,4,2); //promedio Global
        printf("\n\nEl promedio global es de %.3f", promediosGlobEs);

        promediosGlobEs = incisoc(matrix,4); //Promedio de las segundas calificaciones de la escuela elegida
        printf("\tEl promedio de las segundas calificaciones de la escuela elegida es de %.3f \n\n", promediosGlobEs);

        suma = incisoD(matrix);
        printf("\n\tSuma de calificaciones: %.3f\n", suma);

    return 0;
}

void escribirMatriz(float matriz[5][5][5], int n, int m, int p){
    int i,j,k;
    srand(time(NULL)); //Semilla para generar un numero random
    for(i=0; i<n; i++){
        printf("\n");
        for(j=0; j<m; j++){
            for (k = 0; k < p; k++){
                //printf(" Escuela %d \t alumno %d \t calificacion %dª: ", i+1, j+1, k+1);
                // scanf("%f", &matriz[i][j][k]);
                matriz[i][j][k] = rand() % 10; 
                
                /*Generamos los datos por comodidad pero hicimos las corridas con los datos de prueba, sólo hay que descomentar las dos líneas anteriores*/
            }
        }
    }
    imprimirMatriz(matriz, n, m, p);
}

void imprimirMatriz(float matriz[5][5][5], int n, int m, int p){
    int i,j;
    for(i=0; i<n; i++){
        printf("\n\n\n\t------------");idEscuela(i+1); printf("------------\n"); //imprime la escuela/universidad
        printf("\n\t\t\tcalificaciones");
        for(j=0; j<m; j++){
            printf("\n\t alumno %d \t %.2f \t %.2f",j+1,matriz[i][j][0],matriz[i][j][1]);
        }
    }
}

float promedioMatriz(float matriz[5][5][5], int n, int m, int p){
    int i, j, k;
    float suma=0;

    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            for(k=0; k<p; k++){
                suma += matriz[i][j][k];
            }
         }
    }
    // promedio = suma/(n*m*p);
    return suma/(n*m*p);

}
float incisoc(float matriz[5][5][5], int m){
    int j, escuela;
    float suma=0; 

    printf("\n\n1-. UNAM");
    printf("\n2-. IPN");
    printf("\n3-. UAM\n");
    printf("\nDame el número de escuela que deseas calcular: ");
    scanf("%d", &escuela);

    for(j=0; j<m; j++){
        suma+= matriz[escuela-1][j][1];
    }
    printf("\n\tEscuela: ");
    idEscuela(escuela);
    printf(" --\n");
    return suma/m; //promedio
}

float incisoD(float matriz[5][5][5]){
    int escuela, alumno, i,j;
    float suma = 0;
    printf("\nDame el número de escuela: ");
    scanf("%d", &escuela);
    printf("\nDame el número de alumno: ");
    scanf("%d", &alumno);

    printf("\n\tLa suma de las calificaciones del alumno %d, de la escuela ", alumno);
    idEscuela(escuela);

    for ( i = 0; i < escuela; i++){
        for (j = 0; j < alumno; j++){
            suma = matriz[i][j][0] + matriz[i][j][1];
        }
    }
    return suma;
}

void idEscuela(int escuela){
    switch (escuela){
    case 1:
        printf("UNAM");
        break;
    case 2:
        printf("IPN");
        break;
    case 3:
        printf("UAM");
        break;
    default:
        printf("\nEscuela no existente");
        break;
    }
}