#include <stdlib.h>
#include <stdio.h>

struct Nodo{
    int info;
    struct Nodo *siguiente;
}; 

int main(){
struct Nodo *P; int res;struct Nodo* Q;
int i=1;  int dato;

P = ( struct Nodo *)malloc(sizeof(struct Nodo));

printf("Dame el valor del la lista en P: ");
scanf("%d", &(P->info));
P->siguiente=NULL; 

printf("Existen más elementos en la lista? 1=SI/0=NO: ");
scanf("%d", &res);

while(res==1){
    Q = (struct Nodo *)malloc(sizeof(struct Nodo));
    printf("Dame el nuevo valor a ingresar: ");
    scanf("%d", &(Q->info));
    Q->siguiente=P; 
    P=Q; 
    printf("\nExisten más elementos en la lista? 1=SI/0=NO: ");
    scanf("%d", &res);  
    
}

//intento de imprimir
printf("La lista de los elementos de la lista es la siguiente: \n"); 
P=Q; 
while(P!=NULL){
    printf("%d. %d",i, P->info); 
    P=P->siguiente;
    printf("\n");
    i++;
}
//Eliminar el ultimo nodo-------------
P=Q;
if(P->siguiente==NULL){
    free(P);
    P=NULL;
}else{
    struct Nodo *T;
    T = ( struct Nodo *)malloc(sizeof(struct Nodo));
    while(P->siguiente!=NULL){
        T=P; 
        P=P->siguiente;
    }
    free(P);
    T->siguiente=NULL;
}
//.------------------------------
printf("\n\nLa nueva lista sin el ultimo nodo es la siguiente: \n\n");
P=Q; 
i=1;
while(P!=NULL){
    printf("%d. %d",i, P->info); 
    P=P->siguiente;
    printf("\n");
    i++;
}
//BUSQUEDA----------------
printf("\nDame el dato a buscar: ");
scanf("%d", &dato); 
P=Q;
while(P->siguiente!=NULL && P->info!=dato){
    P=P->siguiente; 
}
if(P->info == dato){
printf("\nSi se encontro el valor");
}else{
    printf("\nNo se encontro el valor"); 
}
    return 0; 
}