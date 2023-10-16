#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Nodo{
    int info;
    struct Nodo *liga; 
};

bool vacio(struct Nodo **P); 
void mensaje_cola_vacia();
int menu();
int menusub();
void push(struct Nodo **P, struct Nodo **Q, struct Nodo **Aux, int modo);
void pop(struct Nodo **P, struct Nodo **Q, struct Nodo **Aux, int modo);
void impresion(struct Nodo **P, struct Nodo **Q); 

int main(){
    int eleccion;
    int operacion;
    struct Nodo *P = NULL;
    struct Nodo *Q = NULL;
    struct Nodo *Aux = NULL;


    printf("\t\nPrograma Bicolas");
    do{
        eleccion = menu();

        switch(eleccion){
            case 1: 
                do{
                    operacion = menusub();
                    switch(operacion){
                        case 1: 
                            push(&P,&Q,&Aux,1);
                        break;

                        case 2: 
                            vacio(&P)? mensaje_cola_vacia() : pop(&P,&Q, &Aux, 2);
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
                }while(operacion != 0);
            break;

            case 2: 
                do{
                    operacion = menusub();
                    switch(operacion){
                        case 1: 
                            push(&P,&Q,&Aux,2);
                        break;

                        case 2: 
                            vacio(&P)? mensaje_cola_vacia() : pop(&P,&Q, &Aux, 1);
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
                }while(operacion != 0);
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

int menu(){
        int res;
    printf("\n\n");
    printf("1. Entrada Restringida\n");
    printf("2. Salida Restringida\n");
    printf("0. Salida\n");
    printf("Opción: ");
    scanf("%d", &res);

    return res;
}

int menusub(){
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
void mensaje_cola_vacia(){
    printf("\n-----------------------------------\n");
    printf("\nNo hay lista\n\nCree una lista con la opción 1\n");
    printf("\n-----------------------------------\n");
}

bool vacio(struct Nodo **P){
    if(*P != NULL){
        return false;
    }
    return true;
}

void push(struct Nodo **P, struct Nodo **Q, struct Nodo **Aux, int modo){
    int eleccion; 

    if(modo == 1){
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
    }else{
        printf("\n\n Insertar por principio = 1 || Final = 0\n\n");
        scanf("%d", &eleccion);

        switch(eleccion){
            case 1:
                *Aux = (struct Nodo *)malloc(sizeof(struct Nodo));
                printf("\nDame el valor a ingresar: ");
                scanf("%d", &(*Aux)->info);
                if(vacio(P)){
                    *P = *Aux;
                }else{
                    (*Aux)->liga = *P;
                    *P = *Aux;
                }
            break; 

            case 0:
                push(P, Q, Aux, 1);
            break;

            default:
                printf("\n\nOpcion no valida\n\n");
            break;
        }

    }


}

void pop(struct Nodo **P, struct Nodo **Q, struct Nodo **Aux, int modo){
int eleccion;
    if(modo == 1){
        if((*P)->liga == NULL){
            free(*P); 
            *P = NULL;
        }else{
            *Q = (*P)->liga;
            free(*P);
            *P = *Q;
        }
        printf("\n\nEliminacion del primer elemento exitosa\n\n");
    }else{
        printf("\n\n Eliminar por principio = 1 || Final = 2\n\n");
        scanf("%d", &eleccion);

        switch(eleccion){
            case 1:
                pop(P, Q, Aux, 1);
            break; 

            case 2:
                if((*P)->liga == NULL){
                    free(*P); 
                    *P = NULL;
                }else{
                    *Q = *P;
                    while((*Q)->liga != NULL){
                        *Aux = *Q;
                        *Q = (*Q)->liga;
                    }
                    free(*Q);
                    (*Aux)->liga = NULL;
                printf("Aqui si funcina");
                }
            break;

            default:
                printf("\n\nOpcion no valida\n\n");
            break;
        }
    }
}

void impresion(struct Nodo **P, struct Nodo **Q){
    *Q = *P;
    while(*Q != NULL){
        printf("\n\nElemento: %d", (*Q)->info);
        *Q = (*Q)->liga;
    }
    printf("\n\n");
}