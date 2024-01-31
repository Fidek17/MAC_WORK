#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Nodo{
    int info; 
    struct Nodo *liga;
};

bool lista_vacia(struct Nodo **P); 
void crear_final(struct Nodo **P, struct Nodo **Q, struct Nodo **Aux); 
void elimiinar_final(struct Nodo **P, struct Nodo **Q, struct Nodo **Aux);
void impresion(struct Nodo **P, struct Nodo **Q);
void mensaje_lista_vacia();

int menu();


int main(){
int opcion;
struct Nodo *Q = NULL;
struct Nodo *P = NULL;
struct Nodo *Aux = NULL; 

    do{
        opcion = menu();
        switch (opcion){
        case 1:
            printf("\n\nCreacion de pila\n\n");
            crear_final(&P,&Q, &Aux);
            break;
        case 2: 
            printf("\n\nEliminacion de elemento\n\n");
            lista_vacia(&P) ? mensaje_lista_vacia(): elimiinar_final(&P, &Q, &Aux);
            break;
        case 3:
            printf("\n\nImpresion de pila\n\n");
            lista_vacia(&P) ? mensaje_lista_vacia(): impresion(&P, &Q);
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

void crear_final(struct Nodo **P, struct Nodo **Q, struct Nodo **Aux){
    int n, i;
    printf("¿Cuantos elementos deseas introducir?: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        *Q = (struct Nodo *)malloc(sizeof(struct Nodo));
        printf("Dame el elemento a ingresar: ");
        scanf("%d", &(*Q)->info);
        (*Q)->liga = NULL;
        if(lista_vacia(P)){
            *P = *Q;
        }else{
            *Aux = *P;
            while((*Aux)->liga != NULL){
                *Aux = (*Aux)->liga;
            }
            (*Aux)->liga = *Q;
        }
    }
}

void elimiinar_final(struct Nodo **P, struct Nodo **Q, struct Nodo **Aux){
    *Q = *P;
    
    if((*P)->liga == NULL){
        free(*P);
        *P = NULL;
    }else{
        while((*Q)->liga!=NULL){
                *Aux = *Q;
                *Q = (*Q)->liga;
            }
            printf("Dato encontrado como final: %d", (*Q)->info);
            free(*Q);
            (*Aux)->liga = NULL;
    }
    printf("\n\nEl dato se elimino correctamente\n\n");
}

void impresion(struct Nodo **P, struct Nodo **Q){
    int i;
    i = 1;
    *Q = *P;
    while(*Q != NULL){
        printf("%d. %d\n\n", i, (*Q)->info); 
        *Q = (*Q)->liga;
        i++; 
    }
}
void mensaje_lista_vacia(){
    printf("\n-----------------------------------\n");
    printf("\nNo hay lista\n\nCree una lista con la opción 1\n");
    printf("\n-----------------------------------\n");
}