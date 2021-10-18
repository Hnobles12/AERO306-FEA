#include "../include/parameters.hpp"
#include "../include/process_data.hpp"

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
    cout << "Finite Element Analysis For Simple Beams\n"
         << endl;

    bool display = false;

    string input_file = "input.txt";
    string output_file = "output.txt";

    switch (argc)
    {
        {
        case 1:
            cout << "\nUsage: ./main <input_file> <output_file> <display?>" << endl;
            cout << "Attempting to find input file in working directory." << endl;
            ifstream input_fstream(input_file);
            if (input_fstream)
            {
                cout << "Found input file in working directory." << endl;
                break;
            }
            else
            {
                cout << "Could not find input file in working directory." << endl;
                cout << "Exiting." << endl;
                return 0;
            }
        }

        {
        case 2:
            input_file = argv[1];
            break;
        }
        {
        case 3:
            input_file = argv[1];
            output_file = argv[2];
            break;
        }

        {
        case 4:
            input_file = argv[1];
            output_file = argv[2];
            display = true;
            break;
        }
    }

    // Read data from file:

    std::vector<std::string> lines = get_lines(input_file);

    if (lines.size() == 0)
    {
        cout << "Input file empty or not found." << endl;
        return 0;
    }

    // Process data from file:

    Mesh mesh = read_mesh(lines);
    MaterialParams material_params = readProperties(lines);
    Constraints constraints = readConstraints(lines);
    Loads loads = readLoads(lines);


    /// Outputting Data to File:

    ofstream output_fstream(output_file);

    if (!output_fstream.is_open())
    {
        cout << "\nError: Could not open output file" << endl;
        return 1;
    }

    output_fstream << mesh << endl;
    output_fstream << material_params << endl;
    output_fstream << constraints << endl;
    output_fstream << loads << endl;

    output_fstream.close();


    // Outputting Data to stdout:

    if (display)
    {
        cout << mesh << endl;
        cout << material_params << endl;
        cout << constraints << endl;
        cout << loads << endl;
    }

    return 0;
}
