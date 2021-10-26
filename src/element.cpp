#include "element.hpp"
/*
Element Class:
*/

Element::Element()
{
    this->id = 0;
    this->connectivity = std::vector<int>();
    this->K = MatrixXd::Zero(4, 4);
    this->dof = MatrixXd::Zero(4, 1);
}

Element::Element(int id, std::vector<int> connect)
{
    this->id = id;
    this->connectivity = connect;
    this->K = MatrixXd::Zero(4, 4);
    this->dof = MatrixXd::Zero(4, 1);
}

std::ostream &operator<<(std::ostream &os, const Element &element)
{
    os << "    Element:\n        ID: " << element.id << "\n        Connectivity: ";
    for (int i = 0; i < element.connectivity.size(); i++)
    {
        os << element.connectivity[i] << " ";
    }
    os << std::endl;
    os << "        K: \n"
       << element.K << std::endl;
    os << "        dof: \n"
       << element.dof << std::endl;
    return os;
}

// Build the dof vector for the element
MatrixXd Element::getElementDof()
{
    this->dof = MatrixXd::Zero(4, 1);
    this->dof << this->connectivity[0] * 2 - 2, this->connectivity[0] * 2 - 1, this->connectivity[1] * 2 - 2, this->connectivity[1] * 2 - 1;
    return this->dof;
}

MatrixXd Element::getElementK()
{
    
}