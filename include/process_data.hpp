#ifndef _PROC_DATA_HPP
#define _PROC_DATA_HPP

#include <vector>
#include <string>
#include <fstream>
#include "parameters.hpp"

std::vector<std::string> split(const std::string& s, char delimiter);

std::vector<std::string> get_lines(std::string fname);

Mesh read_mesh(std::vector<std::string>);

MaterialParams readProperties(std::vector<std::string>);

#endif