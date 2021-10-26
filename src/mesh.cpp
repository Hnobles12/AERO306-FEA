#include "mesh.hpp"


// Mesh Struct:

std::ostream &operator<<(std::ostream &os, const Mesh &mesh)
{
    os << "Mesh:\n    Nodes: " << mesh.nodes.size() << std::endl;
    os << "    {\n";
    for (int i = 0; i < mesh.nodes.size(); i++)
    {
        os << mesh.nodes[i];
    }
    os << "    }\n";
    os << "    Elements: " << mesh.elements.size() << std::endl;
    os << "    {\n";
    for (int i = 0; i < mesh.elements.size(); i++)
    {
        os << mesh.elements[i];
    }

    os << "    }\n";

    return os;
}