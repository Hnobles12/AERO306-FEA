#include "../include/parameters.hpp"
#include "../include/process_data.hpp"

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    std::cout << "Running:" << std::endl;
    std::vector<std::string> lines = get_lines("../data/data.txt");
    for (int i = 0; i < lines.size(); i++)
    {
        std::cout << lines[i] << std::endl;
    }
        // std::vector<std::string> line1 = split(lines[0], ' ');
        // for (int i = 0; i<line1.size(); i++){
        //     std::cout << line1[i] << std::endl;
        // }

        return 0;
}
