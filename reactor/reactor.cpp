// We write comments like this

#include <iostream> //Include standard library file which provides input and output capabilities ("print statements") 

#include "Species.h" // Include our own library file for describing a reaction system

int main(int argument_count, char ** command_line_arguments) // Define the main function, which is the entry point to the program.
{ // C++ uses braces to start and end sections of code.
  
  std::cout << "The 'boiler plate' main program is running." << std::endl; // Print out a friendly message.
  // The << symbol is an output operator, while std::cout tells the message to go to "standard output", i.e. your terminal.
  
  reactor::Species calcium("Ca"); // You can declare new variables like this.
  // "Species" is a user defined type, or "class".
  
  std::cout << "A species was created called \"" << calcium.GetName() << "\"" << std::endl; // You use a dot to access a method of a class.
  // To get a quote symbol into a string, escape it with a slash
  // << can be used to chain several outputs together, in this case, a literal string,
  // and the output from calling GetName()

  return 0; // Exit successfully.
}