//==============================================================================
/**
* @file       Number_Node.h
*
* $Id: Number_Node.h 819 2011-01-17 15:24:45Z hillj $
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _NUMBER_NODE_H_
#define _NUMBER_NODE_H_

#include <string>
#include <iostream>
#include <exception>
#include "Binary_Expr_Node.h"  

/**
* @class Number_Node
*
* Basic implementation of a Number Node.
*/
class Number_Node : public Expr_Node
{
public:
	/// Default constructor.
	Number_Node (void);

	/**
	* Initializing constructor.
	*
	* @param[in]      n        number
	*/
	Number_Node (int n);

	/// Destructor.
	~Number_Node (void);

	/**
	* Evaluates the number node.
	*
	* @return				  Returns the value of number node.
	*/
	virtual int eval (void);

	/**
	* Gets the string value of the number token.
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
	* Gets value of the number node.
	*
	* @return				  Returns number node value.
	*/
	int getNumberValue() const;

	/**
	* Gets the token priority of number node.
	*
	* @return				  Returns priority of the node.
	*/
	int getTokenPriority();

private :
	int n_;

};

#endif   // !defined _NUMBER_NODE_H_