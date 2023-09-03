#include <stdio.h>

void ingresardatos(int Arreglo[10][10], int B[30]);
void imprimirdatos(int A[10]);

int main(){
    int A[10][10],prueba[10];
    int i, valor,j, pos=0;

ingresardatos(A, prueba);

printf("\n\nDame el renglon y la columna del valor que deseas hallar en el arreglo");
scanf("%d", &i);
scanf("%d", &j);  

    pos = 1 +(((i-1)*(i))/2) + (j-1);
printf("\n\nEl valor almacenado en %d %d es: %d en la posicion %d del arreglo unidimensional", i, j, prueba[pos], pos);
    return 0; 
}

void ingresardatos(int Arreglo[10][10], int B[30]){
    int i, j, k = 1;
    int n = 4;

    for(i=1; i<n; i++){
        for(j=1; j<n; j++){

            if(j <= i ){
                printf("\n\nDame el valor de la posicion %d  %d; ", i, j);
               scanf("%d", &Arreglo[i][j]);

                   
                    B[k] = Arreglo[i][j];
                    k++;
            
            }else{
                Arreglo[i][j] = 0;
            }

        }

    }

}
