#include <stdio.h>

int main(){
    int k1, arrA[6], arrB[6], temp=0, contaimpar=0, contapar=0,nu;

    nu = 7;

    for(k1=0; k1<nu; k1++){

        printf("\n\nDame el valor %d: ", k1); 
        scanf("%d", &temp);

            if(((temp) % 2) == 0){
                    
                arrA[contapar]=temp;
                contapar++; 
                temp=0;
            }else{
                arrB[contaimpar]=temp; 
                contaimpar++;
                temp=0;
            }
            
        }
    printf("\n\nEl numero de numeros impares es: %d", contaimpar);
    printf("\n\nEl numero de numeros pares es: %d", contapar);

    for(k1=0; k1 < contapar; k1++){
        printf("\n\nEl valor numero %d de valores pares es: %d",k1, arrA[k1]); 
        }
    for(k1=0; k1 < contaimpar; k1++){
        printf("\n\nEl valor numero %d de valores impares es: %d",k1, arrB[k1]); 
        }
    return 0;  
}