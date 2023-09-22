#include <stdio.h>
#include <stdlib.h>

struct Nodo{
    int info;
    struct Nodo *liga;
};

int menu();

int main(){
int eleccion;
struct Nodo *Aux;
struct Nodo *P=NULL;
struct Nodo *Q;
int i,n;


    do{
        eleccion=menu();

        switch(eleccion){
            case 1:
            printf("\n\nLista Inicio\n\n"); 
                printf("\nNumero de valores a ingresar: ");
                scanf("%d", &n); 

                for(i=1; i<=n; i++){
                    Q=(struct Nodo *)malloc(sizeof(struct Nodo));
                    printf("\n\nDame el valor a ingresar: "); 
                    scanf("%d", &Q->info);
                    Q->liga=P;
                    P=Q;

                }

            break;
            case 2:
            printf("\n\nLa lista y sus elementos es la siguiente: \n");
             i = 1;
             Q=P;
                while(Q!=NULL){
                    printf("%d. %d", i, Q->info);
                    Q=Q->liga;
                    i++;
                    printf("\n"); 
                }
            break;
            case 3:
            printf("\n\n");
            if(P==NULL){
                printf("\nNo hay elementos");
            }else{
                if(P->liga==NULL){
                    free(P);
                    P=NULL;
                }else{
                    Q=P;
                    Aux=NULL;
                    while(Q->liga!=NULL){
                        Aux=Q;
                        Q=Q->liga; 
                    }
                    free(Q);
                    Aux->liga=NULL;
                }
                printf("Se elimino el elemento correctamente");
            }
            break;
            case 4:
            printf("\n\n");
            P=NULL;
            printf("\nNumero de valores a ingresar: ");
            scanf("%d", &n);
                for(i=1; i<=n; i++){
                    Aux =(struct Nodo *)malloc(sizeof(struct Nodo)); 
                    printf("\n\nDame el valor que deseas ingresar: ");
                    scanf("%d", &Aux->info); 
                    Aux->liga=NULL;
                    if(P==NULL){
                        P=Aux;
                    }else{
                        Q=P;
                        while(Q->liga!=NULL){
                            Q=Q->liga;
                        } 
                    Q->liga=Aux; 
                    }

                }
            break;
            case 5:
            printf("Eleccion 5");
            break;
            case 6:
            printf("6 eleccion");
            break;
            case 7:
            printf("7 eleccion");
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
    printf("\n\nPrograma que realiza las siguientes operaciones con listas: \n");
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