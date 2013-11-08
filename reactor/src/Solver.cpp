#include "Solver.h"
#include <boost/bind.hpp>
#include <boost/ref.hpp>
#include <boost/numeric/odeint.hpp>

reactor::Solver::Solver(std::istream & source, std::ostream & result):
	parser(),result(result)
{
	system = parser.FromStream(source);
	result << "#Time " ;
	for (std::vector<Species*>::const_iterator species_iterator=system->GetSpecies().begin();
		species_iterator!=system->GetSpecies().end(); species_iterator++)
	{
				result << (*species_iterator)->GetName() << " " << std::flush;
	}
	result << std::endl;
}

reactor::Solver::~Solver() {
	delete system;
}

unsigned int reactor::Solver::Solve(double start_time, double end_time, 
		double initial_step, std::vector<double> &initial_concentrations)
{
	system->SetConcentrations(initial_concentrations);
	return boost::numeric::odeint::integrate(boost::ref(*this), initial_concentrations, 
		start_time, end_time, initial_step, boost::bind(&Solver::observe_integration,this,_1,_2));
}

void reactor::Solver::operator() ( const std::vector<double> &x , std::vector<double> &dxdt , const double)
{
    system->GetRatesGivenConcentrations(x,dxdt);
}

void reactor::Solver::observe_integration(const std::vector<double> &concentrations , const double time){
	result << time << " " << std::flush;
	for (unsigned int i=0; i<concentrations.size();i++){
		result << concentrations[i] <<  " " << std::flush;
	}
	result << std::endl;
}