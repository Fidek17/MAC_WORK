#include <stdio.h>

void SumaArrays(float a[], float b[]){
    int i;
    float c[5];

    printf("\nArreglo resultante al sumar\n");
    for (i = 0; i < 5; i++){
        c[i] = a[i] + b[i];
        printf("\n %dª:%.2f", i, c[i]);
    }
}

int main(){
	double resultado;
	int n, i;
    float array1[5], array2[5];    

	printf("\n\nIngrese los elementos del primer arrreglo ");
    for (i = 0; i < 5; i++){
	    printf("\n%dº: ", i);
	    scanf("%f", &array1[i]);
    }
    
	printf("\n\nIngrese los elementos del segundo arrreglo ");
    for (i = 0; i < 5; i++){
	    printf("\n%dº: ", i);
	    scanf("%f", &array2[i]);
    }

    SumaArrays(array1, array2);
    printf("\n");
    return 0;
}