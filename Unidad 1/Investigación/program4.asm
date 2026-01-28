// Cargar el valor de la dirección 5
@5
D=M

// Restar 10 al valor
@10
D=D-A

// Si D < 0 (valor en 5 es menor que 10), saltar a MENOR
@MENOR
D;JLT

// Si es mayor o igual a 10, guardar 0 en la dirección 7
@7
M=0
@FIN
0;JMP

(MENOR)

@7
M=1

