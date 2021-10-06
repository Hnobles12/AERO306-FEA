#include "../include/process_data.hpp"

std::vector<std::string> split(const std::string &s, char delim)
{
    std::vector<std::string> elems;
    int start = 0;
    int end = 0;
    int delim_i = s.find(delim);
    while (delim_i != std::string::npos)
    {
        end = delim_i;
        elems.push_back(s.substr(start, end - start));
        start = delim_i + 1;
        delim_i = s.find(delim, start);
    }
    return elems;
}
std::vector<std::string> get_lines(std::string file_name)
{
    std::ifstream file(file_name);
    std::string line;
    std::vector<std::string> lines;
    while (std::getline(file, line))
    {
        lines.push_back(line);
    }
    return lines;
}

Mesh read_mesh(std::vector<std::string> lines)
{
    Mesh mesh;

    std::vector<Element> elements;
    std::vector<Node> nodes;

    int i = 0;
    int num_nodes = 0;
    int num_elements = 0;

    while (lines[i] != "\n")
    {
        if (i == 0)
        {
        }
        i++;
    }
    i++;
}