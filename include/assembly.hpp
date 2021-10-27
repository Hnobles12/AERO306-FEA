#ifndef ASSEMBLY_HPP
#define ASSEMBLY_HPP

#include "parameters.hpp"
#include "element.hpp"
#include "mesh.hpp"

MatrixXd assembleGlobalStiffnessMatrix(Mesh);

MatrixXd assembleGlobalLoadVector(Mesh, Loads);

MatrixXd imposeConstraints(MatrixXd, Constraints);

#endif