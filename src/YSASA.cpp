/*
DESCRIPTION

    YSASA

    Yingyulou's SASA calculate tools.
    See README file for full description and examples.

VERSION

    1.0.0

LATEST UPDATE

    2020.4.29

*/

#include <string>
#include <vector>
#include <PDBToolsCpp/PDBTools>
#include "ArgumentParser.hpp"
#include "AtomBall.hpp"
#include "Calculate.hpp"
#include "Constants.hpp"
#include "IO.hpp"
#include "MathUtil.hpp"
#include "PDBParser.hpp"

////////////////////////////////////////////////////////////////////////////////
// Using
////////////////////////////////////////////////////////////////////////////////

using namespace YSASA;
using std::string;
using std::vector;
using PDBTools::Protein;


////////////////////////////////////////////////////////////////////////////////
// Main Program Define
////////////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv)
{
    string pdbFilePath, dotCountStr, outputFilePath, dotFilePath;
    double probeR;

    __inputArguments(argc, argv, pdbFilePath, probeR, dotCountStr, outputFilePath,
        dotFilePath);

    if (!outputFilePath.empty() || !dotFilePath.empty())
    {
        vector<RowVector3d> unitBallCoord;
        vector<AtomBall> atomBallObjList;

        ParseXYZFile(dotCountStr, unitBallCoord);
        Protein *proPtr = LoadPDB(pdbFilePath, unitBallCoord, probeR, atomBallObjList);
        double SASA = CalcSASA(atomBallObjList);

        if (!outputFilePath.empty()) OutputResult(outputFilePath, SASA);
        if (!dotFilePath.empty()) DumpDotPDB(dotFilePath, atomBallObjList);

        delete proPtr;
    }
}
