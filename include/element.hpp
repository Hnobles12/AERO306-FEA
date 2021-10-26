#ifndef __ELEMENT_HPP__
#define __ELEMENT_HPP__

#include "parameters.hpp"

/// Element Class

class Element
{
public:
    int id;
    std::vector<int> connectivity;

    MatrixXd K;
    MatrixXd dof;

    Node n1;
    Node n2;

    Element();
    Element(int, std::vector<int>);

    MatrixXd getElementDof();
    MatrixXd getElementK();

};

std::ostream &operator<<(std::ostream &, const Element &);

#endif