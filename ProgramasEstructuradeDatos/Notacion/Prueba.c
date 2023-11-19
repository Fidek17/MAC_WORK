#include <stdio.h>
#include <stdlib.h>
struct Nodo{
    struct Nodo *izq;
    char info[20];
    struct Nodo *der;
};

int revisionGeneral(char *expresion);
int esOperador(char c);
int dots(char *expresion);
int esOperadorA(char c);
int empezarOperador(char *expresion);
int valoresValidos(char c);


int main() {
    char expresion[100];
    int prueba;
    printf("Ingrese la expresión a revisar: \n\n"); 
    fgets(expresion, sizeof(expresion), stdin);

    printf("La expresión ingresada es: %s", expresion); 

    prueba = revisionGeneral(expresion);
    //prueba = dots(expresion);
    //prueba = empezarOperador(expresion);
    return 0;

}

int revision(char *expresion){
    int i; 
    i = 0; 




    return 0; 
}

int esOperador(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' || c == '^');
}

int esOperadorA(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/'|| c == '^');
}
int valoresValidos(char c){
    return(c == '+' || c == '-' || c == '*' || c == '/' || c == '^'|| c == '(' || c == ')' || c == '0'
    || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7'
    || c == '8' || c == '9'); 
}

int dots(char *expresion){
    int i = 0;
    int control; 
    control = 0;

    while(expresion[i] != '\0' && control != 2){
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
    if (control == 2){
        printf("invalido ");
        return 1; 
    }else{
        printf("valido"); 
        return 0;
    }

}



int empezarOperador(char *expresion){
    if(expresion[0] == '+' || expresion[0] == '^' || expresion[0] == '/'){
        printf("Operacion invalida");
        return 1; 
    }else{
        printf("Operacion valida");
        return 0;
    }
}


int revisionGeneral(char *expresion){
    int i = 0;
    int control; 
    control = 1;

    while(expresion[i] != '\0' && control == 1){
        control = valoresValidos(expresion[i]);
        i++;
    }
    if (control == 1){
        printf("valido ");
        return 0; 
    }else{
        printf("invalido"); 
        return 1;
    }
}