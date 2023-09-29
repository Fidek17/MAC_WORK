#include <stdlib.h>
#include <stdio.h>

struct Nodo{
    struct Nodo *izq;
    int info;
    struct Nodo *der;
};

int menu();
// void creacion(struct Nodo **P, struct Nodo **F);
void creacion_fluida(struct Nodo **P, struct Nodo **F);
void impresion(struct Nodo **P, struct Nodo **Q);
// void borrar_antes(struct Nodo **P, struct Nodo **Q, struct Nodo **S, struct Nodo **F);
void impresion_Final_Principio(struct Nodo **P, struct Nodo **Q, struct Nodo **F);
void busqueda(struct Nodo **P, struct Nodo **Q, struct Nodo **S, struct Nodo **F, int dato);
// struct Nodo *crearNodo(int valor);
struct Nodo *buscarNodo(struct Nodo **P, struct Nodo **Q, struct Nodo **S, struct Nodo **F, int dato);

int main(){
int res;
    struct Nodo *P = NULL;
    struct Nodo *F; 
    // (*F).der = NULL;
    struct Nodo *Q;
    struct Nodo *S;
    struct Nodo *prueba;
    int dato;

    // prueba->info=12;


    // }
    

    printf("\n\nPrograma: Algoritmos ligas doblemente ligadas");

    do{
        res = menu();

        switch(res){
            case 1: 
                printf("a");
                creacion_fluida(&P, &F);
                impresion(&P, &Q);
                // borrar_antes(&P, &Q, &S, &F); 
                break;
            case 2:
                printf("b"); 
                creacion_fluida(&P, &F);
                impresion(&P, &Q); 
                break;
            case 3: 
                printf("c");
                creacion_fluida(&P, &F);
                impresion(&P, &Q);
                break;
            case 4: 
                printf("d");
                creacion_fluida(&P, &F);
                impresion(&P, &Q);
                break;
            case 5: 
                creacion_fluida(&P, &F);
                impresion(&P, &Q);

                break;
            case 6:
                impresion(&P, &Q);
                
                printf("\nnodo a buscar: ");
                scanf("%d", &dato);
                
                prueba = buscarNodo(&P, &Q, &S, &F, dato);
                // printf("\n%d\n", prueba->izq);
                printf("\n---\n");
                // printf("\n%d\n", (*prueba).izq);
                if ((*prueba).izq != NULL){
                printf("\nElemento anterior al nodo dado: %d\n", (*prueba).izq->info);
                }


                printf("\n%d\n", prueba->info);
                if ((*prueba).der != NULL){
                    printf("\nElemento siguiente al nodo dado: %d\n", (*prueba).der->info);
                    printf("\n---\n");
                }
                

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
    printf("6. Busqueda de una Nodo. Por inicio y final\n\n");
    printf("0. Salida\n\n");
    printf("Dame la elcción escogida: ");
    scanf("%d", &res);

    return res;
}

void creacion(struct Nodo **P, struct Nodo **F){
int n, i, dato;
    *P = (struct Nodo *)malloc(sizeof(struct Nodo));
    printf("\n\nInicializacion de Nodo Principio\n");
    printf("\nDame el valor a almacenar: ");
    scanf("%d", &(*P)->info);
    (*P)->izq = NULL;
    (*P)->der = NULL;
    *F = *P;

    printf("\n\nNumero de valores a almacenar: ");
    scanf("%d", &n);

    for(i=0; i<n; i++){
        ((*F)->der)=(struct Nodo *)malloc(sizeof(struct Nodo));
        ((*F)->der)->izq = *F;
        *F = ((*F)->der);  
        (*F)->der=NULL;
        printf ("\n\nDame valor a almacenar: ");
        scanf("%d", &(*F)->info);
    }

}

void creacion_fluida(struct Nodo **P, struct Nodo **F){
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

void impresion_Final_Principio(struct Nodo **P, struct Nodo **Q, struct Nodo **F){
    *Q = *F;
    printf("\nNull <->");
    while(*Q != NULL){
        printf(" %d <->", (*Q)->info);
        *Q = (*Q)->izq;
    }
    printf(" Null");
    printf("\n\n");
}

/*


void busqueda(struct Nodo **P, struct Nodo **Q, struct Nodo **S, struct Nodo **F, int dato){
    *Q = *P;
    *S = *F;
    int i=0;
    // printf("\nNull <->");
    while(*Q != NULL && *S != NULL){
        // printf(" %d <->", (*Q)->info);
        // printf(" %d <--->", (*S)->info);
        i++;
        if (((*Q)->info == dato) || ((*S)->info == dato) ){
            printf("\n\t\t\t%d", dato);
            printf("\n\t||%d or %d||\n", (*Q)->info, (*S)->info);
            printf("-----%d", i);
            break;
        }
        
        printf("\n\t-%d", i);
        *Q = (*Q)->der;
        *S = (*S)->izq;
    }
    printf(" Null");
    printf("\n\n");
}

*/
struct Nodo *buscarNodo(struct Nodo **P, struct Nodo **Q, struct Nodo **S, struct Nodo **F, int dato){

    *Q = *P;
    *S = *F;
    int i=0;
    
    printf("\n\tEL DATO A BUSACAR: %d", dato);
    
    printf("\n\t :::: iteraciones del while sin entrar en condiciones: ");
    printf("\n\t ---- iteracion de Q");
    printf("\n\t ++++ iteracion de S\n");

    while(*Q != NULL && *S != NULL){
        i++;
        if ((*Q)->info == dato ){
            printf("\n\t-- Se encontro con el nodo Q: %d", (*Q)->info);
            printf("\n\t-----%d", i);
            return *Q;
            // break; con return es suficiente para salir del ciclo y de la función. Obviamente, asi que con que me lo regresen alguno de los dos, x quién lo devolvió, solo con tener el nodo, joya.
        }
        else if ((*S)->info == dato ){
            printf("\n\t-- Se encontro con el nodo S: %d", (*S)->info);
            printf("\n\t++++%d", i);
            return *S;
        }

        // Aunq podría ser suficiente con que Q==NULL o S==NULL, una condición... atómica?
        if((*Q)->der == NULL && (*S)->izq == NULL){
            printf("\n\t--NO SE ENCONTRO EL ELEMENTO EN LA LISTA");
            return *P;
            // Nice pero me genera una violación de segmento ):
        }
        



        printf("\n\t:::: %d", i);
        *Q = (*Q)->der;
        *S = (*S)->izq;
    }
    printf(" Null");
    printf("\n\n");
}
