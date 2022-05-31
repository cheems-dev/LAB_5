#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <random>
#include <vector>


void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

const unsigned int SCR_WIDTH = 985;
const unsigned int SCR_HEIGHT = 985;

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec3 aColor;\n"
"out vec3 ourColor;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos, 1.0);\n"
"   ourColor = aColor;\n"
"}\0";

const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"in vec3 ourColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(ourColor, 1.0f);\n"
"}\n\0";

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LABORATORIO5", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    float vertices[] = {
/*
    0C 0.0f,0.0f,
    1D - 0.09f,0.21f,
    2E - 0.06f,-0.14f,
    3F - 0.06f,-0.19f,
    4G	0.04f,-0.13f,
    5H	0.04f,-0.19f,
    6I	0.03f,-0.31f,
    7J - 0.01f,-0.27f,
    8K - 0.04f,-0.32,
    9L  0.0f,-0.35f,
    10M - 0.45f,-0.24f,
    11N - 0.43f,-0.01f,
    12O - 0.49f,0.53f,
    13P - 0.57f,0.26f,
    14Q - 0.75f,0.25f,
    15R - 0.8f,0.4f,
    16S -0.8f,0.6f,
    17T -0.87f,0.38f,
    18U -0.67f,-0.04f,
    19V -0.61f,-0.27f,
    20W -0.46f,-0.39f,
    21Z -0.49f,-0.54f,
    22A1 -0.36f,-0.48f,
    23B1 -0.2f,-0.6f,
    24C1 -0.04f,0.28f,
    25D1 0.03f,0.28f,
    26E1 0.06f,0.21f,
    27F1 0.03f,0.15f
    28G1 -0.04f,0.15f,
    29H1 0.47f,0.53f,
    30I1 0.56f,0.27f,
    31J1 0.74f,0.24f,
    32K1 0.67f,-0.03f,
    33L1 0.43f,-0.02f,
    34M1 0.45f,-0.24f,
    35N1 0.59f,-0.26f,
    36O1 0.45f,-0.39f,
    37P1 0.35f,-0.48f,
    38Q1 0.2f,-0.6f,
    39R1 0.46f,-0.54f,
    40S1 0.8f,0.6f,
    41T1 0.8f,0.4f,
    42U1 0.86f,0.37f,
    43V1 -0.11f,0.44f,
    44W1 -0.07f,0.47f,
    45Z1 0.06f,0.47f,
    46A2 0.09f,0.44f,

    */
    //0.19f, 0.91f, 0.91f,
    //C1V1W1
    -0.04f,0.28f,0.0f,   0.19f, 0.91f, 0.91f,
    -0.11f,0.44f,0.0f,   0.19f, 0.91f, 0.91f,
    -0.07f,0.47f,0.0f,   0.19f, 0.91f, 0.91f,
    //D1Z1A2    0.52f, 1f, 0.83f,
    0.03f,0.28f,0.0f,   0.52f, 1.0f, 0.83f,
    0.06f,0.47f,0.0f,   0.52f, 1.0f, 0.83f,
    0.09f,0.44f,0.0f,   0.52f, 1.0f, 0.83f,
    //DCF    0.59f, 1.0f, 0.52f,
    0.0f,0.0f,0.0f, 0.59f, 1.0f, 0.52f,
    -0.09f,0.21f,0.0f,  0.59f, 1.0f, 0.52f,
    -0.06f,-0.19f,0.0f, 0.59f, 1.0f, 0.52f,
    //CE1H   0.04f, 0.97f, 0.56f,
    0.0f,0.0f,0.0f,  0.04f, 0.97f, 0.56f,
    0.06f,0.21f,0.0f,  0.04f, 0.97f, 0.56f,
    0.04f,-0.19f,0.0f,  0.04f, 0.97f, 0.56f,
    //CDE1//0.93f, 0.07f, 0.47f,
    0.0f,0.0f,0.0f,   0.93f, 0.07f, 0.47f,
    -0.09f,0.21f,0.0f,   0.93f, 0.07f, 0.47f,
    0.06f,0.21f,0.0f,   0.93f, 0.07f, 0.47f,
    //E1DC1//0.97f, 0.45f, 0.69f,
    0.06f,0.21f,0.0f,   0.97f, 0.45f, 0.69f,
    -0.09f,0.21f,0.0f,   0.97f, 0.45f, 0.69f,
    -0.04f,0.28f,0.0f,   0.97f, 0.45f, 0.69f,
    //E1C1D1       0.75f, 0.97f, 0.04f,
     0.06f,0.21f,0.0f,   0.75f, 0.97f, 0.04f,
     -0.04f,0.28f,0.0f,  0.75f, 0.97f, 0.04f,
     0.03f,0.28f,0.0f,   0.75f, 0.97f, 0.04f,
    //CFH   0.04f, 0.6f, 0.97f,
    0.0f,0.0f,0.0f,   0.04f, 0.6f, 0.97f,
    -0.06f,-0.19f,0.0f,  0.04f, 0.6f, 0.97f,
    0.04f,-0.19f,0.0f,   0.04f, 0.6f, 0.97f,
    //FHL   0.14f, 0.04f, 0.97f,
    -0.06f,-0.19f,0.0f, 0.14f, 0.04f, 0.97f,
    0.04f,-0.19f,0.0f, 0.14f, 0.04f, 0.97f,
    0.0f,-0.35f,0.0f, 0.14f, 0.04f, 0.97f,

    //0.97f, 0.02f, 0.02f,
    -0.09f,0.21f,0.0f,  0.97f, 0.02f, 0.02f,
    -0.49f,0.53f,0.0f,  0.97f, 0.02f, 0.02f,
    -0.57f,0.26f,0.0f,  0.97f, 0.02f, 0.02f,
    //0.68f, 0.09f, 0.09f,
    -0.49f,0.53f,0.0f,  0.68f, 0.09f, 0.09f,
     -0.75f,0.25f,0.0f,  0.68f, 0.09f, 0.09f,
     -0.57f,0.26f,0.0f, 0.68f, 0.09f, 0.09f,
     //0.96f, 0.47f, 0.47f,
     -0.49f,0.53f,0.0f,   0.96f, 0.47f, 0.47f,
     -0.8f,0.4f,0.0f,  0.96f, 0.47f, 0.47f,
     -0.75f,0.25f,0.0f,  0.96f, 0.47f, 0.47f,
    //0.89f, 0.78f, 0.09f,
     -0.49f,0.53f,0.0f, 0.89f, 0.78f, 0.09f,
     -0.8f,0.4f,0.0f, 0.89f, 0.78f, 0.09f,
     -0.8f,0.6f,0.0f, 0.89f, 0.78f, 0.09f,

       //0.89f, 0.78f, 0.09f,
     -0.87f,0.38f,0.0f, 0.89f, 0.78f, 0.09f,
     -0.8f,0.4f,0.0f, 0.89f, 0.78f, 0.09f,
     -0.75f,0.25f,0.0f, 0.89f, 0.78f, 0.09f,
        //0.09f, 0.24f, 0.89f,
    -0.87f,0.38f,0.0f, 0.09f, 0.24f, 0.89f,
     -0.8f,0.4f,0.0f, 0.09f, 0.24f, 0.89f,
     -0.8f,0.6f,0.0f, 0.09f, 0.24f, 0.89f,

     //QPU  0.09f, 0.24f, 0.89f,
     -0.75f,0.25f,0.0f, 0.09f, 0.24f, 0.89f,
     -0.57f,0.26f,0.0f, 0.09f, 0.24f, 0.89f,
     -0.67f,-0.04f,0.0f, 0.09f, 0.24f, 0.89f,
     //0.38f, 0.09f, 0.89f,
     -0.57f,0.26f,0.0f, 0.38f, 0.09f, 0.89f,
     -0.67f,-0.04f,0.0f, 0.38f, 0.09f, 0.89f,
     - 0.43f,-0.01f,0.0f, 0.38f, 0.09f, 0.89f,
    //0.79f, 0.04f, 0.24f,
     -0.57f,0.26f,0.0f, 0.79f, 0.04f, 0.24f,
    -0.09f,0.21f,0.0f, 0.79f, 0.04f, 0.24f,
    -0.43f,-0.01f,0.0f, 0.79f, 0.04f, 0.24f,
    //NDF 0.08f, 0.33f, 0.12f,
    -0.43f,-0.01f,0.0f, 0.08f, 0.33f, 0.12f,
    -0.09f,0.21f,0.0f, 0.08f, 0.33f, 0.12f,
    -0.06f,-0.19f,0.0f, 0.08f, 0.33f, 0.12f,
    //NFM  0.08f, 0.19f, 0.33f,
    -0.43f,-0.01f,0.0f, 0.08f, 0.19f, 0.33f,
    -0.06f,-0.19f,0.0f, 0.08f, 0.19f, 0.33f,
    -0.45f,-0.24f,0.0f, 0.08f, 0.19f, 0.33f,

         
    //NVM  0.33f, 0.08f, 0.33f,
    -0.43f,-0.01f,0.0f, 0.33f, 0.08f, 0.33f,
    -0.61f,-0.27f,0.0f, 0.33f, 0.08f, 0.33f,
    -0.45f,-0.24f,0.0f, 0.33f, 0.08f, 0.33f,
    //MFW   0.85f, 0.44f, 0.21f,
    -0.45f,-0.24f,0.0f, 0.85f, 0.44f, 0.21f,
    -0.06f,-0.19f,0.0f, 0.85f, 0.44f, 0.21f,
    -0.46f,-0.39f,0.0f, 0.85f, 0.44f, 0.21f,

    //VMW  0.35f, 0.17f, 0.07f,
    -0.61f,-0.27f,0.0f, 0.35f, 0.17f, 0.07f,
    -0.45f,-0.24f,0.0f, 0.35f, 0.17f, 0.07f,
    -0.46f,-0.39f,0.0f, 0.35f, 0.17f, 0.07f,

    //VWZ  0.35f, 0.07f, 0.12f,
    -0.61f, -0.27f, 0.0f, 0.35f, 0.07f, 0.12f,
    -0.46f, -0.39f, 0.0f, 0.35f, 0.07f, 0.12f,
    -0.49f, -0.54f,0.0f, 0.35f, 0.07f, 0.12f,
    //WZA1   0.34f, 0.35f, 0.07f,
        -0.46f, -0.39f, 0.0f, 0.34f, 0.35f, 0.07f,
        -0.49f, -0.54f, 0.0f, 0.34f, 0.35f, 0.07f,
        -0.36f, -0.48f, 0.0f, 0.34f, 0.35f, 0.07f,
    //FWA1 0.07f, 0.25f, 0.35f,
        -0.06f, -0.19f, 0.0f, 0.07f, 0.25f, 0.35f,
        -0.46f, -0.39f, 0.0f, 0.07f, 0.25f, 0.35f,
        -0.36f, -0.48f, 0.0f, 0.07f, 0.25f, 0.35f,
     //FA1K   0.11f, 1.0f, 0.17f,
        -0.06f, -0.19f, 0.0f, 0.11f, 1.0f, 0.17f,
        -0.36f, -0.48f, 0.0f, 0.11f, 1.0f, 0.17f,
        -0.04f, -0.32, 0.0f, 0.11f, 1.0f, 0.17f,

    //KA1B1   0.39f, 0.08f, 1.0f,
        -0.04f, -0.32, 0.0f, 0.39f, 0.08f, 1.0f,
        -0.36f, -0.48f, 0.0f, 0.39f, 0.08f, 1.0f,
        -0.2f, -0.6f, 0.0f, 0.39f, 0.08f, 1.0f,

    //A1B1Z      0.08f, 0.61f, 1.0f,
        -0.36f, -0.48f, 0.0f, 0.08f, 0.61f, 1.0f,
        -0.2f, -0.6f, 0.0f, 0.08f, 0.61f, 1.0f,
        -0.49f, -0.54f, 0.0f, 0.08f, 0.61f, 1.0f,



    //E1HL1   0.63f, 1.0f, 0.08f,
        0.06f, 0.21f, 0.0f, 0.63f, 1.0f, 0.08f,
        0.04f, -0.19f, 0.0f, 0.63f, 1.0f, 0.08f,
        0.43f, -0.02f, 0.0f, 0.63f, 1.0f, 0.08f,
    //E1I1L1   1.0f, 0.08f, 0.82f,
        0.06f, 0.21f, 0.0f, 1.0f, 0.08f, 0.82f,
        0.56f, 0.27f, 0.0f, 1.0f, 0.08f, 0.82f,
        0.43f, -0.02f, 0.0f, 1.0f, 0.08f, 0.82f,
    //I1K1L1   1.0f, 0.74f, 0.08f,
        0.56f, 0.27f, 0.0f, 1.0f, 0.74f, 0.08f,
        0.67f, -0.03f, 0.0f, 1.0f, 0.74f, 0.08f,
        0.43f, -0.02f, 0.0f, 1.0f, 0.74f, 0.08f,

        //I1J1K1   1.0f, 0.18f, 0.08f,
        0.56f, 0.27f, 0.0f, 1.0f, 0.18f, 0.08f,
         0.74f, 0.24f, 0.0f, 1.0f, 0.18f, 0.08f,
         0.67f, -0.03f, 0.0f, 1.0f, 0.18f, 0.08f,

        //E1H1I1  0.52f, 0.08f, 1.0f,
         0.06f,0.21f, 0.0f, 0.52f, 0.08f, 1.0f,
         0.47f,0.53f, 0.0f, 0.52f, 0.08f, 1.0f,
         0.56f,0.27f, 0.0f, 0.52f, 0.08f, 1.0f,
        //H1I1J1   1.0f, 0.08f, 0.36f,
         0.47f, 0.53f, 0.0f, 1.0f, 0.08f, 0.36f,
         0.56f, 0.27f, 0.0f, 1.0f, 0.08f, 0.36f,
         0.74f, 0.24f, 0.0f, 1.0f, 0.08f, 0.36f,
        //H1T1J1    1.0f, 0.08f, 0.36f,
         0.47f, 0.53f, 0.0f, 1.0f, 0.08f, 0.36f,
         0.8f, 0.4f, 0.0f, 1.0f, 0.08f, 0.36f,
         0.74f, 0.24f, 0.0f, 1.0f, 0.08f, 0.36f,
        //H1S1T1       0.35f, 0.54f, 0.0f,
        0.47f, 0.53f, 0.0f, 0.35f, 0.54f, 0.0f,
         0.8f, 0.6f, 0.0f, 0.35f, 0.54f, 0.0f,
         0.8f, 0.4f, 0.0f, 0.35f, 0.54f, 0.0f,
        //T1S1U1     0.0f, 0.28f, 0.54f,
         0.8f, 0.4f, 0.0f, 0.0f, 0.28f, 0.54f,
         0.8f, 0.6f, 0.0f, 0.0f, 0.28f, 0.54f,
         0.86f, 0.37f, 0.0f, 0.0f, 0.28f, 0.54f,
        //T1U1J1    0.17f, 0.0f, 0.54f,
         0.8f, 0.4f, 0.0f, 0.17f, 0.0f, 0.54f,
         0.86f, 0.37f, 0.0f, 0.17f, 0.0f, 0.54f,
         0.74f, 0.24f, 0.0f, 0.17f, 0.0f, 0.54f,
        //HL1M1      0.47f, 0.54f, 0.0f,
         0.04f, -0.19f, 0.0f, 0.47f, 0.54f, 0.0f,
         0.43f, -0.02f, 0.0f, 0.47f, 0.54f, 0.0f,
         0.45f, -0.24f, 0.0f, 0.47f, 0.54f, 0.0f,
         //L1M1N1   0.54f, 0.0f, 0.23f,
        0.43f, -0.02f, 0.0f, 0.54f, 0.0f, 0.23f,
        0.45f, -0.24f, 0.0f, 0.54f, 0.0f, 0.23f,
        0.59f, -0.26f, 0.0f, 0.54f, 0.0f, 0.23f,
         //HM1O1 0.54f, 0.33f, 0.0f,
        0.04f, -0.19f, 0.0f, 0.54f, 0.33f, 0.0f,
        0.45f, -0.24f, 0.0f, 0.54f, 0.33f, 0.0f,
        0.45f, -0.39f, 0.0f, 0.54f, 0.33f, 0.0f,
         //M1N1O1   0.54f, 0.0f, 0.02f,
        0.45f, -0.24f, 0.0f, 0.54f, 0.0f, 0.02f,
        0.59f, -0.26f, 0.0f, 0.54f, 0.0f, 0.02f,
        0.45f, -0.39f, 0.0f, 0.54f, 0.0f, 0.02f,
         //HO1P1  0.0f, 0.54f, 0.49f,
        0.04f, -0.19f, 0.0f, 0.0f, 0.54f, 0.49f,
        0.45f, -0.39f, 0.0f, 0.0f, 0.54f, 0.49f,
        0.35f, -0.48f, 0.0f, 0.0f, 0.54f, 0.49f,
         //O1N1R1   0.48f, 0.54f, 0.0f,
        0.45f, -0.39f, 0.0f, 0.48f, 0.54f, 0.0f,
        0.59f, -0.26f, 0.0f, 0.48f, 0.54f, 0.0f,
        0.46f, -0.54f, 0.0f, 0.48f, 0.54f, 0.0f,
         //HIP1  0.48f, 0.54f, 0.0f,
        0.04f, -0.19f, 0.0f, 0.48f, 0.54f, 0.0f,
        0.03f, -0.31f, 0.0f, 0.48f, 0.54f, 0.0f,
        0.35f, -0.48f, 0.0f, 0.48f, 0.54f, 0.0f,
         //IQ1P1   0.06f, 0.54f, 0.0f,
        0.03f, -0.31f, 0.0f, 0.06f, 0.54f, 0.0f,
        0.2f, -0.6f, 0.0f, 0.06f, 0.54f, 0.0f,
        0.35f, -0.48f, 0.0f, 0.06f, 0.54f, 0.0f,
         //P1O1R1  0.6f, 0.31f, 0.32f,
        0.35f, -0.48f, 0.0f, 0.6f, 0.31f, 0.32f,
            0.45f, -0.39f, 0.0f, 0.6f, 0.31f, 0.32f,
            0.46f, -0.54f, 0.0f, 0.6f, 0.31f, 0.32f,
         //Q1P1R1   0.6f, 0.31f, 0.32f,
            0.2f, -0.6f, 0.0f, 0.6f, 0.31f, 0.32f,
            0.35f, -0.48f, 0.0f, 0.6f, 0.31f, 0.32f,
            0.46f, -0.54f, 0.0f, 0.6f, 0.31f, 0.32f,


    
    };

    int numTriangles = 4000;

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glUseProgram(shaderProgram);

    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, numTriangles * 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);

    glfwTerminate();
    return 0;
}