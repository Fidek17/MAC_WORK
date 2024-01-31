#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Nodo{
    struct Nodo *izq;
    char info;
    struct Nodo *der;
};

void carga(struct Nodo **raiz);
void insercion(struct Nodo **elemento, int);
void busqueda_elemento(struct Nodo **elemento, struct Nodo **aux, int dato);
void eliminacion(struct Nodo **elemento, struct Nodo **aux, int dato);
void eliminar_casoH(struct Nodo **padre, struct Nodo **hijo); 

int menu();

void preorden(struct Nodo **raiz);
void inorden(struct Nodo **raiz);
void posorden(struct Nodo **raiz); 
bool arbol_vacio(struct Nodo **raiz);
void mensaje_arbol_vacio();

int main(){
    struct Nodo *raiz;
    struct Nodo *aux;
    int respuesta, dato;
    raiz = (struct Nodo *)malloc(sizeof(struct Nodo)); 
    raiz = NULL;
    aux = (struct Nodo *)malloc(sizeof(struct Nodo)); 
    aux = NULL;


    do{
        respuesta = menu();
        
        switch(respuesta){
            case 1:
                carga(&raiz);
                printf("\n\nValor de raíz: %d", raiz->info); 
            break;

            case 2:
                printf("\n\n Indique el dato a BUSCAR en el ABB: ");
                scanf("%d", &dato);
                arbol_vacio(&raiz) ? mensaje_arbol_vacio() : busqueda_elemento(&raiz, &aux ,dato);
                // arbol_vacio(&raiz)? mensaje_arbol_vacio(): preorden(&raiz);
            break;

            case 3: 
                printf("3. Impresión del árbol en distintos ordenes\n\n");
                if (arbol_vacio(&raiz)){
                    mensaje_arbol_vacio();
                }else{
                    printf("\n\n");
                    preorden(&raiz);
                    printf("\n\n\n");
                    inorden(&raiz);
                    printf("\n\n\n");
                    posorden(&raiz);
                    printf("\n\n");
                }
                
                
                // arbol_vacio(&raiz)? mensaje_arbol_vacio(): inorden(&raiz);
            break;

            case 4:
                printf("4. Eliminar elemento\n\n");
                printf("\n\n Indique el dato a BUSCAR y eliminar en el ABB: ");
                scanf("%d", &dato);
                aux = raiz;
                arbol_vacio(&raiz) ? mensaje_arbol_vacio() : eliminacion(&raiz, &aux ,dato);
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
    printf("ALGORITMO QUE CARGA UN ARBOL BINARIO DE BÚSQUEDA\n\n");
    printf("1. Inserción de elementos en el Árbol Binario de Búsqueda\n\n");
    printf("2. Búsqueda de un elemento en el ABB \n\n");
    printf("3. Impresiones en PreOrden, InOrden y PosOrden\n\n");
    printf("4. Eliminar elemento\n\n");
    printf("0. Salida\n\n");
    printf("Opción: ");
    scanf("%d", &res);

    return res;
}


void carga(struct Nodo **raiz){
    struct Nodo *aux;
    int info;
    

    printf("\n\n Indique el dato a insertar en el ABB: ");
    // scanf("%s", &(*raiz)->info);
    scanf("%d", &info);
    
    if(*raiz == NULL){
        *raiz = (struct Nodo *) malloc(sizeof(struct Nodo));
        (*raiz)->izq = NULL;
        (*raiz)->info = info;
        (*raiz)->der = NULL;
    }else{
        insercion(raiz, info); 
    }
}

void insercion(struct Nodo **elemento, int info){
    struct Nodo *aux;
    aux = (struct Nodo *) malloc(sizeof(struct Nodo));

    if (info <= (*elemento)->info){
        
        if ((*elemento)->izq == NULL){
            aux->info = info;
            aux->izq = NULL;
            aux->der = NULL;
            (*elemento)->izq = aux;
        }else{
            insercion(&((*elemento)->izq), info);
        }
           
    }else{

        if ((*elemento)->der == NULL){
            aux->info = info;
            aux->izq = NULL;
            aux->der = NULL;
            (*elemento)->der = aux;
        
        }else{
            insercion(&((*elemento)->der), info);
        }
    }
}

void busqueda_elemento(struct Nodo **elemento, struct Nodo **aux, int dato){
    if (dato < (*elemento)->info){
        if ((*elemento)->izq == NULL){
            printf("\n El nodo no se encuentra en el árbol\n");
        }else{
            (*aux) = (*elemento); 
            busqueda_elemento(&((*elemento)->izq), aux ,dato);
        }
        
    }
    else{
        if (dato > (*elemento)->info){
            if ((*elemento)->der == NULL){
                printf("\n El nodo no se encuentra en el árbol\n");
            }else{
                (*aux) = (*elemento); 
                busqueda_elemento(&((*elemento)->der), aux, dato);
            }
                printf("\n El nodo no se encuentra en el árbol\n");
        }else{
            printf("El valor de la raíz del elemento encontrado es: %d", (*aux)->info);
            printf("EL valor del nodo encontrado es: %d", (*elemento)->info); 
            printf("\n\nEl nodo si se encuentra en el árbol\n\n");

            if(((*elemento)->izq) == NULL){
                printf("\n\nNo hay nada en este lado izquierdo\n\n");
            }else{
                printf("\n\nEl valor a la izquierda de %d es: %d\n\n",(*elemento)->info, ((*elemento)->izq)->info );
            }

            if(((*elemento)->der) == NULL){
                printf("\n\nNo hay nada en este lado derecho\n\n");
            }else{
                printf("\n\nEl valor a la derecha de %d es: %d\n\n",(*elemento)->info, ((*elemento)->der)->info );
            }   

        }
        
    }
}

void preorden(struct Nodo **raiz){
    if(*raiz != NULL){
        printf("\n\n Valor: %d", (*raiz)->info);
        preorden(&(*raiz)->izq);
        preorden(&(*raiz)->der);
    }
}

void inorden(struct Nodo **raiz){
    if(*raiz != NULL){
        inorden(&(*raiz)->izq);
        printf("\n\n Valor: %d", (*raiz)->info);
        inorden(&(*raiz)->der);
    }
}
void posorden(struct Nodo **raiz){
    if(*raiz != NULL){
        posorden(&(*raiz)->izq);
        posorden(&(*raiz)->der);
        printf("\n\n Valor: %d", (*raiz)->info);
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
    printf("\nEl árbol no tiene elementos\n\nInserte al ABB con la opción 1\n");
    printf("\n-----------------------------------\n");
}

void eliminacion(struct Nodo **elemento, struct Nodo **aux, int dato){
    int control;
    struct Nodo *temp;
    if (dato < (*elemento)->info){
        if ((*elemento)->izq == NULL){
            printf("\n El nodo a eliminar no se encuentra en el árbol  1\n");
        }else{
            (*aux) = (*elemento); 
            eliminacion(&(*elemento)->izq, aux ,dato);
        }
        
    }
    else{
        if (dato > (*elemento)->info){
            if ((*elemento)->der == NULL){
                printf("\n El nodo a eliminar no se encuentra en el árbol   2\n");
            }else{
                (*aux) = (*elemento); 
                eliminacion(&(*elemento)->der, aux, dato);
            }
        }else{
            printf("El valor de la raíz del elemento encontrado es: %d", (*aux)->info);
            printf("EL valor del nodo encontrado es: %d", (*elemento)->info); 
            printf("\n\nEl nodo si se encuentra en el árbol\n\n");
            printf("---------------------------------------------");

            if((*elemento)->der == NULL && (*elemento)->izq == NULL){
                printf("\n\n Se trata de un nodo huerfano\n\n");
                 if((*aux)->der== *elemento){
                    free(*elemento);
                    (*aux)->der = NULL;
                 }else{
                    free(*elemento);
                    (*aux)->izq = NULL;
                 }
            }else{
                if((*elemento)->izq == NULL && (*elemento)->der !=NULL){
                    printf("\n\nSe trata de un nodo con solo el elemento de la derecha\n\n");
                    if((*aux)->der== *elemento){
                        (*aux)->der = (*elemento)->der;
                        free(*elemento);
                    }else{
                        (*aux)->izq = (*elemento)->der;
                        free(*elemento);
                    }

                }else{
                    if((*elemento)->izq != NULL && (*elemento)->der == NULL){
                        printf("\n\n Setrata de uno con solo el elemnto de la izquierda \n\n");
                        if((*aux)->der== *elemento){
                            (*aux)->der = (*elemento)->izq;
                            free(*elemento);
                        }else{
                            (*aux)->izq = (*elemento)->izq;
                            free(*elemento);
                        }

                    }else{
                        printf("\n\nSe trata de un nodo raiz");
                    }
                }
            }

        }
        
    }
}
