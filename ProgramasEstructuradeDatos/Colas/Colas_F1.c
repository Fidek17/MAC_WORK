#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Nodo{
    int info;
    struct Nodo *liga;
};

bool vacio(struct Nodo **P); 
void mensaje_cola_vacia();
int menu();
void push(struct Nodo **P, struct Nodo **Q, struct Nodo **Aux);
void pop(struct Nodo **P, struct Nodo **Q); 
void impresion(struct Nodo **P, struct Nodo **Q); 

int main(){
    int eleccion;
    struct Nodo *P = NULL;
    struct Nodo *Q = NULL;
    struct Nodo *Aux = NULL;


    printf("\t\nPrograma Colas 1");
    do{
        eleccion = menu();

        switch(eleccion){
            case 1: 
            push(&P,&Q,&Aux);
            break;

            case 2: 
            vacio(&P)? mensaje_cola_vacia() : pop(&P,&Q);
            break;

            case 3:
            vacio(&P)? mensaje_cola_vacia() : impresion(&P,&Q);
            break;

            case 0:
            printf("\nSaliendo del programa\n");
            break;
            
            default:
            printf("\n\nOpcion no valida por favor digite otra: ");
        }

    }while(eleccion != 0);

    return 0; 
}

bool vacio(struct Nodo **P){
    if(*P != NULL){
        return false;
    }
    return true;
}

void mensaje_cola_vacia(){
    printf("\n-----------------------------------\n");
    printf("\nNo hay lista\n\nCree una lista con la opción 1\n");
    printf("\n-----------------------------------\n");
}

int menu(){
        int res;
    printf("\n\n");
    printf("1. Push (insercion) de un elemento\n");
    printf("2. Pop (sustraccion) elemento\n");
    printf("3. Impresion\n");
    printf("0. Salida\n");
    printf("Opción: ");
    scanf("%d", &res);

    return res;
}

void push(struct Nodo **P, struct Nodo **Q, struct Nodo **Aux){
    
    *Aux = (struct Nodo *)malloc(sizeof(struct Nodo));

    printf("\nDame el valor a ingresar: ");
    scanf("%d", &(*Aux)->info);
    (*Aux)->liga = NULL;

    if(vacio(P)){
        *P = *Aux;
    }else{
        *Q = *P;
        while((*Q)->liga!= NULL){
            *Q = (*Q)->liga;
        }
        (*Q)->liga = *Aux;
    }

    printf("\n\nDato ingresado correctamente\n\n");
    printf("Valor de P: %d", (*P)->info);
}

void pop(struct Nodo **P, struct Nodo **Q){

    if((*P)->liga == NULL){
        free(*P); 
        *P = NULL;
    }else{
        *Q = (*P)->liga;
        free(*P);
        *P = *Q;
    }
    printf("\n\nEliminacion del primer elemento exitosa\n\n");
}

void impresion(struct Nodo **P, struct Nodo **Q){
    *Q = *P;
    while(*Q != NULL){
        printf("\n\nElemento: %d", (*Q)->info);
        *Q = (*Q)->liga;
    }
    printf("\n\n");
}
