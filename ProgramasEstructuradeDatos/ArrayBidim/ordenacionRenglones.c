#include <stdio.h>

void ingresardatos(int Arreglo[10][10], int B[30], int n);
void imprimirdatos(int A[10][10], int n);

int main(){
    int A[10][10],prueba[10];
    int i, control,j, pos=0;
    control=6;

    ingresardatos(A, prueba, control);

    printf("\n\nDame el valor del renglon del del dato que deseas hallar en el arreglo: ");
    scanf("%d", &i);
    printf("\n\nDame el valor de la columna del del dato que deseas hallar en el arreglo: ");
    scanf("%d", &j);
    

    printf("\n\nLa matriz en cuestion es: \n\n");
    imprimirdatos(A, control);
    if(i>=j){

    pos = 1 +(((i-1)*(i))/2) + (j-1);
    printf("\n\nEl valor almacenado en [%d] [%d] es: %d en la posicion %d del arreglo unidimensional", i, j, prueba[pos], pos);
    }else{ 
        printf("\n\nNo se encuentra guardado en el arreglo ya que se trata de un cero");
    }
        return 0; 
}

void ingresardatos(int Arreglo[10][10], int B[30], int n){
    int i, j, k = 1;
    

    for(i=1; i<n; i++){
        for(j=1; j<n; j++){

            if(j <= i ){
                printf("\n\nDame el valor de la posicion [%d]  [%d]; ", i, j);
               scanf("%d", &Arreglo[i][j]);

                   
                    B[k] = Arreglo[i][j];
                    k++;
            
            }else{
                Arreglo[i][j] = 0;
            }

        }

    }

}
void imprimirdatos(int A[10][10], int n){
    int i, j; 
    for(i=1; i<n; i++){
        for(j=1; j<n; j++){

            printf("%d", A[i][j]);
            printf("\t");
        }
        printf("\n");

    }


}