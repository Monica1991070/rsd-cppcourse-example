#include "ReactionSystemParser.h"
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <boost/lexical_cast.hpp>

reactor::ReactionSystem * reactor::ReactionSystemParser::FromStream(std::istream & source)
{
	ReactionSystem *result= new ReactionSystem();

	// The source stream is assumed to look like:
  	//
  	// A + B + C > rate > D
  	// D + E > rate2 > A

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
	 		Reaction & reaction=result->NewReaction(rate);
 		
		  	for (std::vector<std::string>::iterator reactant=reactant_names.begin(); 
		  		reactant!=reactant_names.end(); reactant++)
			{
				reaction.AddReactant(NewOrFind(result,*reactant));
			}
			for (std::vector<std::string>::iterator product=product_names.begin(); 
				product!=product_names.end(); product++)
			{
				reaction.AddProduct(NewOrFind(result,*product));
			} 
		}
 	}
  	return result;
}

reactor::Species * reactor::ReactionSystemParser::NewOrFind(ReactionSystem * result,
	const std::string &name)
{
	if (species_map.find(name) == species_map.end())
	{
		species_map[name]=&result->NewSpecies(name);
	}
	return species_map[name];
}

void reactor::ReactionSystemParser::ParseSpeciesList(std::istream & source,
	std::vector<std::string> &species_names)
{
	std::string word;
	while (source.good()){
		source >> word;
		std::cout << word << std::endl;
		if (word==">") break;
		if (word=="+") continue;
		species_names.push_back(word);
	}
}

void reactor::ReactionSystemParser::ParseLine(std::string & line, 
	std::vector<std::string>& reactant_names, 
	std::vector<std::string> & product_names, 
	double & rate)
{
	std::stringstream source(line);
	ParseSpeciesList(source,reactant_names);
	std::string throwawayarrow;
	source>>rate>>throwawayarrow;
	ParseSpeciesList(source,product_names);
}