#ifndef _PARAMETERS_HPP
#define _PARAMETERS_HPP

#include <vector>
#include <iostream>

#include "../Eigen/Core"
#include "../Eigen/Dense"

using namespace Eigen;

typedef Matrix<double, 4, 4> Matrix4d;
typedef Matrix<double, 4, 1> Vector4d;

class Node
{
public:
    int id;
    float x;
    Node();
    Node(int, double);
};
std::ostream &operator<<(std::ostream &, const Node &);

class Constraints
{
public:
    int num;
    std::vector<int> dofs;

    Constraints();
    Constraints(int, std::vector<int>);
    double operator[](int);
};
std::ostream &operator<<(std::ostream &, const Constraints &);

class MaterialParams
{
public:
    double E;
    double height;
    double width;
    double I;
    MaterialParams();
    MaterialParams(double, double, double);
};
std::ostream &operator<<(std::ostream &, const MaterialParams &);

// typedef struct Mesh
// {
//     std::vector<Node> nodes;
//     std::vector<Element> elements;
// } Mesh;

// std::ostream &operator<<(std::ostream &, const Mesh &);

typedef struct Load
{
    int dof;
    double value;
} Load;

std::ostream &operator<<(std::ostream &, const Load &);

typedef std::vector<Load> Loads;

std::ostream &operator<<(std::ostream &, const Loads &);

// /// Element Class

// class Element
// {
// public:
//     int id;
//     std::vector<int> connectivity;

//     MatrixXd K;
//     MatrixXd dof;

//     Node n1;
//     Node n2;

//     Element();
//     Element(int, std::vector<int>);

//     void getElementDof(double, double);
//     void getElementK(double, double);

//     MatrixXd getElmentK();
//     MatrixXd getElementDof();
// };

// std::ostream &operator<<(std::ostream &, const Element &);

// Helper functions:

Node findNode(std::vector<Node>, int);

#endif