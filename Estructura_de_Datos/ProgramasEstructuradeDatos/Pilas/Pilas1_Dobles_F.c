#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Nodo{
    int info;
    struct Nodo *izq;
    struct Nodo *der;
};
void crear_final(struct Nodo **P, struct Nodo **F, struct Nodo **Q); 
void eliminar(struct Nodo **P, struct Nodo **F, struct Nodo **Q);
bool lista_vacia(struct Nodo **P); 
void impresion(struct Nodo **F, struct Nodo **Q);
void mensaje_lista_vacia();
int menu();

int main(){ 
int opcion;
struct Nodo *F = NULL;
struct Nodo *Q = NULL;
struct Nodo *P = NULL;
struct Nodo *Aux = NULL; 

    do{
        opcion = menu();
        switch (opcion){
        case 1:
            printf("\n\nCreacion de pila");
            crear_final(&P,&F, &Q);
            break;
        case 2: 
            printf("\n\nEliminacion de elemento\n\n");
            lista_vacia(&P) ? mensaje_lista_vacia(): eliminar(&P, &F, &Q);
            break;
        case 3:
            printf("\n\nImpresion de pila\n\n");
            lista_vacia(&P) ? mensaje_lista_vacia(): impresion(&F, &Q);
            break;
        } 
    }while(opcion!= 0);


    return 0; 
}

int menu(){
int res;
    printf("\n\n1. Creación de la pila\n\n");
    printf("2. Eliminación de elemento\n\n");
    printf("3. Impresion de la pila\n\n");
    printf("0. Salir\n\n");
    printf("Dame la opcion que deseas ejecutar: ");
    scanf("%d", &res);

    return res;
}


bool lista_vacia(struct Nodo **P){
    if(*P != NULL){
        return false;
    }else{
        return true;
    }
}

void crear_final(struct Nodo **P, struct Nodo **F, struct Nodo **Q){
int n, i;

    printf("\n\nNumero de valores a almacenar: ");
    scanf("%d", &n);

    for(i = 0; i < n; i ++){
        *Q = (struct Nodo *)malloc(sizeof(struct Nodo));
        printf("\n\n Dame el valor a ingresar: ");
        scanf("%d", &(*Q)->info);
        (*Q)->der = NULL;
        if(lista_vacia(P)){
            (*Q)->izq = NULL;
            *F = *Q;
            *P = *Q;
        }else{
            (*Q)->izq = *F;
            (*F)->der = *Q;
            *F = *Q; 
        }

    }

    printf("\n\nValor de P: %d", (*P)->info);
    printf("\n\nValor de F: %d", (*F)->info);
}
void mensaje_lista_vacia(){
    printf("\n-----------------------------------\n");
    printf("\nNo hay lista\n\nCree una lista con la opción 1\n");
    printf("\n-----------------------------------\n");
}

void eliminar(struct Nodo **P, struct Nodo **F, struct Nodo **Q){
    if(*P == *F){
        free(*P);
        *P = NULL;
        *F = NULL;
    }else{
        *Q = (*F)->izq;
        free(*F);
        (*Q)->der = NULL;
        *F = *Q;
    }
    printf("\n\nSe elimino el final y se reasigno");
}

void impresion(struct Nodo **F, struct Nodo **Q){
    *Q = *F;
    while(*Q != NULL){
        printf("%d\n\n", (*Q)->info);
        *Q = (*Q)->izq;
    }
}