#include "Camera.hpp"

Camera::Camera(GLFWwindow* _window) : mWindow(_window) {
    mLastTime = glfwGetTime();
}

void
Camera::update(){
    // Compute time difference between current and last frame
    double currentTime = glfwGetTime();
    float deltaTime = float(currentTime - mLastTime);
    // Get mouse position
    double xpos, ypos;
    glfwGetCursorPos(mWindow, &xpos, &ypos);
    int windowWidth =0, windowHeight = 0;
    glfwGetWindowSize(mWindow, &windowWidth, &windowHeight);
    int halfWidth = windowWidth/2, halfHeight = windowHeight/2;
    // Reset mouse position for next frame
    glfwSetCursorPos(mWindow, halfWidth, halfHeight);
    // Compute new orientation
    mHorizontalAngle += MouseSpeed * float(halfWidth  - xpos );
    mVerticalAngle   += MouseSpeed * float(halfHeight - ypos );

    // Direction : Spherical coordinates to Cartesian coordinates conversion
    glm::vec3 direction(
        cos(mVerticalAngle) * sin(mHorizontalAngle),
        sin(mVerticalAngle),
        cos(mVerticalAngle) * cos(mHorizontalAngle)
    );

    // Right vector
    glm::vec3 right = glm::vec3(
        sin(mHorizontalAngle - 3.14f/2.0f),
        0,
        cos(mHorizontalAngle - 3.14f/2.0f)
    );

    // Up vector
    glm::vec3 up = glm::cross( right, direction );

    // Move forward
    if (glfwGetKey( mWindow, GLFW_KEY_UP ) == GLFW_PRESS){
        mPosition += direction * deltaTime * mSpeed;
    }
    // Move backward
    if (glfwGetKey( mWindow, GLFW_KEY_DOWN ) == GLFW_PRESS){
        mPosition -= direction * deltaTime * mSpeed;
    }
    // Strafe right
    if (glfwGetKey( mWindow, GLFW_KEY_RIGHT ) == GLFW_PRESS){
        mPosition += right * deltaTime * mSpeed;
    }
    // Strafe left
    if (glfwGetKey( mWindow, GLFW_KEY_LEFT ) == GLFW_PRESS){
        mPosition -= right * deltaTime * mSpeed;
    }

    // Now GLFW 3 requires setting up a callback for this. It's a bit too complicated for this beginner's tutorial, so it's disabled instead.
    float FoV = mInitialFoV;

    // Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
    mProjection = glm::perspective(FoV, 4.0f / 3.0f, 0.1f, 100.0f);
    // Camera matrix
    mView       = glm::lookAt(
                                mPosition,           // Camera is here
                                mPosition+direction, // and looks here : at the same position, plus "direction"
                                up                  // Head is up (set to 0,-1,0 to look upside-down)
                           );

    // For the next frame, the "last time" will be "now"
    mLastTime = currentTime;
}

const glm::mat4
Camera::getMVP() const{
    return mProjection * mView * mModel;
}
