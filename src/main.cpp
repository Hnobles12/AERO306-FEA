#include "../include/parameters.hpp"
#include "../include/process_data.hpp"

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    std::vector<std::string> lines = get_lines("../data/data.txt");
    std::vector<std::string> line1 = split(lines[0], ' ');
    for (int i = 0; i<line1.size(); i++){
        std::cout << line1[i] << std::endl;
    }

        return 0;
}
