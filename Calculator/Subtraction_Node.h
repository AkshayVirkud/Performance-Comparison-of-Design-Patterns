//==============================================================================
/**
* @file       Subtraction_Node.h
*
* $Id: Subtraction_Node.h 819 2011-01-17 15:24:45Z hillj $
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _SUBTRACTION_NODE_H_
#define _SUBTRACTION_NODE_H_

#include <string>
#include <iostream>
#include <exception>
#include "Binary_Expr_Node.h" 

/**
* @class Subtraction_Node
*
* Basic implementation of a Subtraction Node.
*/
class Subtraction_Node : public  Binary_Expr_Node
{
public:
	/// Default constructor.
	Subtraction_Node (void);

	/// Destructor.
	~Subtraction_Node (void);

	/**
	* Initializing constructor.
	*
	* @param[in]      n1        LHS Node
	* @param[in]      n2        RHS Node
	*/
	Subtraction_Node (Expr_Node *n1, Expr_Node *n2);

	/**
	* Implements the subtract operation.
	*
	* @param[in]      n1        First Operand.
	* @param[in]      n2        Second Operand
	* @return				  Returns the result of the subtract operation.
	*/
	virtual int execute (int n1, int n2);

	/**
	* Gets the string value of the subtract token.
	*
	* @return				  Returns string equivalent of the token value.
	*/
	std::string getTokenValue();

	/**
	* Accept method for implementing visitor pattern.
	*
	*  @param[in]    Expr_Node_Visitor	  a pointer or reference to the abstract base class of the Visitor hierarchy.
	*/
	void accept (Expr_Node_Visitor &v);

	/**
	* Gets the token priority of subtract node.
	*
	* @return				  Returns priority of the node.
	*/
	int getTokenPriority();

};

#endif   // !defined Subtraction_Node
