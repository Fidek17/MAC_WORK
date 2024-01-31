#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Nodo{
    char info;
    struct Nodo *izq;
    struct Nodo *der;
};

void carga(struct Nodo **raiz);
int menu();
void preorden(struct Nodo **raiz);
void inorden(struct Nodo **raiz);
void posorden(struct Nodo **raiz); 
bool arbol_vacio(struct Nodo **raiz);
void mensaje_arbol_vacio();

int main(){
    struct Nodo *raiz;
    struct Nodo *aux;
    int respuesta;
    raiz =(struct Nodo *) malloc(sizeof(struct Nodo));
    raiz = NULL;
    do{
        respuesta = menu();
        
        switch(respuesta){
            case 1:
                carga(&raiz);
            break;

            case 2:
                arbol_vacio(&raiz)? mensaje_arbol_vacio(): preorden(&raiz);
            break;

            case 3: 
                printf("3. Imprime el arbol (INORDEN)\n\n");
                arbol_vacio(&raiz)? mensaje_arbol_vacio(): inorden(&raiz);
            break;

            case 4:
                printf("4. Imprime el arbol (POSORDEN)\n\n");
                arbol_vacio(&raiz)? mensaje_arbol_vacio(): posorden(&raiz);
            break;

            case 0:
                printf("Saliendo del programa\n\n");
            break;
            default:
                printf("Digite una opcion valida\n\n"); 
            break; 
        }
        
    }while(respuesta!=0);

    return 0;
}

int menu(){
    int res;
    printf("\n\n");
    printf("ALGORITMO QUE CARGA UN ARBOL BINARIO\n\n");
    printf("1. Carga el arbol\n\n");
    printf("2. Imprime el arbol (PREORDEN)\n\n");
    printf("3. Imprime el arbol (INORDEN)\n\n");
    printf("4. Imprime el arbol (POSORDEN)\n\n");
    printf("0. Salida\n\n");
    printf("Opción: ");
    scanf("%d", &res);

    return res;
}


void carga(struct Nodo **raiz){
    struct Nodo *aux;
    *raiz =(struct Nodo *) malloc(sizeof(struct Nodo));
    int res;
    printf("\n\n Dame el valor de este nodo: ");
    scanf("%s", &(*raiz)->info);
    printf("\n\nExiste hijo izquierdo (1=SI|| 0=NO): ");
    scanf("%d", &res);

    if(res == 1){
        aux =(struct Nodo *) malloc(sizeof(struct Nodo));
        (*raiz)->izq = aux;
        carga(&(*raiz)->izq);
    }else{
        (*raiz)->izq = NULL;
    }

    printf("\n\nExiste hijo derecho (1=SI|| 0=NO): ");
    scanf("%d", &res);

    if(res == 1){
        aux = (struct Nodo *)malloc(sizeof(struct Nodo));
        (*raiz)->der= aux;
        carga(&(*raiz)->der);
    }else{
        (*raiz)->der = NULL;
    }
}

void preorden(struct Nodo **raiz){
    if(*raiz != NULL){
        printf("\n\n Valor: %c", (*raiz)->info);
        preorden(&(*raiz)->izq);
        preorden(&(*raiz)->der);
    }
}

void inorden(struct Nodo **raiz){
    if(*raiz != NULL){
        inorden(&(*raiz)->izq);
        printf("\n\n Valor: %c", (*raiz)->info);
        inorden(&(*raiz)->der);
    }
}
void posorden(struct Nodo **raiz){
    if(*raiz != NULL){
        posorden(&(*raiz)->izq);
        posorden(&(*raiz)->der);
        printf("\n\n Valor: %c", (*raiz)->info);
    }
}

bool arbol_vacio(struct Nodo **raiz){
    if (*raiz != NULL){
        return false;
    }
    return true;
}
void mensaje_arbol_vacio(){
    printf("\n-----------------------------------\n");
    printf("\nNo hay lista\n\nCree una lista con la opción 1\n");
    printf("\n-----------------------------------\n");
}