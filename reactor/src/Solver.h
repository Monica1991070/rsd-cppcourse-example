#include "ReactionSystemParser.h"


#ifndef ONCE_SOLVER
#define ONCE_SOLVER


namespace reactor{

	class Solver
	{
	public:


		Solver(std::istream & source, std::ostream & result);
		
		~Solver();

		unsigned int Solve(double start_time, double end_time, 
			double initial_step, std::vector<double> &initial_conditions);

		void operator() ( const std::vector<double> &x , std::vector<double> &dxdt , const double);

	    void observe_integration(const std::vector<double> &concentrations , const double time);

	private:
		ReactionSystemParser parser;
		ReactionSystem * system;
		std::ostream & result;

	};
}
#endif