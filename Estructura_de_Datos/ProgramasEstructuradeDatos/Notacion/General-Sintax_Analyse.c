#include <stdio.h>
#include <stdlib.h>
struct Nodo{
    struct Nodo *izq;
    char info[20];
    struct Nodo *der;
};

int GeneralAndSintax(char *expresion);

int revisionGeneral(char* expresion);
int esOperador(char c);
int dots(char *expresion);

int casoNegativo(char *expresion);
int esOperadorNegativo(char c);
int operadoresSinNegativo(char c);


int esOperadorA(char c);
int empezarOperador(char *expresion);
int caracteresValidos(char c);


int main() {
    char expresion[100];
    int prueba;
    printf("Ingrese la expresión a revisar: \n\n");
    fgets(expresion, sizeof(expresion), stdin);

    printf("La expresión ingresada es: %s", expresion); 


    prueba = GeneralAndSintax(expresion);
    switch (prueba){
    case 1:
        printf("\nCaracteres inválidos. Ingrese nuevamente la cadena . . . \n"); 
        printf("\n . 1 . \n"); 
        /* code */
        break;
    case 2:
        printf("\nLa expresión empieza de manera incorrecta. Ingrese nuevamente la cadena . . . \n"); 
        printf("\n . 2 . \n"); 
        break;
    case 3:
        printf("\nError de escritura (sintaxis erronea). Ingrese nuevamente la cadena . . . \n"); 
        printf("\n . 3 . \n"); 
        break;
    default:
        printf("\n----EXPRESION VALIDA----- \n"); 
        break;
    }

    return 0;

}

int GeneralAndSintax(char *c){
    int analisis, sintax;

    // analisis = revisionGeneral(*c);
    // sintax = 
    if (revisionGeneral(c) == 1){
        return 1;
    }
    // analisis = empezarOperador(c);
    if (empezarOperador(c) == 1){
        return 2;
    }

    if (dots(c) == 1){
        return 3;
    }

    if(casoNegativo(c) == 1){
        return 3;
    }
    
}

int revisionGeneral(char *expresion){
    int i = 0;
    int control; 
    control = 1;

    while(expresion[i] != '\0' && expresion[i] != '\n' && expresion[i] != '\000' && control == 1){
        control = caracteresValidos(expresion[i]);
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

int empezarOperador(char *expresion){
    if(expresion[0] == '+' || expresion[0] == '^' || expresion[0] == '/' || expresion[0] == '='){
        printf("Operacion invalida");
        return 1; 
    }else{
        printf("Operacion valida");
        return 0;
    }
}

int dots(char *expresion){
    int i = 0;
    int control; 
    control = 0;

    while(expresion[i] != '\0' && expresion[i] != '\n' && expresion[i] != '\000' && control != 2){
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

int casoNegativo(char *expresion){
    int i = 0, control = 0;
    char c, ca;
    while (expresion[i] != '\0' && expresion[i] != '\n' && expresion[i] != '\000'){
        c = expresion[i];
        ca = expresion[i+1];

        if (esOperadorNegativo(expresion[i])== 1 && operadoresSinNegativo(expresion[i+1]) == 1){
            return 1;
        }    
        i++;
    }

}


int esOperador(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' || c == '^');
}

int esOperadorA(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/'|| c == '^');
}

int esOperadorNegativo(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == '^' || c=='.');
}

int operadoresSinNegativo(char c){
    return (c == '+' || c == '*' || c == '/' || c == '^' || c == ')');
}
int caracteresValidos(char c){
    return(c == '+' || c == '-' || c == '*' || c == '/' || c == '^'|| c == '(' || c == ')' || c == '.' || c == '0'
    || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7'
    || c == '8' || c == '9'); 
}

