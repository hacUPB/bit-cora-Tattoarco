// ARRAY = 100 (base del arreglo)
@100
D=A
@ARRAY
M=D

// j = 0
@0
D=A
@CONTADOR
M=D

// sum = 0
@SUM
M=0

(LOOP)

// if j >= 10 -> END
@CONTADOR
D=M
@10
D=D-A
@END
D;JGE

// D = arr[j]
@ARRAY
D=M
@CONTADOR
A=D+M
D=M

// sum = sum + arr[j]
@SUM
M=M+D

// j++
@CONTADOR
M=M+1

@LOOP
0;JMP

(END)
@END
0;JMP
