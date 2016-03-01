#include <string>
#include <iostream>
#include <exception>
#include "Subtract_Command.h"

//
// Subtract_Command
// Default Constructor.
//
Subtract_Command:: Subtract_Command()
{

}


//
// ~Subtract_Command
// Destructor which is called when Subtract_Command objects are destroyed (deallocated).
//
Subtract_Command:: ~Subtract_Command()
{

}


//
// execute(Stack<int>)
// It pops top two operands from the stack, subtracts them and and pushes the result back on stack
//

int Subtract_Command:: evaluate (int n1, int n2) const
{
	// Akshay, please use the template method pattern to reduce
	// duplication of code here.

	// Dr. Hill, I have changed the design and used template method pattern. 
	// I created a class called Binary_Op_Command.
	// It defines the major steps of the execute method and only the operator specific functionality
	// is being written in the individual operator classes.

	return (n1 - n2);

}

//
// getTokenValue
// returns the token value of subtract command.
//
std::string Subtract_Command:: getTokenValue()
{
	return "-";
}

//
// getTokenPriority
// returns the priority of subtract command.
//
int Subtract_Command:: getTokenPriority()
{
	return 1;
}