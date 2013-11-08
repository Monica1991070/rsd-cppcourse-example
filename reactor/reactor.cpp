// We write comments like this

#include <iostream> //Include standard library file which provides input and output capabilities ("print statements") 
#include <boost/numeric/odeint.hpp> // Include ODE solver library, just to check our build system has picked it up ok.

#include "CommandLineParser.h" // Include our own library file for describing a reaction system
#include "Solver.h"
#include <fstream>


int main(int argument_count, const char ** command_line_arguments) // Define the main function, which is the entry point to the program.
{ 
    // Send the command line arguments to a command line parser
    // Open the filename supplied as an input stream;
    std::fstream system_file("filename_here",std::ios_base::in);
    // Create a solver with the file stream for input and stdout for output
    // call Solve on the solver.
}