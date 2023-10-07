#include "ProgramaUnoHeader.h"

int menu();
int metodo();

int main() {
    int respuesta, eleccion; 
    float x0, x1, x;
    
    do {
        respuesta = menu();

        switch (respuesta) {
            case 1:                
                eleccion = metodo();
                if (eleccion == 1) {
                    cout << "Se eligió Secante." << endl;
                    cout << "Dame el valor del x_ 0" << endl;
                    cin >> x0; 
                    cout << "Dame el valor del x_1" << endl;
                    cin >> x1;
                    raizSecante(x0, x1, respuesta);
                } else {
                    cout << "Se eligió Newton." << endl;
                    cout << "Dame el valor de x" << endl;
                    cin >> x;
                    raizNewton(x, respuesta);
                }
                break;
            case 2:
                eleccion = metodo();
                if (eleccion == 1) {
                    cout << "Se eligió Secante." << endl;
                    cout << "Dame el valor del x_ 0" << endl;
                    cin >> x0; 
                    cout << "Dame el valor del x_1" << endl;
                    cin >> x1;
                    raizSecante(x0, x1, respuesta);
                } else {
                    cout << "Se eligió Newton." << endl;
                    cout << "Dame el valor de x" << endl;
                    cin >> x;
                    raizNewton(x, respuesta);
                }
                break;
            case 3:
                eleccion = metodo();
                if (eleccion == 1) {
                    cout << "Se eligió Secante." << endl;
                    cout << "Dame el valor del x_ 0" << endl;
                    cin >> x0; 
                    cout << "Dame el valor del x_1" << endl;
                    cin >> x1;
                    raizSecante(x0, x1, respuesta);
                } else {
                    cout << "Se eligió Newton." << endl;
                    cout << "Dame el valor de x" << endl;
                    cin >> x;
                    raizNewton(x, respuesta);
                }
                break;
            case 4:
                eleccion = metodo();
                if (eleccion == 1) {
                    cout << "Se eligió Secante." << endl;
                    cout << "Dame el valor del x_ 0" << endl;
                    cin >> x0; 
                    cout << "Dame el valor del x_1" << endl;
                    cin >> x1;
                    raizSecante(x0, x1, respuesta);
                } else {
                    cout << "Se eligió Newton." << endl;
                    cout << "Dame el valor de x" << endl;
                    cin >> x;
                    raizNewton(x, respuesta);
                }
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

int metodo() {
    int opcion;
    
    do {
        cout << "\n\nElección de Método: \n\n";
        cout << "1. Secante\n";
        cout << "2. Newton-Raphson\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        
        if (opcion < 1 || opcion > 2) {
            cout << "Opción no válida. Por favor, elija una opción válida." << endl;
        }

    } while (opcion < 1 || opcion > 2);

    return opcion;
}