<h1>Actividad 5</h1>

<p>Para iniciar a realizar a realizar el programa se tomó esta lógica</p>
<img width="300" height="500" alt="image" src="https://github.com/user-attachments/assets/d97c5b5f-0672-46ad-9f04-c32750848bca" />
<p>Pero hubieron errores de lógica, ya que el código estaba siendo muy largo, habiendo allí líneas de código inecesarias.</p>

````.asm
@5
D=A
@13
M=D
@12
M=0
@13
D=M
@12
M=D+M
@10
M=M-1
@13
D=M
````


<p>Luego logré comprender el ciclo y plasmar lo deseado y el código funciona.</p>
<h2>Casos de prueba</h2>

<ul>
  <li>Vuelta 1</li>
    <img width="608" height="399" alt="image" src="https://github.com/user-attachments/assets/1f80fbc7-0e61-4639-b28a-289a20c6ea52" />
  <li>Vuelta 2</li>
    <img width="608" height="399" alt="image" src="https://github.com/user-attachments/assets/4f697e21-9623-4b25-8f00-50cb77e9dbf3" />
  <li>Vuelta 3</li>
    <img width="608" height="399" alt="image" src="https://github.com/user-attachments/assets/0c4c946c-5c1a-4c95-876e-8d5f5440ec33" />
  <li>Vuelta 4</li>
    <img width="608" height="399" alt="image" src="https://github.com/user-attachments/assets/9e2c2b86-c303-4fb1-8d13-464527f0c699" />
  <li>Vuelta 5</li>
    <img width="608" height="399" alt="image" src="https://github.com/user-attachments/assets/722c1e02-899d-42a9-8651-a273f092edc0" />
</ul>
<p>Al llegar a 0 el contador @10 el programa finaliza y se deja de ejecutar el LOOP </p>

<h2>Código final</h2>

```` .asm
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

````



