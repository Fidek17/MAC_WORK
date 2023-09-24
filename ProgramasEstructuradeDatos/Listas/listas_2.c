#include <stdio.h>
#include <stdlib.h>

struct Nodo{
    int info;
    struct Nodo *liga;
}; 

int menu(); 
void insfront(struct Nodo **P, struct Nodo **Q, struct Nodo **Aux);
void imprimir(struct Nodo **P, struct Nodo **Q);
void searchelim(struct Nodo **P, struct Nodo **Q, struct Nodo **Aux);

int main(){
    int eleccion;
    struct Nodo *P=NULL;
    struct Nodo *Q; 
    struct Nodo *Aux;
    int i, n; 

printf("\n\tPrograma que realiza algoritmos con listas\n\n"); 

    do{
        eleccion=menu();

        switch(eleccion){
            case 1: 
                printf("\n\nPrimera eleccion\n\n");
    
                break;
            case 2: 
                printf("Seunda  eleccion");
                break;
            case 3:
                printf("tercera eleccion");
                break;
            case 4:
                printf("cuarta eleccion");
                break;
            case 5:
                printf("quinta eleccion");
                break;
            case 6: 
                printf("\n\nSexta eleccion\n\n");
                insfront(&P, &Q, &Aux);
                break;
            case 7: 
                printf("\n\nSeptima eleccion\n\n");
                imprimir(&P, &Q);
                break;
        }   

    }while(eleccion!=0);


    return 0; 
}

int menu(){
    int res;
    printf("\n\n\tMenu de eleccion\n\n");
    printf("1. Eliminar el nodo que contenga información dada\n\n");
    printf("2. Insertar un nodo antes del nodo que coincida con la informacion dada\n\n");
    printf("3. Insertar un nodo despues de un nodo especifico que coincida con la informacion dada\n\n");
    printf("4. Eliminar un nodo antes del nodo que coincida con la inforamcion dada\n\n");
    printf("5. Eliminar un nodo despues de un nodo que coincida con la informacion dada\n\n");
    printf("6. Crear una lista con cada nuevo elemento al final\n\n");
    printf("7. Imprimir lista\n\n");
    printf("0. Salir\n");

    printf("--------------------------------------------");
    printf("\n\nElige una de las alternativas: ");
    scanf("%d", &res);
    return res;
}

void insfront(struct Nodo **P, struct Nodo **Q, struct Nodo **Aux){
    int n, i; 

    printf("\n\nDame el numero de valores a ingresar: ");
    scanf("%d", &n);

    for(i=1; i<=n; i++){
        *Aux=(struct Nodo *)malloc(sizeof(struct Nodo));
        printf("\n\nDame el valor a ingresar: ");
        scanf("%d", &(*Aux)->info); 
        (*Aux)->liga=NULL; 

        if(*P==NULL){
            *P=*Aux;
        }else{
            *Q=*P;
            while((*Q)->liga!=NULL){
                *Q=(*Q)->liga;
            }
            (*Q)->liga=*Aux;
        }

    }
    printf("\n\n");
}

void imprimir(struct Nodo **P, struct Nodo **Q){
    int i = 1; 
    *Q=*P;

    if(*P==NULL){
        printf("No hay lista generada\n\n");
    }else{
        printf("\nLa lista de elementos es la siguiente: \n"); 
        while((*Q)!=NULL){
            printf("%d.  %d", i, (*Q)->info);
            i++;
            *Q=(*Q)->liga;
            printf("\n\n");
        }
    }
    printf("\n");
}

void searchelim(struct Nodo **P, struct Nodo **Q, struct Nodo **Aux){
    int dato;
        if(*P==NULL){
            printf("\n\nNo hay lista generada");
        }else{
            *Q=*P;

            printf("\nDame el dato a buscar y eliminar: ");
            scanf("%d", &dato);

            while((*Q)->liga!=NULL && (*Q)->info!=dato){
                *Q=(*Q)->liga; 
            }
            if((*Q)->info==dato){
                printf("\nEl dato SI se encontro");
            }else{
                printf("\n\nNo se encontro el dato"); 
            }
        }


}