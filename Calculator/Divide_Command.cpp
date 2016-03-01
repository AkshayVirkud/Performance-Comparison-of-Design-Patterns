#include <string>
#include <iostream>
#include <exception>
#include <stdexcept>
#include "Divide_Command.h"

//
// Divide_Command
// Default Constructor.
//
Divide_Command:: Divide_Command()
{

}


//
// ~Divide_Command
// Destructor which is called when Divide_Command objects are destroyed (deallocated).
//

Divide_Command:: ~Divide_Command()
{

}


//
// execute(Stack<int>)
// It pops top two operands from the stack, divides them and and pushes the result back on stack.
//
int Divide_Command:: evaluate (int n1, int n2) const
{
	// Akshay, please use the template method pattern to reduce
	// duplication of code here.

	// Dr. Hill, I have changed the design and used template method pattern. 
	// I created a class called Binary_Op_Command.
	// It defines the major steps of the execute method and only the operator specific functionality
	// is being written in the individual operator classes.

	if (n2 == 0)
		throw std::overflow_error("Divide by zero exception");

	return (n1 / n2);

}

//
// getTokenValue
// returns the token value of divide command.
//
std::string Divide_Command:: getTokenValue()
{
	return "/";
}

//
// getTokenPriority
// returns the priority of divide command.
//
int Divide_Command:: getTokenPriority()
{
	return 2;
}