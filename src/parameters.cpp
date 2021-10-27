#include "parameters.hpp"

Node::Node()
{
    this->id = 0;
    this->x = 0;
}

Node::Node(int id, double x)
{
    this->id = id;
    this->x = x;
}

std::ostream &operator<<(std::ostream &os, const Node &node)
{
    os << "    Node:\n        ID: " << node.id << "\n        x-pos: " << node.x << std::endl;
    return os;
}

// Constraint Class:

Constraints::Constraints()
{
    this->num = 0;
    this->dofs = std::vector<int>();
}

Constraints::Constraints(int num, std::vector<int> vals)
{
    this->num = num;
    this->dofs = dofs;
}

double Constraints::operator[](int i)
{
    return this->dofs[i];
}

std::ostream &operator<<(std::ostream &os, const Constraints &constraints)
{
    os << "Constraints:\n    Number: " << constraints.num << "\n    Values: ";
    for (int i = 0; i < constraints.dofs.size(); i++)
    {
        os << constraints.dofs[i] << " ";
    }
    os << std::endl;
    return os;
}

// Material Parameters Class:

MaterialParams::MaterialParams()
{
    this->E = 0;
    this->height = 0;
    this->width = 0;
    this->I = 0;
}

MaterialParams::MaterialParams(double E, double height, double witdth)
{
    this->E = E;
    this->height = height;
    this->width = witdth;
    this->I = pow(height, 3) * width / 12;
}

std::ostream &operator<<(std::ostream &os, const MaterialParams &material)
{
    os << "Material Parameters:\n    E: " << material.E << "\n    Height: " << material.height << "\n    Width: " << material.width << "\n    I: " << material.I << std::endl;
    return os;
}

// // Mesh Struct:

// std::ostream &operator<<(std::ostream &os, const Mesh &mesh)
// {
//     os << "Mesh:\n    Nodes: " << mesh.nodes.size() << std::endl;
//     os << "    {\n";
//     for (int i = 0; i < mesh.nodes.size(); i++)
//     {
//         os << mesh.nodes[i];
//     }
//     os << "    }\n";
//     os << "    Elements: " << mesh.elements.size() << std::endl;
//     os << "    {\n";
//     for (int i = 0; i < mesh.elements.size(); i++)
//     {
//         os << mesh.elements[i];
//     }

//     os << "    }\n";

//     return os;
// }

std::ostream &operator<<(std::ostream &os, const Load &load)
{
    os << "\n    Load:\n        DOF: " << load.dof << "\n        Value: " << load.value << std::endl;
    return os;
}

std::ostream &operator<<(std::ostream &os, const Loads &loads)
{
    os << "Loads:\n    Number: " << loads.size() << "\n    Values: \n    {\n ";
    for (int i = 0; i < loads.size(); i++)
    {
        os << loads[i] << " ";
    }

    os << "\n    }" << std::endl;
    return os;
}

Node findNode(std::vector<Node> nodes, int id)
{
    for (int i = 0; i < nodes.size(); i++)
    {
        if (nodes[i].id == id)
        {
            return nodes[i];
        }
    }
    return Node();
}