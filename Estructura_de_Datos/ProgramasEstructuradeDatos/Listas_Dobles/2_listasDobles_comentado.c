#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h> //para el uso de bools

struct Nodo{
    struct Nodo *izq;
    int info;
    struct Nodo *der;
};

int menu();
void creacion(struct Nodo **P, struct Nodo **F);
bool lista_vacia(struct Nodo **P, struct Nodo **F); //verifica si la lista está vacía
void impresion(struct Nodo **P, struct Nodo **Q);

void borrar_antes(struct Nodo **P, struct Nodo **Q, struct Nodo **S, struct Nodo **F); // 1.-
void insercion_principio(struct Nodo **P, struct Nodo **Q); // 2.-
void insercion_posterior_nodo(struct Nodo **P, struct Nodo **Q, struct Nodo **S, struct Nodo **F); // 3.-
void palindromo(struct Nodo **P, struct Nodo **Q, struct Nodo **S, struct Nodo **F); // 4.-

struct Nodo *buscarNodo(struct Nodo **P, struct Nodo **Q, struct Nodo **S, struct Nodo **F, int dato);


int main(){
    struct Nodo *P = NULL;
    struct Nodo *F = NULL;
    struct Nodo *Q;
    struct Nodo *S;
    struct Nodo *prueba;
    int dato, res;

    printf("\n\nPrograma: Algoritmos ligas doblemente ligadas");

    do{
        res = menu();

        switch(res){
            case 1: 
                if(!lista_vacia(&P,&F)){ //Si no está vacía
                    borrar_antes(&P, &Q, &S, &F); 
                    impresion(&P, &Q);
                }
                break;
            case 2: 
                insercion_principio(&P, &Q);
                impresion(&P, &Q); 
                break;
            case 3:
                if(!lista_vacia(&P,&F)){ 
                    insercion_posterior_nodo(&P, &Q, &S, &F);
                    impresion(&P, &Q);
                }
                break;
            case 4:
                if(!lista_vacia(&P,&F)){
                    palindromo(&P,&Q,&S,&F);
                    impresion(&P, &Q);
                }
                break;
            case 5: 
                creacion(&P, &F);
                impresion(&P, &Q);

                break;

            case 6: 
                if(!lista_vacia(&P,&F)){
                    impresion(&P, &Q);
                }

                break;
/*
            case 6:
                impresion(&P, &Q);
        
                printf("\nnodo a buscar: ");
                scanf("%d", &dato);
                
                prueba = buscarNodo(&P, &Q, &S, &F, dato);
                printf("\n%d\n", S->info);
                printf("\n%d\n", Q->info);
                printf("\n---\n");
                // printf("\n%d\n", (*prueba).izq);
                if (prueba != NULL){ // Si encontro el valor
                    printf("\nElemento anterior al nodo dado: %d\n", (*prueba).izq->info);
                    printf("\n%d\n", prueba->info);
                    printf("\nElemento siguiente al nodo dado: %d\n", (*prueba).der->info);
                }
                printf("\n---\n");
*/
        }

    }while(res!=0);

    return 0;
}

int menu(){
    int res;
    printf("\n\n1. Eliminacion de un nodo anterior al de un nodo dado\n");
    printf("2. Insercion de un elemento al principio de la liga\n");
    printf("3. Insercion de un elemento despues uno dado\n");
    printf("4. Determinar si es un palindromo\n");
    printf("5. Creacion de la lista\n");
    printf("6. Impresión\n");
    // printf("6. Busqueda de una Nodo. Por inicio y final\n\n");
    printf("0. Salida\n");
    printf("Opción: ");
    scanf("%d", &res);

    return res;
}

void creacion(struct Nodo **P, struct Nodo **F){
int n, i, dato;
    *P = (struct Nodo *)malloc(sizeof(struct Nodo));
    (*P)->izq = NULL;
    (*P)->der = NULL;
    *F = *P;
    int array[7] = {7,4,9,3,7,1,3};

    // printf("\n\nNumero de valores a almacenar: ");
    // scanf("%d", &n);
    n=8;
        // printf ("\n\nDame el valor a almacenar: ");
        // scanf("%d", &(*F)->info);
    (*F)->info = array[0]; 
    n = n-1;   

    for(i=1; i<n; i++){
        ((*F)->der)=(struct Nodo *)malloc(sizeof(struct Nodo));
        ((*F)->der)->izq = *F;
        *F = ((*F)->der);
        (*F)->der=NULL;
        // printf ("\n\nDame el valor a almacenar: ");
        // scanf("%d", &(*F)->info);
        (*F)->info = array[i]; 
    }
}

bool lista_vacia(struct Nodo **P, struct Nodo **F){
    if (*P == NULL &&  *F == NULL){

        printf("\n-----------------------------------\n");
        printf("\nNo hay lista\n\nCree una lista con la opción 5\n");
        printf("\n-----------------------------------\n");
        return true;
    }
    else{
        return false;
    }
    
}

void impresion(struct Nodo **P, struct Nodo **Q){
    *Q = *P;
    printf("\n\n\tNull <->");
    while(*Q != NULL){
        printf(" %d <->", (*Q)->info);
        *Q = (*Q)->der;
    }
    printf(" Null");
    printf("\t\n\n");
}

void borrar_antes(struct Nodo **P, struct Nodo **Q, struct Nodo **S, struct Nodo **F){
    int dato; 
    struct Nodo *aux;
    *Q=(struct Nodo *)malloc(sizeof(struct Nodo));

    if(*P==*F){
        printf("\n\nNo hay valor anterior que eliminar");
    }else{
        printf("\n\nDame el valor a buscar: ");
        scanf("%d", &dato);
        *S = buscarNodo(P, Q, S, F, dato);
        
        if (*S != NULL){
            *Q = *S; //para no cambiar las variables con Q
            if(*Q==*P){
                printf("\n\nEl valor se encuentra en el principio, por lo tanto no hay anterior");
            }else{
                if((*Q)->izq==*P){
                    *P = *Q;
                    free((*Q)->izq);
                    (*P)->izq=NULL;
                }else{
                    aux = (*Q)->izq; 
                    (aux->izq)->der = *Q;
                    // ((*Q)->izq->izq)->der = *Q;
                    (*Q)->izq = aux->izq; 
                    free(aux); 
                    // free((*Q)->izq); 
                }
                printf("\n\nEl valor se borro exitosamente");
            }
        }else{
            printf("\n\nNo se encontro el dato");
        }
    }
}

void insercion_principio(struct Nodo **P, struct Nodo **Q){
    *Q = (struct Nodo *)malloc(sizeof(struct Nodo)); //Sino se rompe, ya que no hay una asignación de memoria

    printf("\n\nDame el valor a almacenar: ");
    scanf("%d", &(*Q)->info);
        
    (*Q)->der = *P;
    (*Q)->izq = NULL;

    *P = *Q; // Actualizar P para que apunte al nuevo nodo Q
}

void insercion_posterior_nodo(struct Nodo **P, struct Nodo **Q, struct Nodo **S, struct Nodo **F){
    int dato;
    // if (!lista_vacia(P,F)){ //Si no está vacía

        printf("\n Se insertará un nodo delante del indicado ");
        printf("\n Ingresa el nodo: ");
        scanf("%d", &dato);
        
        *Q = buscarNodo(P, Q, S, F, dato);

        if (*Q != NULL){ //Encontro el dato
            
            *S = (struct Nodo *)malloc(sizeof(struct Nodo));
            printf("\n\nDame el valor a almacenar: ");
            scanf("%d", &(*S)->info);
            
            if ((*Q)->der == NULL){ //Si es el último elemento
                (*Q)->der = *S;
                (*S)->der = NULL;
                (*S)->izq = *Q;
            }
            else{
            //Asignaciones del nuevo elemento a los adyacentes
                (*S)->der = (*Q)->der;
                (*Q)->der->izq = *S;
                (*Q)->der = *S;
                (*S)->izq = *Q;            
            }
        }
        else{
            return;
        }
    // }
    // else{ //Está vacia
        // return; 
    // }
}

void palindromo(struct Nodo **P, struct Nodo **Q, struct Nodo **S, struct Nodo **F){
    int bol = 1;
    *Q=*P;
    *S=*F;

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

struct Nodo *buscarNodo(struct Nodo **P, struct Nodo **Q, struct Nodo **S, struct Nodo **F, int dato){

    *Q = *P;
    *S = *F;
    // int i=0;
    /*
    LOS BLOQUES DE CÓDIGO COMENTADO FUNCIONAN, PERO DABAN INFORMACIÓN INNECESARIA PARA LOS PROGRAMAS YA QUE SOLO REQUERIAMOS EL NODO

    printf("\n\tEL DATO A BUSACAR: %d", dato);
    
    printf("\n\t :::: iteraciones del while sin entrar en condiciones: ");
    printf("\n\t ---- iteracion de Q");
    printf("\n\t ++++ iteracion de S\n");

    */
   //Con do-while por lo menos revisamos la lista una vez en caso de que haya solo un elemento
   do
   {
    // while(*Q != NULL && *S != NULL){
        // i++;
        if ((*Q)->info == dato ){
            /*
            printf("\n\t-- Se encontro con el nodo Q: %d", (*Q)->info);
            printf("\n\t-----%d", i);
            */
            return *Q;
            // break; con return es suficiente para salir del ciclo y de la función. Obviamente, asi que con que me lo regresen alguno de los dos, x quién lo devolvió, solo con tener el nodo, joya.
        }
        else if ((*S)->info == dato ){
            /*
            printf("\n\t-- Se encontro con el nodo S: %d", (*S)->info);
            printf("\n\t++++%d", i);
            */
            return *S;
        }

        // Aunq podría ser suficiente con que Q==NULL o S==NULL, una condición... atómica?
        if((*Q)->der == NULL && (*S)->izq == NULL){
            printf("\n\t--NO SE ENCONTRO EL ELEMENTO EN LA LISTA");
            return NULL;
        }
        // printf("\n\t:::: %d", i);

        if(*Q != NULL){
            *Q = (*Q)->der;
        }
        if(*S != NULL){
            *S = (*S)->izq;
        }
    // }
    } while (*Q != NULL && *S != NULL);
    printf("\ns");
}
