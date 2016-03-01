#include <string>
#include <iostream>
#include <exception>
#include "Modulus_Node.h"
#include "Expr_Node_Visitor.h"

//
// Modulus_Node
// Default Constructor.
//
Modulus_Node:: Modulus_Node()
	:Binary_Expr_Node()
{

}

//
// Modulus_Node
// Initializing constructor.
//
Modulus_Node:: Modulus_Node(Expr_Node *n1, Expr_Node *n2)
	:Binary_Expr_Node(n1, n2)
{

}

//
// ~Modulus_Node
// Destructor which is called when Modulus_Node objects are destroyed (deallocated).
//
Modulus_Node:: ~Modulus_Node()
{
  // Akshay, you should let the binary node handle the deletion since
  // you are duplicating the deletion code in all concrete binary
  // nodes.

  // Dr. Hill, I have changed the design and handled the deletion in 
  // the binary node instead of concrete binary nodes.

}



//
// execute (int n1, int n2)
// Performs modulus operation and returns the result.
//
int Modulus_Node :: execute (int n1, int n2)
{
	return n1 % n2;
}

//
// getTokenValue
// returns the token value of modulus node.
//
std::string Modulus_Node:: getTokenValue()
{
	return "%";
}

//
// accept(Expr_Node_Visitor)
// It enables an object to be "visited" by the visitor object.
//
void Modulus_Node::accept(Expr_Node_Visitor &v)
{
	v.Visit_Modulus_Node(*this);
}

//
// getTokenPriority()
// Gets the token priority of Modulus Node.
//
int Modulus_Node:: getTokenPriority()
{
	return 2;
}


