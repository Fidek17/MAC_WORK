### Arquitectura de tres niveles:
- Nivel Externo
- NIvel Conceptual: 
	- Lenguaje de definición de datos. 
- Nivel Interno: 
	- Como se almacena la información y como se desplaza 

## Modelos para modelar datos
- Modelo Entidad - Relación
	- Creado por Chen en 1976. 
- Modelo Relacional
	- Basado en la lógica de predicado y en la teoría de conjuntos. Creado por Codd en 1970

Se va del mundo real a un esquema conceptual a través de una conceptualización. 

#### Elementos del modelo Entidad - Relación:
- Clave
	- Conjunto de atributos que permite identificar inequivocamente a una entidad dentro de un conjunto de entidades. 
- Relación (Conexión o asociación)
	- Conexión semántica entre dos conjuntos de entidades. 
	- Ejemplo: Relación entre los escritores y los libros que han escrito. 
- Dominio
	- Valores para cada uno de los atributos.
	- Tipos de atributos
		1. Simples y compuestos.
		2. Univalorados y multivalorados
			- Ejemplo: Multivalorado: numero-teléfono.
		3. Derivados
			- De otro valores. 

### Caracteristicas de las relaciones:
- Grado
	- Numero de tipos de entidades que participan en la conexión.
		- Reflexiva: O recursiva, grado 1.
		- Binaria: Grado 2 (Más frecuente).
		- Ternaria: Grado 3 .
- Cardinalidad. 
	- Números mínimos y máximos de instancias en una entidad que se relacionan con las instancias de otra entidad. 
	- Máxima
	- Mínima
	- Limita las relaciones entre las entidades y sus instancias con otras.
	- Razón de Participación
		- Participación **Total**
			- Dependencia en existencia
		- Participación **Parcial**
		- 
- Nombres de Rol
	- Tipo de entidad
		- Juega un papel en especifico.
			- Nombre de rol reflexivo (No ambiguedad)
- Claves
	- Superclave 
		- Identificar Univocamente
	- Clave candidata
		- Otra forma de decir otr siper clave posible 
	- Clave primaria
	- Clave alternativa
	- Ejemplo:
		- Película:
			- Título: NO es una clave ya que hay muchas películas con nombres iguales
			- {Título, género, año}: Clave candidata: Podría serlo
			- {Título, director, año}: Es una clave 



# Modelo Entidad / Relación Extendido

*Diferentes niveles para la abstracción necesaria para llegar a la construcción y finalización de una base de datos física.* 
- Mundo real
	- Modelado conceptual
		- Modelado lógico
			- Modelado físico

La manera para construir un modelo de entidad/relación:
1. Identificar las entidades
2. Identificar las relaciones
3. Identificar los tributos y asociarlos
4. ---
5. Determinar los identificadores
6. ---
7. Dibujar el E-R (Esquema conceptual)
8. Revisar el esquema conceptual local con el usuario. 

#### Mejoras de un modelo E-R extendido
1. Especialización
	- Partir el problema o poder dividirlo en subgrupos para obtener una especialización.
	- Desprender o descomponer cada vez más el diagrama y brindarle más información mucho mas especifico.
2. Generalización
	- Varias entidades se van a sintetizar gracias a sus características comunes.
	- Ejemplos:
		- La entidad ==Cliente== tendrás los mismos atributos que el ==empleado== excepto por un solo atributo, Cliente tendrá credito y Empleado tendrá Sueldo. La generalización se observará en poner todos los mismos atributos para ==Cliente== como para ==Empleado== y lo único **especializado** será que si se trata de ==cliente== o de ==empleado== ellos tendrá Sueldo o Credito. Por lo tanto se generalizan los atributos en común y la especialización serán esos atributos que no tienen en común.
3. Herencia de los atributos
	- En el ejemplo de arriba cliente y empleado heredan los atributos de ==persona== quien contendrá todos sus atributos en común. 
4. Restricciones para usar este Modelado Extendido con *especialización* y *generalización*
	- Definida por ==condición==:
		- Se cumple con una característica para que sea posible usar tanto la *especialización* y *generalización*.
	- Definida por el ==usuario==:
		- Restricción impuesta por el usuario, es decir, el usuario hace las relaciones o indica su manera de organización, esto debido por la necesidad o la misma manera que se desea que se construya la base de datos.
5. Pertenencia de las entidades
	1. Disjunto:
		1. Se trata de cuando una entidad no podrá ser algún otro de nivel superior, por decir, se es empleado, cajero o banquero, no los tres o dos a la vez.
	2. Solapados:
		1. Entidades que pueden tener más de una conexión con otras entidades. 
6. Restricciones de ==Completitud==
	1. Total: 
		1. Generalización o especificación total. 
	2. Parcial
		1. Es posible que alguna entidad de nivel superior no se relacione con ninguna entidad de nivel inferior. 
