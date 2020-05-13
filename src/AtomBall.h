/*
    AtomBall.h
    ==========
        Class AtomBall header.
*/

#ifndef __YSASA_ATOM_BALL_H
#define __YSASA_ATOM_BALL_H

#include <vector>
#include <Eigen/Dense>
#include <PDBToolsCpp/PDBTools>

namespace YSASA
{

////////////////////////////////////////////////////////////////////////////////
// Using
////////////////////////////////////////////////////////////////////////////////

using std::vector;
using Eigen::RowVector3d;
using PDBTools::Atom;


////////////////////////////////////////////////////////////////////////////////
// Class AtomBall
////////////////////////////////////////////////////////////////////////////////

class AtomBall
{
public:

    // Constructor
    AtomBall(const Atom *atomObj, const vector<RowVector3d> &unitBallCoord,
        double probeR = 0.);


    // Getter
    const Atom *atomObj() const { return __atomObj; }
    double VDWR() const { return __VDWR; }
    double probeR() const { return __probeR; }
    double realR() const { return __realR; }
    double fullS() const { return __fullS; }
    double dS() const { return __dS; }
    vector<RowVector3d> ballCoord() const { return __ballCoord; }


    // Calc loss S with another ball
    double CalcLossS(AtomBall &rhs);


private:

    // Attribute
    const Atom *__atomObj;
    double __VDWR;
    double __probeR;
    double __realR;
    double __fullS;
    double __dS;
    vector<RowVector3d> __ballCoord;
};


}  // End namespace YSASA


#endif  // __YSASA_ATOM_BALL_H
