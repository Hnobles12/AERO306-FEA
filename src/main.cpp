#include "../include/parameters.hpp"
#include "../include/process_data.hpp"

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    std::vector<std::string> lines = get_lines("./data/data.txt");

    Mesh mesh = read_mesh(lines);
    std::cout << "Mesh read" << std::endl;
    std::cout << mesh << std::endl;

    // std::vector<std::string> lines = get_lines("data.txt");
    // std::cout << "Number of lines: " << lines.size() << std::endl;
    // for (int i = 0; i < lines.size(); i++)
    // {
    //     std::cout << lines[i] << std::endl;
    // }
    // std::vector<std::string> line1 = split(lines[0], ' ');
    // for (int i = 0; i<line1.size(); i++){
    //     std::cout << line1[i] << std::endl;
    // }

    return 0;
}
