***Algoritmo para eliminar el nodo al final de la lista***
```pseudocode
	Si P=NULL
		Escribir("No hay elementos")
	SINO 
		SI P^.liga = NULL
			Quita(P)
			P=NULL
		SINO
			Q=P
			MIENTRAS Q^.Liga! = NULL
				T=Q
				Q=Q^.Liga
			FINMIENTRAS
			Quita(Q)
			T^.Liga=NULL
		FINSI
	FINSI
```
Escenarios posibles: 
1. Existencia de la lista
2. Existen elementos en la lista
	1. Hay más de un elemento
	2. Solo hay un elemento
Funcionará repasando todos los apuntadores de la lista y revisando a dónde apuntan, cuando se llega al apuntador que apunta a NULL significa que llegamos al final de la lista. 

***Algoritmo de búsqueda de un elemento en una lista***

Escenarios posibles: 
1. No hay elementos en la lista.
2. Si hay elementos en la lista. 
	1. No esta el elemento
	2. Si esta el elemento

```pseudocode
SI P=NULL 
	Escribir("No hay elementos en la lista")
SINO
	Escribir("Dame el dato a buscar")
	Leer(Dato)
	Q=P
	MIENTRAS (Q^.Liga!=NULL) y (Q^.INFO!=Dato)
		Q=Q^.Liga
	FINMIENTRAS
	SI Q^.INFO!=Dato
		Escribir("No se encontro el dato")
	SINO
		Escribir("Si esta presente el dato")
	FINSI
FINSI
	 
```
Primero revisará si existen elementos, cuando si existen va a pedir el dato a buscar, recorrerá la lista con el puntero Auxiliar $Q$  en un ciclo MIENTRAS, este ciclo mientras solo se ejecutará mientras no se haya llegado al final de la lista y mientras no se haya encontrado el dato. Esto quiere decir que cuando nos salgamos del ciclo mientras se cumplió que se llego al final de la lista o se cumplió que se encontró el dato y por lo tanto debemos hacer un SI  condicional para revisar que si se haya encontrado el dato y así imprimir si se encontró o no el dato.  


