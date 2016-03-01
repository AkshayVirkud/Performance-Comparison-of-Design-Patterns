#include <string>
#include <iostream>
#include <exception>
#include "Stack.h" 
#include "OpenParanthesis_Node.h"

//
// OpenParanthesis_Node
// Default Constructor.
//
OpenParanthesis_Node:: OpenParanthesis_Node()
{

}


//
// ~OpenParanthesis_Node
// Destructor which is called when Open Paranthesis Node objects are destroyed (deallocated).
//
OpenParanthesis_Node:: ~OpenParanthesis_Node()
{

}


//
// execute(Stack<int>)
// It does nothing but return a true result.
//
int OpenParanthesis_Node:: eval()
{
	return 1;
}

//
// getTokenValue
// returns the token value of Open Paranthesis node
//
std::string OpenParanthesis_Node:: getTokenValue()
{
	return "(";
}

//
// getTokenPriority
// returns the priority of Open Paranthesis node.
// Since we are not considering the priority of open and close paranthesis
// during execution, we return 0.
//
int OpenParanthesis_Node:: getTokenPriority()
{
	return 0;
}

//
// accept(Expr_Node_Visitor)
// It enables an object to be "visited" by the visitor object.
//
void OpenParanthesis_Node::accept(Expr_Node_Visitor &v)
{
	
}
