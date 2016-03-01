#include <string>
#include <iostream>
#include <exception>
#include "Stack.h" 
#include "ClosedParanthesis_Command.h"

//
// ClosedParanthesis_Command
// Default Constructor.
//
ClosedParanthesis_Command:: ClosedParanthesis_Command()
{

}


//
// ~ClosedParanthesis_Command
// Destructor which is called when ClosedParanthesis_Command objects are destroyed (deallocated).
//
ClosedParanthesis_Command:: ~ClosedParanthesis_Command()
{

}


//
// execute(Stack<int>)
// It does nothing but return a true result.
//
bool ClosedParanthesis_Command:: execute (Stack <int> & s)
{
	return true;
}

//
// getTokenValue
// returns the token value of Closed Paranthesis command
//
std::string ClosedParanthesis_Command:: getTokenValue()
{
	return ")";
}

//
// getTokenPriority
// returns the priority of Closed Paranthesis command.
// Since we are not considering the priority of open and close paranthesis
// during execution, we return 0.
//
int ClosedParanthesis_Command:: getTokenPriority()
{
	return 0;
}