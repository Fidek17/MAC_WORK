class NodoDoble:
    def __init__(self, dato):
        self.dato = dato
        self.siguiente = None
        self.anterior = None

class ListaDoble:
    def __init__(self):
        self.cabeza = None
        self.principio = None

    def agregar_al_principio(self, dato):
        nuevo_nodo = NodoDoble(dato)
        if self.principio is None:
            self.cabeza = nuevo_nodo
            self.principio = nuevo_nodo
        else:
            nuevo_nodo.siguiente = self.principio
            self.principio.anterior = nuevo_nodo
            self.principio = nuevo_nodo

    def agregar_al_final(self, dato):
        nuevo_nodo = NodoDoble(dato)
        if self.cabeza is None:
            self.cabeza = nuevo_nodo
            self.principio = nuevo_nodo
        else:
            actual = self.cabeza
            while actual.siguiente:
                actual = actual.siguiente
            actual.siguiente = nuevo_nodo
            nuevo_nodo.anterior = actual

    def eliminar(self, dato):
        actual = self.cabeza
        while actual:
            if actual.dato == dato:
                if actual.anterior:
                    actual.anterior.siguiente = actual.siguiente
                if actual.siguiente:
                    actual.siguiente.anterior = actual.anterior
                if actual == self.cabeza:
                    self.cabeza = actual.siguiente
                return  # Termina después de eliminar el dato
            actual = actual.siguiente

    def imprimir(self):
        actual = self.cabeza
        while actual:
            print(actual.dato, end=' <-> ')
            actual = actual.siguiente
        print("None")

# Uso de la lista doblemente ligada
mi_lista = ListaDoble()
mi_lista.agregar_al_principio(1)
mi_lista.agregar_al_principio(2)
mi_lista.agregar_al_principio(3)

mi_lista.imprimir()  # Imprime "3 <-> 2 <-> 1 <-> None"

mi_lista_dos = ListaDoble()
mi_lista_dos.agregar_al_final(4)
mi_lista_dos.agregar_al_final(5)
mi_lista_dos.agregar_al_final(6)

mi_lista_dos.imprimir()  # Imprime "4 <-> 5 <-> 6 <-> None"
