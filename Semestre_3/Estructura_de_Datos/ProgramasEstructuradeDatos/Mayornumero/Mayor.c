#include <stdio.h>
#include <stdlib.h>


int main(){
    int a, b, c;

printf("\n\nDame el valor del dato a: ");
scanf("%d", &a);

printf("\n\nDame el valor del dato b: ");
scanf("%d", &b);

printf("\n\nDame el valor del dato c: ");
scanf("%d", &c);

if(a > b){
    if(a > c){
        printf("EL mayor valor de todos es el de a: %d", a);
    }else{
        printf("EL mayor valor de todos es el de c: %d", c);
    }


}else{
    if (b > c){
        printf("EL mayor valor de todos es el de b: %d", b);
    }else{
        printf("EL mayor valor de todos es el de c: %d", c);
    }

}

    return 0; 
}