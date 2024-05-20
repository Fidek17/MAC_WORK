### Interpolación Polinomial
- Aproximación a trozos
- Utilizamos tabla de Diferencias Divididas 
- Caso especial, sólo si los datos se presentan de esa forma
- Se requieren datos de $f$ y $f^´$
- $$H(x)=\sum_{k=0}^{n-1} f(z_0,Z_1,...,Z_n)(x-Z_0)(x-Z_1)...(x-Z_{k-1})$$
*n* -> Cantidad de Datos
k -> Términos generados

### Ejemplo:
Dado el siguiente conjunto de datos, obtener el polinomio de **Hermite**:
$x_0=-2$, $x_1=1$, si $f(x_0)=-12$, $f(x_1)=9$  y $f^´(x_0)=22$, $f^´(x_1)= 10$ .

**Solución**
$n = 4$
$k= 0, 1, 2, 3$

**Tabla de Diferencias**

| $k$ | $Z_k$ | $f(Z_k)$ | $f^´(Z_k)$        |                      |                         |
| --- | ----- | -------- | ----------------- | -------------------- | ----------------------- |
| 0   | -2    | -12      | ----              | -----                | -----                   |
| 1   | -2    | -12      | $f(Z_0,Z_1) = 22$ | ----                 | ----                    |
| 2   | 1     | 9        | $f(Z_1,Z_2)=7$    | $f(Z_0,Z_1, Z_2)=-5$ | ----                    |
| 3   | 1     | 9        | $f(Z_2,Z_3)=10$   | $f(Z_1,Z_2, Z_3)=1$  | $f(Z_0,Z_1, Z_2,Z_3)=2$ |
|     |       |          |                   |                      |                         |
$f(Z_1,Z_2)=\frac{f(Z_2)-f(Z_1)}{Z_2-Z_1} = \frac{9-(-12)}{1-(-2)}=\frac{21}{3}=7$
$f(Z_0,Z_1, Z_2)=\frac{f(Z_1,Z_2)-f(Z_0,Z_1)}{Z_2-Z_0}=\frac{7-22}{1-(-2)}=\frac{-15}{3}=-5$

Por lo tanto con la tabla de diferencias completa ya estamos en condiciones de construir el polinomio de **Hermite**:
$$H(x)=f(Z_0)+f(Z_0,Z_1)(x-Z_0)+f(Z_0,Z_1,Z_2)(x-Z_0)(x-Z_1)+f(Z_0,Z_1,Z_2,Z_3)(x-Z_0)(x-Z_1)(x-Z_2)$$

$$H(x) =-12+(22)(x-(-2))+(-5)(x+2)(x-(-2))+(2)(x+2)(x+2)(x-1)$$
$$H(x)=32 +22x-5x^2-20x-20+2x^3+6x^2-8= 2x^3+x^2+2x+4$$
Sacamos la derivada de $H(x)$:
$$H^´(x) = 6x^2+2x+2$$
Ahora solo falta revisar que si es cierto comprobando con los datos que nos proporcionaron:
$$H(-2) =2(-2)^3+(-2)^2+2(-2)+4 = -12$$

$$H^´(-2)= 6(-2)^2+2(-2)+2 = 22$$
Si es correcto y coincide con los datos proporcionados, falta revisar evaluar para $x=1$.
$$H(x) =2(1)^2+1^1+2(1)+4 = 9$$
$$H^´(1)=6(1)^1+2(1)+2=10$$
Como si coinciden los resultados con los datos dados podemos afirmar que es correcto el polinomio de **Hermite**. 

### Ejercicio:
Dada la siguiente función $f(x)=tan(\pi x)$  aproxime con el polinomio de **Hermite**, dado lo siguiente:
$x_0= 0$, $x_1=\frac{1}{4}$
$f(x_0)=0$, $f(x_1)=1$
$f^´(x_0)=\pi$, $f^´(x_1)=2\pi$
- Encuentre la aproximación para $H(\frac{1}{8})$

**Solución**
$n =4$
$k =0,1,2,3$
**Tabla de Diferencias**

| $k$ | $Z_k$         | $f(Z_k)$ | $f^´(Z_k)$         |                           |                                 |
| --- | ------------- | -------- | ------------------ | ------------------------- | ------------------------------- |
| 0   | 0             | 0        | ----               | -----                     | -----                           |
| 1   | 0             | 0        | $f(Z_0,Z_1) = \pi$ | ----                      | ----                            |
| 2   | $\frac{1}{4}$ | 1        | $f(Z_1,Z_2)=4$     | $f(Z_0,Z_1, Z_2)=16-4\pi$ | ----                            |
| 3   | $\frac{1}{4}$ | 1        | $f(Z_2,Z_3)=2\pi$  | $f(Z_1,Z_2, Z_3)=8\pi-16$ | $f(Z_0,Z_1, Z_2,Z_3)=48\pi-128$ |

$f(Z_1,Z_2)=\frac{f(Z_2)-f(Z_1)}{Z_2-Z_1} = \frac{1-0}{\frac{1}{4}-0}=\frac{1}{\frac{1}{4}}= 4$
$f(Z_0,Z_1, Z_2)=\frac{f(Z_1,Z_2)-f(Z_0,Z_1)}{Z_2-Z_0}=\frac{4-\pi}{\frac{1}{4}-0} =16-4\pi$
$f(Z_1,Z_2, Z_3)=\frac{f(Z_2,Z_3)-f(Z_1,Z_2)}{Z_3-Z_1} = \frac{2\pi-4}{\frac{1}{4}-0}=8\pi-16$
$f(Z_0,Z_1,Z_2, Z_3)=\frac{f(Z_1,Z_2,Z_3)-f(Z_0,Z_1,Z_2)}{Z_3-Z_0} =\frac{(8\pi-16)-(16-4\pi)}{\frac{1}{4}-0} =48\pi-128$

**Polinomio de Hermite**:
$$H(x)=f(Z_0)+f(Z_0,Z_1)(x-Z_0)+f(Z_0,Z_1,Z_2)(x-Z_0)(x-Z_1)+f(Z_0,Z_1,Z_2,Z_3)(x-Z_0)(x-Z_1)(x-Z_2)$$
$$H(x) = 0 + (\pi)(x-0)+(16-4\pi)(x-0)(x-0)+(48\pi-128)(x-0)(x-0)(x-\frac{1}{4})$$
$$H(x)=\pi x + 16x^2-4\pi x^2+ (48\pi-128)(x^2)(x-\frac{1}{4})$$
$$H(x)=\pi x + 16x^2-4\pi x^2+ (48\pi-128)(x^3-\frac{1}{4}x^2)$$
$$H(x)=\pi x + 16x^2-4\pi x^2+ (48\pi-128)(x^3-\frac{1}{4}x^2)$$
$$H(x)=\pi x + 16x^2-4\pi x^2+ 48x^3\pi-128x^3-12x^2\pi+32x^2$$
$$H(x)=(48\pi-128)x^3+(-16\pi+48)x^2+\pi x $$
Se debe sacar la derivada del polinomio encontrado:
$$H^´(x)=3(48\pi-128)x^2+2(-16\pi+48)x+\pi $$
Revisar si es correcto evaluando:
$x = 0$
$$H(0)= (48\pi-128)(0)+(-16\pi+48)(0)+\pi(0) = 0 $$
- Derivada
$$H^´(x)=3(48\pi-128)(0)+2(-16\pi+48)(0)+\pi = \pi$$
$x=\frac{1}{4}$
$$H(\frac{1}{4})=(48\pi-128)(\frac{1}{4})^3+(-16\pi+48)(\frac{1}{4})^2+\pi (\frac{1}{4}) $$
$$H(\frac{1}{4})=\frac{48\pi}{64}-2-\pi+3+\frac{\pi}{4}$$
$$H(\frac{1}{4})=\frac{3\pi}{4}+1-\pi+\frac{\pi}{4}= \pi-\pi+1 = 1$$
- Evaluando en $\frac{1}{8}$ como pide el problema:
$$H(x)=(48\pi-128)(\frac{1}{8})^3+(-16\pi+48)(\frac{1}{8})^2+\pi(\frac{1}{8}) $$
$$H(x)=(48\pi-128)(\frac{1}{512})+(-16\pi+48)(\frac{1}{64})+(\frac{\pi}{8}) $$
$$H(x)=(\frac{48\pi}{512}-\frac{128}{512})+(\frac{-16\pi}{64}+\frac{48}{64})+(\frac{\pi}{8})= 0.4018... $$

### Ejercicio 2:
Encuentre el polinomio de **Hermite** y encuentre la aproximación para $H(1.5)$.

| $k$ | $Z_k$ | $f(Z_k)$  | $f^´(Z_k)$ |
| --- | ----- | --------- | ---------- |
| 0   | 1.3   | 0.6200860 | -0.5220232 |
| 1   | 1.6   | 0.4554022 | -0.5698959 |
| 2   | 1.9   | 0.2818186 | -0.5811571 |
Primero construiremos la tabla de diferencias:

| $k$ | $Z_k$ | $f(Z_k)$  | $f^´(Z_k)$ |
| --- | ----- | --------- | ---------- |
| 0   | 1.3   | 0.6200860 | -0.5220232 |
| 1   | 1.3   | 0.6200860 | -0.5220232 |
| 2   | 1.6   | 0.4554022 | -0.5698959 |
| 3   | 1.6   | 0.4554022 | -0.5698959 |
| 4   | 1.9   | 0.2818186 | -0.5811571 |
| 5   | 1.9   | 0.2818186 | -0.5811571 |
