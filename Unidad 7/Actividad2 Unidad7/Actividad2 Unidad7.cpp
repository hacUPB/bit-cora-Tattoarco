#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

const unsigned int SCR_WIDTH = 400;
const unsigned int SCR_HEIGHT = 400;

// ─── Shader A: usa location 0 (posición) ────────────────────────────────────
const char* vertSrcA = R"glsl(
    #version 460 core
    layout(location = 0) in vec3 aPos;
    void main() {
        gl_Position = vec4(aPos, 1.0);
    }
)glsl";

// ─── Shader B: usa location 1 (color como posición falsa) ───────────────────
const char* vertSrcB = R"glsl(
    #version 460 core
    layout(location = 1) in vec3 aColor;
    void main() {
        gl_Position = vec4(aColor * 0.5, 1.0);
    }
)glsl";

// ─── Shader C: usa location 2 (offset 2D) ───────────────────────────────────
const char* vertSrcC = R"glsl(
    #version 460 core
    layout(location = 2) in vec2 aOffset;
    void main() {
        gl_Position = vec4(aOffset, 0.0, 1.0);
    }
)glsl";

// Fragment shader compartido por los tres
const char* fragSrc = R"glsl(
    #version 460 core
    out vec4 FragColor;
    void main() {
        FragColor = vec4(1.0, 0.5, 0.2, 1.0);
    }
)glsl";

unsigned int VAO, VBO;
unsigned int shaderA, shaderB, shaderC;

// ─── Compila un vertex shader + el fragment compartido ──────────────────────
unsigned int buildShaderProgram(const char* vertSrc) {
    int  success;
    char log[512];

    unsigned int vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vertSrc, nullptr);
    glCompileShader(vs);
    glGetShaderiv(vs, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vs, 512, nullptr, log);
        std::cerr << "ERROR VERTEX SHADER:\n" << log << "\n";
    }

    unsigned int fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &fragSrc, nullptr);
    glCompileShader(fs);
    glGetShaderiv(fs, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fs, 512, nullptr, log);
        std::cerr << "ERROR FRAGMENT SHADER:\n" << log << "\n";
    }

    unsigned int prog = glCreateProgram();
    glAttachShader(prog, vs);
    glAttachShader(prog, fs);
    glLinkProgram(prog);
    glGetProgramiv(prog, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(prog, 512, nullptr, log);
        std::cerr << "ERROR LINKING PROGRAM:\n" << log << "\n";
    }

    glDeleteShader(vs);
    glDeleteShader(fs);
    return prog;
}

// ─── VBO con los 3 atributos entrelazados ───────────────────────────────────
void setupGeometry() {
    float vertices[] = {
        //  pos              color            offset
        -1.0f, -1.0f, 0.0f,  0.0f, 0.0f, 0.0f,  0.1f, 0.5f,
         0.0f, -1.0f, 0.0f,  1.0f, 0.0f, 0.0f,  0.2f, 0.5f,
        -0.5f, -0.5f, 0.0f,  0.5f, 0.5f, 0.0f,  0.15f, 0.75f,
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Location 0 — posición (3 floats, empieza en byte 0)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
        8 * sizeof(float), (void*)(0));
    glEnableVertexAttribArray(0);

    // Location 1 — color (3 floats, empieza después de 3 floats)
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,
        8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // Location 2 — offset (2 floats, empieza después de 6 floats)
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE,
        8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glBindVertexArray(0);
}

int main() {
    if (!glfwInit()) {
        std::cerr << "Fallo al inicializar GLFW\n";
        return -1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT,
        "Multi-shader VAO", nullptr, nullptr);
    if (!window) {
        std::cerr << "Error creando ventana\n";
        glfwTerminate();
        return -1;
    }

    int bufW, bufH;
    glfwGetFramebufferSize(window, &bufW, &bufH);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Fallo al cargar GLAD\n";
        return -1;
    }

    glfwSwapInterval(1);

    // Compilar los tres programas
    shaderA = buildShaderProgram(vertSrcA);
    shaderB = buildShaderProgram(vertSrcB);
    shaderC = buildShaderProgram(vertSrcC);

    setupGeometry();
    glViewport(0, 0, bufW, bufH);

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glBindVertexArray(VAO);

        // ── Draw call 1: solo posición (location 0) ──────────────────────────
        glUseProgram(shaderA);
        glEnableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
        glDisableVertexAttribArray(2);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // ── Draw call 2: solo color (location 1) ─────────────────────────────
        glUseProgram(shaderB);
        glDisableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        glDisableVertexAttribArray(2);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // ── Draw call 3: solo offset (location 2) ────────────────────────────
        glUseProgram(shaderC);
        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
        glEnableVertexAttribArray(2);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
    }

    // Limpieza
    glfwMakeContextCurrent(window);
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderA);
    glDeleteProgram(shaderB);
    glDeleteProgram(shaderC);

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}