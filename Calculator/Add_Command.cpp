#include <string>
#include <iostream>
#include <exception>
#include "Add_Command.h"

//
// Add_Command
// Default Constructor.
//
Add_Command:: Add_Command()
{

}

//
// ~Add_Command
// Destructor which is called when AddCommand objects are destroyed (deallocated).
//
Add_Command:: ~Add_Command()
{

}



//
// evaluate (int n1, int n2)
// Adds two integers and returns the result.
//
int Add_Command :: evaluate (int n1, int n2) const
{
	// Akshay, please use the template method pattern to reduce
	// duplication of code here.

	// Dr. Hill, I have changed the design and used template method pattern. 
	// I created a class called Binary_Op_Command.
	// It defines the major steps of the execute method and only the operator specific functionality
	// is being written in the individual operator classes.

	return n1 + n2;

}

//
// getTokenValue
// returns the token value of add command.
//
std::string Add_Command:: getTokenValue()
{
	return "+";
}

//
// getTokenPriority
// returns the priority of add command.
//
int Add_Command:: getTokenPriority()
{
	return 1;
}