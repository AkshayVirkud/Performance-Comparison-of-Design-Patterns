#include <string>
#include <iostream>
#include <exception>
#include "Stack.h" 
#include "Number_Command.h"

//
// Number_Command
// Default Constructor.
//
Number_Command:: Number_Command()
{

}

//
// ~Number_Command
// Number Command Destructor
//
Number_Command:: ~Number_Command()
{

}

//
// Number_Command
// Initializing constructor that creates number command having the value that is passes as a parameter.
//
Number_Command:: Number_Command (int num)
	: n_ (num) { }


//
// execute(Stack<int>)
// It pushes the number value on the integer stack.
//
bool Number_Command:: execute (Stack <int> & s)
{
	s.push (this->n_);
	return true;

}

//
// getTokenValue
// returns the token value of number command.
//
std::string Number_Command:: getTokenValue()
{
	return "number";
}

//
// getTokenPriority
// Since we are not considering the priority of number command during execution, we return 0.
//
int Number_Command:: getTokenPriority()
{
	return 0;
}