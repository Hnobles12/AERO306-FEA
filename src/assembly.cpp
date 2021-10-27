#include "assembly.hpp"

#include <vector>
using namespace std;

MatrixXd assembleGlobalStiffnessMatrix(Mesh mesh)
{
    int n = mesh.nodes.size()*2;
    MatrixXd K = MatrixXd::Zero(n, n);

    for (int i = 0; i < mesh.elements.size(); i++)
    {
        Element e = mesh.elements[i];
        MatrixXd Ke = e.K;

        int n1 = e.dof(0) - 1;
        int n2 = e.dof(1) - 1;
        int n3 = e.dof(2) - 1;
        int n4 = e.dof(3) - 1;

        K(n1, n1) += Ke(0,0);
        K(n1, n2) += Ke(0, 1);
        K(n1, n3) += Ke(0, 2);
        K(n1, n4) += Ke(0, 3);
        K(n2, n1) += Ke(1, 0);
        K(n2, n2) += Ke(1, 1);
        K(n2, n3) += Ke(1, 2);
        K(n2, n4) += Ke(1, 3);
        K(n3, n1) += Ke(2, 0);
        K(n3, n2) += Ke(2, 1);
        K(n3, n3) += Ke(2, 2);
        K(n3, n4) += Ke(2, 3);
        K(n4, n1) += Ke(3, 0);
        K(n4, n2) += Ke(3, 1);
        K(n4, n3) += Ke(3, 2);
        K(n4, n4) += Ke(3, 3);
    }
    return K;
}