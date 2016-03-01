
//==============================================================================
/**
* @file       ClosedParanthesis_Command.h
*
* $Id: ClosedParanthesis_Command.h 819 2011-01-17 15:24:45Z hillj $
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _CLOSEDPARANTHESIS_NODE_H_
#define _CLOSEDPARANTHESIS_NODE_H_

#include <string>
#include <iostream>
#include <exception>
#include "Expr_Node.h"
#include "Stack.h" 
/**
* @class ClosedParanthesis_Command
*
* Basic implementation of a Close Paranthesis.
*/
class ClosedParanthesis_Node : public Expr_Node
{
public:
	/// Default constructor.
	ClosedParanthesis_Node (void);

	/// Destructor.
	~ClosedParanthesis_Node (void);

	// Used to travese the tree 
	int eval (void);

	/**
	* Gets the string value of the Close Paranthesis node.
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
	* Gets the token priority of closed paranthesis node.
	*
	* @return				  Returns priority of the node.
	*/
	int getTokenPriority();

};

#endif   // !defined _CLOSEDPARANTHESIS_NODE_H_
