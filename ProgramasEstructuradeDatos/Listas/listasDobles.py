import os
class NodoDoble:
    def __init__(self, dato):
        self.dato = dato
        self.izq = None
        self.der = None

class ListaDoble:
    def __init__(self):
        self.principio = None
        self.final = None

    def agregar_al_final(self, dato):
        nuevo_nodo = NodoDoble(dato) #Q
        if self.principio is None:
            self.principio = nuevo_nodo
            self.final = nuevo_nodo
        else:
            actual = self.final
            while actual.der:
                actual = actual.der
            actual.der = nuevo_nodo
            nuevo_nodo.izq = self.final
            # print(f'---{self.final.dato} ---- {actual.dato} -- {actual.der.dato}')
            self.final = actual.der

    def eliminar(self, dato):
        actual = self.principio  # Comenzamos desde el principio de la lista
        while actual:
            if actual.dato == dato:  # Comparamos el dato del nodo actual con el dato a eliminar
                if actual.izq is None:
                    # Si actual es el primer nodo, actualizamos self.principio
                    self.principio = actual.der
                    actual.der.izq = None  # Actualizamos el enlace izquierdo del nuevo primer nodo
                    # self.principio.izq
                    # print(f'{self.principio.izq}')
                else:
                    if actual.der:
                        actual.der.izq = actual.izq
                        actual.izq.der = actual.der  
                        
                    else:
                        self.final = actual.izq
                        self.final.der = None
                return  # Terminamos después de eliminar el dato
            
            else:
                if actual.der is None:
                    print('No se encuentra el dato en la lista')
            actual = actual.der  # Avanzamos al siguiente nodo
        print("\nNo hay  lista")
    
    def eliminar_ultimo_elemento(self):
        if self.principio is None:
            print('No hay lista')
        else:
            if self.principio.der is None:
                self.principio = None
            else:
                aux = self.final.izq
                self.final = aux
                self.final.der = None
            return
            
    def imprimir(self):
        actual = self.principio
        while actual:
            print(f'{actual.dato}', end=' <--> ')
            actual = actual.der
        print("None")


def main():

    
    # Crear una instancia de ListaDoble
    mi_lista = ListaDoble()



    print("\nAgrega los elementos empezando por el final\n")
    cantidad = int(input('\n¿Cuántos elementos tendrá la lista? '))
    # cantidad=4
    print("Ingresa los elementos \n")
    i=0
    while i < cantidad and i>=0:
        dato = int(input(' : '))
        # dato = i+1
        mi_lista.agregar_al_final(dato)
        i+=1

    mi_lista.imprimir()

    mi_lista.eliminar_ultimo_elemento()
    
    mi_lista.imprimir()

    nodo_a_eliminar = int(input('Ingresa el nodo a eliminar: \n'))

    mi_lista.eliminar(nodo_a_eliminar)
    mi_lista.imprimir()

    

if __name__ == "__main__":
    main()

"""

     def switch_case(opcion):
         if opcion == 1:
             print("\nAgrega los elementos empezando por el final\n")
             cantidad = int(input('\n¿Cuántos elementos tendrá la lista? '))
             # cantidad=4
             print("Ingresa los elementos \n")
             i=0
             while i < cantidad and i>=0:
                 dato = int(input(' : '))
                 # dato = i+1
                 mi_lista.agregar_al_final(dato)
                 i+=1
             mi_lista.imprimir()

         elif opcion == 2:
             print("\nLa lista queda: \n")
             mi_lista.imprimir()

         elif opcion == 3:
             print("Opción 3 seleccionada")
             mi_lista.eliminar_ultimo_elemento()
             mi_lista.imprimir()

         elif opcion == 4:
             nodo_a_eliminar = int(input('Ingresa el nodo a eliminar: \n'))
             mi_lista.eliminar(nodo_a_eliminar)
             mi_lista.imprimir()
            
         else:
             print("Opción no válida")


    
    while True: 
        os.system("clear")
        print("\n\t1. Crear lista doblememnte ligada\n")
        print("\n\t2. Imprimir lista\n")
        print("\n\t3. Eliminar ultimo elemento\n")
        print("\n\t4. Buscar elemento y eliminarlo\n")
        print("\n\t0. Salir\n")

        respuesta = int(input("Opcion: "))
        
        while True:
            if respuesta == 1:
                switch_case(1)
            elif respuesta >1 and respuesta <= 4:
                switch_case(respuesta)
            elif respuesta == 0:
                print('\nPrograma finalizado. Gracias :)\n')
                break
            else:
                print("Opcion invalida: Digita una nueva")
                break
"""