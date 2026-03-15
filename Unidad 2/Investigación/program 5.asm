//Ejemplo 1
//Iniciar la variable A = 10
@10 
D=A
@a
M=D
// p = &a
@a
D=A
@p
M=D
// *p = 20
@20
D=A
@p
// A = dirección guardada en p
A=M     
// *p = 20
M=D    

//Ejemplo 2
// a = 10
@10
D=A
@a
M=D

// b = 5
@5
D=A
@b
M=D

// p = &a
@a
D=A
@p
M=D

// b = *p
@p
A=M     // A = dirección almacenada en p
D=M     // D = *p
@b
M=D     // b = D
