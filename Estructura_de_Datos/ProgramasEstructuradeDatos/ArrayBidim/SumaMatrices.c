#include <stdio.h>

int main(){
    int mat1[5][5],mat2[5][5],mat3[5][5];
int i, j, aux;
aux = 4;

printf("\n\nPrograma que suma matrices (deben ser de la misma dimension)");

printf("\n\nAqui se pondran los datos de la primera matriz\n");

for(i=0; i<2; i++){
    for(j=0; j<aux; j++){
        printf("\n\nDame el valor de la poscion c:%d  r:%d: ", i, j);
        scanf("%d", &mat1[i][j]);
    }
}

printf("\n\nAqui se pondran los datos de la segunda matriz\n");

for(i=0; i<2; i++){
    for(j=0; j<aux; j++){
        printf("\n\nDame el valor de la poscion c:%d  r:%d: ", i, j);
        scanf("%d", &mat2[i][j]);
    }
}

for(i=0; i<2; i++){
    for(j=0; j<aux; j++){
       mat3[i][j] = mat1[i][j] + mat2[i][j]; 
    }
}
for(i=0; i<2; i++){
    for(j=0; j<aux; j++){
        printf("\n\nEl valor de la poscion c:%d  r:%d de M3 es: %d", i, j,mat3[i][j]);
    }
}



    return 0;
}