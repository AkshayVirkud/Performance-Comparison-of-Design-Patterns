#include <string>
#include <iostream>
#include <exception>
#include "Number_Node.h"
#include "Expr_Node_Visitor.h"

//
// Number_Node
// Default Constructor.
//
Number_Node:: Number_Node()
{

}

//
// Number_Node(int n)
// Initializing constructor.
//
Number_Node:: Number_Node(int n)
{
	n_ = n;
}

//
// ~Number_Node
// Destructor which is called when Number_Node objects are destroyed (deallocated).
//
Number_Node:: ~Number_Node()
{

}



//
// execute (int n1, int n2)
// Returns the number node value.
//
int Number_Node :: eval ()
{
	return n_;
}

//
// getTokenValue
// returns the token value of number node.
//
std::string Number_Node:: getTokenValue()
{
	return "";
}

//
// accept(Expr_Node_Visitor)
// It enables an object to be "visited" by the visitor object.
//
void Number_Node::accept(Expr_Node_Visitor &v)
{
	v.Visit_Number_Node(*this);
}

//
// getNumberValue
// returns value of the number node.
//
int Number_Node::getNumberValue()const
{
	return this->n_;
}

//
// getTokenPriority()
// Gets the token priority of Number Node.
// Since the number node is immediately pushed on the expression stack,
// it has been assigned highest priority.
//
int Number_Node:: getTokenPriority()
{
	return 4;
}

