#include <stdio.h>
#include <stdlib.h>

struct Nodo{
    int info;
    struct Nodo *liga; 
};

int main(){
    struct Nodo *Principio=NULL;
    struct Nodo *Auxiliar; 
    struct Nodo *actual;
    int res,i;

    do{
    Auxiliar = (struct Nodo*)malloc(sizeof(struct Nodo)); 
        printf("\n\nDame el valor a ingresar: ");
        scanf("%d", &(Auxiliar->info));
        Auxiliar->liga=NULL; 

        if(Principio==NULL){
            Principio=Auxiliar;
        }else{
            actual=Principio;
            while(actual->liga!=NULL){
                actual=actual->liga;
            }
        actual->liga=Auxiliar;
        }
    printf("\nDeseas escribir mas datos dentro de la lista (1=SI/=NO): ");
    scanf("%d", &res); 

    }while(res==1); 

//Imprimir lista

printf("\n\nLa lista creada es:\n");
i=1;
Auxiliar=Principio;
while(Auxiliar!=NULL){
    printf("%d. %d", i, Auxiliar->info);
    Auxiliar=Auxiliar->liga; 
    printf("\n");
    i++;
}


    return 0; 
}