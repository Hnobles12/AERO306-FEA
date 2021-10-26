#ifndef ELEMENT_DOF_HPP
#define ELEMENT_DOF_HPP

#include "../Eigen/Core"

typedef Eigen::Matrix<double, 4, 4> Matrix4d;
typedef Eigen::Matrix<double, 4, 1> Vector4d;

Vector4d getElementDof(double, double);
Matrix4d getElementK(double, double);
// Vector4f getElementF(float, float);

#endif