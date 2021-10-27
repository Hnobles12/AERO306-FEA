#include "element.hpp"

/*
Element Class:
*/

Element::Element()
{
    this->id = 0;

    this->n1 = Node();
    this->n2 = Node();

    this->connectivity = std::vector<int>({0,0});
    this->K = MatrixXd::Zero(4, 4);
    this->dof = MatrixXd::Zero(4, 1);
}

Element::Element(int id, Node n1, Node n2)
{
    this->id = id;

    this->n1 = n1;
    this->n2 = n2;
    this->connectivity = std::vector<int>({0,0});
    this->connectivity[0] = n1.id;
    this->connectivity[1] = n2.id;
    this->K = MatrixXd::Zero(4, 4);
    this->dof = MatrixXd::Zero(4, 1);
}

std::ostream &operator<<(std::ostream &os, const Element &element)
{
    os << "    Element:\n        ID: " << element.id << "\n        Connectivity: ";
    os << element.connectivity[0] << " " << element.connectivity[1] << std::endl;
    os << "        K: \n"
       << element.K << std::endl;
    os << "        dof: \n"
       << element.dof << std::endl;
    return os;
}

// Build the dof vector (assembly vector) for the element; Returns indicies of dof in matrix.
MatrixXd Element::getElementDof()
{
    this->dof = MatrixXd::Zero(4, 1);
    this->dof << this->connectivity[0] * 2 - 2, this->connectivity[0] * 2 - 1, this->connectivity[1] * 2 - 2, this->connectivity[1] * 2 - 1;
    return this->dof;
}

MatrixXd Element::getElementK()
{
}