#ifndef ELEMENT_DOF_HPP
#define ELEMENT_DOF_HPP

#include "../Eigen/Core"

typedef Eigen::Matrix<float, 4, 4> Matrix4f;
typedef Eigen::Matrix<float, 4, 1> Vector4f;

Vector4f getElementDof(float, float);
Matrix4f getElementK(float, float);

#endif