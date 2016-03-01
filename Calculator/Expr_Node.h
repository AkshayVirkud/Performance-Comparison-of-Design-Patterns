//==============================================================================
/**
* @file       Expr_Node.h
*
* $Id: Expr_Node.h 819 2011-01-17 15:24:45Z hillj $
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _EXPR_NODE_H_
#define _EXPR_NODE_H_

#include <string>
#include <iostream>
#include <exception>

/**
* @class Expr_Node
*
* Basic implementation of a Expression Node.
*/

class Expr_Node_Visitor;
class Expr_Node 
{
public:
	/// Default constructor.
	Expr_Node (void);

	/// Destructor.
	virtual ~Expr_Node (void);

	// Used to travese the tree 
	virtual int eval (void) = 0;

	/**
	* Pure virtual get string value of token operation.
	*
	* @return				  Returns string equivalent of the token value.
	*/
	virtual std::string getTokenValue() = 0;

	/**
	* Accept method for implementing visitor pattern.
	*
	* @param[in]    Expr_Node_Visitor	  a pointer or reference to the abstract base class of the Visitor hierarchy.
	*/
	virtual void accept (Expr_Node_Visitor & v) = 0;

	/**
	* Gets the node priority.
	*
	* @return				  Returns priority of the Expr_Node.
	*/
	virtual int getTokenPriority() = 0;
};

#endif   // !defined Expr_Node
