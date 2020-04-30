/*
    MathUtil.hpp
    ============
        Math utils implementation.
*/

#ifndef __YSASA_MATH_UTIL_HPP
#define __YSASA_MATH_UTIL_HPP

#include <cmath>

namespace YSASA
{

////////////////////////////////////////////////////////////////////////////////
// Calc The Surface Area Of The Ball
////////////////////////////////////////////////////////////////////////////////

inline double CalcBallS(double R)
{
    // R is the radius of the ball
    return 4 * M_PI * pow(R, 2);
}


}  // End namespace YSASA


#endif  // __YSASA_MATH_UTIL_HPP
