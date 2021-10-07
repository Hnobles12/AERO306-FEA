#include <iostream>
#include "../include/process_data.hpp"
#include <fstream>

using namespace std;

int main()
{
    ifstream file("./data/data.txt");

    while (!file.eof())
    {
        string data;
        getline(file, data);
        if (data.length() == 0){
            cout << "Newline" << endl;
            continue;
        }
            cout << data << endl;
    }

    return 0;
}