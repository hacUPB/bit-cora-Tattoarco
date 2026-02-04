## Actividad 1

- Punto en el screen

![alt text](image-1.png)

## Actividad 2

- Línea horizontal de 16 px

![alt text](image.png)

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

![alt text](image-2.png)

El código no funciona, la línea se mueve a la izquierda al oprimir la tecla "i" pero se hace mas chica al oprimir la "d".
Estos no fucnionaba porque el loop retornaba al inici, reiniciando el ciclo desde 0.

- Código funcional. (Se mueve de lado a lado)
![alt text](image-3.png)

- Ahora el c+odigo se tiene que mover n° veces al oprimir "d" e "i"
