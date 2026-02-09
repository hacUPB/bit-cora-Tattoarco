@100
D=A
@ARRAY
M=D
A=M

@CONTADOR
//Declaro e inicializo el contador en 0
M=0
// Inicio el LOOP y le sumo 1 en cada vuelta 
(LOOP)
@ARRAY
A=M
D=M
//SUM = SUM + D 
@CONTADOR
M=M+1
D=M
@10
D=D-A
@LOOP
D;JLT

@SUM
M=0

