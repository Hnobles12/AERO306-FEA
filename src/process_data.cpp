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
    if (s.back() != delim)
        elems.push_back(s.substr(start, s.size() - start));
    return elems;
}
std::vector<std::string> get_lines(std::string file_name)
{
    std::ifstream file(file_name);
    std::string line;
    std::vector<std::string> lines;
    if (file.is_open())
    {
        std::cout << "File is open" << std::endl;
        while (getline(file, line))
        {
            lines.push_back(line);
        }
        file.close();
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

    //Read all the nodes and number of nodes/elements
    while (lines[i] != "\n")
    {
        if (i == 0)
        {
            std::vector<std::string> num_nodes_str = split(lines[i], ' ');
            num_nodes = std::stoi(num_nodes_str[1]);
            std::vector<std::string> num_elements_str = split(lines[i + 1], ' ');
            num_elements = std::stoi(num_elements_str[1]);
        }
        else if (i < num_nodes + 2)
        {
            std::vector<std::string> node_str = split(lines[i], ' ');
            int id = std::stoi(node_str[0]);
            double x = std::stod(node_str[1]);
            Node node(id, x);
            nodes.push_back(node);
        }
        else
        {
            i++;
            // i++;
            break;
        }

        i++;
    }

    while (lines[i] != "\n")
    {
        std::vector<std::string> element_str = split(lines[i], ' ');
        int id = std::stoi(element_str[0]);
        std::vector<int> nodes_id;
        nodes_id.push_back(std::stoi(element_str[1]));
        nodes_id.push_back(std::stoi(element_str[2]));

        Element element(id, nodes_id);
        elements.push_back(element);
        i++;
        if (i == lines.size())
        {
            break;
        }
    }

    mesh.nodes = nodes;
    mesh.elements = elements;

    return mesh;
}