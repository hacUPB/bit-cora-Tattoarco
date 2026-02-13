# Actividad 5

## Programa 1

- Código en c++

````.c++
int a = 10; 
int*p; 
p = &a; 
*p = 20;
````

![img activity 5](./img/image-7.png)

### Estado inicial

````.asm
RAM[16]=a
RAM[17]=p
````

1. a = 10

````.asm
RAM[a] = 10
````

2. p = &a

````.asm
RAM[p] = dirección de a (ej: 16)
````

3. *p = 20

````.asm
A = RAM[p] → 16
RAM[16] = 20
````

4. Resultado final

````.asm
a = 20
p = dirección de a
````

Aquí se confirma que el puntero no guarda el valor, guarda la dirección.
Cuando usamos A=M, estamos diciendo: "ve a la dirección almacenada en p  ".

## Programa 2

- Código en c++

````.c++
int a = 10; 
int b = 5; 
int *p; 
p = &a; 
b =*p;
````
