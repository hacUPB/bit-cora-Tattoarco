@1
D=A
@13      
M=D

(LOOP)
// Si i > 5, terminar
@13
D=M
@5
D=D-A
@END
D;JGT

// suma = suma + i
@13
D=M
@12
M=M+D


@13
M=M+1

// Volver al inicio del ciclo
@LOOP
0;JMP
