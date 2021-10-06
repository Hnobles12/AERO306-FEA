#include "../include/parameters.hpp"

Node::Node(int id, double x)
{
    this->id = id;
    this->x = x;
}

std::ostream &operator<<(std::ostream &os, const Node &node)
{
    os << "Node:\n    ID: " << node.id << "\n    x-pos: " << node.x << std::endl;
    return os;
}

/*
Element Class:
*/

Element::Element(int id, std::vector<int> connect)
{
    this->id = id;
    this->connectivity = connect;
}

std::ostream &operator<<(std::ostream &os, const Element &element)
{
    os << "Element:\n    ID: " << element.id << "\n    Connectivity: ";
    for (int i = 0; i < element.connectivity.size(); i++)
    {
        os << element.connectivity[i] << " ";
    }
    os << std::endl;
    return os;
}
// Constraint Class:

Constraints::Constraints(int num, std::vector<double> vals)
{
    this->num = num;
    this->vals = vals;
}

double Constraints::operator[](int i)
{
    return this->vals[i];
}

std::ostream &operator<<(std::ostream &os, const Constraints &constraints)
{
    os << "Constraints:\n    Number: " << constraints.num << "\n    Values: ";
    for (int i = 0; i < constraints.vals.size(); i++)
    {
        os << constraints.vals[i] << " ";
    }
    os << std::endl;
    return os;
}

// Material Parameters Class:

MaterialParams::MaterialParams(double E, double height, double witdth)
{
    this->E = E;
    this->height = height;
    this->width = witdth;
}

std::ostream &operator<<(std::ostream &os, const MaterialParams &material)
{
    os << "Material Parameters:\n    E: " << material.E << "\n    Height: " << material.height << "\n    Width: " << material.width << std::endl;
    return os;
}