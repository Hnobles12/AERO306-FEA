#include "parameters.hpp"
#include "process_data.hpp"
#include "assembly.hpp"

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

    // Get element K and dof matricies:
    for (int i = 0; i < mesh.elements.size(); i++)
    {
        mesh.elements[i].getElementDof();
        mesh.elements[i].getElementK(material_params);
    }

    // Assemble global K and F matricies:

    MatrixXd K0 = assembleGlobalStiffnessMatrix(mesh);

    // Add in point loads:

    MatrixXd F0 = assembleGlobalLoadVector(mesh, loads);

    // Impose kinematic constraints:

    MatrixXd K = imposeConstraints(K0, constraints);

    // Solve for displacements:

    MatrixXd U = K.inverse() * F0;

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

    output_fstream << "Global Stiffness Matrix (no imposed constraints)\nK0 = " << endl
                   << K0 << endl;

    output_fstream << endl;

    output_fstream << "Global Load Vector (no imposed constraints)\nF0 = " << endl
                   << F0 << endl;

    output_fstream << endl;

    output_fstream << "Global Stiffness Matrix (after imposition of constraints)\nK = " << K << endl;

    output_fstream << endl;

    output_fstream << "Displacements\nU = \n"
                   << U << endl;

    output_fstream.close();

    // Outputting Data to stdout:

    if (display)
    {
        cout << mesh << endl;
        cout << material_params << endl;
        cout << constraints << endl;
        cout << loads << endl;

        cout << "Global Stiffness Matrix (no imposed constraints)\nK0 = " << endl
             << K0 << endl;
        cout << endl;
        cout << "Global Load Vector (no imposed constraints)\nF0 = " << endl
             << F0 << endl;
        cout << endl;
        cout << "Global Stiffness Matrix (after imposition of constraints)\nK = " << K << endl;
        cout << endl;
        cout << "Displacements\nU = \n" << U << endl;
    }

    return 0;
}
