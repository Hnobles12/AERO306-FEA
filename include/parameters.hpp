#ifndef _PARAMETERS_HPP
#define _PARAMETERS_HPP

#include <vector>
#include <iostream>

class Node
{
public:
    int id;
    float x;

    Node(int, double);
};
std::ostream &operator<<(std::ostream &, const Node &);

/// Element Class

class Element
{
public:
    int id;
    std::vector<int> connectivity;
    Element(int, std::vector<int>);
};
std::ostream &operator<<(std::ostream &, const Element &);

class Constraints
{
public:
    int num;
    std::vector<double> vals;

    Constraints(int, std::vector<double>);
    double operator[](int);
};
std::ostream &operator<<(std::ostream &, const Constraints &);

class MaterialParams
{
public:
    double E;
    double height;
    double width;
    MaterialParams(double, double, double);
};
std::ostream &operator<<(std::ostream &, const MaterialParams &);

typedef struct Mesh
{
    std::vector<Node> nodes;
    std::vector<Element> elements;
} Mesh;

std::ostream &operator<<(std::ostream &, const Mesh &);

#endif