/*
    Constants.hpp
    =============
        Constants define.
*/

#ifndef __YSASA_CONSTANTS_HPP
#define __YSASA_CONSTANTS_HPP

#include <string>
#include <unordered_map>

namespace YSASA
{

////////////////////////////////////////////////////////////////////////////////
// Using
////////////////////////////////////////////////////////////////////////////////

using std::string;
using std::unordered_map;


////////////////////////////////////////////////////////////////////////////////
// VDW Radii HashMap
////////////////////////////////////////////////////////////////////////////////

const unordered_map<string, double> VDW_RADII_HASH
{
    {"C", 1.70},
    {"H", 1.20},
    {"O", 1.52},
    {"N", 1.55},
    {"S", 1.80},
};


}  // End namespace YSASA


#endif  // __YSASA_CONSTANTS_HPP
