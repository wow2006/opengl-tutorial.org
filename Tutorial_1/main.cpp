#include <iostream>         // std::cout, std::cerr
#include <GL/glew.h>        // GLEW
#include <GLFW/glfw3.h>     // GLFW3
#include <glm/glm.hpp>      // GLM

using namespace std;
using namespace glm;

int main(int argc, char** argv){
    if(!glfwInit()){
        cerr << "Failed to inialize GLFW\n";
        return -1;
    }
    glfwWindowHint(GLFW_SAMPLES, 4);                // 4x antialiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);  // OpenGL 3.3 Core Profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //We don't want the old OpenGL

    GLFWwindow* window = nullptr;
    return 0;
}

