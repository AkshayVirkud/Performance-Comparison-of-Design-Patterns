//==============================================================================
/**
* @file       Binary_Expr_Node.h
*
* $Id: Binary_Expr_Node.h 819 2011-01-17 15:24:45Z hillj $
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _BINARY_EXPR_NODE_H_
#define _BINARY_EXPR_NODE_H_

#include <string>
#include <iostream>
#include <exception>
#include "Expr_Node.h"

/**
* @class Binary_Expr_Node
*
* Basic implementation of a Binary Expression Node.
*/
class Binary_Expr_Node : public Expr_Node
{
public:
	/// Default constructor.
	Binary_Expr_Node (void);

	/**
	* Initializing constructor.
	*
	* @param[in]      n1        LHS Node
	* @param[in]      n2        RHS Node
	*/
	Binary_Expr_Node (Expr_Node *n1, Expr_Node *n2);

	/// Destructor.
	virtual ~Binary_Expr_Node (void);

	/**
	* Used to travese the tree.
	*
	* 
	* @return          Evaluation result.
	*/
	virtual int eval (void);

	/**
	* Performs a binary operation on the tree node.
	*
	* @param[in]      n1        LHS Node
	* @param[in]      n2        RHS Node
	* @return          Execution result.
	*/
	virtual int execute (int n1, int n2) = 0;

	/**
	* abstract definition of the GetTokenValue function.
	*
	* @return				  Returns string equivalent of the token value.
	*/
	virtual std::string getTokenValue() = 0;

	/**
	* Accept method for implementing visitor pattern.
	*
	*  @param[in]    Expr_Node_Visitor	  a pointer or reference to the abstract base class of the Visitor hierarchy.
	*/
	virtual void accept (Expr_Node_Visitor & v);

	/**
	* Fetches the right node.
	*
	*  @return    Right Expression Node
	*/
	virtual Expr_Node* getRightNode() const;

	/**
	* Fetches the left node.
	*
	*  @return    Left Expression Node
	*/
	virtual Expr_Node* getLeftNode() const;

	/**
	* Sets the value of right node.
	*
	*  @param[in]    Right Expression Node value.
	*/
	virtual void setRightNode(Expr_Node* node);

	/**
	* Sets the value of left node.
	*
	*  @param[in]   Left Expression Node value.
	*/
	virtual void setLeftNode(Expr_Node* node);

	/**
	* Gets the node priority.
	*
	* @return				  Returns priority of the Binary Expr_Node.
	*/
	virtual int getTokenPriority() = 0;

protected:
	Expr_Node *right_;
	Expr_Node *left_;
};

#endif   // !defined _BINARY_EXPR_NODE_