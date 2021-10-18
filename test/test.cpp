#include <iostream>
#include <vector>

#include "../include/parameters.hpp"
// #include "../Eigen/Core"

using namespace std;
using namespace Eigen;

class Test
{
public:
    MatrixXd K;

    Test()
    {
        this->K = MatrixXd::Zero(4, 4);
    }
};

ostream &operator<<(ostream &os, const Test &t)
{
    os << "K: " << endl
       << t.K << endl;
    return os;
}

int main()
{
    vector<int> nodeids;

    nodeids.push_back(1);
    nodeids.push_back(2);

    // Element e = Element(5, nodeids);

    auto test = Test();

    // cout << test.K << endl;
    cout << test << endl;

    // cout << e.K << endl;

    MatrixXd m = MatrixXd::Zero(4, 4);
    // cout << m << endl;
}