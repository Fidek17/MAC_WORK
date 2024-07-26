## 1. Integración por #Newton-Cortes

Se creará un trapecio con la ayuda de los puntos dados $a$ y $b$ evaluados con la función dada $f(x)$.
La médula de este método de integración se ve de la siguiente manera:
$$I = \int_{a}^{b} f(x)dx\approx \int_{a}^{b} P_n (x) dx$$
Donde:
$$P_n(x) = a_0+ a_1x+ a_2x^2+a_3x^3+...+a_nx^n$$


### 1.1 Regla del #trapecio
Se comienza que $n = 1$ y por lo tanto se tiene lo siguiente:
$$I = \int_{a}^{b} f(x)dx\approx \int_{a}^{b} P_1 (x) dx$$
Es decir: $P_1(x)$ = Grado 1 o una línea. 


![[IMG_2412.jpeg| 500]]

$$I \approx \int_{a}^{b} (a_0+a_1x) =(b-a)\frac{f(a)+ f(b)}{2}$$

==Ejemplo:== 
$$\int_{0}^{1} e^{x^2} dx$$
Donde: 
$a = 0$   $b = 1$     $f(x) = e^{x^2}$

**Solución:**
$$I \approx (1-0)\frac{f(0)+f(1)}{2} \approx \frac{1+e}{2} \approx 1.85914$$
#### 1.1.2 Regla del trapecio #compuesto 
![[IMG_2413.jpeg| 500]]

Donde: 
$$h = \frac{b-a}{n}$$
Y por lo tanto la integral o la regla del trapecio compuesta para $n$ particiones es:
$$I \approx \int_{a}^{b} f(x) dx \approx \int_{x_0}^{x_1} f(x) dx +  \int_{x_1}^{x_2} f(x) dx +... +  \int_{n-1}^{n} f(x) dx$$
Desarrollando:
$$I \approx (x_1-x_0)[\frac{f(x_0)+f(x_1)}{2}]+ ... + (x_n-x_{n-1})[\frac{f(x_{n-1)}+f(x_n)}{2}]$$
Simplificado se ve de la siguiente manera:
$$\int_{a}^{b} f(x)dx \approx \frac{h}{2}[f(x_0)+2f(x_1)+2f(x_2)+ ...+ 2f(x_{n-1}) + f(x_n)]$$
**Nota:** 
- Para obtener el polinomio utiliza Lagrange de grado 1, un poco de álgebra y se llega a la fórmula.
==Ejemplo:== 
- Usa Regla del *trapecio compuesto* para resolver.
$$\int_{0}^{1} e^{x^2} dx$$
Donde: 
$a = 0$   $b = 1$     $f(x) = e^{x^2}$    $n =3$

**Solución:**  
$h = \frac{1-0}{3} = \frac{1}{3}$ 
Por lo tanto el valor de cada intervalo será de $\frac{1}{3}$ y aplicando la fórmula siguiente:
$$\int_{a}^{b} f(x)dx \approx \frac{h}{2}[f(x_0)+2f(x_1)+2f(x_2)+ ...+ 2f(x_{n-1}) + f(x_n)]$$
Tenemos el siguiente desarrollo:
$$\int_{0}^{1} e^{x^2} \approx \frac{1}{6}[f(x_0)+2f(x_1)+2f(x_2)+f(x_3)]$$
Y el valor de las $x$ es:
- $x_0 = 0$
- $x_1 = \frac{1}{3}$
- $x_2 = \frac{1}{3} + \frac{1}{3} = \frac{2}{3}$
- $x_3 = \frac{1}{3} + \frac{1}{3}+ \frac{1}{3} = 1$
Por lo tanto tenemos que resolver lo siguiente:
$$\frac{1}{6}[f(0) + 2f(\frac{1}{3}) + 2f(\frac{2}{3}) + f(1)] = \frac{1}{6}[1 + 2(1.117519069) + 2(1.55962348) + e]$$
Entonces el resultado es:
$$\frac{1}{6}[1 + 2(1.117519069) + 2(1.55962348) + e] = 1.512094494$$

#### ==Ejemplo 2:==
- Usa Regla del *trapecio compuesto* para resolver.
$$\int_{2}^{4} \frac{e^x}{x} dx$$
Donde: 
$a = 2$   $b = 4$     $f(x) = \frac{e^x}{x}$    $n =4$

**Solución:**
$$h = \frac{4-2}{4} = \frac{1}{2}$$
Por lo tanto las $x$ es:
- $x_0 = 2$
- $x_1 = \frac{5}{2}$
- $x_2 = 3$
- $x_3 = \frac{7}{2}$
- $x_4 = 4$
$$\int_{2}^{4} \frac{e^x}{x} \approx \frac{1}{4}[f(x_0)+2f(x_1)+2f(x_2)+2f(x_3)+ f(x_4)]$$
Ya desarrollado seria: 
$$\int_{2}^{4} \frac{e^x}{x} \approx \frac{1}{4}[3.6945+2(4.873)+2(6.6951)+2(9.46156)+ 13.64954] = \frac{1}{4}(59.40336)$$
El resultado será:
$$\int_{2}^{4} \frac{e^x}{x}= 14.85084$$
### 2.1 Regla de #Simspon $\frac{1}{3}$

- Es un polinomio de aproximación de grado superior a 1. 
- Se usa para polinomios de segundo grado.
- Es necesario contener 3 puntos, por lo que si tenemos $[a,b]$, tendremos que nuestro tercer punto es $c$ tal que:
$$c = \frac{a+b}{2}$$
$\therefore$ $x_0 = a$, $x_1=x_0+h$, $x_2 = b$ donde $h = \frac{b-a}{2}$.
Se trata de una aproximación lo más cercana posible a la función y se observa así:
![[IMG_2487.jpeg| 300]]

La fórmula queda de la siguiente forma:
$$I = \frac{b-a}{6}\left[f(a)+4f(\frac{a+b}{2})+f(b)\right] \approx \frac{1}{3}h\left[f(a)+4f\left(\frac{a+b}{2}\right)+f(b)\right]$$
Si se tratara de más intervalos para se capaces de aproximarnos aun más a la integral original o a la función original es como se observa en la foto: 
![[IMG_2489.jpeg| 300]]
Y como se puede observar el área será la suma de todas las integrales pequeñas que existen en los rectángulos y gracias a este análisis nuestra fórmula se observa de la siguiente forma:
$$I \approx \int_a^{x_1} f(x)dx + \int_{x_1}^{x_2}f(x)dx+...+\int_{n-1}^{b}f(x)dx$$
$$I \approx \frac{h}{3}\left[f(x_0)+4\sum_{i =1,3,5,...}^nf(x_i)+ 2\sum_{j=2,4,6,...}^{n-2} f(x_j)+f(x_n)\right]$$

==Ejemplo:==
Encontrar una aproximación a la integral por medio de la regla de **Simspon**
$$\int_0^1 e^{x^2}dx$$
Donde:
- $a = 0$
- $b = 1$
- $x_1 = \frac{1-0}{2} = 0.5$
- $f(x) =e^{x^2}$
- $h =\frac{1-0}{2} = 0.5$ 
**Solución:**
Como solo es necesario encontrarlo según tres puntos usamos la siguiente fórmula:
$$I \approx \frac{1}{3}h\left[f(a)+4f\left(\frac{a+b}{2}\right)+f(b)\right]$$
*Aplicando tenemos:*
$$I \approx \frac{0.5}{3}\left[1+ 4f(0.5)+f(1)\right] \approx 0.166\left[1 + 4e^{(0.5)^2+e }\right]\approx 1.475730....$$

==Ejemplo Parte dos==
Encontrar la misma aproximación pero a través de cuatro intervalos:

$$\int_0^1 e^{x^2}dx$$
Donde:
- $n = 4$
- $a = 0 = x_0$
- $b = 1 = x_4$
- $h =\frac{b-a}{n} = \frac{1-0}{4} = \frac{1}{4}$ 
- $x_1 =\frac{1}{4}$
- $x_2 = \frac{1}{4}+\frac{1}{4} =\frac{1}{2}$
- $x_3 = \frac{1}{4}+\frac{1}{4}+\frac{1}{4} = \frac{3}{4}$ 
- $f(x) =e^{x^2}$
Haciendo uso de la fórmula para cuando se tiene más de tres puntos a usar: 
$$I \approx \frac{h}{3}\left[f(x_0+4\sum_{i =1,3,5,...}^nf(x_i)+ 2\sum_{j=2,4,6,...}^{n-2} f(x_j)+f(x_n)\right]$$
**Aplicando:**
$$I \approx \frac{0.25}{3}\left[f(0)+4\left(f\left(\frac{1}{4}\right)+f\left(\frac{3}{4}\right)\right)+ 2\left(f\left(\frac{1}{2}\right)\right)+f\left(1\right)\right]$$
$$I \approx 0.08333\left[f(0)+4\left(1+1.75\right)+ 2\left(1.2840\right)+e\right]$$
$$I \approx 0.08333\left[1+4\left(1.0644+1.75\right)+ 2\left(1.2840\right)+e\right]$$
$$I \approx 0.08333\left[1+11.2576+ 2.568+e\right] \approx 1.46193$$
==Ejemplo 2==
Encontrar una aproximación a la integral por medio de la regla de **Simspon**
$$\int_2^4 \frac{e^x}{x}dx$$
Donde:
- $a = 2$
- $b = 4$
- $x_1 = \frac{4-2}{2}+a = 1+2= 3$
- $f(x) =\frac{e^x}{x}$
- $h =\frac{4-2}{2} = 1$ 
**Solución:**
Como solo es necesario encontrarlo según tres puntos usamos la siguiente fórmula:
$$I \approx \frac{1}{3}h\left[f(a)+4f\left(\frac{a+b}{2}\right)+f(b)\right]$$
*Aplicando tenemos:*
$$I \approx \frac{1}{3}\left[f(2)+ 4f(3)+f(4)\right] \approx 0.333\left[3.6945 + 26.7807+13.6495\right]\approx 14.7082 $$
==Ejemplo 2 parte 2==
Encontrar la misma aproximación pero a través de cuatro intervalos:

$$\int_2^4 \frac{e^x}{x}dx$$
Donde:
- $n = 4$
- $a = 2 = x_0$
- $b = 4 = x_4$
- $h =\frac{4-2}{4} = \frac{1}{2}$ 
- $x_1 =2+\frac{1}{2}=\frac{5}{2}$
- $x_2 = \frac{5}{2}+\frac{1}{2} =3$
- $x_3 = 3+\frac{1}{2} = \frac{7}{2}$ 
- $f(x) =\frac{e^x}{x}$
Haciendo uso de la fórmula para cuando se tiene más de tres puntos a usar: 
$$I \approx \frac{h}{3}\left[f(x_0+4\sum_{i =1,3,5,...}^nf(x_i)+ 2\sum_{j=2,4,6,...}^{n-2} f(x_j)+f(x_n)\right]$$
**Aplicando:**
$$I \approx \frac{0.5}{3}\left[f(2)+4\left(f\left(\frac{5}{2}\right)+f\left(\frac{7}{2}\right)\right)+ 2\left(f\left(3\right)\right)+f\left(4\right)\right]$$
$$I \approx 0.1666\left[3.6945+4\left(4.873+9.4615\right)+ 2\left(6.6951\right)+13.6495\right]$$
$$I \approx 0.1666\left[3.6945+57.338+ 13.3902+13.6495\right] \approx 14.6728$$

### 2.2 Regla de simpson #3/8

Este genera un polinomio de 3er grado para que se aproxime a una función dada. 
La manera o como se observa la fórmula después de toda la operación y análisis es:
$$I \approx \frac{3}{8}h\left[f(a)+3f(x_1)+3f(x_2)+f(b)\right]$$
En donde:
$$h = \frac{b-a}{3}$$
==Ejercicio 1: ==
Encontrar una aproximación a la integral por medio de la regla de **Simspon $\frac{3}{8}$**

$$\int_0^1 e^{x^2}dx$$
Donde:
- $a = 0$
- $b = 1$
- $h =\frac{1-0}{3} = \frac{1}{3}$ 
- $x_1 = \frac{1}{3}$
- $x_2 = \frac{1}{3}+\frac{1}{3}=\frac{2}{3}$
- $f(x) =e^{x^2}$
**Solución:**
Aplicamos la siguiente fórmula para encontrar una aproximación a la integral: 
$$I \approx \frac{3}{8}h\left[f(a)+3f(x_1)+3f(x_2)+f(b)\right]$$
**Aplicando:**
$$I \approx \frac{3}{8}\left(\frac{1}{3}\right)\left[f(0)+3f\left(\frac{1}{3}\right)+3f\left(\frac{2}{3}\right)+f(1)\right]$$
$$\approx\frac{1}{8}\left[1+3(1.1175)+3(1.5596)\right]\approx1.1289$$
==Ejercicio 2:==
Encontrar una aproximación a la integral por medio de la regla de **Simspon $\frac{3}{8}$**

$$\int_2^4 \frac{e^x}{x}dx$$
Donde:
- $a = 2$
- $b = 4$
- $h =\frac{4-2}{3} = \frac{2}{3}$ 
- $x_1 = \frac{6}{3}+ \frac{2}{3}=\frac{8}{3}$
- $x_2 = \frac{8}{3}+\frac{2}{3}=\frac{10}{3}$
- $f(x) =\frac{e^x}{x}$
**Solución:**
Aplicamos la siguiente fórmula para encontrar una aproximación a la integral: 
$$I \approx \frac{3}{8}h\left[f(a)+3f(x_1)+3f(x_2)+f(b)\right]$$
**Aplicando:**
$$I \approx \frac{3}{8}\left(\frac{2}{3}\right)\left[f(2)+3f\left(\frac{8}{3}\right)+3f\left(\frac{10}{3}\right)+f(4)\right]$$
$$\approx \frac{1}{4}\left[3.6945+3(5.3969)+3(8.4094)\right] \approx\frac{1}{4}(45.1134)\approx 11.2783$$
==Ejercicio FInal==
Según la siguiente integral encontrar lo siguiente:
- Aproximar por Simpson $\frac{1}{3}$
- Aproximar por Simpson $\frac{1}{3}$ con múltiples intervalos donde $n=4$
- Aproximar por Simpson $\frac{3}{8}$ 
- Aproximar por Trapecio por intervalos múltiples donde $n=4$
- Comparar resultados y concluye cual resultó mejor 
$$\int_0^3x\cdot e^{2x}dx$$
1. Aproximar por Simpson $\frac{1}{3}$
Donde:
- $a = 0$
- $b = 3$
- $h =\frac{3-0}{2} = \frac{3}{2}$ 
- $x_1 = 0+ \frac{3}{2}=\frac{3}{2}$
- $f(x) =x\cdot e^{2x}$

**Solución:**
Como solo es necesario encontrarlo según tres puntos usamos la siguiente fórmula:
$$I \approx \frac{1}{3}h\left[f(a)+4f\left(\frac{a+b}{2}\right)+f(b)\right]$$
*Aplicando tenemos:*
$$I \approx \frac{1}{3}\left(\frac{3}{2}\right)\left[f(0)+4f\left(\frac{3}{2}\right)+f(3)\right]$$
$$\approx\frac{1}{2}\left[0+4(30.1283)+1210.2863\right] \approx 665.39975$$
2. Aproximar por Simpson $\frac{1}{3}$ con múltiples intervalos donde $n=4$
Donde:
- $a = 0$
- $b = 3$
- $h =\frac{3-0}{4} = \frac{3}{4}$ 
- $x_1 = 0+ \frac{3}{4}=\frac{3}{4}$
- $x_2 = \frac{3}{4}+ \frac{3}{4}=\frac{6}{4}$
- $x_3 = \frac{6}{4}+ \frac{3}{4}=\frac{9}{4}$
- $f(x) =x\cdot e^{2x}$
Haciendo uso de la fórmula para cuando se tiene más de tres puntos a usar: 
$$I \approx \frac{h}{3}\left[f(x_0)+4\sum_{i =1,3,5,...}^nf(x_i)+ 2\sum_{j=2,4,6,...}^{n-2} f(x_j)+f(x_n)\right]$$
**Aplicando:**
$$I \approx \frac{3/4}{3}\left[f(0)+4(f\left(\frac{3}{4}\right)+ f\left(\frac{9}{4}\right))+ 2\left(f\left(\frac{6}{4}\right)\right)+f(3)\right]$$
$$\approx \frac{1}{4}\left[0+4(3.3612+202.5385)+2(30.1283)+1210.2863\right]$$
$$\approx \frac{1}{4}(2094.1417) \approx 523.535425$$
3. Aproximar por Simpson $\frac{3}{8}$ 
- $a = 0$
- $b = 3$
- $h =\frac{3-0}{3} = \frac{3}{3} =1$ 
- $x_1 = 0+ 1=1$
- $x_2= 1+ 1=2$
- $f(x) =x\cdot e^{2x}$

**Solución:**
Aplicamos la siguiente fórmula para encontrar una aproximación a la integral: 
$$I \approx \frac{3}{8}h\left[f(a)+3f(x_1)+3f(x_2)+f(b)\right]$$
**Aplicando:**
$$I \approx \frac{3}{8}(1)\left[f(0)+3f(1)+3f(2)+f(3)\right]$$
$$\approx \frac{3}{8}\left[0+3(7.3890)+3(109.1963)+1210.2863\right]\approx\frac{3}{8}(1560.0422)$$
$$I\approx585.015825 $$
4. Aproximar por Trapecio por intervalos múltiples donde $n=4$
Donde: 
$a = 0$  $b = 3$        $n =6$

**Solución:**
$$h = \frac{3-0}{6} = \frac{3}{6} =\frac{1}{2}$$
Por lo tanto las $x$ es:
- $x_1 = 0+ \frac{1}{2}=\frac{1}{2}$
- $x_2 = \frac{1}{2}+ \frac{1}{2}=1$
- $x_3 = 1+ \frac{1}{2}=\frac{3}{2}$
- $x_4 = \frac{3}{2}+ \frac{1}{2}=\frac{4}{2}$
- $x_5 = \frac{4}{2}+ \frac{1}{2}=\frac{5}{2}$
- $f(x) =x\cdot e^{2x}$
$$I \approx \frac{1}{4}[f(x_0)+2f(x_1)+2f(x_2)+2f(x_3)+ 2f(x_4)+2f(x_5)+f(x_6)]$$
Ya desarrollado seria: 
$$I \approx \frac{1}{4}[f(0)+2f\left(\frac{1}{2}\right)+2f\left(\frac{2}{2}\right)+2f\left(\frac{3}{2}\right)+ 2f\left(\frac{4}{2}\right)+2f\left(\frac{5}{2}\right)+f(3)]$$
$$\approx \frac{1}{4}\left[0+2(1.3591)+2(7.3890)+2(30.1283)+2(109.1963)+2(371.0329)+1210.2863\right]\approx\frac{1}{4}(2248.4975)$$
$$I\approx 562.124375$$
5. Aproximar por regla del Trapecio 
$$I \approx \int_{a}^{b} (a_0+a_1x) =(b-a)\frac{f(a)+ f(b)}{2}$$
Donde: 
$a = 0$   $b = 3$    

**Solución:**
$$I \approx 3\left[\frac{f(0)+f(3)}{2}\right] \approx3\left[\frac{0+1210.2863}{2}\right]\approx 1815.42945$$
## Integración de #Romberg

Sea $I(h)$ el  valor de la integral que aproxima $I = \int_a^b f(x)dx$, mediante una partición de intervalos $h = \frac{b-a}{n}$, usando la regla del trapecio. Entonces:
$$I = I(h)+E(h)$$
Donde $E(h)$ es el error de truncamiento de la regla trapezoidal.

### Método de extrapolación de #Richardson

- Combina dos aproximaciones de integración numérica, para obtener un tercer valor más exacto.

Supón que tenemos: $I(h_1)$, $I(h_2)$ con subintervalos $h_1$ y $h_2$.
$$\therefore I = I(h_1)+E(h_1)\text{,      } I = I(h_2)+ E(h_2)\rightarrow I(h_1)+E(h_1) = I(h_2)+E(h_2)$$

- El error de truncamiento en la regla del trapecio es:
$$E(h_1)\approx -\frac{b-a}{12}h^2, f^{´´}(E)$$
$$E(h_2)\approx -\frac{b-a}{12}h^2, f^{´´}(E)$$

Tratando de dejar el error en términos de los intervalos tenemos:
$$I \approx I(h_2)+\frac{I(h_1)-I(h_2)}{1-(\frac{h_1}{h_2})^2}$$
Cuando $h_2 =\frac{h_1}{2}\rightarrow$ Esto es Romberg
$$I \approx \frac{4}{3} I(h_2)-\frac{I(h_1)}{3}$$
El algoritmo se trabajará en niveles:


==Ejemplo==
Usar la extrapolación de Richardson para encontrar la integral:
$$\int_0^1 e^{x^2}$$
**Solución**
Se hará hasta el nivel tres:

Comenzando con el nivel 0:
- $h_1 = b-a = 1$
- $h_2 = \frac{b-a}{2} = \frac{1}{2}$
- $h_3 = \frac{b-a}{4}=\frac{1}{4}$
	- $x_1 = 0+ \frac{1}{4} = \frac{1}{4}$
	- 
Continuando usando Integración por el trapecio tenemos:
- La manera o fórmula es:
$$\int_{a}^{b} f(x)dx \approx \frac{h}{2}[f(x_0)+2f(x_1)+2f(x_2)+ ...+ 2f(x_{n-1}) + f(x_n)]$$

*Aplicando*:
$$I(h_1) = \frac{1}{2}(e^{0^2}+e^{1^2}) =1.85914091$$
$$I(h_2)= \frac{1}{4}\left[e^{0^2}+2e^{(\frac{1}{2})^2}+ e^{1^2}\right]=1.571583165$$
$$I(h_3)= \frac{1}{8}\left[e^{0^2}+2\left[e^{(\frac{1}{4})^2}+e^{(\frac{2}{4})^2}+e^{(\frac{3}{4})^2}\right]+ e^{1^2}\right]= 1.490678862$$
Una vez calculado las integrales de esas diferentes $h$ se continua con el Nivel 1:
- Nivel 1: $\frac{4}{3}I(h_2)-\frac{1}{3}I(h_1)$           y          $\frac{4}{3}I(h_3)-\frac{1}{3}I(h_2)$

- **Nota:** Como se puede notar, en el nivel dos es repetir esa misma fórmula hasa que se usen todas las $h$ que fueron calculadas.

*Aplicando:*
$$I_i=(h_1,h_2)=\frac{4}{3}(1.571583165)-\frac{1}{3}(1.85914091)=1.475730582$$
$$I_n=(h_2,h_3)= \frac{4}{3}(1.490678862)-\frac{1}{3}(1.571583165) =1.463710761$$
Ya que se calculo este nivel, solo resta calcular el nivel 2, ya que como se esta mostrando fuimos bajando el número de ecuaciones a usar una por una cada vez que subíamos de nivel, por lo tanto al llegar al nivel 2 solo quedará una ecuación y por lo tanto nos dará nuestro resultado:

- Nivel 2: $\frac{16}{15}I_n-\frac{1}{15}I_i$

*Aplicando:*
$$I_F=\frac{16}{15}(1.463710761)-\frac{1}{15}(1.475730582) = 1.46290944$$

Como ya nos quedamos con una sola ecuación posible a usar, podemos decir que llegamos al final del problema y por lo tanto:
$$\int_0^1e^{x^2}dx\approx 1.46290944$$

==Ejercicio:==
Calcular por Richardson con $h_4$ la siguiente integral:
$$\int_1^2 e^xln(x)dx$$
**Solución:**
Tenemos que el valor de las $h$ es:
- $h_1 = b-a = 1$
- $h_2 = \frac{b-a}{2} = \frac{1}{2}$
- $h_3 = \frac{b-a}{4}=\frac{1}{4}$
- $h_4= \frac{b-a}{8} =\frac{1}{8}$

Continuando por la regla de Trapecio:
La formula a usar es:
$$\int_{a}^{b} f(x)dx \approx \frac{h}{2}[f(x_0)+2f(x_1)+2f(x_2)+ ...+ 2f(x_{n-1}) + f(x_n)]$$

*Aplicando:*
$$h_1 = \frac{1}{2}\left[e^1ln(1)+e^2ln(2)\right] = 2.56085170098652425$$
$$h_2 = \frac{1}{4}\left[e^1ln(1)+2e^{\frac{1}{2}}ln(\frac{1}{2})+ e^2ln(2)\right]= 2.18901012219916315$$
$$h_3 = \frac{1}{8}\left[e^1ln(1)+2\left(e^{\frac{5}{4}}ln\left(\frac{5}{4}\right)+e^{\frac{6}{4}}ln\left(\frac{6}{4}\right)+e^{\frac{7}{4}}ln\left(\frac{7}{4}\right)\right)+ e^2ln(2)\right]= 2.0943085695047854375$$
$$h_3 = \frac{1}{16}\left[e^1ln(1)+2\left(e^{\frac{9}{8}}ln\left(\frac{9}{8}\right)+e^{\frac{10}{8}}ln\left(\frac{10}{8}\right)+e^{\frac{11}{8}}ln\left(\frac{11}{8}\right)+e^{\frac{12}{8}}ln\left(\frac{12}{8}\right)+e^{\frac{13}{8}}ln\left(\frac{13}{8}\right)+e^{\frac{14}{8}}ln\left(\frac{14}{8}\right)+e^{\frac{15}{8}}ln\left(\frac{15}{8}\right)\right)+ e^2ln(2)\right]= 2.0705245010213471937$$
Pasamos al nivel 1 ahora donde:
$$\frac{4}{3}I(h_2)-\frac{1}{3}I(h_1)$$
*Aplicando para todos las h:*
$$(h_2,h_1)=\frac{4}{3}(2.18901012219916315)-\frac{1}{3}(2.56085170098652425)=2.06506292927004278333$$
$$(h_3,h_2)=\frac{4}{3}(2.0943085695047854375)-\frac{1}{3}(2.18901012219916315)=2.0627413852733262$$
$$(h_4,h_3)=\frac{4}{3}(2.0705245010213471937)-\frac{1}{3}(2.0943085695047854375)=2.0625964781935344457667$$

Pasamos al nivel 2 ahora donde: 
$$\frac{16}{15}I_n-\frac{1}{15}I_i$$
*Aplicando para las h restantes:*
$$((h_3,h_2),(h_2,h_1)) = \frac{16}{15}(2.0627413852733262)-\frac{1}{15}(2.06506292927004278333) = 2.06258661567354509444467$$
$$((h_4,h_3),(h_3,h_2)) = \frac{16}{15}(2.0625964781935344457667)-\frac{1}{15}(2.0627413852733262) = 2.0625868177215483288178133$$

Pasamos al nivel 3 ahora en donde:
$$\frac{64}{63}I_n-\frac{1}{63}I_j$$

*Aplicando para las ultimas dos ecuaciones restantes:*
$$ I = \frac{64}{63}(2.0625868177215483288178133)-\frac{1}{63}(2.06258661567354509444467) = 2.062586820928659491268180654 $$
Como ya no hay mas ecuaciones además de una sola, el resultado es:
$$\therefore \int_1^2 e^xln(x)dx \approx 2.062586820928659491268180654$$





# Ejercicios de la práctica

1. Usar la regla del trapecio para aproximar: 
$$\int_0^6 \frac{\text{cos (x)}}{x+1}dx$$
- Dividiendo en un solo intervalo.
- Dividiendo en 6 intervalos.

1.1 Un solo intervalo:
$$I = \frac{6-0}{2}\left[\frac{\text{cos (0)}}{0+1}+\frac{\text{cos (6)}}{6+1}\right] = 3.4262236694434286$$