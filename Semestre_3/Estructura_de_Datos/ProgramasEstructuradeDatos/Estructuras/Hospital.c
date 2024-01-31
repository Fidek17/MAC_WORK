#include <stdio.h>


int main(){
    struct domicilio{
        char calle[100];
        int numero; 
        char ciudad[100];
    };

    struct enfermo{
        char nombre[100];
        int edad;
        char sexo[10]; 
        struct domicilio direccion;
    }; 
    struct enfermo paciente[3];
    int i, n=3;

    for(i=0; i<n; i++){
        printf("\n\nDame el nombre del paciente %d: ",i);
        fgets(paciente[i].nombre, sizeof(paciente[i].nombre), stdin );
        
    }
    for(i=0; i<n; i++){
printf("\n\nEl nombre del paciente %d es: %s", i, paciente[i].nombre);
    }


    return 0;
}