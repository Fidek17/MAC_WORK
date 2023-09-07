#include <stdio.h>
#include <stdlib.h>

    struct Alumno{
        int NumCuen; 
        int edad;
        char sexo;
        float cal1, cal2, prom;
    };

void ingresaralumno(struct Alumno grupo[5], int n);
float promedioind(struct Alumno Aind);
void Mujer(struct Alumno grupo[5], int n); 
void edad_prom(struct Alumno grupo[5], int n);
void promG(struct Alumno grupo[5], int n);


int main(){

    int n; 
    n=2;

        struct Alumno alum[5];

        ingresaralumno(alum, n);

        Mujer(alum,n);

        edad_prom(alum,n);

        promG(alum, n);




    return 0;
}

void ingresaralumno(struct Alumno grupo[5], int n){
    int i;
    float promedio;

    for(i=0; i<n; i++ ){
        printf("-------------------------------------------"); 
        printf("\n\tAlumno %d", i+1);
        printf("\n\nNumero de cuenta: "); 
        scanf("%d", &grupo[i].NumCuen); 

        printf("Edad: "); 
        scanf("%d", &grupo[i].edad);

        printf("Sexo: "); 
        scanf("%s", &grupo[i].sexo);

        printf("Calificacion 1: "); 
        scanf("%f", &grupo[i].cal1);

        printf("Calificacion 2: "); 
        scanf("%f", &grupo[i].cal2);

        grupo[i].prom=promedioind(grupo[i]);

        printf("Promedio: %f", grupo[i].prom); 
        printf("\n\n");
    }
}

float promedioind(struct Alumno Aind){
    int i; 
    float suma, promedio;
        suma = Aind.cal1+Aind.cal2;
        promedio = suma /2;

    return promedio;
}

void Mujer(struct Alumno grupo[5], int n){
    int i, suma, control=0;
    printf("Lista de numeros de cuenta de alumnas:\n");
      for(i=0; i<n; i++){
        if(grupo[i].sexo=='F'){
            printf("\nNo. de Cuenta alumno %d: %d", i, grupo[i].NumCuen);
            control=1;
        }
      }

    if(control!=1){
        printf("\n\nNo hay alumnas en el grupo");

    }
}

void edad_prom(struct Alumno grupo[5], int n){
    int i, edad, control=0;
    printf("\n\nDame el valor de la edad que quieres revisar en los alumnos: "); 
    scanf("%d", &edad);

    printf("\n\nLa lista de numeros de cuenta de los alumnos con %d y promedio aprobatorio es: ", edad);
    for(i=0; i<n; i++){

        if(grupo[i].edad == edad){
            if(grupo[i].prom>50.00){

                printf("\n%d: %d", i, grupo[i].NumCuen);
                control = 1 ;
            }
        }
    }
    if(control!=1){
        printf("\n\nNingún alumno cumple con ambas condiciones");
    }
}

void promG(struct Alumno grupo[5], int n){
    int i; 
    float suma=0, promedio;

    for(i=0; i<n; i++){
        suma = suma + grupo[i].cal1 + grupo[i].cal2;
    }
    promedio = suma/(n*2);
    printf ("\n\nEl valor del promedio general es: %f", promedio);
}