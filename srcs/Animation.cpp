#include "../includes/Animation.hpp"
#include "../includes/Scop.hpp"
#include "../includes/Camera.hpp"
#include "../includes/Object.hpp"
#include "../includes/glm/glm.hpp"
#define GLM_ENABLE_EXPERIMENTAL
#include "../includes/glm/gtx/transform.hpp"

Animation::Animation() : animationTimer(0), stepTime(3.14), stepTimer(0), step(0) {
    maxStepNbr = 0;
    nowTime = 0;
    lastTime = 0;
    deltaTime = 0;
    cube = NULL;
    window = NULL;
    camera = NULL;

    initHeadPosition = Vector3(0, 4.7, 0);
    initBodyPosition = Vector3(0, 0, 0);
    initRightArmPosition = Vector3(2, 1.7, 0);
    initRightForearmPosition = Vector3(0, -2.5, 0);
    initLeftArmPosition = Vector3(-2, 1.7, 0);
    initLeftForearmPosition = Vector3(0, -2.5, 0);
    initRightThighPosition = Vector3(1, -3, 0);
    initRightLowerLegPosition = Vector3(0, -2.8, 0);
    initLeftThighPosition = Vector3(-1, -3, 0);
    initLeftLowerLegPosition = Vector3(0, -2.8, 0);

    headScale = Vector3(0.6, 0.6, 0.6);
    bodyScale = Vector3(1.6, 3.12, 0.3);
    rightArmScale = Vector3(0.3, 1, 0.1);
    rightForearmScale = Vector3(0.3, 1, 0.1);
    leftArmScale = Vector3(0.3, 1, 0.1);
    LeftForearmScale = Vector3(0.3, 1, 0.1);
    rightThighScale = Vector3(0.3, 1, 0.1);
    rightLowerLegScale = Vector3(0.3, 1, 0.1);
    leftThighScale = Vector3(0.3, 1, 0.1);
    leftLowerLegScale = Vector3(0.3, 1, 0.1);
}

Animation::~Animation() {}

int Animation::GetStep() {
    return step;
}

void Animation::AddHeadPosition(Vector3 pos) {
    headPosition.push_back(pos);
    if (static_cast<int>(headPosition.size()) > maxStepNbr - 1) {
        maxStepNbr = static_cast<int>(headPosition.size()) - 1;
    }
}

void Animation::AddHeadRotation(Vector4 radians) {
    headRotation.push_back(radians);
    if (static_cast<int>(headRotation.size()) > maxStepNbr - 1) {
        maxStepNbr = static_cast<int>(headRotation.size()) - 1;
    }
}

void Animation::AddBodyPosition(Vector3 pos) {
    bodyPosition.push_back(pos);
    if (static_cast<int>(bodyPosition.size()) > maxStepNbr - 1) {
        maxStepNbr = static_cast<int>(bodyPosition.size()) - 1;
    }
}

void Animation::AddRightArmPosition(Vector3 pos) {
    rightArmPosition.push_back(pos);
    if (static_cast<int>(rightArmPosition.size()) > maxStepNbr - 1) {
        maxStepNbr = static_cast<int>(rightArmPosition.size()) - 1;
    }
}

void Animation::AddRightArmRotation(Vector4 radians) {
    rightArmRotation.push_back(radians);
    if (static_cast<int>(rightArmRotation.size()) > maxStepNbr - 1) {
        maxStepNbr = static_cast<int>(rightArmRotation.size()) - 1;
    }
}

void Animation::AddLeftArmPosition(Vector3 pos) {
    leftArmPosition.push_back(pos);
    if (static_cast<int>(leftArmPosition.size()) > maxStepNbr - 1) {
        maxStepNbr = static_cast<int>(leftArmPosition.size()) - 1;
    }
}

void Animation::AddLeftArmRotation(Vector4 radians) {
    leftArmRotation.push_back(radians);
    if (static_cast<int>(leftArmRotation.size()) > maxStepNbr - 1) {
        maxStepNbr = static_cast<int>(leftArmRotation.size()) - 1;
    }
}

void Animation::AddRightForearmPosition(Vector3 pos) {
    rightForearmPosition.push_back(pos);
    if (static_cast<int>(rightForearmPosition.size()) > maxStepNbr - 1) {
        maxStepNbr = static_cast<int>(rightForearmPosition.size()) - 1;
    }
}

void Animation::AddRightForearmRotation(Vector4 radians) {
    rightForearmRotation.push_back(radians);
    if (static_cast<int>(rightForearmRotation.size()) > maxStepNbr - 1) {
        maxStepNbr = static_cast<int>(rightForearmRotation.size()) - 1;
    }
}

void Animation::AddLeftForearmPosition(Vector3 pos) {
    leftForearmPosition.push_back(pos);
    if (static_cast<int>(leftForearmPosition.size()) > maxStepNbr - 1) {
        maxStepNbr = static_cast<int>(leftForearmPosition.size()) - 1;
    }
}

void Animation::AddLeftForearmRotation(Vector4 radians) {
    leftForearmRotation.push_back(radians);
    if (static_cast<int>(leftForearmRotation.size()) > maxStepNbr - 1) {
        maxStepNbr = static_cast<int>(leftForearmRotation.size()) - 1;
    }
}

void Animation::AddRightThighPosition(Vector3 pos) {
    rightThighPosition.push_back(pos);
    if (static_cast<int>(rightThighPosition.size()) > maxStepNbr - 1) {
        maxStepNbr = static_cast<int>(rightThighPosition.size()) - 1;
    }
}

void Animation::AddRightThighRotation(Vector4 radians) {
    rightThighRotation.push_back(radians);
    if (static_cast<int>(rightThighRotation.size()) > maxStepNbr - 1) {
        maxStepNbr = static_cast<int>(rightThighRotation.size()) - 1;
    }
}

void Animation::AddRightLowerLegPosition(Vector3 pos) {
    rightLowerLegPosition.push_back(pos);
    if (static_cast<int>(rightLowerLegPosition.size()) > maxStepNbr - 1) {
        maxStepNbr = static_cast<int>(rightLowerLegPosition.size()) - 1;
    }
}

void Animation::AddRightLowerLegRotation(Vector4 radians) {
    rightLowerLegRotation.push_back(radians);
    if (static_cast<int>(rightLowerLegRotation.size()) > maxStepNbr - 1) {
        maxStepNbr = static_cast<int>(rightLowerLegRotation.size()) - 1;
    }
}

void Animation::AddLeftThighPosition(Vector3 pos) {
    leftThighPosition.push_back(pos);
    if (static_cast<int>(leftThighPosition.size()) > maxStepNbr - 1) {
        maxStepNbr = static_cast<int>(leftThighPosition.size()) - 1;
    }
}

void Animation::AddLeftThighRotation(Vector4 radians) {
    leftThighRotation.push_back(radians);
    if (static_cast<int>(leftThighRotation.size()) > maxStepNbr - 1) {
        maxStepNbr = static_cast<int>(leftThighRotation.size()) - 1;
    }
}

void Animation::AddLeftLowerLegPosition(Vector3 pos) {
    leftLowerLegPosition.push_back(pos);
    if (static_cast<int>(leftLowerLegPosition.size()) > maxStepNbr - 1) {
        maxStepNbr = static_cast<int>(leftLowerLegPosition.size()) - 1;
    }
}

void Animation::AddLeftLowerLegRotation(Vector4 radians) {
    leftLowerLegRotation.push_back(radians);
    if (static_cast<int>(leftLowerLegRotation.size()) > maxStepNbr - 1) {
        maxStepNbr = static_cast<int>(leftLowerLegRotation.size()) - 1;
    }
}

void Animation::AddArmsRotation(Vector4 radians) {
    AddRightArmRotation(radians);
    AddLeftArmRotation(radians);
}

void Animation::AddThighsPosition(Vector3 pos) {
    leftThighPosition.push_back(pos);
    rightThighPosition.push_back(pos);
    if (static_cast<int>(leftThighPosition.size()) > maxStepNbr - 1) {
        maxStepNbr = static_cast<int>(leftThighPosition.size()) - 1;
    } else if (static_cast<int>(rightThighPosition.size()) > maxStepNbr - 1) {
        maxStepNbr = static_cast<int>(rightThighPosition.size()) - 1;
    }
}

void Animation::AddThighsRotation(Vector4 radians) {
    leftThighRotation.push_back(radians);
    rightThighRotation.push_back(radians);
    if (static_cast<int>(leftThighRotation.size()) > maxStepNbr - 1) {
        maxStepNbr = static_cast<int>(leftThighRotation.size()) - 1;
    } else if (static_cast<int>(rightThighRotation.size()) > maxStepNbr - 1) {
        maxStepNbr = static_cast<int>(rightThighRotation.size()) - 1;
    }
}

void Animation::AddLowerLegsPosition(Vector3 pos) {
    leftLowerLegPosition.push_back(pos);
    rightLowerLegPosition.push_back(pos);
    if (static_cast<int>(leftLowerLegPosition.size()) > maxStepNbr - 1) {
        maxStepNbr = static_cast<int>(leftLowerLegPosition.size()) - 1;
    } else if (static_cast<int>(rightLowerLegPosition.size()) > maxStepNbr - 1) {
        maxStepNbr = static_cast<int>(rightLowerLegPosition.size()) - 1;
    }
}

void Animation::AddLowerLegsRotation(Vector4 radians) {
    leftLowerLegRotation.push_back(radians);
    rightLowerLegRotation.push_back(radians);
    if (static_cast<int>(leftLowerLegRotation.size()) > maxStepNbr - 1) {
        maxStepNbr = static_cast<int>(leftLowerLegRotation.size()) - 1;
    } else if (static_cast<int>(rightLowerLegRotation.size()) > maxStepNbr - 1) {
        maxStepNbr = static_cast<int>(rightLowerLegRotation.size()) - 1;
    }
}

void Animation::HeadAnimation(MatrixStack &mat) {
    mat.Push();
    mat.translate(initHeadPosition - Vector3(0, 1, 0), false);
    if (headRotation.size() > 1)
        mat.rotate(lerp(headRotation[step].w, headRotation[step + 1].w, fmod(stepTimer, stepTime) / stepTime), Vector3(headRotation[step]), true);
    cube->drawMesh(window, *camera, Scale(mat.GetMatrix(), headScale, true), Vector4::RED);
    mat.Pop();
}

void Animation::BodyAnimation(MatrixStack &mat) {
    mat.translate(initBodyPosition, false);
    if (bodyPosition.size() > 1)
        mat.translate(Vector3(bodyPosition[step].x, lerp(bodyPosition[step].y, bodyPosition[step + 1].y, fmod(stepTimer, stepTime) / stepTime), bodyPosition[step].z));
    cube->drawMesh(window, *camera, Scale(mat.GetMatrix(), bodyScale, true), Vector4::GREEN);
}

void Animation::ArmsAnimation(MatrixStack &mat) {
    //right
    mat.Push();
    mat.translate(Vector3(0, -1.4, 0), false);
    if (rightArmPosition.size() > 1)
         mat.translate(Vector3(lerp(rightArmPosition[step].x, rightArmPosition[step + 1].x, fmod(stepTimer, stepTime) / stepTime), lerp(rightArmPosition[step].y, rightArmPosition[step + 1].y, fmod(stepTimer, stepTime) / stepTime), lerp(rightArmPosition[step].z, rightArmPosition[step + 1].z, fmod(stepTimer, stepTime) / stepTime)), true);
    if (rightArmRotation.size() > 1)
        mat.rotate(lerp(rightArmRotation[step].w, rightArmRotation[step + 1].w, fmod(stepTimer, stepTime) / stepTime), Vector3(rightArmRotation[step]), false);
    mat.translate(Vector3(0, 0.7, 0), false);
    mat.translate(initRightArmPosition, false);
    cube->drawMesh(window, *camera, Scale(mat.GetMatrix(), rightArmScale, true));
    mat.Push();
    mat.translate(initRightForearmPosition + Vector3(0, 0.5, 0), true);
    if (rightForearmPosition.size() > 1)
        mat.translate(Vector3(lerp(rightForearmPosition[step].x, rightForearmPosition[step + 1].x, fmod(stepTimer, stepTime) / stepTime), lerp(rightForearmPosition[step].y, rightForearmPosition[step + 1].y, fmod(stepTimer, stepTime) / stepTime), lerp(rightForearmPosition[step].z, rightForearmPosition[step + 1].z, fmod(stepTimer, stepTime) / stepTime)), true);
    if (rightForearmRotation.size() > 1)
        mat.rotate(lerp(rightForearmRotation[step].w, rightForearmRotation[step + 1].w, fmod(stepTimer, stepTime) / stepTime), Vector3(rightForearmRotation[step]), true);
    cube->drawMesh(window, *camera, Scale(mat.GetMatrix(), rightForearmScale, true));
    mat.Pop();
    mat.Pop();
    //left
    mat.Push();
    mat.translate(Vector3(0, -1.4, 0), false);
    if (leftArmPosition.size() > 1)
        mat.translate(Vector3(lerp(leftArmPosition[step].x, leftArmPosition[step + 1].x, fmod(stepTimer, stepTime) / stepTime), lerp(leftArmPosition[step].y, leftArmPosition[step + 1].y, fmod(stepTimer, stepTime) / stepTime), lerp(leftArmPosition[step].z, leftArmPosition[step + 1].z, fmod(stepTimer, stepTime) / stepTime)), true);
    if (leftArmRotation.size() > 1)
        mat.rotate(lerp(leftArmRotation[step].w, leftArmRotation[step + 1].w, fmod(stepTimer, stepTime) / stepTime), Vector3(leftArmRotation[step]), false);
    mat.translate(Vector3(0, 0.7, 0), false);
    mat.translate(initLeftArmPosition, false);
    cube->drawMesh(window, *camera, Scale(mat.GetMatrix(), leftArmScale, true));
    mat.Push();
    mat.translate(initLeftForearmPosition + Vector3(0, 0.5, 0), true);
    if (leftForearmPosition.size() > 1)
        mat.translate(Vector3(lerp(leftForearmPosition[step].x, leftForearmPosition[step + 1].x, fmod(stepTimer, stepTime) / stepTime), lerp(leftForearmPosition[step].y, leftForearmPosition[step + 1].y, fmod(stepTimer, stepTime) / stepTime), lerp(leftForearmPosition[step].z, leftForearmPosition[step + 1].z, fmod(stepTimer, stepTime) / stepTime)), true);
    if (leftForearmRotation.size() > 1)
        mat.rotate(lerp(leftForearmRotation[step].w, leftForearmRotation[step + 1].w, fmod(stepTimer, stepTime) / stepTime), Vector3(leftForearmRotation[step]), true);
    cube->drawMesh(window, *camera, Scale(mat.GetMatrix(), LeftForearmScale, true));
    mat.Pop();
    mat.Pop();
}

void Animation::LegsAnimation(MatrixStack &mat) {
    //rightleg
    mat.Push();
    if (rightThighPosition.size() > 1)
        mat.translate(Vector3(lerp(rightThighPosition[step].x, rightThighPosition[step + 1].x, fmod(stepTimer, stepTime) / stepTime), lerp(rightThighPosition[step].y, rightThighPosition[step + 1].y, fmod(stepTimer, stepTime) / stepTime), lerp(rightThighPosition[step].z, rightThighPosition[step + 1].z, fmod(stepTimer, stepTime) / stepTime)), true);
    if (rightThighRotation.size() > 1)
        mat.rotate(lerp(rightThighRotation[step].w, rightThighRotation[step + 1].w, fmod(stepTimer, stepTime) / stepTime), Vector3(rightThighRotation[step]), true);
    mat.translate(Vector3(0, -1.4, 0),  true);
    mat.translate(initRightThighPosition + Vector3(0, 0.5, 0), false);
    cube->drawMesh(window, *camera, Scale(mat.GetMatrix(), rightThighScale, true));
    mat.Push();
    mat.translate(initRightLowerLegPosition + Vector3(0, 1, 0), true);
    if (rightLowerLegPosition.size() > 1)
        mat.translate(Vector3(lerp(rightLowerLegPosition[step].x, rightLowerLegPosition[step + 1].x, fmod(stepTimer, stepTime) / stepTime), lerp(rightLowerLegPosition[step].y, rightLowerLegPosition[step + 1].y, fmod(stepTimer, stepTime) / stepTime), lerp(rightLowerLegPosition[step].z, rightLowerLegPosition[step + 1].z, fmod(stepTimer, stepTime) / stepTime)), true);
    if (rightLowerLegRotation.size() > 1)
        mat.rotate(lerp(rightLowerLegRotation[step].w, rightLowerLegRotation[step + 1].w, fmod(stepTimer, stepTime) / stepTime), Vector3(rightLowerLegRotation[step]));
    cube->drawMesh(window, *camera, Scale(mat.GetMatrix(), rightLowerLegScale, true));
    mat.Pop();
    mat.Pop();

    //leftleg
    mat.Push();
    if (leftThighPosition.size() > 1)
        mat.translate(Vector3(lerp(leftThighPosition[step].x, leftThighPosition[step + 1].x, fmod(stepTimer, stepTime) / stepTime), lerp(leftThighPosition[step].y, leftThighPosition[step + 1].y, fmod(stepTimer, stepTime) / stepTime), lerp(leftThighPosition[step].z, leftThighPosition[step + 1].z, fmod(stepTimer, stepTime) / stepTime)), true);
    if (leftThighRotation.size() > 1)
        mat.rotate(lerp(leftThighRotation[step].w, leftThighRotation[step + 1].w, fmod(stepTimer, stepTime) / stepTime), Vector3(leftThighRotation[step]));
    mat.translate(Vector3(0, -1.4, 0),  true);
    mat.translate(initLeftThighPosition + Vector3(0, 0.5, 0), false);
    cube->drawMesh(window, *camera, Scale(mat.GetMatrix(), leftThighScale, true));
    mat.Push();
    mat.translate(initLeftLowerLegPosition + Vector3(0, 1, 0), true);
    if (leftLowerLegPosition.size() > 1)
        mat.translate(Vector3(lerp(leftLowerLegPosition[step].x, leftLowerLegPosition[step + 1].x, fmod(stepTimer, stepTime) / stepTime), lerp(leftLowerLegPosition[step].y, leftLowerLegPosition[step + 1].y, fmod(stepTimer, stepTime) / stepTime), lerp(leftLowerLegPosition[step].z, leftLowerLegPosition[step + 1].z, fmod(stepTimer, stepTime) / stepTime)), true);
    if (leftLowerLegRotation.size() > 1)
        mat.rotate(lerp(leftLowerLegRotation[step].w, leftLowerLegRotation[step + 1].w, fmod(stepTimer, stepTime) / stepTime), Vector3(leftLowerLegRotation[step]));
    cube->drawMesh(window, *camera, Scale(mat.GetMatrix(), leftLowerLegScale, true));
    mat.Pop();
    mat.Pop();
}

void Animation::Play(GLFWwindow *window, Camera &camera, Object &cube) {
    this->window = window;
    this->camera = &camera;
    this->cube = &cube;
    nowTime = glfwGetTime();
    deltaTime = nowTime - lastTime;
    lastTime = nowTime;
    animationTimer += deltaTime;
    stepTimer += deltaTime * 4;
    if (stepTimer > stepTime) {
        if (step == maxStepNbr - 1) {
            step = 0;
        } else {
            step++;
        }
        stepTimer = 0;
    }
    MatrixStack matrixStack;
    BodyAnimation(matrixStack);
    HeadAnimation(matrixStack);
    ArmsAnimation(matrixStack);
    LegsAnimation(matrixStack);
}
