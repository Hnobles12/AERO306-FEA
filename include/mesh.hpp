#ifndef __MESH_HPP
#define __MESH_HPP

#include "parameters.hpp"
#include "element.hpp"


typedef struct Mesh
{
    std::vector<Node> nodes;
    std::vector<Element> elements;
} Mesh;

std::ostream &operator<<(std::ostream &, const Mesh &);

#endif