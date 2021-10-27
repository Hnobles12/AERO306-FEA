#ifndef __ELEMENT_HPP__
#define __ELEMENT_HPP__

#include "parameters.hpp"

/// Element Class

class Element
{
public:
    int id;
    std::vector<int> connectivity;
    double length;

    MatrixXd K;
    MatrixXd dof;

    Node n1;
    Node n2;

    Element();
    Element(int, Node, Node);

    MatrixXd getElementDof();
    MatrixXd getElementK(MaterialParams);
};

std::ostream &operator<<(std::ostream &, const Element &);

#endif