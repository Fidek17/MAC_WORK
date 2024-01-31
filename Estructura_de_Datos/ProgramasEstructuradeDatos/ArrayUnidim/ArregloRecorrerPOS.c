#include <stdio.h>

int main(){
    int array[10], i, pos, valor,n, temp; 

    n = 5; 

for(i=0; i<n; i++){
    printf("\n\nDame el valor del arreglo en la posicion %d: ", i);
    scanf("%d", &array[i]);
}
printf("\n\nDame el valor de la posicion donde quieres poner el numero: ");
scanf("%d", &pos);

printf("\n\nDame el valor que quieres colocar en la poscion numero %d: ", pos); 
scanf("%d", &valor);

i=0;

for(i=0; i<n; i++){
    if(i==pos){
       for(pos=i; pos < n+1; pos++){
            temp=array[pos];
            array[pos] = valor;
            valor = temp;

       }
    }


}

for(i=0; i<n+1; i++){
    printf("\n\nEl valor de la posicion %d es: %d", i, array[i]);

}

    return 0; 
}