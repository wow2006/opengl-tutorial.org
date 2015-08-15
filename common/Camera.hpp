#ifndef CAMERA_HPP
#define CAMERA_HPP
#include <cmath>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <glm/matrix.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace glm;
using namespace std;

class Camera{
public:
	Camera(GLFWwindow* _window);
    void update();
    const glm::mat4 getMVP() const;
protected:
	GLFWwindow* mWindow = nullptr;
    glm::mat4   mModel;
    glm::mat4   mView;
    glm::mat4   mProjection;
    double      mLastTime = 0;
private:
    // Initial position : on +Z
    glm::vec3 mPosition = glm::vec3( 0, 0, 5 );
    // Initial horizontal angle : toward -Z
    float mHorizontalAngle = 3.14f;
    // Initial vertical angle : none
    float mVerticalAngle = 0.0f;
    // Initial Field of View
    float mInitialFoV = 45.0f;
    // 3 units / second
    float mSpeed = 3.0f;
    float MouseSpeed = 0.005f;
};
#endif//CAMERA_HPP
