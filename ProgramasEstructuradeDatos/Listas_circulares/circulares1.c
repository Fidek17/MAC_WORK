#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h> //para el uso de bools

struct Nodo{
    int info;
    struct Nodo *der;
};

int menu();
bool lista_vacia(struct Nodo **P);
void creacion_por_final(struct Nodo **P, struct Nodo **F);
void imprimir_lista(struct Nodo **P, struct Nodo **F);

int main(){
    struct Nodo *PRINCIPIO = NULL;
    struct Nodo *FINAL = NULL;
    // struct Nodo *AUX;
    int dato, res;

    do{
        res = menu();

        switch(res){
            case 1: 
                creacion_por_final(&PRINCIPIO, &FINAL);
                imprimir_lista(&PRINCIPIO, &FINAL);
                break;
            case 2: 
                if(lista_vacia(&PRINCIPIO)){
                    // creación de lista??
                    break;
                }
                // Ejecución de código

                break;
            case 3:
                if(!lista_vacia(&PRINCIPIO)){ 
                }
                break;
            case 4:
                if(!lista_vacia(&PRINCIPIO)){
                }
                break;
            case 5: 
                break;

            case 6: 
                if(!lista_vacia(&PRINCIPIO)){
                    imprimir_lista(&PRINCIPIO, &FINAL);
                }

                break;
        }

    }while(res!=0);
    
    free(PRINCIPIO);
    free(FINAL);

    return 0;
}

int menu(){
    int res;
    printf("\n\n");
    printf("1. ALGORITMO QUE CREA UNA LISTA CIRCULAR POR EL FINAL (5,3,19,7)\n");
    printf("2. ALGORITMO QUE IMPRIMA EL CONTENIDO DE UNA LISTA CIRCULAR\n");
    printf("3. ALGORITMO QUE ELIMINA EL PRIMER ELEMENTO DE UNA LISTA CIRCULAR\n");
    printf("4. ALGORITMO QUE BUSCA UN ELEMENTO CON INFORMACIÓN DADA POR EL USUARIO EN UNA LISTA CIRCULAR Y QUE IMPRIMA LA DIRECCIÓN DEL ELEMENTO ANTECEDENTE Y LA INFORMACIÓN DEL ELEMENTO CONSECUENTE (BUSCAR EL 4, BUSCAR EL 3)\n");
    printf("5. Creacion de la lista\n");
    printf("6. Impresión\n");
    printf("0. Salida\n");
    printf("Opción: ");
    scanf("%d", &res);

    return res;
}

bool lista_vacia(struct Nodo **P){
    if (*P){
        return false;
    }
    printf("\n-----------------------------------\n");
    printf("\nNo hay lista\n\nCree una lista con la opción 1\n");
    printf("\n-----------------------------------\n");
    return true;
}

void creacion_por_final(struct Nodo **P, struct Nodo *
*F){
    // *AUX = (struct Nodo *)malloc(sizeof(struct Nodo));
    int cantidad, i, dato;
    *P = (struct Nodo*)malloc(sizeof(struct Nodo));
    *F = (struct Nodo*)malloc(sizeof(struct Nodo));
    
    printf("\nIngrese la cantidad de elementos en la lista: ");
    scanf("%d", &cantidad);
    printf("\nElemento del nodo: ");   
    scanf("%d", &(*P)->info);
    
    struct Nodo *AUX = *P;
    AUX = *P;
    (*P)->der = *F;
    *F = *P;
    // *AUX = (*AUX)->der;
    (*F)->der = *P;      

    // AUX = AUX->der;
    for (i = 1; i < cantidad; i++){
        AUX = (struct Nodo *)malloc(sizeof(struct Nodo));
        printf("Elemento del nodo: ");   
        scanf("%d", &dato);

        AUX->info = dato;
        *F = AUX;
        (*F)->der = *P;   
        printf("--%d\n", i);
        // AUX = AUX->der;
    }
    // free(AUX);
    AUX = NULL;
}

void imprimir_lista(struct Nodo **P, struct Nodo **F){
    // int cantidad, i, dato;
    struct Nodo *AUX = *P;
    // AUX = (struct Nodo *)malloc(sizeof(struct Nodo));
    // *P = (struct Nodo*)malloc(sizeof(struct Nodo));
    // *F = (struct Nodo*)malloc(sizeof(struct Nodo));
    // *AUX = (struct Nodo *)malloc(sizeof(struct Nodo));
    
    printf("\n\nLista\n");
    // AUX = *P;

    do{
    
        printf(" %d ->", AUX->info);
        AUX = AUX->der;
        // printf("\nAja\n");
    
    }while(AUX != *P);
    printf("\n\nLesto\n");

}