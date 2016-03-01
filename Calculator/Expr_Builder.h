//==============================================================================
/**
* @file       Expr_Builder.h
*
* $Id: Expr_Builder.h 819 2011-01-17 15:24:45Z hillj $
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _EXPR_BUILDER_H_
#define _EXPR_BUILDER_H_

#include <string>
#include <iostream>
#include <exception>
#include "Binary_Expr_Node.h"
#include "Subtraction_Node.h"
#include "Addition_Node.h"
#include "Number_Node.h"
#include "Stack.h"
#include"Unary_Expr_Node.h"

/**
* @class Expr_Builder
*
* Basic implementation of a Expression Builder
*/


class Expr_Builder {
public:

	//constructor
	Expr_Builder (void);

	//destructor
	virtual ~Expr_Builder (void);

	/**
	* Abstract Implementation of build expression method.
	*
	*/
	virtual void build_expression (void)= 0;

	/**
	* Abstract Implementation of build number method.
	* @param[in]      n        value of the number node.
	*/
	virtual void build_number (int n) = 0;

	/**
	* Abstract Implementation of build add operand method.
	*
	*/
	virtual void build_add_operand (void) = 0;

	/**
	* Abstract Implementation of build subtract operand method.
	*
	*/
	virtual void build_subtract_operand (void) = 0;

	/**
	* Abstract Implementation of build multiply operand method.
	*
	*/
	virtual void build_multiply_operand (void) = 0;

	/**
	* Abstract Implementation of build divide operand method.
	*
	*/
	virtual void build_divide_operand (void) = 0;

	/**
	* Abstract Implementation of build modulus operand method.
	*
	*/
	virtual void build_modulus_operand (void) = 0;

	/**
	* Abstract Implementation of build openParanthesis method.
	*
	*/
	virtual void build_openParanthesis_operand (void) = 0;

	/**
	* Abstract Implementation of build closedParanthesis method.
	*
	*/
	virtual void build_closedParanthesis_operand (void)= 0;


	/**
	* Abstract Implementation of build unary operand method.
	*
	*/
	virtual void build_unary_operand (void) = 0;

	// get the current expression
	virtual Expr_Node * get_expression (void) = 0;

	// get expression stack.
	virtual Stack<Expr_Node*> get_expressionStack (void) = 0;

	// get operator stack.
	virtual Stack<Expr_Node*> get_operatorStack (void) = 0;

protected:
	// Stack for storing expressions while creating tree.
	Stack<Expr_Node*> expression_stack_;

	// Stack for storing expressions while creating tree.
	Stack<Expr_Node*> operator_stack_;
};

#endif   // !defined Expr_Builder