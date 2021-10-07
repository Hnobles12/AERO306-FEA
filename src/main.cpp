#include "../include/parameters.hpp"
#include "../include/process_data.hpp"

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
    cout << "Finite Element Analysis For Simple Beams" << endl;

    bool display = false;

    string output_file = "output.txt";

    if (argc < 4)
    {
        cout << "\nUsage: ./main <input_file> <output_file> <display?>" << endl;
        return 0;
    }
    else
    {
        string input_file = argv[1];
        output_file = argv[2];
        if (argc == 4)
        {
            display = true;
        }
    }

    std::vector<std::string> lines = get_lines("./data/data.txt");

    Mesh mesh = read_mesh(lines);
    MaterialParams material_params = readProperties(lines);
    Constraints constraints = readConstraints(lines);
    Loads loads = readLoads(lines);

    ofstream output_fstream(output_file);

    if(!output_fstream.is_open())
    {
        cout << "\nError: Could not open output file" << endl;
        return 1;
    }

    output_fstream << mesh << endl;
    output_fstream << material_params << endl;
    output_fstream << constraints << endl;
    output_fstream << loads << endl;

    output_fstream.close();

    if (display)
    {
        cout << mesh << endl;
        cout << material_params << endl;
        cout << constraints << endl;
        cout << loads << endl;
    }

    return 0;
}
