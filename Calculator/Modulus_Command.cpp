#include <string>
#include <iostream>
#include <exception>
#include "Modulus_Command.h"

//
// Modulus_Command
// Default Constructor.
//
Modulus_Command:: Modulus_Command()
{

}

//
// ~Modulus_Command
// Destructor which is called when Modulus_Command objects are destroyed (deallocated).
//
Modulus_Command:: ~Modulus_Command()
{

}


//
// evaluate (int n1, int n2)
// computes modulus of one integer with respect to second integers and returns the result.
//
int Modulus_Command:: evaluate (int n1, int n2) const
{
	// Akshay, please use the template method pattern to reduce
	// duplication of code here.

	// Dr. Hill, I have changed the design and used template method pattern. 
	// I created a class called Binary_Op_Command.
	// It defines the major steps of the execute method and only the operator specific functionality
	// is being written in the individual operator classes.

	if (n2 == 0)
		throw std::overflow_error("Modulus by zero exception");

	return (n1 % n2);

}

//
// getTokenValue
// returns the token value of modulus command.
//
std::string Modulus_Command:: getTokenValue()
{
	return "%";
}

//
// getTokenPriority
// returns the priority of modulus command.
//
int Modulus_Command:: getTokenPriority()
{
	return 2;
}