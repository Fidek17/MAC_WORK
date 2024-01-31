#include <stdio.h>

int fib(int );

int main(){
int n, resul, final;

printf("\n\nDame el valor de hasta donde quiere llegar el termino de fibonacci: \n");
scanf("%d", &n);
final = fib(n);
printf("\n\nEl resultado del Fibonacci de %d es : %d", n, final);

}

int fib( n){

    int resul;

    if(n>2){

        resul = fib(n-1)+fib(n-2);

    }else{
        if(n==0){
            resul =0; 
        }else{
      resul = 1;
        }
    }
return resul;
}
