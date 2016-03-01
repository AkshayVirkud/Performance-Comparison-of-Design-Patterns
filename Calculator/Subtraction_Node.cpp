#include <string>
#include <iostream>
#include <exception>
#include "Subtraction_Node.h"
#include "Expr_Node_Visitor.h"

//
// Subtraction_Node
// Default Constructor.
//
Subtraction_Node:: Subtraction_Node()
	:Binary_Expr_Node()
{

}


//
// ~Subtraction_Node
// Destructor which is called when Subtraction_Node objects are destroyed (deallocated).
//
Subtraction_Node:: ~Subtraction_Node()
{
  // Akshay, you should let the binary node handle the deletion since
  // you are duplicating the deletion code in all concrete binary
  // nodes.

  // Dr. Hill, I have changed the design and handled the deletion in 
  // the binary node instead of concrete binary nodes.

}

//
// Subtraction_Node(Expr_Node, Expr_Node)
// Initializing constructor.
//
Subtraction_Node:: Subtraction_Node(Expr_Node *n1, Expr_Node *n2)
	:Binary_Expr_Node(n1, n2)
{

}

//
// execute (int n1, int n2)
// Subtracts two integers and returns the result.
//
int Subtraction_Node :: execute (int n1, int n2)
{
	return n1 - n2;
}


//
// getTokenValue
// returns the token value of subtract node.
//
std::string Subtraction_Node:: getTokenValue()
{
	return "-";
}

//
// accept(Expr_Node_Visitor)
// It enables an object to be "visited" by the visitor object.
//
void Subtraction_Node::accept(Expr_Node_Visitor &v)
{
	v.Visit_Subtraction_Node(*this);
}

//
// getTokenPriority()
// Gets the token priority of Subtraction Node.
//
int Subtraction_Node:: getTokenPriority()
{
	return 1;
}

