#include <stdio.h>
#include <stdlib.h>

#include "bibliote.h"

/*
struct Nodo{
    int info;
    struct Nodo *liga;
};
*/

int menu();
void insback(struct Nodo **P, struct Nodo **Q); 
void mostrar(struct Nodo **P, struct Nodo **Q);
void eliminarf(struct Nodo **P, struct Nodo **Q, struct Nodo **Aux);
void insfront(struct Nodo **P, struct Nodo **Q, struct Nodo **Aux);
void search(struct Nodo **P, struct Nodo **Q);
void insNback(struct Nodo **P, struct Nodo **Q); 
void insNfront(struct Nodo **P, struct Nodo **Q, struct Nodo **Aux); 

int main(){
int eleccion;
struct Nodo *Aux;
struct Nodo *P=NULL;
struct Nodo *Q;

int i,n;
    printf("\n\nPrograma que realiza las siguientes operaciones con listas: \n");

    do{
        eleccion=menu();

        switch(eleccion){
            case 1:
                printf("\n\nLista Inicio\n\n"); 
                insback(&P,&Q);

            break;
            case 2:
                printf("\n\nLa lista y sus elementos es la siguiente: \n");
                mostrar(&P,&Q);
            break;
            case 3:
                printf("\n");
                eliminarf(&P,&Q,&Aux);
            break;
            case 4:
                printf("\n\nLista Final\n\n");
                insfront(&P,&Q,&Aux);
            break;
            case 5:
                printf("\n\nBusqueda de elemento en lista\n\n");
                search(&P,&Q);
            break;
            case 6:
                printf ("\n\nInsercion de elementos al inicio de la lista\n\n");
                insNback(&P,&Q);
            break;
            case 7:
                printf("\n\nInsercion de elementos al final de la lista\n\n");
                insfront(&P,&Q,&Aux);
            break;
            case 8:
            printf("8 eleccion");
            break;
        }
    }while(eleccion!=0);

    return 0;
}

int menu(){
int res;
    printf("1. Crear lista y agregar elemntos por el inicio\n");
    printf("2. Imprimir la lista \n");
    printf("3. Eliminar el ultimo elemento de una lista creada\n");
    printf("4. Crear lista y agregar elementos al final de ella\n");
    printf("5. Buscar un elemento dentro de la lista\n");
    printf("6. Insertar elmentos por el inicio de una lista existente \n");
    printf("7. Insertar elementos por el final de una lista existente \n");
    printf("8. Eliminar el primer elemento de una lista\n");
    printf("0. Salir\n");

    printf("Ingresa la opcion que deseas ejecutar: "); 
    scanf("%d", &res);
    return res;
}
