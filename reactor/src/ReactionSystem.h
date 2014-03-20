#include <string> // use the string capabilities from the standard library
#include <vector>
#include <exception>

#include "Species.h"
#include "Reaction.h"

#ifndef ONCE_REACTIONSYSTEM_H
#define ONCE_REACTIONSYSTEM_H
namespace reactor{

  class ReactionSystem // A "class" is a user defined type with built-in functions
  {   
  public:
    ReactionSystem(); // Declare constructor function.
    ~ReactionSystem(); // Delete the reaction system

    Reaction & NewReaction(double rate);
    const std::vector<Reaction *> & GetReactions() const {return reactions;}

    Species & NewSpecies(const std::string &name);
    const std::vector<Species *> & GetSpecies() const { return species;}

    const std::vector<double> GetRatesOfChange() const; // Given the current species concentrations, return the rates of change
    const std::vector<double> GetConcentrations() const ; // return array of species concentrations
    void GetRatesGivenConcentrations(const std::vector<double> & concentrations, std::vector<double> & rates);
    void SetConcentrations(const std::vector<double> & );

  private:
    std::vector< Reaction * > reactions;
    std::vector< Species * > species;
  };
}

#endif //ONCE_REACTIONSYSTEM_H
