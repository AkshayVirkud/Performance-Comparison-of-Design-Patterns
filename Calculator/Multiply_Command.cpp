#include <string>
#include <iostream>
#include <exception>
#include "Multiply_Command.h"

//
// Multiply_Command
// Default Constructor.
//
Multiply_Command:: Multiply_Command()
{

}

//
// ~Multiply_Command
// Destructor which is called when Multiply_Command objects are destroyed (deallocated).
//
Multiply_Command:: ~Multiply_Command()
{

}


//
// evaluate (int n1, int n2)
// Multiplies two integers and returns the result.
//
int Multiply_Command:: evaluate (int n1, int n2) const
{
	// Akshay, please use the template method pattern to reduce
	// duplication of code here.

	// Dr. Hill, I have changed the design and used template method pattern. 
	// I created a class called Binary_Op_Command.
	// It defines the major steps of the execute method and only the operator specific functionality
	// is being written in the individual operator classes.

	return (n1 * n2);

}

//
// getTokenValue
// returns the token value of multiply command.
//
std::string Multiply_Command:: getTokenValue()
{
	return "*";
}

//
// getTokenPriority
// returns the priority of multiply command.
//
int Multiply_Command:: getTokenPriority()
{
	return 2;
}
