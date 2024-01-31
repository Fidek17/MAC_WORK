#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct lista{
    struct lista *izq;
    char info[20];
    struct lista *der;
};

struct pilaP{
    char info;
    float numero;
    struct pilaP *sig;
};

struct pilaNumbers{
    float numero;
    struct pilaNumbers *sig;
};


struct pilaC{
    char info;
    struct pilaC *sig;
}; 

void impresion(struct lista **P, struct lista **Q);
int jerarquia(char c); 
int GeneralAndSintax(char *expresion);
void parentizar(struct lista **P, struct lista **F, struct lista ** Q);
void traduccion(struct pilaP **P1, struct pilaC **PC, struct pilaC **QC, struct lista **P, struct lista **F); 
void pushPilaP(struct pilaP **P1, float numero, char c); 
void impresionPilaNum(struct pilaP **P1);
void pushPilaC(struct pilaC **PC, char c);
void impresionPilaCaracteres(struct pilaC **PC); 
char popPilaCaracteres(struct pilaC **PC);
void caracter(struct pilaP **P1, struct pilaC **PC, char c);
char lastItemChars(struct pilaC **PC);
void imprimirTraduccion(struct pilaP **P1); 
char popPilaPrincipalCaracter(struct pilaP **P1);
float popPilaPrincipalNumero(struct pilaP **P1);
float popPilaNumeros(struct pilaNumbers **PN);
void pushPilaNumeros(struct pilaNumbers **PN, float numero);
float operar(float numero1, float numero2, char c);
void funcion(struct pilaP **P1);
char endPilaPrincipal(struct pilaP **P1);



int revisionGeneral(char* expresion);
int esOperador(char c);
int dots(char *expresion);

int casoNegativo(char *expresion);
int esOperadorNegativo(char c);
int operadoresSinNegativo(char c);


int esOperadorA(char c);
int empezarOperador(char *expresion);
int caracteresValidos(char c);
int Numero(char c);

void porNombrar_ingresarAlista(char *expresion, struct lista **P, struct lista **F); 
void creaNodo(struct lista **P, struct lista **F, char *c, int i, int a);
void ingresarAlista(struct lista **P, struct lista **F, char *expresion, char *varX);

int main() {
    struct lista *P = NULL; 
    struct lista *F; 
    struct lista *Q; 
    struct pilaP *P1;
    struct pilaC *PC; 
    struct pilaC *QC;
    struct pilaNumbers *PN; 
    char expresion[100];
    char variableX[10];
    int prueba;
    char pruebac;
    printf("Ingrese la expresión a revisar: \n\n");
    fgets(expresion, sizeof(expresion), stdin);

    printf("La expresión ingresada es: %s", expresion);
    
    printf("\nIngresa el valor de la variable x: ");
    fgets(variableX, sizeof(variableX), stdin);
    

    prueba = GeneralAndSintax(variableX);

    if(prueba != 0){
        printf("\n\nHay algun error con la variableX. Ingresala de nuevo \n\n");  
        return 0;
    }
    
    prueba = GeneralAndSintax(expresion);
    switch (prueba){
    case 1:
        printf("\n\nCaracteres inválidos. Ingrese nuevamente la cadena \n\n");  
        break;
    case 2:
        printf("\n\nLa expresión empieza de manera incorrecta. Ingrese nuevamente la cadena . . . \n\n"); 
        break;
    case 3:
        printf("\n\nError de escritura (sintaxis erronea). Ingrese nuevamente la cadena . . . \n\n"); 
        break;
    default:
        printf("\n\n\t----EXPRESION VALIDA----- \t\n\n"); 
        ingresarAlista(&P, &F, expresion, variableX);
        parentizar(&P,&F,&Q);
        impresion(&P, &Q); 
        traduccion(&P1, &PC, &QC, &P, &F);
        imprimirTraduccion(&P1);
        funcion(&P1);
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
    return 0; 
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
    int i = 0;
    // int control = 0;
    // char c, ca;
    while (expresion[i] != '\0' && expresion[i] != '\n' && expresion[i] != '\000'){
        if (esOperadorNegativo(expresion[i])== 1 && operadoresSinNegativo(expresion[i+1]) == 1){
            return 1;
        }    
        i++;
    }
    return 0; 
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
    return (c == '+' || c == '*' || c == '/' || c == '^');
}
int caracteresValidos(char c){
    return(c == '+' || c == '-' || c == '*' || c == '/' || c == '^'|| c == '(' || c == ')' || c == '.' || c == '0'
    || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7'
    || c == '8' || c == '9' || c == 'x' || c == 'X');
}

int Numero(char c){
    return( c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7'
    || c == '8' || c == '9' || c=='0'); 
}

int variables(char c){
    return( c == 'x' || c=='X' || c == 'y' || c=='Y');
}

void impresion(struct lista **P, struct lista **Q){
    int i=0; 
    *Q = *P;
    printf("\n\n");
    while(*Q != NULL){
        printf("%d: %s \n\n", i, (*Q)->info);
        *Q = (*Q)->der;
        i++;
    }
    printf(" Null");
    printf("\n\n");
}


void creaNodo(struct lista **P, struct lista **F, char *c, int i, int a){
int n = 0;
    if(*P == NULL){
        *P = (struct lista *)malloc(sizeof(struct lista));

        while(c[i] != '\0' && c[i] !='\n' && i != a){
            (*P)->info[n] = c[i]; 
            i++; 
            n++;
        }
        (*P)->der = NULL;
        (*P)->izq = NULL;
        *F = *P;
    }else{
        (*F)->der = (struct lista *)malloc(sizeof(struct lista));
        ((*F)->der)->izq = *F;
        *F = (*F)->der;
        (*F)->der=NULL;
        while(c[i] != '\0' && c[i] !='\n' && i != a){
            (*F)->info[n] = c[i]; 
            i++; 
            n++;
        }
    }

} 


void ingresarAlista(struct lista **P, struct lista **F, char *expresion, char *varX){
    int i, a, q=0, w=0;
    char aux = '*';
    char *puntero_aux = &aux;
    
    char negativeX[11];
    
    int len = strlen(negativeX); //encuentra el final de la cadena
    
    i = 0;
    q = 0;
    *P = NULL;

    /**/
    negativeX[0] = '-';
    while(varX[w] != '\0' && varX[w] != '\n'){
        negativeX[w+1] = varX[w];
        w++;
    }

    char *punteroToNegative = negativeX;

    while(expresion[i] != '\0' && expresion[i] != '\n' ){
        // Es numero

        printf(" %c", expresion[i]);
/*----------------------------- número -----------------------------*/
        if(Numero(expresion[i]) == 1 ){
            a = i; 
            while(esOperador(expresion[a])!= 1 && variables(expresion[a]) != 1 && expresion[a] != '\0' && expresion[a] != '\n'){
                a++; 
            }
            creaNodo(P,F,expresion,i,a); 
            i = a;
        }


/*
        else if (expresion[i] == '+' && expresion[i+1] == '-' ){            
        }
*/
        
/*----------------------------- VARAIBLE X-----------------------------*/
            else if (expresion[i] == 'x' || expresion[i] == 'X'){
                // a=i-1;

                if (Numero(expresion[i-1]) == 1 && esOperador(expresion[i+1]) == 1){
                    // #x + 
                    creaNodo(P,F, puntero_aux, 0, 1); //Agrego '*' antes la variable x. -> #*x
                    // Uso puntero_aux por los parametros de la funcion creaNodo
                }
                creaNodo(P,F, varX, q, w);
                i++;
             }
/*----------------------------- operador-----------------------------*/
        else{
            //Sino es numero es el caso de -+
            if((expresion[i] == '-' && operadoresSinNegativo(expresion[i-1]) == 1) || (expresion[0] == '-') && i==0){

                a = i+1; 
                if (variables(expresion[i+1]) == 1){
                   creaNodo(P,F,punteroToNegative,q,w+1);
                    i = i+2;
                }else{
                    /* code */
                
                
                    while(esOperador(expresion[a]) != 1 && variables(expresion[a]) != 1 && expresion[a] != '\0' && expresion[a] != '\n' ){
                        a++; 
                    }
                    creaNodo(P,F,expresion,i,a); 
                    i = a;
                }
            }

            else{
                //Sino es el caso de -+ o un numero, es un operador y solo se ingresa en la lista
                a = i + 1;
                creaNodo(P, F, expresion, i, a);
     
                i++; 
            }
        }
    }

}
int jerarquia(char c) {
  if (c == '^')
    return 3;
  if (c == '*' || c == '/')
    return 2;
  if (c == '+' || c == '-')
    return 1;
  return 0;
}


void parentizar(struct lista **P, struct lista **F, struct lista **Q) {
    // Agrega paréntesis "(" al principio de la lista
    *Q = (struct lista *)malloc(sizeof(struct lista));
    (*Q)->info[0] = '(';
    (*Q)->izq = NULL;
    (*Q)->der = *P;

    // Verifica si la lista está vacía
    if (*P != NULL) {
        (*P)->izq = *Q;
    }

    *P = *Q;

    // Agrega paréntesis ")" al final de la lista
    *Q = (struct lista *)malloc(sizeof(struct lista));
    (*Q)->info[0] = ')';
    (*Q)->der = NULL;
    (*Q)->izq = *F;

    // Verifica si la lista está vacía
    if (*F != NULL) {
        (*F)->der = *Q;
    }

    // Actualiza el puntero final de la lista
    *F = *Q;
}


void traduccion(struct pilaP **P1, struct pilaC **PC, struct pilaC **QC, struct lista **P, struct lista **F){
    struct lista *Q;
    int i = 0;
    float numero;
    *P1 = NULL;
    *PC = NULL;
    Q = *P; 
    while(Q != NULL){
        if(Numero(Q->info[0]) == 1 ){
            numero = atof(Q->info);
            pushPilaP(P1, numero, 'a');
        }else{
            if(Q->info[0] == '-' && Numero(Q->info[1]) == 1 ){
                numero = atof(Q->info);
                pushPilaP(P1, numero, 'a');
            }else{
                caracter(P1, PC, Q->info[0]);
            }

        }




        Q = Q->der;
        i++;

    }
}

void pushPilaP(struct pilaP **P1, float numero, char c){
    struct pilaP *Aux = (struct pilaP *)malloc(sizeof(struct pilaP));
    struct pilaP *Q;
//Preparamos todo para que el nodo este perfecto 
    Aux->info = c;
    Aux->numero = numero;
    Aux->sig = NULL;

    if(*P1 == NULL){
        *P1 = Aux; 
    }else{
        Q = *P1;
        while(Q->sig!=NULL ){
            Q = Q->sig;
        }
        Q->sig = Aux;
    }
}

void impresionPilaNum(struct pilaP **P1){
    struct pilaP *Q; 
    Q = *P1;
    int i = 0;
    while(Q!= NULL){
        printf("\n\n%d. Numero: %f   Char: %c", i, Q->numero, Q->info);
        i++;
        Q = Q->sig; 
    }
}

void pushPilaC(struct pilaC **PC, char c){
    struct pilaC *Aux = (struct pilaC *)malloc(sizeof(struct pilaC));
    struct pilaC *Q;

    Aux->info = c;
    Aux->sig = NULL;

    if(*PC == NULL){
        *PC = Aux;
    }else{
        Q = *PC;
        while(Q->sig != NULL){
            Q = Q->sig;
        }
        Q->sig = Aux;
    }

}
void impresionPilaCaracteres(struct pilaC **PC){
    struct pilaC *Q; 
    Q = *PC;
    int i = 0;
    while(Q != NULL){
        printf("\n\n%d. Caracter; %c", i, Q->info);
        i++;
        Q = Q->sig;
    }
}
char popPilaCaracteres(struct pilaC **PC){
    struct pilaC *Aux; 
    struct pilaC *Q; 
    char caracter;

    Q = *PC;

    if((*PC)->sig == NULL){
        caracter = (*PC)->info; 
        free(*PC);
        *PC = NULL;
    }else{
        while(Q->sig != NULL){
            Aux = Q;
            Q = Q->sig;
        }
        caracter = Q->info; 
        free(Q); 
        Aux->sig = NULL; 
    }
    return caracter;
}
char lastItemChars(struct pilaC **PC) {
  struct pilaC *Q;
  char caracter;

  Q = *PC;
  if(*PC == NULL){
    return '\0'; 
  }
  if ((*PC)->sig == NULL) {
    caracter = (*PC)->info;
  } else {
    while (Q->sig != NULL) {
      Q = Q->sig;
    }
    caracter = Q->info;
  }
  return caracter;
}

void caracter(struct pilaP **P1, struct pilaC **PC, char c){
  char control;
  char ultimo;

  if (c == '('){
    pushPilaC(PC, c);
  }else{
    if( c == ')'){
        control = popPilaCaracteres(PC);
        while(control != '('){
            pushPilaP(P1, 0.0, control);
            control = popPilaCaracteres(PC); 
        }
    }else{
        //Unico caso posible es el de operador
        ultimo = lastItemChars(PC);
        if(jerarquia(c) <= jerarquia(ultimo)){
            while(jerarquia(c) <= jerarquia(ultimo)){
                pushPilaP(P1, 0.0, ultimo);
                control = popPilaCaracteres(PC); 
                ultimo = lastItemChars(PC);
            }
            pushPilaC(PC, c);
        }else{
            if(ultimo == '('){
            pushPilaC(PC, c);
            }else{
                pushPilaP(P1, 0.0, c);
            }
        }
    }
  }
}

void imprimirTraduccion(struct pilaP **P1){
    struct pilaP *Q;
    Q = *P1;
    printf("\n\n La expresion en posfijo es: \n\n");
    while(Q!=NULL){
        if(Q->info == 'a'){
            printf("  %f", Q->numero);
        }else{
            printf("  %c", Q->info);
        }
        Q = Q->sig; 
    }

}

char popPilaPrincipalCaracter(struct pilaP **P1){
    struct pilaP *Aux; 
    struct pilaP *Q; 
    char caracter;

    Q = *P1;

    if((*P1)->sig == NULL){
        caracter = (*P1)->info; 
        free(*P1);
        *P1 = NULL;
    }else{
        while(Q->sig != NULL){
            Aux = Q;
            Q = Q->sig;
        }
        caracter = Q->info; 
        free(Q); 
        Aux->sig = NULL; 
    }
    return caracter;
}

float popPilaPrincipalNumero(struct pilaP **P1){
    struct pilaP *Aux; 
    struct pilaP *Q; 
    float num;

    Q = *P1;

    if((*P1)->sig == NULL){
        num = (*P1)->numero; 
        free(*P1);
        *P1 = NULL;
    }else{
        while(Q->sig != NULL){
            Aux = Q;
            Q = Q->sig;
        }
        num = Q->numero; 
        free(Q); 
        Aux->sig = NULL; 
    }
    return num;
}

char endPilaPrincipal(struct pilaP **P1){
    struct pilaP *Aux; 
    struct pilaP *Q; 
    char caracter;

    Q = *P1;
    while(Q->sig != NULL){
        Q = Q->sig;
    }
    caracter = Q->info;
    return caracter;
}
float popPilaNumeros(struct pilaNumbers **PN){
    struct pilaNumbers *Q;
    struct pilaNumbers *Aux;
    float num;
    Q = *PN;

    if((*PN)->sig== NULL){
        num = (*PN)->numero;
        free(*PN); 
        *PN = NULL;
    }else{
        while(Q->sig != NULL){
            Aux = Q;
            Q = Q->sig; 
        }
        num = Q->numero;
        free(Q);
        Aux->sig = NULL;
    }
    return num;
}

void pushPilaNumeros(struct pilaNumbers **PN, float numero){
    struct pilaNumbers *Aux = (struct pilaNumbers *)malloc(sizeof(struct pilaNumbers));
    struct pilaNumbers *Q;

    Aux->numero = numero;
    Aux->sig = NULL;

    if(*PN == NULL){
        *PN= Aux;
    }else{
        Q = *PN;
        while(Q->sig != NULL){
            Q = Q->sig;
        }
        Q->sig = Aux;
    }

}

float operar(float numero1, float numero2, char c){
    float resultado;
    switch(c){
        case '+':
        return resultado = numero2+numero1;
        
        case '-':
        return resultado = numero2-numero1;
        
        case '*':
        return resultado = numero2-numero1;

        case '/':
        return resultado = numero2-numero1;

        case '^':
        return resultado = numero2-numero1;
    }
return 0; 
}

void funcion(struct pilaP **P1){
    char control;
    float numero1;
    float numero2;
    char operador;
    float resultado;
    float numeroprincipal;
    struct pilaNumbers *PN = NULL;
    struct pilaC *PC = NULL;
    while(P1 != NULL){
        control = endPilaPrincipal(P1);

        if(control == 'a'){
            numeroprincipal = popPilaPrincipalNumero(P1);
            pushPilaNumeros(&PN, numeroprincipal);
            }else{
            printf("\n\nCaso de que es operador"); 
            operador = popPilaPrincipalCaracter(P1);
            printf("Valor de operador %c", operador);
        }
        
    }
}
/*
printf("Entra la funcio cunidns "); 
    while(P1 != NULL){
        control = endPilaPrincipal(P1);
//Si tiene a en el cajon de char entonces es un numero
        if(control == 'a'){
            numeroprincipal = popPilaPrincipalNumero(P1);
            pushPilaNumeros(&PN, numeroprincipal); 
            if((PN)->sig != NULL){
                if((PC) != NULL){
                    numero1 = popPilaNumeros(&PN);
                    numero2 = popPilaNumeros(&PN); 
                    operador = popPilaCaracteres(&PC);
                    resultado = operar(numero1, numero2, operador); 
                    pushPilaNumeros(&PN, resultado);

                }else{
                    printf("No muy seguro de uqe hacer ene ste caso"); 
                }
            }else{
                printf("solo se agrga el numero a la pila");
            }
        }else{
            operador = popPilaPrincipalCaracter(P1);
            pushPilaC(&PC, operador);
        }

    }
*/