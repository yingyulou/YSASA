/*
    Calculate.hpp
    =============
        Calculate functions implementation.
*/

#ifndef __YSASA_CALCULATE_HPP
#define __YSASA_CALCULATE_HPP

#include <vector>
#include "AtomBall.h"

namespace YSASA
{

////////////////////////////////////////////////////////////////////////////////
// Using
////////////////////////////////////////////////////////////////////////////////

using std::vector;


////////////////////////////////////////////////////////////////////////////////
// Calc SASA (Solvent-Accessible Surface Area)
////////////////////////////////////////////////////////////////////////////////

double CalcSASA(vector<AtomBall> &atomBallObjList)
{
    double SASA = 0.;

    for (auto &atomTObj: atomBallObjList)
    {
        SASA += atomTObj.fullS();
    }

    for (int i = 0; i < atomBallObjList.size() - 1; i++)
    {
        for (int j = i + 1; j < atomBallObjList.size(); j++)
        {
            if (*atomBallObjList[i].atomObj() - *atomBallObjList[j].atomObj() <
                atomBallObjList[i].realR() + atomBallObjList[j].realR())
            {
                SASA -= atomBallObjList[i].CalcLossS(atomBallObjList[j]);
            }
        }
    }

    return SASA;
}


}  // End namespace YSASA


#endif  // __YSASA_CALCULATE_HPP
