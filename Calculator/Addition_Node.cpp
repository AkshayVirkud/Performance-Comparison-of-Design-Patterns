#include <string>
#include <iostream>
#include <exception>
#include "Addition_Node.h"
#include "Expr_Node_Visitor.h"

//
// Addition_Node
// Default Constructor.
//
Addition_Node:: Addition_Node()
	:Binary_Expr_Node()
{

}

//
// Addition_Node(Expr_Node, Expr_Node)
// Initializing constructor.
//
Addition_Node:: Addition_Node(Expr_Node *n1, Expr_Node *n2)
	:Binary_Expr_Node(n1, n2)
{
	
}

//
// ~Addition_Node
// Destructor which is called when Addition node objects are destroyed (deallocated).
//
Addition_Node:: ~Addition_Node()
{
  // Akshay, you should let the binary node handle the deletion since
  // you are duplicating the deletion code in all concrete binary
  // nodes.

  // Dr. Hill, I have changed the design and handled the deletion in 
  // the binary node instead of concrete binary nodes.


}



//
// execute (int n1, int n2)
// Adds two integers and returns the result.
//
int Addition_Node :: execute (int n1, int n2)
{
	return n1 + n2;
}

//
// getTokenValue
// Returns the token value of addition node.
//
std::string Addition_Node:: getTokenValue()
{
	return "+";
}

//
// accept(Expr_Node_Visitor)
// It enables an object to be "visited" by the visitor object.
//
void Addition_Node::accept(Expr_Node_Visitor &v)
{
	v.Visit_Addition_Node(*this);
}

//
// getTokenPriority()
// Gets the token priority of Addition Node.
//
int Addition_Node:: getTokenPriority()
{
	return 1;
}

