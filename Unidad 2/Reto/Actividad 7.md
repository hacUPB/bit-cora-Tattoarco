# Actividad 7

## Parte 1: recuperación de conocimiento (Retrieval Practice)

1. Explica cómo se representa y manipula un puntero en el lenguaje ensamblador de Hack. Describe las operaciones equivalentes a p = &a (asignar dirección) y \*p = 20 (escribir a través del puntero) usando instrucciones de ensamblador.

En el lenguaje ensamblador Hack no existen punteros como tipo de dato, pero se pueden simular usando variables que guardan direcciones de memoria.

Un “puntero” en Hack es simplemente una variable que contiene la dirección de otra variable.

### p = &a (guardar la dirección de `a` en `p`)

Esto significa: p apunta a a.

En Hack se hace así:

```asm
@a
D=A      // D = dirección de a
@p
M=D      // p = dirección de a
```

Aquí:

A contiene direcciones.

D=A copia esa dirección.

M=D la guarda en la variable p.

2. ¿Cómo implementarías el acceso a un elemento de un arreglo, como arr[j], en lenguaje ensamblador? Describe el rol de la dirección base del arreglo y el índice j en esta operación.

Debemos calcular manualmente la dirección del elemento.

Un arreglo es simplemente un bloque de memoria contigua.

Si el arreglo comienza en la dirección 100, entonces:

arr[0] → RAM[100]

arr[1] → RAM[101]

arr[2] → RAM[102]

- Implementación de arr[j]

Supongamos:

ARRAY guarda la dirección base

CONTADOR guarda el valor de j

```.asm
@ARRAY
D=M          // D = dirección base del arreglo

@CONTADOR
A=D+M        // A = base + j

D=M          // D = arr[j]
```

- Aquí:

D=M (primera vez) obtiene la dirección base.

A=D+M calcula base + índice.

D=M (segunda vez) obtiene el valor del arreglo.

## Parte 2: reflexión sobre tu proceso (Metacognición)

1. ¿Cuál fue el concepto más abstracto o difícil de “traducir” de C++ a ensamblador en esta unidad (punteros, ciclos, arreglos)? ¿Qué hiciste para lograr entenderlo?

El tema más cmplicado fueron los punteros, aun sigo intentando comprenderlos en su totalidad, pero, convirtiendo el problema a un lenguaje más sencillo logré avanzar un poco más.

2. En la Actividad 06 se sugirió construir el programa “PASO A PASO mediante pruebas”. ¿Cómo te ayudó este enfoque a manejar la complejidad del problema?

Me funcionó para saber como funcionaban los loops, los array y como hacer que funcionen.

3. Esta unidad fue el “puente” hacia C++. ¿Qué concepto de bajo nivel te sientes más seguro de poder identificar cuando lo veas implementado en C++?

Los ciclos, creo que es un tema interesante, además el saber cómo funciona más a fondo el computador al ingresarle datos.
