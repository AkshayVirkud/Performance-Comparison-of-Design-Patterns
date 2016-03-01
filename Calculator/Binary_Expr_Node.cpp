#include <string>
#include <iostream>
#include <exception>
#include "Binary_Expr_Node.h"
#include "Expr_Node.h"

//
// Binary_Expr_Node
// Default Constructor.
//
Binary_Expr_Node :: Binary_Expr_Node()
	: left_(0),
	right_(0)
{

}


//
// Binary_Expr_Node(Expr_Node, Expr_Node)
// Initializing constructor.
//
Binary_Expr_Node :: Binary_Expr_Node(Expr_Node *n1, Expr_Node *n2)
	: left_(n1),
	right_(n2)
{

}

//
// ~Binary_Expr_Node
// Destructor which is called when Binary_Expr_Node objects are destroyed (deallocated).
//
Binary_Expr_Node:: ~Binary_Expr_Node()
{
  // Akshay, the binary node should delete the left and right not, not
  // the individual concrete nodes.

  // Dr. Hill, I have deleted the left and right in the binary node.

	if(0 != left_)
		delete left_;

	if(0 != right_)
		delete right_;
}

//
// getLeftNode
// Fetches the left node. 
//
Expr_Node* Binary_Expr_Node::getLeftNode()const
{
	return this->left_;
}

//
// getRightNode
// Fetches the right node. 
//
Expr_Node* Binary_Expr_Node::getRightNode()const
{
	return this->right_;
}

//
// setLeftNode(Expr_Node)
// Sets the value of left node. 
//
void Binary_Expr_Node::setLeftNode(Expr_Node* node)
{
	this->left_ = node;
}

//
// setRightNode(Expr_Node)
// Sets the value of right node. 
//
void Binary_Expr_Node::setRightNode(Expr_Node* node)
{
	this->right_ = node;
}

//
// eval()
// It pops top two operands from the stack, evaluates them and and pushes the result back on stack.
//
int Binary_Expr_Node:: eval()
{
	int n2 = left_->eval();
	int n1 = right_ ->eval();
	int result = this->execute (n1, n2);
	return result;
	return 0;
}

//
// accept(Expr_Node_Visitor)
// It enables an object to be "visited" by the visitor object.
//
void Binary_Expr_Node::accept(Expr_Node_Visitor &v)
{
	
}
