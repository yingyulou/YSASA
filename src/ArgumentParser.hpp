/*
    ArgumentParser.hpp
    ==================
        Command line argument parser function implementation.
*/

#ifndef __YSASA_ARGUMENT_PARSER_HPP
#define __YSASA_ARGUMENT_PARSER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <boost/program_options.hpp>

namespace YSASA
{

////////////////////////////////////////////////////////////////////////////////
// Using
////////////////////////////////////////////////////////////////////////////////

using std::string;
using std::cout;
using std::endl;


////////////////////////////////////////////////////////////////////////////////
// Input Arguments
////////////////////////////////////////////////////////////////////////////////

void __inputArguments(int argc, char **argv, string &pdbFilePath, double &probeR,
    string &dotCountStr, string &outputFilePath, string &dotFilePath)
{
    namespace po = boost::program_options;

    po::options_description desc;

    desc.add_options()

        ("help,h", "show this help message and exit")

        (",i", po::value<string>(&pdbFilePath)->required(),
            "Input PDB File Path (Required)")

        (",p", po::value<double>(&probeR)->default_value(0.),
            "Probe R, Default = 0. (VDW Surface)")

        (",c", po::value<string>(&dotCountStr)->default_value("60"),
            "Dot Count, Default = 60")

        (",o", po::value<string>(&outputFilePath),
            "Output Result File Path")

        (",d", po::value<string>(&dotFilePath),
            "Output Dot File Path");

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);

    if (vm.count("help"))
    {
        cout << desc << endl;
        exit(1);
    }

    po::notify(vm);
}


}  // End namespace YSASA


#endif  // __YSASA_ARGUMENT_PARSER_HPP
