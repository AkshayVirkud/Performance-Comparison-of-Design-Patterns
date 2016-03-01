#include <string>
#include <iostream>
#include <exception>
#include "Expr_Node_Visitor.h"
#include "Multiplication_Node.h"

//
// Multiplication_Node
// Default Constructor.
//
Multiplication_Node:: Multiplication_Node()
	:Binary_Expr_Node()
{

}

//
// Multiplication_Node
// Initializing constructor.
//
Multiplication_Node:: Multiplication_Node(Expr_Node *n1, Expr_Node *n2)
	:Binary_Expr_Node(n1, n2)
{

}

//
// ~Multiplication_Node
// Destructor which is called when Multiplication_Node objects are destroyed (deallocated).
//
Multiplication_Node:: ~Multiplication_Node()
{
  // Akshay, you should let the binary node handle the deletion since
  // you are duplicating the deletion code in all concrete binary
  // nodes.

  // Dr. Hill, I have changed the design and handled the deletion in 
  // the binary node instead of concrete binary nodes.

}



//
// execute (int n1, int n2)
// Multiplies two integers and returns the result.
//
int Multiplication_Node :: execute (int n1, int n2)
{
	return n1 * n2;
}

//
// getTokenValue
// returns the token value of multiply node.
//
std::string Multiplication_Node:: getTokenValue()
{
	return "*";
}

//
// accept(Expr_Node_Visitor)
// It enables an object to be "visited" by the visitor object.
//
void Multiplication_Node::accept(Expr_Node_Visitor &v)
{
	v.Visit_Multiplication_Node(*this);
}

//
// getTokenPriority()
// Gets the token priority of Multiplication Node.
//
int Multiplication_Node:: getTokenPriority()
{
	return 2;
}

