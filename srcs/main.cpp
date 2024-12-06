#include <cmath>
#include <iostream>
#include <string>
#include <stack>
#include "../includes/Scop.hpp"
#include "../includes/Camera.hpp"
#include "../includes/Mesh.hpp"
#include "../includes/Object.hpp"
#include "../includes/MatrixStack.hpp"
#include "../includes/Animation.hpp"

void viewport_size_callback(GLFWwindow* window, int width, int height) {
    (void)window;
    glViewport(0, 0, width, height);
}

GLFWwindow *InitGLFW() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        exit(0);
    }
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window;
    window = glfwCreateWindow(1920, 1200, "window", NULL, NULL);
    if (!window) {
        std::cerr << "failed to create window" << std::endl;
        glfwTerminate();
        exit(0);
    }
    glfwMakeContextCurrent(window);

    glewExperimental = true;
    if (glewInit() != GLEW_OK) {
        std::cerr << "failed to initialize GLEW" << std::endl;
        glfwTerminate();
        exit(0);
    }
    glfwSetFramebufferSizeCallback(window, viewport_size_callback);

    glEnable(GL_DEPTH_TEST);

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    return window;
}

void walkInit(Animation &anim) {
    anim.AddLeftArmRotation(Vector4(1, 0, 0, 0.2));
    anim.AddLeftArmRotation(Vector4(1, 0, 0, 0));
    anim.AddLeftArmRotation(Vector4(1, 0, 0, -0.2));
    anim.AddLeftArmRotation(Vector4(1, 0, 0, 0));
    anim.AddLeftArmRotation(Vector4(1, 0, 0, 0.2));

    anim.AddRightArmRotation(Vector4(1, 0, 0, -0.2));
    anim.AddRightArmRotation(Vector4(1, 0, 0, 0));
    anim.AddRightArmRotation(Vector4(1, 0, 0, 0.2));
    anim.AddRightArmRotation(Vector4(1, 0, 0, 0));
    anim.AddRightArmRotation(Vector4(1, 0, 0, -0.2));

    anim.AddLeftThighRotation(Vector4(1, 0, 0, -0.2));
    anim.AddLeftThighRotation(Vector4(1, 0, 0, 0));
    anim.AddLeftThighRotation(Vector4(1, 0, 0, 0.2));
    anim.AddLeftThighRotation(Vector4(1, 0, 0, 0));
    anim.AddLeftThighRotation(Vector4(1, 0, 0, -0.2));

    anim.AddRightThighRotation(Vector4(1, 0, 0, 0.2));
    anim.AddRightThighRotation(Vector4(1, 0, 0, 0));
    anim.AddRightThighRotation(Vector4(1, 0, 0, -0.2));
    anim.AddRightThighRotation(Vector4(1, 0, 0, 0));
    anim.AddRightThighRotation(Vector4(1, 0, 0, 0.2));
}

void initJumpAnim(Animation &anim) {
    anim.AddBodyPosition(Vector3(0, 3, 0));
    anim.AddBodyPosition(Vector3(0, 6, 0));
    anim.AddBodyPosition(Vector3(0, 3, 0));
    anim.AddBodyPosition(Vector3(0, 0, 0));

    anim.AddThighsRotation(Vector4(1, 0, 0, -0.2));
    anim.AddThighsRotation(Vector4(1, 0, 0, 0));
    anim.AddThighsRotation(Vector4(1, 0, 0, 0));
    anim.AddThighsRotation(Vector4(1, 0, 0, 0));
    anim.AddThighsRotation(Vector4(1, 0, 0, -0.2));

    anim.AddLowerLegsRotation(Vector4(1, 0, 0, 0.4));
    anim.AddLowerLegsRotation(Vector4(1, 0, 0, 0));
    anim.AddLowerLegsRotation(Vector4(1, 0, 0, 0));
    anim.AddLowerLegsRotation(Vector4(1, 0, 0, 0));
    anim.AddLowerLegsRotation(Vector4(1, 0, 0, 0.4));

    anim.AddArmsRotation(Vector4(1, 0, 0, -0.2));
    anim.AddArmsRotation(Vector4(1, 0, 0, 0));
    anim.AddArmsRotation(Vector4(1, 0, 0, 0));
    anim.AddArmsRotation(Vector4(1, 0, 0, 0));
    anim.AddArmsRotation(Vector4(1, 0, 0, -0.2));
}

void initKungFu(Animation &anim) {
    anim.AddLeftArmRotation(Vector4(0, 0.2, 0.8, -0.3));
    anim.AddLeftArmRotation(Vector4(0, 0.2, 0.8, 0));
    anim.AddLeftArmRotation(Vector4(0, 0.2, 0.8, -0.3));

    anim.AddLeftForearmRotation(Vector4(1, 0, 0, -0.3));
    anim.AddLeftForearmRotation(Vector4(1, 0, 0, 0));
    anim.AddLeftForearmRotation(Vector4(1, 0, 0, -0.3));

    anim.AddRightArmRotation(Vector4(1, 0, 0, -0.2));
    anim.AddRightArmRotation(Vector4(1, 0, 0, 0));
    anim.AddRightArmRotation(Vector4(1, 0, 0, -0.2));

    anim.AddRightForearmRotation(Vector4(1, 0, 0, -0.2));
    anim.AddRightForearmRotation(Vector4(1, 0, 0, 0));
    anim.AddRightForearmRotation(Vector4(1, 0, 0, -0.2));
}

void GetTimer(double &lastTime, double &deltaTime) {
    double nowTime;
    nowTime = glfwGetTime();
    deltaTime = nowTime - lastTime;
    lastTime = nowTime;
}

int main(void) {
    srand(time(NULL));
    GLFWwindow *window;
    window = InitGLFW();

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    Shader cubeShader = Shader("./shaders/VertexShader.shader", "./shaders/greenPieceFS.shader");
    Shader fontShader = Shader("./shaders/fontVS.shader", "./shaders/fontFS.shader");
    Mesh bodyMesh = Mesh("./objects/body.obj");
    Mesh headMesh = Mesh("./objects/head.obj");
    Mesh armMesh = Mesh("./objects/arm.obj");

    Object body = Object(cubeShader, &bodyMesh, Vector4::RED);
    Object head = Object(cubeShader, &headMesh, Vector4(0.4, 0.2, 0.8, 1));
    Object arm = Object(cubeShader, &armMesh, Vector4::GREEN);

    Camera camera = Camera(Vector3(30, 0, 20), Vector3(0, 1, 0));
    Mesh boardMesh = Mesh("./objects/plateau.obj");

    Font font = Font();

    Animation jumpAnimation;
    initJumpAnim(jumpAnimation);
    Animation walkAnimation;
    walkInit(walkAnimation);
    Animation kungFuAnimation;
    initKungFu(kungFuAnimation);

    double lastTime = 0;
    double deltaTime = 0;

    double actionTimer = 0;
    double distanceTimer = 0;
    long double distanceTraveled = 0;

    bool swap = true;
    while ((glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
        glfwWindowShouldClose(window) == 0)) {
            glClearColor(0.0f, 0.45f, 0.3f, 0.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            GetTimer(lastTime, deltaTime);
            actionTimer += deltaTime;
            distanceTimer += deltaTime;

            if (distanceTimer >= M_PI) {
                distanceTraveled += 120.0 / 100.0;
                distanceTimer = 0;
            }
            font.RenderText(fontShader, std::to_string(distanceTraveled), 160, 160, 1, Vector3(0.1, 0.8, 0.2));
            if (swap)
                walkAnimation.Jump(window, camera, body, head, arm);
            else
                jumpAnimation.Jump(window, camera, body, head, arm);
            //kungFuAnimation.Jump(window, camera, body, head, arm);

            if ((glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS) && actionTimer > 1) {
                swap = (swap == true) ? false : true;
                actionTimer = 0;
            }
            glfwSwapBuffers(window);
            glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}
