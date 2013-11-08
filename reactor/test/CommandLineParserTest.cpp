#include "CommandLineParser.h" // Include the code that we are testing
#include <gtest/gtest.h> // Include the google test framework

using namespace reactor;

class CommandLineParserTest: public ::testing::Test {
public:
	int argc;
	const char ** argv;
	std::vector<const char *> argument_buffer;
	std::vector<std::string> arguments;
	CommandLineParserTest(): argument_buffer(), arguments()
	{
		arguments.push_back("command_name");
		arguments.push_back("filename");
		arguments.push_back("1.5");
		arguments.push_back("100.0");
		arguments.push_back("0.0");
		for (std::vector<std::string>::iterator argument_iterator=arguments.begin(); argument_iterator!=arguments.end(); argument_iterator++)
		{
			argument_buffer.push_back(argument_iterator->c_str());
		}
		argv=&argument_buffer[0];
		argc=arguments.size();
	};
};

TEST_F(CommandLineParserTest, CommandLineParserCanParse) {
	CommandLineParser parser(argc,argv);
	EXPECT_EQ("filename",parser.GetReactionSystemFileName());
	EXPECT_EQ(1.5,parser.GetFinalTime());
	std::vector<double> expected_initial_conditions;
	expected_initial_conditions.push_back(100.0);
	expected_initial_conditions.push_back(0.0);
	EXPECT_EQ(expected_initial_conditions,parser.GetInitialConditions());
}



int main(int argc, char **argv) { // A main function scaffold to call the tests
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}