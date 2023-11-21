#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct lista{
    struct lista *izq;
    char info[20];
    struct lista *der;
};

void impresion(struct lista **P, struct lista **Q);

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
int Numero(char c);

void porNombrar_ingresarAlista(char *expresion, struct lista **P, struct lista **F); 
void creaNodo(struct lista **P, struct lista **F, char *c, int i, int a);
void ingresarAlista(char *expresion, struct lista **P, struct lista **F);

int main() {
    struct lista *P = NULL; 
    struct lista *F; 
    struct lista *Q; 
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
        ingresarAlista(expresion, &P, &F);
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
    || c == '8' || c == '9'); 
}

int Numero(char c){
    return( c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7'
    || c == '8' || c == '9'); 
}
/*
void porNombrar_ingresarAlista(char *expresion, struct lista **P, struct lista **F){
    int i;
    i = 0;
    int a, q;
    q = 0;
    *P = NULL; 
    while(expresion[i] != '\0' && expresion[i] != '\n' ){
        if(expresion[i] == '-' && operadoresSinNegativo(expresion[i-1]) == 1){
            printf("Encontre el caso negativo");
            q = i+1;
            while(esOperador(expresion[q]) != 1 && expresion[q] != '\0' && expresion[q] != '\n' ){
                printf("\n\nExpresion: %c", expresion[q]); 
                q++;
            }
            printf("\n\nEncontre el negativo en la iteracion %d y el final en %d\n\n", i, q); 
            printf("\n\n Caracter en posicion de i: %c y caracrer en poscion de q-1: %c", expresion[i], expresion[q-1]);
            creaNodo(P,F,expresion,i,q);
            i = q; 
        }else{
            if(expresion[i] == '.'){
                printf("\nEncontre el caso del punto\n"); 
                q = i-1;
                while(esOperador(expresion[q])!=1 && expresion[q] != '\0' && expresion[q] != '\n'){
                    printf("\n\nCaracter encontrado en %d: %c", q, expresion[q]); 
                    q = q - 1; 
                }
                a = i; 
                i = q+1;
                q = a+1; 
                while(esOperador(expresion[q]) != 1 && expresion[q] != '\0' && expresion[q] != '\n'){
                    printf("\n\nCaracter encontrado en %d: %c", q, expresion[q]); 
                    q = q + 1; 
                }
                creaNodo(P, F, expresion, i, q); 
                i = q; 
            }else{
                a = i + 1;
                creaNodo(P, F, expresion, i, a);
                printf("\n\nEN esta %d iteracion mi elemento es %c",i, expresion[i]); 
                i++;   
            }
        }
    }
}
*/


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


void ingresarAlista(char *expresion, struct lista **P, struct lista **F){
    int i;
    i = 0;
    int a, q;
    q = 0;
    *P = NULL;
    while(expresion[i] != '\0' && expresion[i] != '\n' ){
        // Es numero
        if(Numero(expresion[i]) == 1 ){
            a = i; 
            while(esOperador(expresion[a])!= 1 && expresion[a] != '\0' && expresion[a] != '\n'){
                a = a + 1; 
            }
            creaNodo(P,F,expresion,i,a); 
            i = a;
        }else{
            //Sino es numero es el caso de -+
            if(expresion[i] == '-' && operadoresSinNegativo(expresion[i-1]) == 1){
                a = i+1; 
                while(esOperador(expresion[a]) != 1 && expresion[a] != '\0' && expresion[a] != '\n' ){
                    a++; 
                }
                creaNodo(P,F,expresion,i,a); 
                i = a;
            }else{
                //Sino es el caso de -+ o un numero, es un operador y solo se ingresa en la lista
                a = i + 1;
                creaNodo(P, F, expresion, i, a);
                printf("\n\nEN esta %d iteracion mi elemento es %c",i, expresion[i]); 
                i++; 
            }
        }
    }


}