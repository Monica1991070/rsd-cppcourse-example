// We write comments like this

#include <iostream> //Include standard library file which provides input and output capabilities ("print statements") 
#include <boost/numeric/odeint.hpp> // Include ODE solver library, just to check our build system has picked it up ok.

#include "CommandLineParser.h" // Include our own library file for describing a reaction system
#include "Solver.h"
#include <fstream>


int main(int argument_count, const char ** command_line_arguments) // Define the main function, which is the entry point to the program.
{ 
	reactor::CommandLineParser parser(argument_count,command_line_arguments);
	std::fstream system_file(
		parser.GetReactionSystemFileName().c_str(),
		std::ios_base::in);
	reactor::Solver solver(
		system_file,
		std::cout);
	solver.Solve(0.0,
		parser.GetFinalTime(),
		parser.GetFinalTime()/100.0,
		parser.GetInitialConditions());
}