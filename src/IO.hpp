/*
    IO.hpp
    ======
        I/O functions implementation.
*/

#ifndef __YSASA_IO_HPP
#define __YSASA_IO_HPP

#include <cstdio>
#include <string>
#include <vector>
#include <stdexcept>
#include <boost/filesystem.hpp>
#include <boost/format.hpp>
#include <Eigen/Dense>
#include <PDBToolsCpp/PDBTools>
#include "AtomBall.h"

namespace YSASA
{

////////////////////////////////////////////////////////////////////////////////
// Using
////////////////////////////////////////////////////////////////////////////////

using std::string;
using std::vector;
using std::invalid_argument;
using boost::filesystem::path;
using boost::filesystem::exists;
using Eigen::RowVector3d;
using PDBTools::Atom;


////////////////////////////////////////////////////////////////////////////////
// Get .xyz File Path
////////////////////////////////////////////////////////////////////////////////

string __getXYZFilePath(const string &dotCountStr)
{
    string xyzFilePath = (path(__FILE__).parent_path().parent_path() /
        "data" / (dotCountStr + ".xyz")).string();

    if (!exists(xyzFilePath))
    {
        throw invalid_argument((boost::format("Invalid argument: -c %s. File: %s not exists") %
            dotCountStr % xyzFilePath).str());
    }

    return xyzFilePath;
}


////////////////////////////////////////////////////////////////////////////////
// Parse .xyz File
////////////////////////////////////////////////////////////////////////////////

void ParseXYZFile(const string &dotCountStr, vector<RowVector3d> &unitBallCoord)
{
    FILE *f = fopen(__getXYZFilePath(dotCountStr).c_str(), "r");
    double x, y, z;

    while (fscanf(f, "%lf %lf %lf", &x, &y, &z) != EOF)
    {
        unitBallCoord.emplace_back(x, y, z);
    }

    fclose(f);
}


////////////////////////////////////////////////////////////////////////////////
// Output Result
////////////////////////////////////////////////////////////////////////////////

void OutputResult(const string &outputFilePath, double SASA)
{
    FILE *fo = fopen(outputFilePath.c_str(), "w");
    fprintf(fo, "SASA: %.6f (A^2)\n", SASA);
    fclose(fo);
}


////////////////////////////////////////////////////////////////////////////////
// Dump Dot PDB
////////////////////////////////////////////////////////////////////////////////

void DumpDotPDB(const string &outputFilePath, const vector<AtomBall> &atomBallObjList)
{
    FILE *fo = fopen(outputFilePath.c_str(), "w");

    for (auto &atomBallObj: atomBallObjList)
    {
        for (auto &atomCoord: atomBallObj.ballCoord())
        {
            fprintf(fo, "%s", Atom("", 0, atomCoord).Dumps().c_str());
        }
    }

    fclose(fo);
}


}  // End namespace YSASA


#endif  // __YSASA_IO_HPP
