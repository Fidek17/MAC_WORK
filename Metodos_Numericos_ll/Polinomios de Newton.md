
| Punto | $x_i$ | $f[xi]$ | $$\Delta f[x_i]$$                      | $$\Delta f[x_i]$$        | $$\Delta^3f(x_i)$$      | $$\Delta^4f(x_i)$$       |
| ----- | ----- | ------- | -------------------------------------- | ------------------------ | ----------------------- | ------------------------ |
| 0     | 50    | 24.94   |                                        |                          |                         |                          |
|       |       |         | $\Delta f[x_0] = 30.11 - 24.94 = 5.17$ |                          |                         |                          |
| 1     | 60    | 30.11   |                                        | $\Delta^2 f[x_0] = 0.77$ |                         |                          |
|       |       |         | $\Delta f[x_1] = 5.94$                 |                          | $\Delta^3f(x_0) = 0.08$ |                          |
| 2     | 70    | 36.05   |                                        | $\Delta^2 f[x_1] = 0.85$ |                         | $\Delta^4f(x_0) = 0.01$  |
|       |       |         | $\Delta f[x_2] = 6.79$                 |                          | $\Delta^3f(x_1)= 0.09$  |                          |
| 3     | 80    | 42.84   |                                        | $\Delta^2 f[x_2]= 0.94$  |                         | $\Delta^4f(x_1) = -0.03$ |
|       |       |         | $\Delta f[x_3] = 7.73$                 |                          | $\Delta^3f(x_3)= 0.06$  |                          |
| 4     | 90    | 50.57   |                                        | $\Delta^2 f[x_3]= 1.00$  |                         |                          |
|       |       |         | $\Delta f[x_4] = 8.73$                 |                          |                         |                          |
| 5     | 100   | 59.30   |                                        |                          |                         |                          |

$h = 10$: Este es la diferencia que existe en cada $x_i$
Ahora si sabemos que si: $x = x_0+sh$
Entonces: 
$$s = \frac{x-x_0}{h} = \frac{64-50}{10}= 1.4$$
Y un polinomio de primer grado queda como:
$$p(x) = f[x_0]+s\Delta f[x_0] = 24.94+1.4(5.17) = 32.18$$
#### Ejercicio
1.1 Cambia el pivote de la formula con $x_1$ y encuentra el polinomio de primer grado para la temperatura de 64°F
$$s = \frac{x-x_1}{h}=\frac{64-60}{10}= 0.4$$
- Polinomio de primer grado:
$$p(x) = f[x_1] + s\Delta f[x_1] = 30.11 + 0.4(5.94) = 32.48$$
- Polinomio de segundo grado: 
$$ p(x) = 32.48 + (-0.12*0.85 )= 32.378$$
