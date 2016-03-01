//==============================================================================
/**
* @file       Expr_Tree_Builder.h
*
* $Id: Expr_Tree_Builder.h 819 2011-01-17 15:24:45Z hillj $
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _EXPR_TREE_BUILDER_H_
#define _EXPR_TREE_BUILDER_H_

#include <string>
#include <iostream>
#include <exception>
#include "Expr_Builder.h"
#include "Tree_Expr_Node_Factory.h"

/**
* @class Expr_Tree_Builder
*
* Basic implementation of an Expression Tree Builder
*/


class Expr_Tree_Builder : public Expr_Builder 
{
public:
	//constructor
	Expr_Tree_Builder (void);

	//destructor
	virtual ~Expr_Tree_Builder (void);

	/**
	* Creates a tree expression.
	*
	*/
	virtual void build_expression (void);

	/**
	* Creates a number node.
	* @param[in]      n        value of the number node.
	*/
	virtual void build_number (int n);

	/**
	* Creates an add node
	*
	*/
	virtual void build_add_operand (void);

	/**
	* Creates a subtract node
	*
	*/
	virtual void build_subtract_operand (void);

	/**
	* Creates a multiply node
	*
	*/
	virtual void build_multiply_operand (void);

	/**
	* Creates a division node
	*
	*/
	virtual void build_divide_operand (void);

	/**
	* Creates a modulus node
	*
	*/
	virtual void build_modulus_operand (void);

	/**
	* Creates a unary node
	*
	*/
	virtual void build_unary_operand (void);

	/**
	* Creates a openParanthesis node
	*
	*/
	virtual void build_openParanthesis_operand (void);

	/**
	* Creates a closedParanthesis node
	*
	*/
	virtual void build_closedParanthesis_operand (void);

	/**
	* Calculates the operator priority.
	*
	* @param[in]     objOperator     operator
	* @return		 Priority for the operator. 
	*/
	int getOperatorPriority(std::string objOperator);

	/**
	* Checks for higher priority operator.
	*
	* @param[in]     leftPriority     LHS operator
	* @param[in]     rightPriority    RHS operator
	* @return		 Returns true if the LHS operator has higher priority else returns false. 
	*/
	bool checkPriority(int leftPriority, int rightPriority);

	/**
	* Arranges the operators on the operator stack as per their priority.
	*
	* @param[in]     token     Current Expression Node.
	* @return		 Returns true if execution was successful else returns false. 
	*/
	bool arrangeOperatorByPriority(Expr_Node * token);

	/**
	* Set of operations that need to be performed when the incoming token is a closed paranthesis.
	*
	* @return		 Returns true if execution was successful else returns false. 
	*/
	bool evaluateClosedParanthesisNode();

	/**
	* Set of operations that need to be performed when the input expression is parsed and 
	* there are operators still pending on the operator stack.
	*
	* @return		 Returns true if execution was successful else returns false. 
	*/
	bool evaluateRemainingStackItems();

	/**
	* Returns the created tree
	*
	* @return          Reference to tree
	*/
	Expr_Node * get_expression (void);

	/**
	* Returns the expression stack
	*
	* @return          Reference to expression stack
	*/
	virtual Stack<Expr_Node*> get_expressionStack (void);

	/**
	* Returns the operator stack
	*
	* @return          Reference to operator stack
	*/
	virtual Stack<Expr_Node*> get_operatorStack (void);


private:
	// current state of expression tree
	Expr_Node * tree_;

	// tree expression node factory for creating factory objects.
	Tree_Expr_Node_Factory objTree_Expr_Node_Factory_;

	// other variables to coordinate build process
};

#endif   // !defined _EXPR_TREE_BUILDER_H_