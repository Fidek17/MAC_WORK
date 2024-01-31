#include <stdio.h>

int main(){
int frase[2][20];
char frasec[2][20];
int i, j, n, control, respuesta;
n = 11;

printf("\n\nDeseas que el programa compare numeros o letras? 1=letras||0=numeros:  ");
scanf("%d", &respuesta);

if(respuesta==0){

        for(j=0; j<n; j++){
            printf("\n\nDime el digito de la posicion 0  %d: ",j);
            scanf("%d", &frase[0][j]);
        }
    

        for(j=n-1, i=0; j>=0; j--, i++){
            frase[1][j] = frase[0][i];
        }

    for(i=0; i<2; i++){
        for(j=0; j<n; j++){
            printf("\n\nEl valor de la posicion %d  %d es: %d", i, j, frase[i][j]);
        }
    }

    
control = 0;

        for(j=0; j<n; j++){
         if(frase[0][j]!=frase[1][j]){
            control = 1;
         }
        }

if(control==0){
    printf("\n\nSe trata de un palindromo");
}else{
    printf("\n\nNo se trata de un palindromo");
}
}else{

            for(j=0; j<n; j++){
            printf("\n\nDime la letra de la posicion 0  %d: ",j);
            scanf(" %c", &frasec[0][j]);
        }
    

        for(j=n-1, i=0; j>=0; j--, i++){
            frasec[1][j] = frasec[0][i];
        }

    for(i=0; i<2; i++){
        for(j=0; j<n; j++){
            printf("\n\nLa letra de la posicion %d  %d es: %c", i, j, frasec[i][j]);
        }
    }

    
control = 0;

        for(j=0; j<n; j++){
         if(frasec[0][j]!=frasec[1][j]){
            control = 1;
         }
        }

if(control==0){
    printf("\n\nSe trata de un palindromo");
}else{
    printf("\n\nNo se trata de un palindromo");
}
}


   return 0;
}