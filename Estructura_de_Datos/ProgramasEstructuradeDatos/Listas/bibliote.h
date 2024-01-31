#include <stdio.h>
#include <stdlib.h>

struct Nodo{
    int info;
    struct Nodo *liga;
};

void insback(struct Nodo **P, struct Nodo **Q){
    
    int i,n;
    printf("\nNumero de valores a ingresar: ");
    scanf("%d", &n); 

    for(i=1; i<=n; i++){
        *Q=(struct Nodo *)malloc(sizeof(struct Nodo));
        printf("\n\nDame el valor a ingresar: "); 
        scanf("%d", &(*Q)->info);
        (*Q)->liga=*P;
        *P=*Q;

    }

}

void mostrar(struct Nodo **P, struct Nodo **Q){
                 int i = 1;
             *Q=*P;
                while((*Q)!=NULL){
                    printf("%d. %d", i, (*Q)->info);
                    *Q=(*Q)->liga;
                    i++;
                    printf("\n"); 
                }
                printf("\n");
}

void eliminarf(struct Nodo **P, struct Nodo **Q, struct Nodo **Aux){
            if(*P==NULL){
                printf("\nNo hay elementos");
            }else{
                if((*P)->liga==NULL){
                    free(*P);
                    *P=NULL;
                }else{
                    *Q=*P;
                    *Aux=NULL;
                    while((*Q)->liga!=NULL){
                        *Aux=*Q;
                        *Q=(*Q)->liga; 
                    }
                    free(*Q);
                    (*Aux)->liga=NULL;
                }
                printf("Se elimino el elemento correctamente");
            }

}

void insfront(struct Nodo **P, struct Nodo **Q, struct Nodo **Aux){
    int n,i; 
                *P=NULL;
            printf("\nNumero de valores a ingresar: ");
            scanf("%d", &n);
                for(i=1; i<=n; i++){
                    *Aux =(struct Nodo *)malloc(sizeof(struct Nodo)); 
                    printf("\n\nDame el valor que deseas ingresar: ");
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
}

void search(struct Nodo **P, struct Nodo **Q){
int dato;
    if(*P==NULL){
        printf("\nNo hay elementos\n");
    }else{
        printf("\n\nDame el elemento a buscar: ");
        scanf("%d", &dato); 
        *Q=*P;
        while((*Q)->liga!=NULL && (*Q)->info!=dato){
            *Q=(*Q)->liga; 
        }
        if((*Q)->info==dato){
            printf("\nEL dato %d SI existe en la lista\n", dato); 
        }else{
            printf("\nEL dato %d NO existe en la lista\n", dato); 
        }
    }


}

void insNback(struct Nodo **P, struct Nodo **Q){
    int i,n;

    if(*P==NULL){
        printf("\n\nNo hay una lista existente");
    }else{
        printf("\nNumero de valores a ingresar: ");
        scanf("%d", &n); 

        for(i=1; i<=n; i++){
            *Q=(struct Nodo *)malloc(sizeof(struct Nodo));
            printf("\n\nDame el valor a ingresar: "); 
            scanf("%d", &(*Q)->info);
            (*Q)->liga=*P;
            *P=*Q;
        }

    }
    printf("\n");
}

void insNfront(struct Nodo **P, struct Nodo **Q, struct Nodo **Aux){
    int n,i; 
        printf("\nNumero de valores a ingresar: ");
        scanf("%d", &n);
        for(i=1; i<=n; i++){

            *Aux =(struct Nodo *)malloc(sizeof(struct Nodo)); 
            printf("\n\nDame el valor que deseas ingresar: ");
            scanf("%d", &(*Aux)->info); 
            (*Aux)->liga=NULL;

                *Q=*P;
                while((*Q)->liga!=NULL){
                    *Q=(*Q)->liga;
                
            (*Q)->liga=*Aux; 
            }

                }

}