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
    window = glfwCreateWindow(1024, 768, "Tutorial 01", nullptr, nullptr);
    if(window == nullptr){
        cerr << "Failed to open GLFW window.\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewExperimental= true;                         // Needed in core profile
    if(glewInit() != GLEW_OK){
        cerr << "Failed to initalize GLEW.\n";
        return -1;
    }

    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    do{
        // Draw nothing, see you in tutorial 2 !
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(window) == 0 );

    return 0;
}

