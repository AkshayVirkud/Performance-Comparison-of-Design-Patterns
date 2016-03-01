#include <exception>
#include <cstring>          // for size_t definition
#include <cstdlib>
#include <iostream>
#include <ctype.h>
#include <sstream>
#include <string>
#include <stdexcept>
#include "Expr_Tree_Builder.h"
#include "Stack.h" 
#include "Tree_Expr_Node_Factory.h" 

//
// Expr_Tree_Builder
// Default Constructor.
//
Expr_Tree_Builder :: Expr_Tree_Builder() 
{

}

//
// ~Expr_Tree_Builder
// Destructor for Expr_Tree_Builder
//
Expr_Tree_Builder:: ~Expr_Tree_Builder () 
{

}

//
// build_expression()
// Creates Tree expression
//
void Expr_Tree_Builder::build_expression()
{
	this->tree_ = new Number_Node();
}

//
// build_number(int n)
// Creates Number Node.
//
void Expr_Tree_Builder::build_number(int n)
{
	// Akshay, instead of allocating a new factory each time, you should
	// just make it a private variable on this class.

	// Dr. Hill, I have removed the code for allocating a new factory each time 
	// and I have made a private factory variable for this class.  

	Expr_Node* node = objTree_Expr_Node_Factory_.create_number_node(n);
	expression_stack_.push(node);
}

//
// build_add_operand()
// Creates Addition Node.
//
void Expr_Tree_Builder::build_add_operand()
{
	// Akshay, instead of allocating a new factory each time, you should
	// just make it a private variable on this class.

	// Dr. Hill, I have removed the code for allocating a new factory each time 
	// and I have made a private factory variable for this class. 

	Expr_Node* addNode = objTree_Expr_Node_Factory_.create_add_node();
	arrangeOperatorByPriority(addNode);
	operator_stack_.push(addNode);
}

//
// build_subtract_operand()
// Creates Subtract Node.
//
void Expr_Tree_Builder::build_subtract_operand()
{
	// Akshay, instead of allocating a new factory each time, you should
	// just make it a private variable on this class.

	// Dr. Hill, I have removed the code for allocating a new factory each time 
	// and I have made a private factory variable for this class. 

	Expr_Node* subtractNode = objTree_Expr_Node_Factory_.create_subtract_node();
	arrangeOperatorByPriority(subtractNode);
	operator_stack_.push(subtractNode);
}

//
// build_multiply_operand()
// Creates Multiply Node.
//
void Expr_Tree_Builder::build_multiply_operand()
{
	// Akshay, instead of allocating a new factory each time, you should
	// just make it a private variable on this class.

	// Dr. Hill, I have removed the code for allocating a new factory each time 
	// and I have made a private factory variable for this class. 

	Expr_Node* multiplyNode = objTree_Expr_Node_Factory_.create_multiplication_node();
	arrangeOperatorByPriority(multiplyNode);
	operator_stack_.push(multiplyNode);
}

//
// build_divide_operand()
// Creates Divide Node.
//
void Expr_Tree_Builder::build_divide_operand()
{
	// Akshay, instead of allocating a new factory each time, you should
	// just make it a private variable on this class.

	// Dr. Hill, I have removed the code for allocating a new factory each time 
	// and I have made a private factory variable for this class. 

	Expr_Node* divideNode = objTree_Expr_Node_Factory_.create_division_node();
	arrangeOperatorByPriority(divideNode);
	operator_stack_.push(divideNode);
}

//
// build_modulus_operand()
// Creates Modulus Node.
//
void Expr_Tree_Builder::build_modulus_operand()
{
	// Akshay, instead of allocating a new factory each time, you should
	// just make it a private variable on this class.

	// Dr. Hill, I have removed the code for allocating a new factory each time 
	// and I have made a private factory variable for this class. 

	Expr_Node* modulusNode = objTree_Expr_Node_Factory_.create_modulus_node();
	arrangeOperatorByPriority(modulusNode);
	operator_stack_.push(modulusNode);
}

//
// build_unary_operand()
// Creates Unary Node.
//
void Expr_Tree_Builder::build_unary_operand()
{
	// Akshay, instead of allocating a new factory each time, you should
	// just make it a private variable on this class.

	// Dr. Hill, I have removed the code for allocating a new factory each time 
	// and I have made a private factory variable for this class. 

	Expr_Node* unaryNode = objTree_Expr_Node_Factory_.create_unary_node();
	operator_stack_.push(unaryNode);

}

//
// build_openParanthesis_operand()
// Creates Operand Paranthesis Node.
//
void Expr_Tree_Builder::build_openParanthesis_operand()
{
	Expr_Node* openParanthesisNode = objTree_Expr_Node_Factory_.create_openParanthesis_node();
	operator_stack_.push(openParanthesisNode);
}

//
// build_closedParanthesis_operand()
// Creates Closed Paranthesis Node.
//
void Expr_Tree_Builder::build_closedParanthesis_operand()
{
	evaluateClosedParanthesisNode();
	Expr_Node* openParanthesisNode = operator_stack_.top();
	operator_stack_.pop();
	delete openParanthesisNode;
}

//
// get_expression()
// Returns reference to expression tree.
//
Expr_Node * Expr_Tree_Builder::get_expression()
{
	evaluateRemainingStackItems();
	this->tree_ = expression_stack_.top();
	expression_stack_.pop();
	return this->tree_;
}

//
// CheckPriority (int, int)
// Determines whether the left or the right operator has the higher priority.
//
bool Expr_Tree_Builder::checkPriority(int leftPriority, int rightPriority)
{
	if(leftPriority >= rightPriority)
	{
		return true;
	}

	return false;
}

//
// ArrangeOperatorByPriority (Expr_Node)
// Determines the priority of operators in the operator stack.
//
bool Expr_Tree_Builder::arrangeOperatorByPriority(Expr_Node * token)
{
	std::string rightOperator = token->getTokenValue();
	int rightOperatorPriority = token->getTokenPriority();
	while(!operator_stack_.is_empty() && checkPriority(operator_stack_.top()->getTokenPriority(), rightOperatorPriority) && !("(" == token->getTokenValue()))
	{
		Expr_Node* operatorNode = operator_stack_.top();
		operator_stack_.pop();
		if(operatorNode->getTokenValue() == "u")
		{
			Expr_Node* childNode = expression_stack_.top();
			expression_stack_.pop();
			dynamic_cast<Unary_Expr_Node*> (operatorNode)->set_child(childNode);
			expression_stack_.push(operatorNode);
		}
		else
		{
			Expr_Node* rightNode = expression_stack_.top();
			expression_stack_.pop();
			Expr_Node* leftNode = expression_stack_.top();
			expression_stack_.pop();
			dynamic_cast<Binary_Expr_Node*> (operatorNode)->setLeftNode(leftNode);
			dynamic_cast<Binary_Expr_Node*> (operatorNode)->setRightNode(rightNode);
			expression_stack_.push(operatorNode);
		}
	}
	return true;
}

//
// EvaluateClosedParanthesisNode()
// Set of operations to be performed when we encounter close paranthesis.
//
bool Expr_Tree_Builder::evaluateClosedParanthesisNode()
{
	while(!operator_stack_.is_empty() && ("(" != operator_stack_.top()->getTokenValue()))
	{
		Expr_Node* operatorNode = operator_stack_.top();
		operator_stack_.pop();
		if(operatorNode->getTokenValue() == "u")
		{
			Expr_Node* childNode = expression_stack_.top();
			expression_stack_.pop();
			dynamic_cast<Unary_Expr_Node*> (operatorNode)->set_child(childNode);
			expression_stack_.push(operatorNode);
		}
		else
		{
			Expr_Node* rightNode = expression_stack_.top();
			expression_stack_.pop();
			Expr_Node* leftNode = expression_stack_.top();
			expression_stack_.pop();
			dynamic_cast<Binary_Expr_Node*> (operatorNode)->setLeftNode(leftNode);
			dynamic_cast<Binary_Expr_Node*> (operatorNode)->setRightNode(rightNode);
			expression_stack_.push(operatorNode);
		}
	}
	return true;
}

//
// EvaluateClosedParanthesisNode()
// Pop all the operands from the operator stack and add them to expression stack.
//
bool Expr_Tree_Builder::evaluateRemainingStackItems()
{
	while(!operator_stack_.is_empty())
	{
		Expr_Node* operatorNode = operator_stack_.top();
		operator_stack_.pop();
		if(operatorNode->getTokenValue() == "u")
		{
			Expr_Node* childNode = expression_stack_.top();
			expression_stack_.pop();
			dynamic_cast<Unary_Expr_Node*> (operatorNode)->set_child(childNode);
			expression_stack_.push(operatorNode);
		}
		else
		{
			Expr_Node* rightNode = expression_stack_.top();
			expression_stack_.pop();
			Expr_Node* leftNode = expression_stack_.top();
			expression_stack_.pop();
			dynamic_cast<Binary_Expr_Node*> (operatorNode)->setLeftNode(leftNode);
			dynamic_cast<Binary_Expr_Node*> (operatorNode)->setRightNode(rightNode);
			expression_stack_.push(operatorNode);
		}
	}
	return true;
}

//
// get_expressionStack()
// Fetches the expression stack of Expression Tree Builder.
//
Stack<Expr_Node*> Expr_Tree_Builder::get_expressionStack()
{
	return this->expression_stack_;
}

//
// get_operatorStack()
// Fetches the operator stack of Expression Tree Builder.
//
Stack<Expr_Node*> Expr_Tree_Builder::get_operatorStack()
{
	return this-> operator_stack_;
}




