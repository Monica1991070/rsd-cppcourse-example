#include "ReactionSystemParser.h"
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <boost/lexical_cast.hpp>

reactor::ReactionSystem * reactor::ReactionSystemParser::FromStream(std::istream & source)
{
	ReactionSystem *result= new ReactionSystem();

  	while (source.good())
  	{
  		std::string line;
  		std::getline(source,line);
 		std::vector<std::string> reactant_names;
 		std::vector<std::string> product_names;
 		double rate(0.0);
 		ParseLine(line, reactant_names, product_names, rate);

 		if (rate!=0.0)
 		{
 			// Insert code to create a reaction using the given names and rate
		}
 	}
  	return result;
}

reactor::Species * reactor::ReactionSystemParser::NewOrFind(ReactionSystem * result,
	const std::string &name)
{
	// Add code to test if this species is already in the species_map.
	return new Species("Dummy name");
}

void reactor::ReactionSystemParser::ParseLine(std::string & line, 
	std::vector<std::string>& reactant_names, 
	std::vector<std::string> & product_names, 
	double & rate)
{
	// Add code to parse a reaction and get the names and rate.
}