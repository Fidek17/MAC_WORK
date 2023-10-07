#include "ProgramaUnoHeader.h"

int menu();
int metodo(int funcion);

int main() {
    int respuesta, eleccion; 
    float x0, x1, x;
    
    do {
        respuesta = menu();

        switch (respuesta) {
            case 1:                
                eleccion = metodo(respuesta);
                break;
            case 2:
                eleccion = metodo(respuesta);
                break;
            case 3:
                eleccion = metodo(respuesta);
                break;
            case 4:
                eleccion = metodo(respuesta);
                break;
            case 0:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción no válida. Por favor, elija una opción válida." << endl;
                break;
        }

    } while (respuesta != 0);

    return 0;
}

int menu() {
    int opcion;
    
    cout << "\n\nFuncion 1: x^2 cos(x) - 2x\n";
    cout << "Funcion 2: (6 - 2/x^2) (e^2+x /4) + 1\n";
    cout << "Funcion 3: x^3 - 3sen(x^2) + 1\n";
    cout << "Funcion 4: x^3 + 6x^2 + 9.4x\n";
    cout << "0. Salida\n\n";

    // Pedir al usuario que elija una opción
    cout << "Seleccione una opción: ";
    cin >> opcion;
    
    return opcion;
}

int metodo(int funcion) {
    int opcion;
    float x0, x1, x;
    
    do {
        cout << "\n\nElección de Método: \n\n";
        cout << "1. Secante\n";
        cout << "2. Newton-Raphson\n\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        
        if (opcion < 1 || opcion > 2) {
            cout << "Opción no válida. Por favor, elija una opción válida." << endl;
        }

    } while (opcion < 1 || opcion > 2);

    if(opcion == 1){
        cout << "\n\nSe eligió el método de la Secante.\n\n";
        cout << "Dame el valor del x_ 0: ";
        cin >> x0; 
        cout << "Dame el valor del x_1: ";
        cin >> x1;
        raizSecante(x0, x1, funcion);
    }else{
        cout << "\n\nSe eligió Newton.\n\n";
        cout << "Dame el valor de x: ";
        cin >> x;
        raizNewton(x, funcion);
    }

    return opcion;
}