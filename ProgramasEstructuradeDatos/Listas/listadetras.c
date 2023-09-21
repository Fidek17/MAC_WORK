#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int info;
    struct Nodo* liga;
};

int main() {
    struct Nodo* P = NULL; // Inicializa P como NULL, ya que no hay elementos en la lista al principio
    struct Nodo* N; // Nodo auxiliar para ingresar el siguiente elemento
    int n, i;

    printf("Cuantos datos se ingresaran en la lista: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        N = (struct Nodo*)malloc(sizeof(struct Nodo)); // Crea un nuevo nodo N

        printf("\nDame el valor a ingresar: ");
        scanf("%d", &(N->info));
        N->liga = P; // Enlaza el nuevo nodo N al principio de la lista
        P = N; // Actualiza P para que apunte al nuevo primer nodo
    }

    printf("La lista de los elementos de la lista es la siguiente: \n");
    N = P;
    i = 1;
    while (N != NULL) { // Verifica si N no es NULL para imprimir el contenido
        printf("%d. %d\n", i, N->info);
        N = N->liga;
        i++;
    }

    // Liberar la memoria ocupada por la lista
    while (P != NULL) {
        N = P;
        P = P->liga;
        free(N);
    }

    return 0;
}
