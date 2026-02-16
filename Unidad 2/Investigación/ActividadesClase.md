# Actividad 1

- Punto en el screen

![Activity 1 Screenshot](./img/image-1.png)

## Actividad 2

- Línea horizontal de 16 px

![Activity 2 Screenshot](./img/image.png)

## Actividad 3

- Primero de debe calcular en X el registro que quede en la mitad: 16384+(128\*32)+16.

RAM[20496] = -1 \
Leer KBD \
si KBD = 105 \
 izquierda \
si no \
si KBD = 68 \
 derecha \
si no \
ir a KBD

izquierda \
RAM [20496] = 0 \
RAM [20495] = -1

derecha \
RAM [20495] = -1 \
RAM [20496] = 0

- Asi se Visualiza en código asembly (Se utilizó IA para saber en dóde penr las etiquetas y saber como funcionan)

![Assembly Code Non-functional](./img/image-2.png)

El código no funciona, la línea se mueve a la izquierda al oprimir la tecla "i" pero se hace mas chica al oprimir la "d".
Estos no fucnionaba porque el loop retornaba al inici, reiniciando el ciclo desde 0.

- Código funcional. (Se mueve de lado a lado)

![Functional Code](./img/image-3.png)

- Ahora el codigo se tiene que mover n° veces al oprimir "d" e "i" (funciona)

![Movement Code](./img/image-4.png)

```.asm
//Asigno el valor 20496 al puntero
@20496
D=A
@PUNTERO
M=D
//Pinto el puntero
@PUNTERO
A=M
M=-1

(KBD_LOOP)
@KBD
D=M
@105
D=D-A
@IZQUIERDA
D;JEQ
@KBD
D=M
@100
D=D-A
@DERECHA
D;JEQ
@KBD_LOOP
0;JMP


(IZQUIERDA)
@PUNTERO
A=M
M=0
@PUNTERO
M=M-1
@PUNTERO
A=M
M=-1
@KBD_LOOP
0;JMP


(DERECHA)
@PUNTERO
A=M
M=0
@PUNTERO
M=M+1
@PUNTERO
A=M
M=-1
@KBD_LOOP
0;JMP
```

![Movement demonstration GIF](https://media2.giphy.com/media/v1.Y2lkPTc5MGI3NjExMG0xcjNiZzduZDZ2Z2UwOHJvMWlzdG8ydGFoc2owZTgxYWVzMXAzYiZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/bJ4TVNYNUympPgcpem/giphy.gif)
