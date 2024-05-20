
#### Interpolación
Es cuando dado unos puntos dados se crea un polinomio para crear una función que pase por esos puntos, todo para poder encontrar el valor de otros puntos dentro del intervalo que nos indiquen que es donde se construyo el polinomio. 

### Extrapolación
Cuando después de crear un polinomio que pasa por diferentes puntos otorgados dentro de un intervalo especificado, se querrá encontrar otros puntos fuera de ese intervalo, pero entre más alejado se este del intervalo el valor puede ser cada vez menos preciso. 

### Nota:
Mínimos Cuadrados es para poder aproximarnos lo más posible a los puntos que nos otorguen. 

La fórmula que tiene sentido en base al analisis expuesto en la foto es:
$$\sum_{i=1}^{n} |p(x_i) - f(x_i)| = \sum_{i=1}^{n} (d_i) = mínima$$

Pero el método se desarrolla para mínimos **cuadrados**, por lo que solo tenemos que usar la misma fórmula pero al cuadrado: 
$$\sum_{i=1}^{n} [p(x_i) - f(x_i)]^2 = \sum_{i=1}^{n} (d_i)^2$$

### Ejercicio:
Según la siguiente tabla, ¿Cuál será el valor cuando la fuerza sea de 5?

==*Nota: Como el valor 5 se encuentra dentro de nuestro intervalo proporcionado (0 al 7) se trata de interpolación*.


| Fuerza $(x)$      | 0     | 2     | 3     | 6     | 7     |
| ----------------- | ----- | ----- | ----- | ----- | ----- |
| Longitud $(F(x))$ | 0.150 | 0.182 | 0.200 | 0.258 | 0.270 |
Continuaremos armando nuestra tabla que necesita la información que nos da la misma tabla al principio del problema:

| Puntos   | Fuerza ($x_i$) | Longitud $(F(x_i)= y_i)$ | $x_i^2$ | $x_i \cdot F(x_i)$ |
| -------- | -------------- | ------------------------ | ------- | ------------------ |
| 1        | 0              | $$0.150$$                | $$0$$   | $$0$$              |
| 2        | 2              | $$0.182$$                | $$4$$   | $$0.364$$          |
| 3        | 3              | $$0.200$$                | $$9$$   | $$0.600$$          |
| 4        | 6              | $$0.258$$                | $$36$$  | $$1.548$$          |
| 5        | 7              | $$0.270$$                | $$49$$  | $$1.890$$          |
| $\sum_P$ | $$18$$         | $$1.060$$                | $$98$$  | $$4.408$$          |
Recordemos que se desea generar un polinomio que cree una gráfica que sea una linea, por lo tanto conviene recordar la ecuación de la recta:
$$p(x) = a_0 +a _1x$$
Y las fórmulas para generar los datos de $a_0$ y $a_1$ serán las siguientes:

$$a_0 = \frac{[\sum f(x_i)][\sum x_i^2]- [\sum x_i][\sum f(x_i)x_i]}{m \sum x_i^2 - [\sum x_i]^2}$$
$$a_1 = \frac{m[\sum f(x_i)x_i]- [\sum f(x_i)][\sum x_i]}{m \sum x_i^2 - [\sum x_i]^2}$$
Ahora sustituyendo las variables que tenemos de la tabla que creamos en las fórmulas, el resultado es:

$$a_0 = \frac{(1.060)(98)-(18)(4.402)}{(5)(98)- (18^2)} = 0.148457813$$

$$a_0 = \frac{(5)(4.402)-(1.060)(18)}{(5)(98)- (18^2)} = 0.0176506$$
Con los valores de $a_0$ y $a_1$ vamos a armar el polinomio:
$$p(x) = 0.148457813 + 0.0176506x$$
Sustituyendo:
$$p(5) = 0.148457813 + 0.0176506(5) = 0.2367108$$
Se termina el ejercicio.


Si deseamos generar un polinomio de tamaño dos, es decir, cuadratico de la forma $p(x) = a_0+a_1x+a_2x^2$, primero debemos pensar que se hace el mismo análisis en el que simplemente es la distancia de nuestro polinomio a los diferentes puntos dados, tenemos:
$$\sum_{i=1}^{m} = [ a_0+a_1x+a_2x^2- f(x_i)]^2$$
Para encontrar los valores de $a_0$, $a_1$ y $a_3$ se tendrá que resolver el siguiente sistema:
$$\begin{matrix}
ma_0 +a_1\sum_{i=1}^m x_i + a_2\sum_{i=1}^m x_i^2  =\sum_{i=1}^{m} f(x_1) \\
\\
a_0\sum_{i=1}^m x_i + a_1\sum_{i=1}^m x_i^2 + a_2\sum_{i=1}^m x_i^3 = \sum_{i=1}^m f(x_i)x_i \\
\\
a_0\sum_{i=1}^m x_i^2 + a_1\sum_{i=1}^m x_i^3 + a_2\sum_{i=1}^m x_i^4 = \sum_{i=1}^m f(x_i)x_i^2

\end{matrix}$$

Pero si se desea encontrar un polinomio de grado $n$ su analisís se observa de la siguiente manera:

$$\sum_{i=1}^{m}[a_0+a_1x_i+a_2x_i^2+...+a_nx_i^n- f(x_i)]$$
El sistema de ecuaciones generalizado:
$$\begin{matrix}
ma_0 + a_1\sum x + a_2\sum x^2 +...+  a_n\sum x^n = \sum y\\ \\
a_0\sum x + a_2\sum x^2 + a_2\sum x^3 + ... + + a_n\sum x^n+1 = \sum x y \\ \\
a_0\sum x^2 + a_1\sum x^3 + a_2\sum x^4 + ... + a_n\sum x^n+2 = \sum x^2y \\ \\
. \\
. \\
. \\
a_0\sum x^n + a_1\sum x^{n*1}+ a_2\sum x^{n+2} + ... + a_n\sum x^{n+n} = \sum x^n y
\end{matrix}$$
==Ejercicio:==
La compañia de IBM a obtenido las siguientes ganancias. Determinar las ganancias para agosto. 
Se tiene la siguiente tabla:

| Mes       | Ene | Feb | Mar | Abril | Mayo | Junio | Julio |
| --------- | --- | --- | --- | ----- | ---- | ----- | ----- |
| Ganancias | 1.3 | 3.5 | 4.2 | 5.0   | 7.0  | 8.8   | 10.1  |
Encontrar el polinomio por mínimos cuadrados. De grado 1 y de grado 2. 
- Debemos crear nuestra tabla primero:

| Puntos $i$ | Mes $x$ | Ganancias $F(x_i)$ | $x_i^2$    | $x_i\cdot f(x_i)$ |
| ---------- | ------- | ------------------ | ---------- | ----------------- |
| 1          | 1       | $$1.3$$            | $$1.69$$   | $$1.3$$           |
| 2          | 2       | $$3.5$$            | $$12.25$$  | $$7$$             |
| 3          | 3       | $$4.2$$            | $$17.64$$  | $$12.6$$          |
| 4          | 4       | $$5.0$$            | $$25$$     | $$20$$            |
| 5          | 5       | $$7.0$$            | $$49$$     | $$35$$            |
| 6          | 6       | $$8.8$$            | $$77.44$$  | $$52.8$$          |
| 7          | 7       | $$10.1$$           | $$102.01$$ | $$70.7$$          |
| $\sum$     | $$28$$  | $$39.9$$           | $$285.03$$ | $$199.4$$         |



- Usando las ecuaciones:
$$a_0 = \frac{[\sum f(x_i)][\sum x_i^2]- [\sum x_i][\sum f(x_i)x_i]}{m \sum x_i^2 - [\sum x_i]^2}$$
$$a_1 = \frac{m[\sum f(x_i)x_i]- [\sum f(x_i)][\sum x_i]}{m \sum x_i^2 - [\sum x_i]^2}$$
