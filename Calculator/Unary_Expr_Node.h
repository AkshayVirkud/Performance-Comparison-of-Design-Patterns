//==============================================================================
/**
* @file       Unary_Expr_Node.h
*
* $Id: Unary_Expr_Node.h 819 2011-01-17 15:24:45Z hillj $
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _UNARY_EXPR_NODE_H_
#define _UNARY_EXPR_NODE_H_

#include <string>
#include <iostream>
#include <exception>
#include "Expr_Node.h"

/**
* @class Unary_Expr_Node
*
* Basic implementation of a Unary Expression Node.
*/

class Unary_Expr_Node : public Expr_Node {
public:
	/// Default constructor.
	Unary_Expr_Node (void);

	//destructor
	virtual ~Unary_Expr_Node (void);

	/**
	* Initializing constructor.
	*
	* @param[in]      n1        Child Node
	*/
	Unary_Expr_Node (Expr_Node *n1);

	// Used to travese the tree 
	virtual int eval (void);

	/**
	* Gets the string value of the unary token.
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
	* Gets the child of Unary Node.
	*
	* @return				  Returns child expression node.
	*/
	Expr_Node * get_child() const;

	/**
	* Gets the child of Unary Node.
	*
	* @return				  Returns child expression node.
	*/
	void set_child(Expr_Node * node);

	/**
	* Gets the token priority of unary node.
	*
	* @return				  Returns priority of the node.
	*/
	int getTokenPriority();

protected:
	Expr_Node * child_;
};

#endif   // !defined _UNARY_EXPR_NODE_H_