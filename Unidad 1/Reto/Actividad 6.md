## Parte 1: Auto evaluación

1. Describe con tus palabras las tres fases del ciclo Fetch-Decode-Execute. ¿Qué rol juega el Program Counter (PC) en este ciclo?

El ciclo tiene tres fases: En el **fetch** el computador trae la instrucción desde la memoria, en el **decode** interpreta qué debe hacer la instrucción y dinalmente en el **execute** ejecuta la instrucción.

El **PC** indica la dirección de la siguiente instrucción que se va a ejecutar.

2. ¿Cuál es la diferencia fundamental entre una instrucción-A (que empieza con @) y una instrucción-C (que involucra D, M, A, etc.) en el lenguaje ensamblador de Hack? Da un ejemplo de cada una.

La instrucción-A sirve para cargar un valor o una dirección en el registro A.
Ejemplo: @2 y la instrucción-C sirve para hacer cálculos o mover datos.
Ejemplo: D=M

3. Explica la función de los siguientes componentes del computador Hack: el registro D, el registro A y la ALU.

- Registro D: guarda datos temporales para cálculos.
- Registro A: guarda direcciones de memoria o valores.
- ALU: realiza operaciones matemáticas y lógicas.

4. ¿Cómo se implementa un salto condicional en Hack? Describe un ejemplo (p. ej., saltar si el valor de D es mayor que cero).

Un salto condicional se hace usando una comparación y una instrucción de salto.
Ejemplo: saltar si D es mayor que cero.
```` .asm
@LOOP
D;JGT
````

5. ¿Cómo se implementa un loop en el computador Hack? Describe un ejemplo (p. ej., un loop que decremente un valor hasta que llegue a cero).
Un loop se hace con una etiqueta y un salto.
Ejemplo: repetir mientras un valor sea mayor que cero.
```` .asm
(LOOP)
@contador
M=M-1
D=M
@LOOP
D;JGT
````

6. ¿Cuál es la diferencia entre la instrucción D=M y la instrucción M=D?
- **D=M:** copia el valor de la memoria al registro D.
- **M=D:** copia el valor de D a la memoria.

7. Describe brevemente qué se necesita para leer un valor del teclado (KBD) y para “pintar” un pixel en la pantalla (SCREEN).

Para leer el teclado se usa la dirección **KBD** y para pintar un pixel se escribe un valor en **SCREEN**, ambos se controlan escribiendo o leyendo direcciones de memoria.

## Parte 2: reflexión sobre tu proceso (metacognición)
1. ¿Cuál fue el concepto o actividad más desafiante de esta unidad para ti y por qué?

Los ciclos y las etiquetas de salto, ya que esta no se suelen delcarar como se hace en un lenguaje de alto nivel, también el comprender como funciona el asiganr los nímeros a un espacio en la memoria.

2. La metodología de “predecir, ejecutar, observar y reflexionar” fue central en nuestras actividades. ¿En qué momento esta metodología te resultó más útil para entender algo que no tenías claro?

La metodología fue más útil cuando hacía predicciones antes de ejecutar el código y luego veía el resultado en el emulador.


3. Describe un momento “¡Aha!” que hayas tenido durante estas dos semanas. ¿Qué estabas haciendo cuando ocurrió?

En los momentos de pobar los códigos que el profesor nos brindaba y los analizamos.

4. Pensando en la próxima unidad, ¿Qué harás diferente en tu proceso de estudio para aprender de manera más efectiva?

Practicar más el tema de los ciclos y etiquetas, ya que un cuclo es fundamental al ejecutar una accion en un código de forma repetida.