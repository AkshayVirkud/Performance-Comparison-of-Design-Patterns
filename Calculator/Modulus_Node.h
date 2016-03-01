//==============================================================================
/**
* @file       Modulus_Node.h
*
* $Id: Modulus_Node.h 819 2011-01-17 15:24:45Z hillj $
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _MODULUS_NODE_H_
#define _MODULUS_NODE_H_

#include <string>
#include <iostream>
#include <exception>
#include "Binary_Expr_Node.h"  

/**
* @class Modulus_Node
*
* Basic implementation of a Modulus_Node.
*/
class Modulus_Node : public  Binary_Expr_Node
{
public:
	/// Default constructor.
	Modulus_Node (void);

	/**
	* Initializing constructor.
	*
	* @param[in]      n1        LHS Node
	* @param[in]      n2        RHS Node
	*/
	Modulus_Node (Expr_Node *n1, Expr_Node *n2);

	/// Destructor.
	~Modulus_Node (void);

	/**
	* Implements the modulus operation.
	*
	* @param[in]      n1        First Operand.
	* @param[in]      n2        Second Operand
	* @return				  Returns the result of the modulus operation.
	*/
	virtual int execute (int n1, int n2);

	/**
	* Gets the string value of the modulus token.
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
	* Gets the token priority of modulus node.
	*
	* @return				  Returns priority of the node.
	*/
	int getTokenPriority();

};

#endif   // !defined Modulus_Node
