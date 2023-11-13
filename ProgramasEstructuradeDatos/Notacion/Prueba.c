#include <stdio.h>
#include <stdlib.h>
struct Nodo{
    struct Nodo *izq;
    char info[20];
    struct Nodo *der;
};

int revision(char *expresion);
int esOperador(char c);
int dots(char *expresion);

int main() {
    char expresion[100];
    int prueba;
    printf("Ingrese la expresión a revisar: \n\n");
    fgets(expresion, sizeof(expresion), stdin);

    printf("La expresión ingresada es: %s", expresion); 

    prueba = dots(expresion);
    return 0;

}

int revision(char *expresion){
    int i; 
    i = 0; 




    return 0; 
}

int dots(char *expresion){
    int i = 0;
    int control; 
    control = 0;

    while(expresion[i] != '\0' || control < 2){
       if(expresion[i] == '.'){
        control++; 
       }
       if (esOperador(expresion[i]) == 1){
        control = 0;
       }

       printf("\nValor de control en iteracion %d: %d\n\n", i, control);
       printf("char en cuestion: %c", expresion[i]);
        i++;
    }
if (control > 1){
    printf("invalido ");
}else{
    printf("valido"); 
}
    return 0; 
}
int esOperador(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')');
}