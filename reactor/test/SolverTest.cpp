#include "Solver.h" // Include the code that we are testing
#include <gtest/gtest.h> // Include the google test framework
#include <cmath>

using namespace reactor;

class SolverTest: public ::testing::Test {
public:
	std::istringstream system;
	std::ostringstream result;
	std::vector<double> initial_conditions;
	Solver solver;
	SolverTest():
		system("A > 2.0 > B\n"),result(),initial_conditions(),solver(system,result)
	{
		initial_conditions.push_back(100.0);
		initial_conditions.push_back(0.0);
	};
};

TEST_F(SolverTest, SolverCanParse) {
	EXPECT_EQ("#Time A B \n",result.str());
}

TEST_F(SolverTest, SolverCanSolve) {
	unsigned int step_count=solver.Solve(0,1.5,0.1,initial_conditions);
	EXPECT_NE(step_count,0);
	EXPECT_NEAR(100*std::exp(-2.0*1.5),initial_conditions[0],0.001);
	EXPECT_NEAR(100-100*std::exp(-2.0*1.5),initial_conditions[1],0.001);
}

int main(int argc, char **argv) { // A main function scaffold to call the tests
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}