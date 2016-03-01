#include <string>
#include <iostream>
#include <exception>
#include "Division_Node.h"
#include "Expr_Node_Visitor.h"

//
// Division_Node
// Default Constructor.
//
Division_Node:: Division_Node()
	:Binary_Expr_Node()
{

}

//
// Division_Node(Expr_Node, Expr_Node)
// Initializing constructor.
//
Division_Node:: Division_Node(Expr_Node *n1, Expr_Node *n2)
	:Binary_Expr_Node(n1, n2)
{

}

//
// ~Division_Node
// Destructor which is called when Division_Node objects are destroyed (deallocated).
//
Division_Node:: ~Division_Node()
{
  // Akshay, you should let the binary node handle the deletion since
  // you are duplicating the deletion code in all concrete binary
  // nodes.

  // Dr. Hill, I have changed the design and handled the deletion in 
  // the binary node instead of concrete binary nodes.

}



//
// execute (int n1, int n2)
// Divides two integers and returns the result.
//
int Division_Node :: execute (int n1, int n2)
{
	return n1 / n2;
}

//
// getTokenValue
// returns the token value of divide node.
//
std::string Division_Node:: getTokenValue()
{
	return "/";
}

//
// accept(Expr_Node_Visitor)
// It enables an object to be "visited" by the visitor object.
//
void Division_Node::accept(Expr_Node_Visitor &v)
{
	v.Visit_Division_Node(*this);
}

//
// getTokenPriority()
// Gets the token priority of Division Node.
//
int Division_Node:: getTokenPriority()
{
	return 2;
}

