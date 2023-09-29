#include <stdlib.h>
#include <stdio.h>

struct Nodo{
    struct Nodo *izq;
    int info;
    struct Nodo *der;
};

int menu();
void creacion(struct Nodo **P, struct Nodo **F);
void impresion(struct Nodo **P, struct Nodo **Q);
void borrar_antes(struct Nodo **P, struct Nodo **Q, struct Nodo **S, struct Nodo **F);
void palindromo(struct Nodo **P, struct Nodo **Q, struct Nodo **S, struct Nodo **F);

int main(){
int res;
struct Nodo *P = NULL;
struct Nodo *F; 
struct Nodo *Q;
struct Nodo *S;

    printf("\n\nPrograma: Algoritmos ligas doblemente ligadas");

    do{
        res = menu();

        switch(res){
            case 1: 
                printf("a");
                borrar_antes(&P, &Q, &S, &F); 
                break;
            case 2: 
                printf("b"); 
                break;
            case 3: 
                printf("c");
                break;
            case 4: 
                printf("d");
                palindromo(&P,&Q,&S,&F);
                break;
            case 5: 
                creacion(&P, &F);
                impresion(&P, &Q);
                break;
        }

    }while(res!=0);

    return 0;
}

int menu(){
    int res;
    printf("\n\n1. Eliminacion de un nodo anterior al de un nodo dado\n\n");
    printf("2. Insercion de un elemento al principio de la liga\n\n");
    printf("3. Insercion de elemento despues uno dado\n\n");
    printf("4. Determinar si es un palindromo\n\n");
    printf("5. Creacion de la lista\n\n");
    printf("0. Salida\n\n");
    printf("Dame la elcción escogida: ");
    scanf("%d", &res);

    return res;
}

void creacion(struct Nodo **P, struct Nodo **F){
int n, i, dato;
    *P = (struct Nodo *)malloc(sizeof(struct Nodo));
    (*P)->izq = NULL;
    (*P)->der = NULL;
    *F = *P;

    printf("\n\nNumero de valores a almacenar: ");
    scanf("%d", &n);
        printf ("\n\nDame el valor a almacenar: ");
        scanf("%d", &(*F)->info);
        n = n-1;   

    for(i=0; i<n; i++){
        ((*F)->der)=(struct Nodo *)malloc(sizeof(struct Nodo));
        ((*F)->der)->izq = *F;
        *F = ((*F)->der);  
        (*F)->der=NULL;
        printf ("\n\nDame el valor a almacenar: ");
        scanf("%d", &(*F)->info);
    }
printf("\n\nPRinciopoip: %d", (*P)->info);
printf("\n\nFinal: %d", (*F)->info); 

}

void impresion(struct Nodo **P, struct Nodo **Q){
    *Q = *P;
    printf("\nNull <->");
    while(*Q != NULL){
        printf(" %d <->", (*Q)->info);
        *Q = (*Q)->der;
    }
    printf(" Null");
    printf("\n\n");
}

void borrar_antes(struct Nodo **P, struct Nodo **Q, struct Nodo **S, struct Nodo **F){
int dato; 
int bol=1;
int bolEncontrado = 0;
(*P)->der=(struct Nodo *)malloc(sizeof(struct Nodo));
    if(*P == NULL){
        printf("\nNo hay lista generada");
    }else{
        *Q = *P;
        *S = *F;
        if(*P == *F){
            printf("\n\nSolo hay un elemento, por lo tanto no hay elemento anterior para eliminar");
        }else{
            printf("\nDame el dato a buscar para borrar el anterior: ");
            scanf("%d", &dato); 
            
            if((*P)->info==dato){
                printf("\nNo hay dato anterior a eliminar");
            }else{
                if((*P)->der->info==dato){
                    printf("\n\nEl valor se encontro en el segundo termino");
                }else{
                    while((*S)->der != *Q && *S!=*Q && bol!=0){
                        if((*Q)->info==dato){
                            bol = 0;
                            bolEncontrado = 2;
                            printf("\nQ encontro el valor");
                        }else{
                            if((*S)->info==dato){
                                bol = 0;
                                bolEncontrado = 1;
                                printf("\nS encontro el valor");
                            }else{
                                printf("\n\nNo se encontro el dato");
                                *S = (*S)->izq;
                                *Q = (*Q)->der;
                            }
                        }   
                    }
                }
            }
        }
    }
    printf("\n\nEl valor en el que se quedo S: %d", (*S)->info);
    printf("\n\nEl valor en el que se quedo Q: %d", (*Q)->info);
}

void palindromo(struct Nodo **P, struct Nodo **Q, struct Nodo **S, struct Nodo **F){
    int bol = 1;
    *Q=*P;
    *S=*F;
    if(*P==NULL){
        printf("\n\nNo hay lista generada");
    }else{
        if(*P==*F){
            printf("\n\nSolo existe un elemento en la lista: es palindromo");
        }else{
            while((*Q)->der!=*S && *Q!=*S && bol!=0){
                if((*Q)->info==(*S)->info){
                    bol = 1;
                }else{
                    bol = 0;
                }
                *Q = (*Q)->der;
                *S = (*S)->izq; 
            }
        }
        if(bol == 1 ){
            printf("\n\nSe trata de un palindromo");
        }else{
            printf("\n\nNo es un palindromo");
        }
    }
}