import os
#Definicion y creacion de funciones y algoritmos
class Nodo: 
    def __init__(self, valor):
        self.izq = None
        self.valor = valor
        self.der = None

class ligadoble: 
    def  __init__(self):
            self.P = None
            self.F = None
    
    def agregar_Final(self,numero):
        i=1
        while i <= numero:
            dato = int(input("Dame el valor a guardar: "))
            Q = Nodo(dato)
            if self.P is None: 
                self.P=Q
                self.F=Q
            else:
                Q.izq = self.F
                self.F.der = Q
                self.F = Q
            i=i+1

    def buscar_Eliminar(self):
        valor=int(input("Valor a eliminar: "))
        Aux=self.P
        if self.P:
            if self.P.valor== valor:
                self.P=Aux.der
                if self.P:
                    self.P.izq=None
                del Aux
            else: 
                while Aux and Aux.valor!=valor:
                    Aux=Aux.der
                if Aux is not None and Aux.valor == valor: 
                    izquierda = Aux.izq
                    derecha = Aux.der
                    if derecha: 
                        izquierda.der = derecha
                        derecha.izq = izquierda
                    else: 
                        izquierda.der=None
                    del Aux
                    print("Se encontro el valor y se elimino correctamente")
                else:
                    print("No se encontro el valor")
                
        else:
            print("No hay lista generada")


        

    def eliminar_Final(self):
        if self.P is self.F:
            del self.P
            del self.F
            self.F=None
            self.P=None
        else:
            Aux = self.F.izq
            del self.F
            Aux.der =None
            self.F=Aux
        print("Se ha eliminado el nodo de forma exitosa")

    
    def imprimir(self):
        if self.P is None: 
            print()
            print("No existe lista")
            print()
        else: 
            Q=self.P
            print()
            print("La lista es la siguiente: ")
            print()
            while Q:
                print(Q.valor, end= " <-> ")
                Q=Q.der
            print("None")
            print()
         

    
def crear(lista): 
    print("Crear lista")
    print()
    cantidad = int(input ("Numero de valores a almacenar: "))
    print()
    lista.agregar_Final(cantidad)
    print()
    print("Presiona enter")
    input()

def imprimir(lista):
    lista.imprimir()
    print("Presiona enter")
    input()

def buscar(lista):
    print("Eliminar el nodo con el elemento dado")
    print()
    print()
    lista.buscar_Eliminar()
    print()
    print("Presiona enter")
    input()

def eliminarfinal(lista):
    print()
    print()
    print("Elimina el ultimo nodo")
    print()

    lista.eliminar_Final()
    print()
    print("Presiona enter")
    input()


switch={
    1: crear, 
    2: imprimir,
    3: buscar,
    4: eliminarfinal,
}

#Implmemntacion principal: Funcion principal
lista = ligadoble()
while True: 
    os.system("clear")
    print("1. Crear lista doblememnte ligada")
    print()
    print("2. Imprimir lista")
    print()
    print("3. Buscar elemento y eliminarlo")
    print()
    print("4. Eliminar ultimo elemento")
    print()
    respuesta = int(input("Dame tu respuesta: "))
    print(respuesta)

    if respuesta==0: 
        break
    else: 
        if respuesta in switch: 
            switch[respuesta](lista)
        else:
            print("Opcion invalida: Digita una nueva")


