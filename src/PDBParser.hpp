/*
    PDBParser.hpp
    =============
        PDB parser functions implementation.
*/

#ifndef __YSASA_PDB_PARSER_HPP
#define __YSASA_PDB_PARSER_HPP

#include <vector>
#include <string>
#include <cctype>
#include <PDBToolsCpp/PDBTools>
#include "AtomBall.h"

namespace YSASA
{

////////////////////////////////////////////////////////////////////////////////
// Using
////////////////////////////////////////////////////////////////////////////////

using std::vector;
using std::string;
using PDBTools::Load;
using PDBTools::Protein;


////////////////////////////////////////////////////////////////////////////////
// Load PDB File
////////////////////////////////////////////////////////////////////////////////

Protein *LoadPDB(const string &pdbFilePath, const vector<RowVector3d> &unitBallCoord,
    double probeR, vector<AtomBall> &atomBallObjList)
{
    Protein *proPtr = Load(pdbFilePath, true);

    for (auto atomPtr: proPtr->GetAtoms())
    {
        if (isdigit(atomPtr->name[0]))
        {
            atomPtr->name = "H";
        }
        else
        {
            atomPtr->name = atomPtr->name[0];
        }

        atomBallObjList.emplace_back(atomPtr, unitBallCoord, probeR);
    }

    return proPtr;
}


}  // End namespace YSASA


#endif  // __YSASA_PDB_PARSER_HPP
