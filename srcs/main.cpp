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
    anim.AddHeadRotation(Vector4(1, 0, 0, 0.3));
    anim.AddHeadRotation(Vector4(1, 0, 0, 0));
    anim.AddHeadRotation(Vector4(1, 0, 0, -0.3));
    anim.AddHeadRotation(Vector4(1, 0, 0, 0));
    anim.AddHeadRotation(Vector4(1, 0, 0, 0.3));

    anim.AddLeftArmRotation(Vector4(1, 0, 0, 0.2));
    anim.AddLeftArmRotation(Vector4(1, 0, 0, 0));
    anim.AddLeftArmRotation(Vector4(1, 0, 0, -0.2));
    anim.AddLeftArmRotation(Vector4(1, 0, 0, 0));
    anim.AddLeftArmRotation(Vector4(1, 0, 0, 0.2));

    anim.AddLeftForearmPosition(Vector3(0, 0, 0));
    anim.AddLeftForearmPosition(Vector3(0, 0, 0));
    anim.AddLeftForearmPosition(Vector3(0, 0, 0.3));
    anim.AddLeftForearmPosition(Vector3(0, 0, 0));
    anim.AddLeftForearmPosition(Vector3(0, 0, 0));

    anim.AddLeftForearmRotation(Vector4(1, 0, 0, 0));
    anim.AddLeftForearmRotation(Vector4(1, 0, 0, 0));
    anim.AddLeftForearmRotation(Vector4(1, 0, 0, -0.1));
    anim.AddLeftForearmRotation(Vector4(1, 0, 0, 0));
    anim.AddLeftForearmRotation(Vector4(1, 0, 0, 0));

    anim.AddRightArmRotation(Vector4(1, 0, 0, -0.2));
    anim.AddRightArmRotation(Vector4(1, 0, 0, 0));
    anim.AddRightArmRotation(Vector4(1, 0, 0, 0.2));
    anim.AddRightArmRotation(Vector4(1, 0, 0, 0));
    anim.AddRightArmRotation(Vector4(1, 0, 0, -0.2));

    anim.AddRightForearmPosition(Vector3(0, 0, 0.3));
    anim.AddRightForearmPosition(Vector3(0, 0, 0));
    anim.AddRightForearmPosition(Vector3(0, 0, 0));
    anim.AddRightForearmPosition(Vector3(0, 0, 0));
    anim.AddRightForearmPosition(Vector3(0, 0, 0.3));

    anim.AddRightForearmRotation(Vector4(1, 0, 0, -0.1));
    anim.AddRightForearmRotation(Vector4(1, 0, 0, 0));
    anim.AddRightForearmRotation(Vector4(1, 0, 0, 0));
    anim.AddRightForearmRotation(Vector4(1, 0, 0, 0));
    anim.AddRightForearmRotation(Vector4(1, 0, 0, -0.1));

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

    anim.AddLeftLowerLegPosition(Vector3(0, 0, 0));
    anim.AddLeftLowerLegPosition(Vector3(0, 0, 0));
    anim.AddLeftLowerLegPosition(Vector3(0, 0, -0.2));
    anim.AddLeftLowerLegPosition(Vector3(0, 0, 0));
    anim.AddLeftLowerLegPosition(Vector3(0, 0, 0));

    anim.AddLeftLowerLegRotation(Vector4(1, 0, 0, 0));
    anim.AddLeftLowerLegRotation(Vector4(1, 0, 0, 0));
    anim.AddLeftLowerLegRotation(Vector4(1, 0, 0, 0.1));
    anim.AddLeftLowerLegRotation(Vector4(1, 0, 0, 0));
    anim.AddLeftLowerLegRotation(Vector4(1, 0, 0, 0));

    anim.AddRightLowerLegPosition(Vector3(0, 0, -0.2));
    anim.AddRightLowerLegPosition(Vector3(0, 0, 0));
    anim.AddRightLowerLegPosition(Vector3(0, 0, 0));
    anim.AddRightLowerLegPosition(Vector3(0, 0, 0));
    anim.AddRightLowerLegPosition(Vector3(0, 0, -0.2));

    anim.AddRightLowerLegRotation(Vector4(1, 0, 0, 0.1));
    anim.AddRightLowerLegRotation(Vector4(1, 0, 0, 0));
    anim.AddRightLowerLegRotation(Vector4(1, 0, 0, 0));
    anim.AddRightLowerLegRotation(Vector4(1, 0, 0, 0));
    anim.AddRightLowerLegRotation(Vector4(1, 0, 0, 0.1));
}

void initJumpAnim(Animation &anim) {
    anim.AddBodyPosition(Vector3(0, 0, 0));
    anim.AddBodyPosition(Vector3(0, 3, 0));
    anim.AddBodyPosition(Vector3(0, 6, 0));
    anim.AddBodyPosition(Vector3(0, 3, 0));
    anim.AddBodyPosition(Vector3(0, 0, 0));

    anim.AddThighsRotation(Vector4(1, 0, 0, -0.2));
    anim.AddThighsRotation(Vector4(1, 0, 0, 0));
    anim.AddThighsRotation(Vector4(1, 0, 0, 0));
    anim.AddThighsRotation(Vector4(1, 0, 0, 0));
    anim.AddThighsRotation(Vector4(1, 0, 0, -0.2));

    anim.AddLowerLegsPosition(Vector3(0, 0.3, -1));
    anim.AddLowerLegsPosition(Vector3(0, 0, 0));
    anim.AddLowerLegsPosition(Vector3(0, 0, 0));
    anim.AddLowerLegsPosition(Vector3(0, 0, 0));
    anim.AddLowerLegsPosition(Vector3(0, 0.3, -1));

    anim.AddLowerLegsRotation(Vector4(1, 0, 0, 0.4));
    anim.AddLowerLegsRotation(Vector4(1, 0, 0, 0));
    anim.AddLowerLegsRotation(Vector4(1, 0, 0, 0));
    anim.AddLowerLegsRotation(Vector4(1, 0, 0, 0));
    anim.AddLowerLegsRotation(Vector4(1, 0, 0, 0.4));

    anim.AddArmsPosition(Vector3(0, 0, 0.1));
    anim.AddArmsPosition(Vector3(0, 0, 0));
    anim.AddArmsPosition(Vector3(0, 0, 0));
    anim.AddArmsPosition(Vector3(0, 0, 0));
    anim.AddArmsPosition(Vector3(0, 0, 0.1));

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
    Mesh cubeMesh = Mesh("./objects/cube.obj");

    Object body = Object(cubeShader, &bodyMesh, Vector4::RED);
    Object head = Object(cubeShader, &headMesh, Vector4(0.4, 0.2, 0.8, 1));
    Object arm = Object(cubeShader, &armMesh, Vector4::GREEN);
    Object cube = Object(cubeShader, &cubeMesh, Vector4::RED);

    Camera camera = Camera(Vector3(15, 0, 0), Vector3(0, 1, 0));
    Mesh boardMesh = Mesh("./objects/plateau.obj");

    Font font = Font();

    Animation jumpAnimation;
    initJumpAnim(jumpAnimation);
    Animation walkAnimation;
    walkInit(walkAnimation);
    Animation kungFuAnimation;
    initKungFu(kungFuAnimation);
    Animation idleAnimation;

    double lastTime = 0;
    double deltaTime = 0;

    double actionTimer = 0;
    double distanceTimer = 0;
    long double distanceTraveled = 0;
    int currentAnimationId = 0;
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
            font.RenderText(fontShader, std::to_string(jumpAnimation.GetStep()), 160, 160, 1, Vector3(0.1, 0.8, 0.2));
            font.RenderText(fontShader, "<", 360, 160, 1, Vector3(0.1, 0.8, 0.2));
            font.RenderText(fontShader, ">", 400, 160, 1, Vector3(0.1, 0.8, 0.2));
            if (currentAnimationId == 0)
                idleAnimation.Play(window, camera, cube);
            else if (currentAnimationId == 1)
                walkAnimation.Play(window, camera, cube);
            else if (currentAnimationId == 2)
                jumpAnimation.Play(window, camera, cube);
            //kungFuAnimation.Play(window, camera, body, head, arm);
            if ((glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS) && actionTimer > 1) {
                currentAnimationId = (currentAnimationId == 2) ? 0 : currentAnimationId + 1;
                actionTimer = 0;
            }
            glfwSwapBuffers(window);
            glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}
