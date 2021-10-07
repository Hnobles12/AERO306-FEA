#include "../include/parameters.hpp"
#include "../include/process_data.hpp"

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    std::vector<std::string> lines = get_lines("./data/data.txt");

    Mesh mesh = read_mesh(lines);
    MaterialParams material_params = readProperties(lines);
    Constraints constraints = readConstraints(lines);

    cout << constraints << endl;

    return 0;
}
