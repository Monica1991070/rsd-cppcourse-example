#include <string> // use the string capabilities from the standard library
#include <vector>
#include <iostream>

#include "Species.h"

#ifndef ONCE_REACTION_H
#define ONCE_REACTION_H


namespace reactor{

  typedef double RateConstant;

  class Reaction // A "class" is a user defined type with built-in functions
  {   
  public:
    Reaction(RateConstant rate); // Declare constructor function.
    RateConstant GetRate() const; // Const because it doesn't change the rate

    void AddReactant( Species &  species){reactants.push_back(species);}
    void AddProduct( Species  &  species){products.push_back(species);}

    const std::vector<  Species > & GetReactants() const { return reactants;}
    const std::vector<  Species > & GetProducts() const { return products;}

    double GetFlux() const ; 
  private:

    RateConstant rate; // A member variable for the class to store the reaction rate
    std::vector< Species > reactants;
    std::vector< Species > products;
  };
}

#endif //ONCE_REACTION_H
