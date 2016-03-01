//==============================================================================
/**
* @file       Division_Node.h
*
* $Id: Division_Node.h 819 2011-01-17 15:24:45Z hillj $
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _DIVISION_NODE_H_
#define _DIVISION_NODE_H_

#include <string>
#include <iostream>
#include <exception>
#include "Binary_Expr_Node.h"  

/**
* @class Division_Node
*
* Basic implementation of a Divide Expression Node.
*/
class Division_Node : public  Binary_Expr_Node
{
public:
	/// Default constructor.
	Division_Node (void);

	/**
	* Initializing constructor.
	*
	* @param[in]      n1        LHS Node
	* @param[in]      n2        RHS Node
	*/
	Division_Node (Expr_Node *n1, Expr_Node *n2);

	/// Destructor.
	~Division_Node (void);

	/**
	* Implements the division operation.
	*
	* @param[in]      n1        First Operand.
	* @param[in]      n2        Second Operand
	* @return				  Returns the result of the division operation.
	*/
	virtual int execute (int n1, int n2);

	/**
	* Gets the string value of the divide token.
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
	* Gets the token priority of Dividision Node.
	*
	* @return				  Returns priority of the node.
	*/
	int getTokenPriority();

};

#endif   // !defined _DIVISION_NODE_H_
