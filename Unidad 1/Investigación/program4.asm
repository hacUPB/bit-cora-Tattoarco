@5
D=M

@10
D=D-A

// Si D < 0, ir a MENOR
@MENOR
D;JLT

// Caso: mayor o igual a 10
@7
M=0
@FIN
0;JMP

(MENOR)
// Caso: menor que 10
@7
M=1

(FIN)
@FIN
0;JMP
