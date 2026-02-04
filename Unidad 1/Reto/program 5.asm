// contador = 5
@5
D=A
@13
M=D
// suma = 0
@12
M=0
(LOOP)
// suma = suma + contador
@10
D=M
@12
M=D+M

// contador = contador - 1
@10
M=M-1

// si contador > 0, repetir
@10
D=M
@LOOP
D;JGT

(END)
@END
0;JMP
