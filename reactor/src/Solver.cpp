#include "Solver.h"
#include <boost/bind.hpp>
#include <boost/ref.hpp>
#include <boost/numeric/odeint.hpp>

reactor::Solver::Solver(std::istream & source, std::ostream & result):
	parser(),result(result)
{
	// set the system using the from FromStream method of parser. 
	system = parser.FromStream(source);
	// Output to the result stream a header line, looking like:
	//"#Time Ca O C\n"
}

reactor::Solver::~Solver() {
	// Think about what to delete.
}

unsigned int reactor::Solver::Solve(double start_time, double end_time, 
		double initial_step, std::vector<double> &initial_concentrations)
{
	// Use SetConcentrations() on the system with the initial concentrations.
	return boost::numeric::odeint::integrate(boost::ref(*this), initial_concentrations, 
		start_time, end_time, initial_step, boost::bind(&Solver::observe_integration,this,_1,_2));
}

void reactor::Solver::operator() ( const std::vector<double> &x , std::vector<double> &dxdt , const double time)
{
	// Use GetRatesGivenConcentrations on the system to set the dxdt given the x.
}

void reactor::Solver::observe_integration(const std::vector<double> &concentrations , const double time){
	// Print onto the output stream, a line consisting of the time and concentrations, separated by spaces.
}