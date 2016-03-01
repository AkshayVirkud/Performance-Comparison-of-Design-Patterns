#include <string>
#include <iostream>
#include <exception>
#include "Unary_Expr_Node.h"
#include "Expr_Node_Visitor.h"

//
// Unary_Expr_Node
// Default Constructor.
//
Unary_Expr_Node::Unary_Expr_Node()
	:child_(0)
{

}


//
// ~Unary_Expr_Node
// Destructor which is called when Unary_Expr_Node objects are destroyed (deallocated).
//
Unary_Expr_Node::~Unary_Expr_Node()
{
	if(0 != child_)
		delete child_;
}

//
// Unary_Expr_Node(Expr_Node)
// Initializing constructor.
//
Unary_Expr_Node::Unary_Expr_Node(Expr_Node *n1)
{
	this->child_ = n1;
}

//
// eval()
// Evaluates a unary node and returns result.
//
int Unary_Expr_Node:: eval()
{
	int n = child_->eval();
	return n * -1;
}

//
// getTokenValue
// Returns the token value of unary node.
//
std::string Unary_Expr_Node:: getTokenValue()
{
	return "u";
}

//
// accept(Expr_Node_Visitor)
// It enables an object to be "visited" by the visitor object.
//
void Unary_Expr_Node::accept(Expr_Node_Visitor &v)
{
	v.Visit_Unary_Node(*this);
}

//
// get_child()
// Returns child of Unary node.
//
Expr_Node * Unary_Expr_Node:: get_child() const
{
	return this->child_;
}

//
// set_child()
// Sets the value of the child of Unary node.
//
void Unary_Expr_Node:: set_child(Expr_Node * node)
{
	this->child_ = node;
}

//
// getTokenPriority()
// Gets the token priority of Unary Node.
//
int Unary_Expr_Node:: getTokenPriority()
{
	return 3;
}