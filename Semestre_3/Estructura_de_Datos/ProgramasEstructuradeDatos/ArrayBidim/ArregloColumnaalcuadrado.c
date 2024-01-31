#include <stdio.h>
#include <math.h>

int main(){
    float array[5][3];
int i, j, control;

    for(i=0; i<5; i++){
        printf("\n\nDame el valor que deseas introducir en la poscion r:%d  c:0: ", i);
        scanf("%f", &array[i][0]);
    }



    for(j=0; j<5; j++){
        array[j][1] = pow(array[j][0], 2);
    }

      for(j=0; j<5; j++){
        array[j][2] = pow(array[j][0], 3);
    }

for(i=1; i<3; i++){
    for(j=0; j<5; j++){
        printf("\n\nEl valor de la posicion r:%d  c:%d es: %f", j, i, array[j][i]);
    }
}
    return 0;
}