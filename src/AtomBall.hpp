/*
    AtomBall.hpp
    ============
        Class AtomBall implementation.
*/

#ifndef __YSASA_ATOM_BALL_HPP
#define __YSASA_ATOM_BALL_HPP

#include <vector>
#include <Eigen/Dense>
#include <PDBToolsCpp/PDBTools>
#include "AtomBall.h"
#include "Constants.hpp"
#include "MathUtil.hpp"

namespace YSASA
{

////////////////////////////////////////////////////////////////////////////////
// Using
////////////////////////////////////////////////////////////////////////////////

using std::vector;
using Eigen::RowVector3d;
using PDBTools::Atom;


////////////////////////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////////////////////////

AtomBall::AtomBall(const Atom *atomObj, const vector<RowVector3d> &unitBallCoord,
    double probeR):
    __atomObj(atomObj), __VDWR(VDW_RADII_HASH.at(atomObj->name)), __probeR(probeR),
    __realR(__VDWR + __probeR), __fullS(CalcBallS(__realR)),
    __dS(__fullS / unitBallCoord.size()), __ballCoord(unitBallCoord)
{
    for (auto &dotCoord: __ballCoord)
    {
        dotCoord = dotCoord * __realR + __atomObj->coord;
    }
}


////////////////////////////////////////////////////////////////////////////////
// Calc loss S with another ball
////////////////////////////////////////////////////////////////////////////////

double AtomBall::CalcLossS(AtomBall &rhs)
{
    double lossS = 0.;

    for (auto dotCoordIter = __ballCoord.begin(); dotCoordIter != __ballCoord.end();
        dotCoordIter++)
    {
        if ((*dotCoordIter - (rhs.__atomObj)->coord).norm() < rhs.__realR)
        {
            lossS += __dS;
            __ballCoord.erase(dotCoordIter--);
        }
    }

    for (auto dotCoordIter = rhs.__ballCoord.begin(); dotCoordIter != rhs.__ballCoord.end();
        dotCoordIter++)
    {
        if ((*dotCoordIter - __atomObj->coord).norm() < __realR)
        {
            lossS += rhs.__dS;
            rhs.__ballCoord.erase(dotCoordIter--);
        }
    }

    return lossS;
}


}  // End namespace YSASA


#endif  // __YSASA_ATOM_BALL_HPP
