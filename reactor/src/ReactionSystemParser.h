#include <string> // use the string capabilities from the standard library
#include <vector>
#include <map>
#include <exception>
#include <iostream>

#include "ReactionSystem.h"


#ifndef ONCE_REACTIONSYSTEMPARSER_H
#define ONCE_REACTIONSYSTEMPARSER_H

namespace reactor {

  class ReactionSystemParser
  {   
  public:
    ReactionSystemParser(){};
    ReactionSystem * FromStream(std::istream & source);
    void ParseLine(std::string & source, 
      std::vector<std::string>& reactant_names, 
      std::vector<std::string> & product_names, 
      double & rate);
    Species * NewOrFind(ReactionSystem * result, 
      const std::string &name);
    
  private:
    std::map<std::string, Species *> species_map;
    void ParseSpeciesList(std::string & source,
    std::vector<std::string> &species_names);
  };
}

#endif //ONCE_REACTIONSYSTEMPARSER_H
