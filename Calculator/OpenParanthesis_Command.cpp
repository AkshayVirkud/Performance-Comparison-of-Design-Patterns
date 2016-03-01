#include <string>
#include <iostream>
#include <exception>
#include "OpenParanthesis_Command.h"

//
// OpenParanthesis_Command
// Default Constructor.
//
OpenParanthesis_Command:: OpenParanthesis_Command()
{

}

//
// ~OpenParanthesis_Command
// Destructor for OpenParanthesis_Command
//
OpenParanthesis_Command:: ~OpenParanthesis_Command()
{

}


//
// execute(Stack<int>)
// It does nothing but return a true result.
//
bool OpenParanthesis_Command:: execute (Stack <int> & s)
{
	return true;

}

//
// getTokenValue
// returns the token value of open paranthesis command.
//
std::string OpenParanthesis_Command:: getTokenValue()
{
	return "(";
}

//
// getTokenPriority
// returns the priority of open paranthesis command.
// Since we are not considering the priority of open and close paranthesis
// during execution, we return 0.
//
int OpenParanthesis_Command:: getTokenPriority()
{
	return 0;
}