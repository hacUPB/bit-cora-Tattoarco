## Actividad 6

### Parte 1

1. Describe brevemente los cambios que realizaste en el código C++ (dónde obtienes el tiempo, cómo y dónde actualizas el uniform).

`glGetUniformLocation` se llama una sola vez antes del loop para obtener la ubicación del `uniform time`. Dentro del loop, cada frame se llama `glfwGetTime()` para obtener el tiempo actual y se envía al shader con `glUniform1f(timeLocation, time)`.

2. Pega el código modificado de tu fragment shader.

```c++
#version 460 core
out vec4 FragColor;
uniform float time;
void main() {
    float r = (sin(time * 1.0) + 1.0) / 2.0;
    float g = (sin(time * 2.0) + 1.0) / 2.0;
    float b = (sin(time * 3.0) + 1.0) / 2.0;
    FragColor = vec4(r, g, b, 1.0);
}
```


3. Explica cómo usaste la función de tiempo (sin, cos, u otra) para lograr el efecto de cambio de color cíclico. ¿Qué rango de valores produce tu cálculo y cómo afecta eso al color final?

sin() produce valores entre -1 y 1. La fórmula (sin(x) + 1.0) / 2.0 lo convierte al rango [0, 1], que es lo que OpenGL espera para cada canal de color. Cada canal usa una frecuencia distinta (* 1.0, * 2.0, * 3.0) para que los tres no pulsen sincronizados y el resultado sea una variación de color continua en lugar de un simple fade de brillo.


4. Incluye una captura de pantalla o UN ENLACE a un video mostrando el resultado del triángulo con color cambiante.

[Video del tringulo](./Triangulo%20video.mp4)

5. Reflexión: ¿Qué otros efectos visuales simples podrías lograr usando el tiempo como uniform? Piensa en la posición, el tamaño o la rotación (aunque no hemos visto rotaciones formalmente, ¡intuitivamente podrías intentarlo!). Anota al menos una idea.

Podría usar el tiempo para hacer que el triángulo se mueva de un lado a otro usando una función seno para modificar su posición en el vertex shader.


Profe si llega a leer esto, yale entendí :|