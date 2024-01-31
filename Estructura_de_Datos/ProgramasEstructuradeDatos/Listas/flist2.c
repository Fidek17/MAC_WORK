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

void createBeforeFound(struct Nodo **P, struct Nodo **Q, struct Nodo **Aux, struct Nodo **NewA); 
void createAfterFound(struct Nodo **P, struct Nodo **Q, struct Nodo **Aux, struct Nodo **NewA);
void deleteBeforeFound(struct Nodo **P, struct Nodo **Q, struct Nodo **Aux, struct Nodo **NewA);
void deleteAfterFound(struct Nodo **P, struct Nodo **Q, struct Nodo **Aux);

int main(){
    int eleccion, i, n; 
    struct Nodo *P=NULL;
    struct Nodo *Q; 
    struct Nodo *Aux;
    struct Nodo *NewA;

    printf("\n\tPrograma que realiza algoritmos con listas\n\n"); 

    do{
        eleccion=menu();

        switch(eleccion){
            case 1: 
                printf("\n\nPrimera eleccion\n\n");
                searchelim(&P, &Q, &Aux);
                imprimir(&P, &Q);
            break;
            
            case 2: 
                printf("Segunda  eleccion");
                createBeforeFound(&P, &Q, &Aux, &NewA);
                imprimir(&P, &Q);
            break;
            
            case 3:
                printf("tercera eleccion");
                createAfterFound(&P, &Q, &Aux, &NewA);
                imprimir(&P, &Q);
            break;

            case 4:
                printf("\ncuarta eleccion\n");
                deleteBeforeFound(&P, &Q, &Aux, &NewA);
                imprimir(&P, &Q);
            break;
            
            case 5:
                printf("quinta eleccion");
                deleteAfterFound(&P, &Q, &Aux);
                imprimir(&P, &Q);
            break;
        
            case 6: 
                printf("\n\nSexta eleccion\n\n");
                insfront(&P, &Q, &Aux);
                imprimir(&P, &Q);
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
    printf("\n\n\tMenu de eleccion\n");
    printf("1. Eliminar el nodo que contenga información dada\n");
    printf("2. Insertar un nodo antes del nodo dado\n");
    printf("3. Insertar un nodo despues de un nodo dado\n");
    printf("4. Eliminar un nodo antes del nodo dado\n");
    printf("5. Eliminar un nodo despues de un nodo dado\n");
    printf("6. Crear una lista con cada nuevo elemento al final\n");
    printf("7. Imprimir lista\n");
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
        printf("\nNo hay lista generada\n\n");
    }else{
        printf("\nLa lista de elementos es la siguiente: \n"); 
        while((*Q)!=NULL){
            printf("%d.  %d", i, (*Q)->info);
            i++;
            *Q=(*Q)->liga;
            printf("\n");
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
            *Aux=*Q;
            *Q=(*Q)->liga; 
        }
        if((*Q)->info==dato){
            (*Aux)->liga=(*Q)->liga;
            printf("\nEl dato SI se encontro y se elimino correctamente\n\n");
        }else{
            printf("\n\nNo se encontro el dato"); 
        }
    }
}

void createBeforeFound(struct Nodo **P, struct Nodo **Q, struct Nodo **Aux, struct Nodo **NewA){
int dato, datonew; 
    if(*P==NULL){
        printf("\n\nNo hay lista generada\n\n");
    }else{
        *Q=*P;

        printf("\nDame el dato a buscar para insertar uno nuevo detras: ");
        scanf("%d", &dato);
        if((*Q)->info==dato){
            *Q=(struct Nodo *)malloc(sizeof(struct Nodo));
                printf("\n\n Si se encontro el dato \n\n"); 
                printf("\nDame el nuevo dato a ingresar detras: ");
                scanf("%d", &datonew);
                (*Q)->info=datonew;
                (*Q)->liga=*P;
                *P=*Q;
        }else{
            while((*Q)->liga!=NULL && (*Q)->info!=dato){
                *Aux=*Q;
                *Q=(*Q)->liga;
            }
            
            if((*Q)->info==dato){
                *NewA=(struct Nodo *)malloc(sizeof(struct Nodo));
                printf("\n\n Si se encontro el dato \n\n"); 
                printf("\nDame el nuevo dato a ingresar detras: ");
                scanf("%d", &datonew);
                (*NewA)->info=datonew;
                (*Aux)->liga=*NewA;
                (*NewA)->liga=*Q;
                printf("\n\nEl dato se inserto correctamente");
            }else{
                printf("\n\nNo se encontro el elemento\n\n");
            }
        }
    }
    printf("\n\n"); 
}

void createAfterFound(struct Nodo **P, struct Nodo **Q, struct Nodo **Aux, struct Nodo **NewA){
int dato;
    if(*P==NULL){
        printf("\n\nNo hay lista generada\n\n");
    }else{
        *Q=*P;
        printf("\n\nDame el valor a buscar en la lista: ");
        scanf("%d", &dato);
        while((*Q)->liga!=NULL && (*Q)->info!=dato){
            *Q=(*Q)->liga;
        }
        if((*Q)->info==dato){
            *Aux=(struct Nodo *)malloc(sizeof(struct Nodo));
            printf("\nDame el dato a ingresar a continuacion: "); 
            scanf("%d", &(*Aux)->info);
            if((*Q)->liga==NULL){
                printf("\n\nEl elemento es el ultimo\n\n"); 
                (*Aux)->liga=NULL;
                (*Q)->liga=(*Aux); 
            }else{
                (*Aux)->liga=(*Q)->liga;
                (*Q)->liga=(*Aux);
            }

        }else{
            printf("\n\nNo se encontro el dato\n");
        }
    }
}

void deleteBeforeFound(struct Nodo **P, struct Nodo **Q, struct Nodo **Aux, struct Nodo **NewA){
        int dato;
        if(*P==NULL){
            printf("\n\nNo hay lista generada");
        }else{
            *Q=*P; //
            // *Aux = *Q;
            // *Saux = *Aux;


            printf("\nDame el dato a buscar y eliminar el elemento anterior a éste: ");
            scanf("%d", &dato);

            if((*P)->info==dato){
                printf("\n----No hay  nodo anterior para eliminar\n\n");
            }else{
               
                while((*Q)->liga !=NULL && (*Q)->info!=dato){
                    *NewA = *Aux;
                    *Aux = *Q;
                    *Q=(*Q)->liga;
                }

                if((*Q)->info==dato){
                    if ((*P)->liga == (*Aux)->liga){
                        *P=*Q;
                    }else{

                    (*NewA)->liga= *Q;
                    free(*Aux);
                    printf("\nEl dato SI se encontro y se elimino correctamente\n\n");
                    }
                }else{
                    printf("\n\nNo se encontro el dato"); 
                }
            }
        }
}

void deleteAfterFound(struct Nodo **P, struct Nodo **Q, struct Nodo **Aux){
    int dato; 
    if(*P==NULL){
        printf("\n\nNo hay lista generada\n\n");
    }else{
        *Q=*P;
        printf("\n\nDame el dato a buscar en la lista: ");
        scanf("%d", &dato);
        while((*Q)->liga!=NULL && (*Q)->info!=dato){
            *Q=(*Q)->liga;
        }
        if((*Q)->info==dato){
            if((*Q)->liga==NULL){
                printf("\n\nNo hay elemento siguiente que eliminar\n\n");
            }else{
                *Aux=(*Q)->liga;
                if((*Aux)->liga==NULL){
                    free(*Aux); 
                    (*Q)->liga=NULL;
                }else{
                    (*Q)->liga=(*Aux)->liga;
                    free(*Aux);
                }
            }
        }else{
            printf("\n\nNo se encontro el dato\n\n");
        }
    }

}