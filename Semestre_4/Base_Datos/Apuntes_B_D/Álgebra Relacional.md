
Es definida por **Codd** en 1972. 

| *Álgebra relacional*                                                                                                |
| ------------------------------------------------------------------------------------------------------------------- |
| Es un conjunto de operaciones simples sobre tablas relacionales sobre las que se definen operaciones más complejas. |
|                                                                                                                     |
|                                                                                                                     |
*Elementos del modelo relacional*
- Estructura de datos:
	- Tales como lo son las tuplas, estructuras, etc.
- Integridad de los datos:
	- Contiene datos nulos y si nos afectaría dentro de la base de datos y su integridad, como si se tratase de una *Llave primaria*.
- Manipulación de Datos:
	- Se entendien como las operaciones del Álgebra relacional.

#### ¿Qué es un Sistema Relacional?
Sistema de gestión de bases de datos que utiliza el modelo relacional como modelo de datos, se da en el año 1980

#### ¿Cómo podemos saber si se trata de un modelo relacional?
- Usuario  -> tablas
- Realizar operaciones de álgebra relacional. 

### Partes de un modelo de Datos
1. Parte estructural: 
	1. Relación
	2. Atributos
	3. Tuplas 
2. Parte de Integridad:
	1. Dos reglas:
		1. Regla de integridad de entidades (de llaves primarias PK)
			1. LAs claves con las que organizamos una tabla o el atributo. 
		2. Regla de integridad *referencial* (de llaves foráneas / "extranjeras" FK). 
			1. Una clave es foranea si viene de otro modelo de datos o sistema relacional.
3. Parte manipulativa:
	1. Cálculo Relacional:
		1. Expresiones **Declarativas** (lenguaje no procedimental)
	2. Álgebra Relacional
		1. **Secuencias** de Operaciones

#### ¿Por qué se usa el Cálculo Relacional?

Se usa cuando es necesario evitar la complejidad del Álgebra relacional.

## Operaciones de Álgebra relacional

1. Operaciones tradicionales de teoría de conjuntos
	1. Unión 
		1. Construye una relación formado por todas las tuplas que cumplen los atributos de ambas relaciones. Simbolo de representación: U
		2. Si se tiene por ejemplo, $RuS$: Solo será posible realizar la únion si tienen cosas en común (tuplas) que coincidan en ambos conjuntos. 
		3. En la unión se juntarán todas las tuplas de $R_1$ con $R_2$. 
		4. Se tendrá la unión de todas las tuplas, es decir, la unión de todos pero sin la repetición de los ya existentes. Es decir que si en las dos tablas existe un mismo ente, un renglón (Tuplas) repetido en ambas tablas, al hacer la unión solo aparecerá uno solo. 
	2. Intersección
		1. Una relación formada por las tuplas que aparecen en las dos relaciones o en las dos tablas. 
		2. Será el conjunto de tuplas que están en $R$ pero a su vex en $S$.
		3. Las cabeceras deben ser iguales en ambas tablas a realizar la intersección para así generar una intersección más limpia. 
	3. Diferencia
		1. Relación formada por todas las tuplas de la primera relación que no aparezcan en la segunda, de las dos relaciones especificadas.
		2. Conjunto de tuplas que están en $R$, pero *NO* en $S$.
		3. Se le quitará todo a $R_1$ lo que sea que tenga que aparezca en $R_2$.
		4. Deben tener cabeceras ídenticas para que sean compatibles con esta operación. 
		5. **No es lo mismo**: $R_1-R_2$  que $R_2-R_1$.
	4. Producto cartesiano
		1. A partir de dos relaciones se construye una relación con todas las combinaciones posibles de tuplas. $R$ x $S$
		2. La cabecera resultante después de realizar esta operación será la suma de las cabeceras de $R_1$ y $R_2$.
		3. No es muy práctica ya que se genera mucha información que debe ser almacenada, además de no dar información nueva, simplemente une. 
		4. ¿Qué sucede si existen nombres o atributos iguales? Se les asigna un alias. 
		5. Después de realizar $R$ x $S$ debe estar bien formado (nombres de atributos únicos).
		6. No debe haber nombres repetidos o atributos, es decir, evitar la colisión de los atributos.
		7. *Soluciones posibles a los problemas:*
			1. Renombrar atributos 
			2. Prefijar atributos 
	5. Detalles extra:
		1. La *unión*, *intersección* y *producto cartesiano* son *conmutativas* y *asociativas*
		2. La diferencia **no** es conmutativa
2. Operaciones relacionales especiales:
	1. Selección:
		1. Las comparaciones pueden ser combinadas con operadores lógicos.
		2. Se usa la letra para delimitarlo: $\sigma$
		3. Es de esquema horizontal.
		4. Obtener un subconjunto de las tuplas de una relación para las que se satisfacen la unica condición de selección: $\sigma_{condición} (Relación)$
		5. Ejemplo: $\sigma_{nombrealumno="Erika"}(alumno)$
		6. La condición es una expresión booleana especificada mediante mediante los términos de atributos de la relación. 
		7. Ejemplos:
			1. Actores cuyo salario es mayor a 3000: $\sigma_{salario>3000}(Actores)$
			2. Actores representados por la agencia número 2, cuyo salario no llega a los 22,000, o bien por la agencia 4 y con salario superior a 32,000: $$\sigma_{(agencia = 2 AND salario<22,000) OR (agencia=4 AND salario> 35000)}(Actores)$$
			3. La operación de restricción es conmutativa.
	2. **Proyección**: 
		1. Simbolo: $\pi$
		2. Solo interesan algunos atributos de una relación y se proyecta la relación sobre esos atributos
		3. Se maneja como un esquema vertical. Esto porque como extrae atributos, es decir extrae columnas 
		4. Se observa asi:$$\pi_{listAtrib}(Relación)$$
		5. Elimina las tuplas repetidas en el resultado que devuelve. 
	3. Concatenación:
		1. A partir de dos relaciones construye una relación que contiene todsa las posbles combinaciones de tuplas 
		2. Forma general para relaciones 
		3. Union de las cabeceras de A y B. 
		4. Unir las tablas A y B en base de las tuplas que tienn en común la una con la otra y trae condigo a las cabeceras. 
		5. Varias modalidades de Reunión (join) :
			1. Reunión natural
	4. División:
		1. $A\div B$
		2. Es poco común y es útil en ocasiones especiales.
