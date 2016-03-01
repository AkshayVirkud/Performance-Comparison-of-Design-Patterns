#include <string>
#include <iostream>
#include <exception>
#include "Stack.h" 
#include "ClosedParanthesis_Node.h"

//
// ClosedParanthesis_Command
// Default Constructor.
//
ClosedParanthesis_Node:: ClosedParanthesis_Node()
{

}


//
// ~ClosedParanthesis_Command
// Destructor which is called when ClosedParanthesis_Command objects are destroyed (deallocated).
//
ClosedParanthesis_Node:: ~ClosedParanthesis_Node()
{

}


//
// execute(Stack<int>)
// It does nothing but returns 1.
//
int ClosedParanthesis_Node:: eval()
{
	return 1;
}

//
// getTokenValue
// returns the token value of Closed Paranthesis command
//
std::string ClosedParanthesis_Node:: getTokenValue()
{
	return ")";
}

//
// getTokenPriority
// returns the priority of Closed Paranthesis node.
// Since we are not considering the priority of open and close paranthesis
// during execution, we return 0.
//
int ClosedParanthesis_Node:: getTokenPriority()
{
	return 0;
}

//
// accept(Expr_Node_Visitor)
// It enables an object to be "visited" by the visitor object.
//
void ClosedParanthesis_Node::accept(Expr_Node_Visitor &v)
{
	
}
