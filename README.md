# cs1d3_perm4

### Miller-Rabin 

El test de Miller-Rabin es un test de primalidad probabilístico, es decir: dado un candidato n, nos dirá si el número es compuesto con total seguridad, pero si el algoritmo resuelve que n es primo sólo podemos estar bastante seguros de que este resultado es cierto.

El teorema establece algunas de las claves del algoritmo; siendo n el número que queremos comprobar (asumiremos que es un número impar, ya que no hay primos pares mayores que 2):
* Se trabaja en el grupo multiplicativo (Z/nZ)∗, es decir el grupo de los enteros módulo n.
* Descomponer n−1 como m2k, para algún k≥1 y m impar.
* Para un a∈(Z/nZ)∗ dado, comprobar si pertenece al conjunto B=a∈(Z/nZ)∗ : am=1∨am2i=−1 Ⅎi∈[0,k).

Para este ejercicio en el codigo he utilizado las funciones que explicare a continuacion que para mi son las mas importantes.

| Funciones | Explicacion |
| ---------- | ------------ |
| witness |  Con esta funcion  lo que haremos sera verificar que un numero pueda ser primo cuando lo evualemos con diversas condiciones. |
| millerRabin | Lo que hace esta funcion es un test de witness en un numero S de bases para un numero N para asi poder comprobar si estos resultados son primos o no. |
| GeneradorDePrimos | Con este metodo vamos a obtener los numeros primos de 3 cifras mediante la funcion millerRabin. |

### Generate-Prime

| Funciones | Explicacion |
| ---------- | ------------ |
| witness |  Con esta funcion  lo que haremos sera verificar que un numero pueda ser primo cuando lo evualemos con diversas condiciones. |
| millerRabin | Lo que hace esta funcion es un test de witness en un numero S de bases para un numero N para asi poder comprobar si estos resultados son primos o no. |
| GeneradorDePrimos | Con este metodo vamos a obtener 100 numeros primos distintos de 10 bits. |
