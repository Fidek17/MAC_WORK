#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct lista{
    struct lista *izq;
    char info[20];
    struct lista *der;
};

void impresion(struct lista **P, struct lista **Q);
int jerarquia(char c); 
int GeneralAndSintax(char *expresion);
void parentizar(struct lista **P, struct lista **F, struct lista ** Q);

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
    char expresion[100];
    char variableX[10];
    int prueba;
    printf("Ingrese la expresión a revisar: \n\n");
    fgets(expresion, sizeof(expresion), stdin);

    printf("La expresión ingresada es: %s", expresion);
    
    printf("\nIngresa el valor de la variable x: ");
    fgets(variableX, sizeof(variableX), stdin);
    

    prueba = GeneralAndSintax(variableX);
    if(prueba != 0){
        printf("\n\nHay algun error con la variableX. Ingresala de nuevo \n\n");  
        return;
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
        impresion(&P, &Q); 
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
    return (c == '+' || c == '*' || c == '/' || c == '^' || c == ')');
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

    char *punteroToNegative = &negativeX;

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
                printf("\n\nEN esta %d iteracion mi elemento es %c",i, expresion[i]); 
                i++; 
            }
        }
    }

}
int jerarquia(char c){
    if(c == '^'){
        return 1;
    }else{
        if(c == '*' || c == '/'){
            return 2;
        }else{
            if(c == '+' || c == '-'){
                return 3; 
            }else{
                return 0;
            }
        }
    }
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