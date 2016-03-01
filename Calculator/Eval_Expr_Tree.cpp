#include "Eval_Expr_Tree.h"
//
// Eval_Expr_Tree
// Default Constructor.
//
Eval_Expr_Tree::Eval_Expr_Tree(void) 
{

}

//
// ~Eval_Expr_Tree
// Destructor
//
Eval_Expr_Tree::~Eval_Expr_Tree(void) 
{

}

//
// Visit_Number_Node(const Number_Node & node)
// Visit the number node and get the node value.
//
void Eval_Expr_Tree::Visit_Number_Node(const Number_Node & node)
{
	this->result_ = node.getNumberValue();
}

//
// Visit_Addition_Node(const Addition_Node & node)
// Traverse right node , left node and compute the addition result.
//
void Eval_Expr_Tree::Visit_Addition_Node(const Addition_Node & node)
{
	Eval_Expr_Tree left;
	Eval_Expr_Tree right;

	node.getLeftNode()->accept(left); 
	node.getRightNode()->accept(right);
	this->result_=left.result() + right.result();
}

//
// Visit_Subtraction_Node(const Subtraction_Node & node)
// Traverse right node , left node and compute the subtraction result.
//
void Eval_Expr_Tree::Visit_Subtraction_Node(const Subtraction_Node & node)
{
	Eval_Expr_Tree left;
	Eval_Expr_Tree right;

	node.getLeftNode()->accept(left); 
	node.getRightNode()->accept(right);
	this->result_=left.result() - right.result();
}

//
// Visit_Multiplication_Node(const Multiplication_Node & node)
// Traverse right node , left node and compute the multiplication result.
//
void Eval_Expr_Tree::Visit_Multiplication_Node(const Multiplication_Node & node)
{
	Eval_Expr_Tree left;
	Eval_Expr_Tree right;

	node.getLeftNode()->accept(left); 
	node.getRightNode()->accept(right);
	this->result_=left.result() * right.result();
}

//
// Visit_Modulus_Node(const Modulus_Node & node)
// Traverse right node , left node and compute the modulus result.
//
void Eval_Expr_Tree::Visit_Modulus_Node(const Modulus_Node & node)
{
	Eval_Expr_Tree left;
	Eval_Expr_Tree right;

	node.getLeftNode()->accept(left); 
	node.getRightNode()->accept(right);

	if (right.result() == 0)
	{
		delete &node;
		throw std::overflow_error("Modulus by zero exception");
	}

	this->result_=left.result() % right.result();
}

//
// Visit_Division_Node(const Division_Node & node)
// Traverse right node , left node and compute the division result.
//
void Eval_Expr_Tree::Visit_Division_Node(const Division_Node & node)
{
	Eval_Expr_Tree left;
	Eval_Expr_Tree right;

	node.getLeftNode()->accept(left); 
	node.getRightNode()->accept(right);

	if (right.result() == 0)
	{
		delete &node;
		throw std::overflow_error("Divide by zero exception");
	}

	this->result_=left.result() / right.result();
}

//
// Visit_Unary_Node(const Unary_Expr_Node & node)
// Traverse the child node and get its value.
//
void Eval_Expr_Tree::Visit_Unary_Node(const Unary_Expr_Node & node)
{
	Eval_Expr_Tree child;
	node.get_child()->accept(child);
	this->result_= -1 * child.result();
}

//
// result (void) const
// Get Result.
//
int Eval_Expr_Tree::result (void) const { return this->result_; }