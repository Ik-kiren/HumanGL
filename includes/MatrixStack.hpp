#pragma once
#include <vector>
#include "./Matrix4.hpp"

class MatrixStack {

 private:
    std::vector<Matrix4> matrixStack;

 public:
    MatrixStack();
    ~MatrixStack();

    void Push();
    void Pop();
    void translate(Vector3 vec);
    void rotate(Vector3 axis);
    void rotate(float radians, Vector3 axis);
    void scale(float scale);
    void scale(Vector3 vec);
    Matrix4 GetMatrix();
};
