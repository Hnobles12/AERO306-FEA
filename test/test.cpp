#include <iostream>
#include <vector>

#include "parameters.hpp"
#include "element.hpp"
// #include "../Eigen/Core"

using namespace std;
using namespace Eigen;

int main()
{
    vector<int> conn = {4, 1};

    Element element(4, conn);
    element.getElementDof();

    cout << element.dof << endl;

    return 0;
}