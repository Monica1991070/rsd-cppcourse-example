#include <string> // use the string capabilities from the standard library

#ifndef ONCE_SPECIES_H
#define ONCE_SPECIES_H

namespace reactor
{

  class Species // A "class" is a user defined type with built-in functions
  {   
  public:
    Species(const std::string &input_name); // Declare constructor function.
    const std::string & GetName() const;// Declare a get name function.

    void   SetConcentration(double new_concentration) {concentration=new_concentration;} // Set concentration
    double GetConcentration() const {return concentration;}
    void   ReSetRateOfChange() {rate_of_change=0;} // Reset rate of change
    double GetRateOfChange() const {return rate_of_change;}
    void	 ContributeToRateOfChange(double flux) {rate_of_change+=flux;}

  private:
    std::string name; // A member variable for the class to store the name of the system.
    double concentration;
    double rate_of_change;

  };
}

#endif //ONCE_SPECIES_H
