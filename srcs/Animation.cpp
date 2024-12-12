#include "../includes/Animation.hpp"
#include "../includes/MatrixStack.hpp"
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
    AddHeadPosition(Vector3(0, 4.7, 0));
    AddRightArmPosition(Vector3(2, 1.7, 0));
    AddRightForearmPosition(Vector3(0, -2.5, 0));
    AddLeftArmPosition(Vector3(-2, 1.7, 0));
    AddLeftForearmPosition(Vector3(0, -2.5, 0));
    AddRightThighPosition(Vector3(1, -3, 0));
    AddRightLowerLegPosition(Vector3(0, -2.8, 0));
    AddLeftThighPosition(Vector3(-1, -3, 0));
    AddLeftLowerLegPosition(Vector3(0, -2.8, 0));
    AddBodyPosition(Vector3(0, 0, 0));
}

Animation::~Animation() {}

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

void Animation::Jump(GLFWwindow *window, Camera &camera, Object &body, Object &head, Object &arm) {
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
    matrixStack.translate(bodyPosition[0]);
    if (bodyPosition.size() > 0)
        matrixStack.translate(Vector3(bodyPosition[step].x, lerp(bodyPosition[step].y, bodyPosition[step + 1].y, fmod(stepTimer, stepTime) / stepTime), bodyPosition[step].z));
    body.drawMesh(window, camera, matrixStack.GetMatrix());
    //head
    matrixStack.Push();
    matrixStack.translate(headPosition[0]);
    if (headRotation.size() > 0)
        matrixStack.rotate(lerp(headRotation[step].w, headRotation[step + 1].w, fmod(stepTimer, stepTime) / stepTime), Vector3(headRotation[step]));
    head.drawMesh(window, camera, matrixStack.GetMatrix());
    matrixStack.Pop();
    //right
    matrixStack.Push();
    matrixStack.translate(rightArmPosition[0]);
    if (rightArmRotation.size() > 0)
        matrixStack.rotate(lerp(rightArmRotation[step].w, rightArmRotation[step + 1].w, fmod(stepTimer, stepTime) / stepTime), Vector3(rightArmRotation[step]));
    arm.drawMesh(window, camera, matrixStack.GetMatrix());
    matrixStack.translate(rightForearmPosition[0]);
    if (rightForearmRotation.size() > 0)
        matrixStack.rotate(lerp(rightForearmRotation[step].w, rightForearmRotation[step + 1].w, fmod(stepTimer, stepTime) / stepTime), Vector3(rightForearmRotation[step]));
    arm.drawMesh(window, camera, matrixStack.GetMatrix());
    matrixStack.Pop();
    //left
    matrixStack.Push();
    matrixStack.translate(leftArmPosition[0]);
    if (leftArmRotation.size() > 0)
        matrixStack.rotate(lerp(leftArmRotation[step].w, leftArmRotation[step + 1].w, fmod(stepTimer, stepTime) / stepTime), Vector3(leftArmRotation[step]));
    arm.drawMesh(window, camera, matrixStack.GetMatrix());
    matrixStack.translate(leftForearmPosition[0]);
    if (leftForearmRotation.size() > 0)
        matrixStack.rotate(lerp(leftForearmRotation[step].w, leftForearmRotation[step + 1].w, fmod(stepTimer, stepTime) / stepTime), Vector3(leftForearmRotation[step]));
    arm.drawMesh(window, camera, matrixStack.GetMatrix());
    matrixStack.Pop();
    //rightleg
    matrixStack.Push();
    matrixStack.translate(rightThighPosition[0]);
    if (rightThighRotation.size() > 0)
        matrixStack.rotate(lerp(rightThighRotation[step].w, rightThighRotation[step + 1].w, fmod(stepTimer, stepTime) / stepTime), Vector3(rightThighRotation[step]));
    arm.drawMesh(window, camera, matrixStack.GetMatrix());
    matrixStack.translate(rightLowerLegPosition[0]);
    if (rightLowerLegRotation.size() > 0)
        matrixStack.rotate(lerp(rightLowerLegRotation[step].w, rightLowerLegRotation[step + 1].w, fmod(stepTimer, stepTime) / stepTime), Vector3(rightLowerLegRotation[step]));
    arm.drawMesh(window, camera, matrixStack.GetMatrix());
    matrixStack.Pop();
    //leftleg
    matrixStack.Push();
    matrixStack.translate(leftThighPosition[0]);
    if (leftThighRotation.size() > 0)
        matrixStack.rotate(lerp(leftThighRotation[step].w, leftThighRotation[step + 1].w, fmod(stepTimer, stepTime) / stepTime), Vector3(leftThighRotation[step]));
    arm.drawMesh(window, camera, matrixStack.GetMatrix());
    matrixStack.translate(leftLowerLegPosition[0]);
    if (leftLowerLegRotation.size() > 0)
        matrixStack.rotate(lerp(leftLowerLegRotation[step].w, leftLowerLegRotation[step + 1].w, fmod(stepTimer, stepTime) / stepTime), Vector3(leftLowerLegRotation[step]));
    arm.drawMesh(window, camera, matrixStack.GetMatrix());
    matrixStack.Pop();
}

void Animation::Play(GLFWwindow *window, Camera &camera, Object &cube) {
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
    Matrix4 tmp(1);
    MatrixStack matrixStack;
    matrixStack.scale(Vector3(1.6, 3.12, 0.3), false);
    matrixStack.translate(bodyPosition[0], false);
    if (bodyPosition.size() > 1)
        matrixStack.translate(Vector3(bodyPosition[step].x, lerp(bodyPosition[step].y, bodyPosition[step + 1].y, fmod(stepTimer, stepTime) / stepTime), bodyPosition[step].z));
    cube.drawMesh(window, camera, matrixStack.GetMatrix(), Vector4::GREEN);
    //head
    matrixStack.Push();
    matrixStack.scale(Vector3(1.0/1.6, 1.0/3.12, 0.5), false);
    matrixStack.scale(Vector3(0.8, 0.8, 1), false);
    matrixStack.translate(headPosition[0] - Vector3(0, 1, 0), false);
    if (headRotation.size() > 1)
        matrixStack.rotate(lerp(headRotation[step].w, headRotation[step + 1].w, fmod(stepTimer, stepTime) / stepTime), Vector3(headRotation[step]), true);
    cube.drawMesh(window, camera, matrixStack.GetMatrix(), Vector4::RED);
    matrixStack.Pop();
    //right
    matrixStack.Push();
    matrixStack.scale(Vector3(1.0/1.6, 1.0/3.12, 1), false);
    matrixStack.scale(Vector3(0.3, 1.4, 0.5), false);
    matrixStack.translate(Vector3(0, -1.4, 0), false);
    if (rightArmRotation.size() > 1)
        matrixStack.rotate(lerp(rightArmRotation[step].w, rightArmRotation[step + 1].w, fmod(stepTimer, stepTime) / stepTime), Vector3(rightArmRotation[step]), false);
    matrixStack.translate(Vector3(0, 0.7, 0), false);
    matrixStack.translate(rightArmPosition[0], false);
    cube.drawMesh(window, camera, matrixStack.GetMatrix());
    matrixStack.Push();
    //
    Matrix4 swap = matrixStack.GetMatrix();
    glm::mat4 glmtmp(1);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            glmtmp[i][j] = swap[i][j];
        }
    }
    glmtmp = glm::translate(glmtmp, glm::vec3(rightForearmPosition[0].x, rightForearmPosition[0].y, rightForearmPosition[0].z) + glm::vec3(0, 0.5, 0));
    glmtmp = glm::rotate(glmtmp, static_cast<float>(lerp(rightForearmRotation[step].w, rightForearmRotation[step + 1].w, fmod(stepTimer, stepTime) / stepTime)), glm::vec3(rightForearmRotation[step].x, rightForearmRotation[step].y, rightForearmRotation[step].z));
    
    //tmp = Translate(tmp , Vector3(0, -1.4, 0), false);
    //tmp = Rotate(tmp, lerp(rightForearmRotation[step].w, rightForearmRotation[step + 1].w, fmod(stepTimer, stepTime) / stepTime), Vector3(rightForearmRotation[step]), false);
    //tmp = Translate(tmp , Vector3(0, 1.4, 0), false);
    //matrixStack.SetMatrix(tmp * matrixStack.GetMatrix());
    //matrixStack.translate(rightForearmPosition[0] + Vector3(0, 0.5, 0), true);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            swap[i][j] = glmtmp[i][j];
        }
    }
    matrixStack.SetMatrix(swap);
    cube.drawMesh(window, camera, matrixStack.GetMatrix());
    matrixStack.Pop();
    matrixStack.Pop();
    //left
    matrixStack.Push();
    matrixStack.scale(Vector3(1.0/1.6, 1.0/3.12, 1), false);
    matrixStack.scale(Vector3(0.3, 1.4, 0.5), false);
    matrixStack.translate(Vector3(0, -1.4, 0), false);
    if (leftArmRotation.size() > 1)
        matrixStack.rotate(lerp(leftArmRotation[step].w, leftArmRotation[step + 1].w, fmod(stepTimer, stepTime) / stepTime), Vector3(leftArmRotation[step]), false);
    matrixStack.translate(Vector3(0, 0.7, 0), false);
    matrixStack.translate(leftArmPosition[0], false);
    cube.drawMesh(window, camera, matrixStack.GetMatrix());
    matrixStack.Push();
    tmp = Translate(tmp , Vector3(0, -1.4, 0), false);
    tmp = Rotate(tmp, lerp(leftForearmRotation[step].w, leftForearmRotation[step + 1].w, fmod(stepTimer, stepTime) / stepTime), Vector3(leftForearmRotation[step]), false);
    tmp = Translate(tmp , Vector3(0, 1.4, 0), false);
    matrixStack.SetMatrix(tmp * matrixStack.GetMatrix());
    matrixStack.translate(leftForearmPosition[0] + Vector3(0, 0.5, 0), true);
    cube.drawMesh(window, camera, matrixStack.GetMatrix());
    matrixStack.Pop();
    matrixStack.Pop();
    //rightleg
    matrixStack.Push();
    matrixStack.scale(Vector3(1.0/1.6, 1.0/3.12, 0.5), false);
    matrixStack.scale(Vector3(0.3, 1.4, 1), false);
    matrixStack.translate(Vector3(0, -1.4, 0),  true);
    matrixStack.translate(rightThighPosition[0] + Vector3(0, 0.5, 0), false);
    if (rightThighRotation.size() > 1)
        matrixStack.rotate(lerp(rightThighRotation[step].w, rightThighRotation[step + 1].w, fmod(stepTimer, stepTime) / stepTime), Vector3(rightThighRotation[step]));
    cube.drawMesh(window, camera, matrixStack.GetMatrix());
    matrixStack.translate(rightLowerLegPosition[0] + Vector3(0, 1, 0), true);
    if (rightLowerLegRotation.size() > 1)
        matrixStack.rotate(lerp(rightLowerLegRotation[step].w, rightLowerLegRotation[step + 1].w, fmod(stepTimer, stepTime) / stepTime), Vector3(rightLowerLegRotation[step]));
    cube.drawMesh(window, camera, matrixStack.GetMatrix());
    matrixStack.Pop();
    //leftleg
    matrixStack.Push();
    matrixStack.scale(Vector3(1.0/1.6, 1.0/3.12, 0.5), false);
    matrixStack.scale(Vector3(0.3, 1.4, 1), false);
    matrixStack.translate(Vector3(0, -1.4, 0),  true);
    matrixStack.translate(leftThighPosition[0] + Vector3(0, 0.5, 0), false);
    if (leftThighRotation.size() > 1)
        matrixStack.rotate(lerp(leftThighRotation[step].w, leftThighRotation[step + 1].w, fmod(stepTimer, stepTime) / stepTime), Vector3(leftThighRotation[step]));
    cube.drawMesh(window, camera, matrixStack.GetMatrix());
    matrixStack.translate(leftLowerLegPosition[0] + Vector3(0, 1, 0), true);
    if (leftLowerLegRotation.size() > 1)
        matrixStack.rotate(lerp(leftLowerLegRotation[step].w, leftLowerLegRotation[step + 1].w, fmod(stepTimer, stepTime) / stepTime), Vector3(leftLowerLegRotation[step]));
    cube.drawMesh(window, camera, matrixStack.GetMatrix());
    matrixStack.Pop();
}