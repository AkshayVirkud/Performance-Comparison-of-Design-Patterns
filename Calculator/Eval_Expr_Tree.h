//==============================================================================
/**
* @file       Eval_Expr_Tree.h
*
* $Id: Eval_Expr_Tree.h 819 2011-01-17 15:24:45Z hillj $
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _EVAL_EXPR_TREE_H_
#define _EVAL_EXPR_TREE_H_

#include <string>
#include <iostream>
#include <exception>
#include <stdexcept>
#include "Binary_Expr_Node.h"
#include "Subtraction_Node.h"
#include "Addition_Node.h"
#include "Number_Node.h"
#include "Multiplication_Node.h"
#include "Division_Node.h"
#include "Modulus_Node.h"
#include "Expr_Node_Visitor.h"
#include "Unary_Expr_Node.h"

/**
* @class Expr_Node_Visitor
*
* Basic implementation of a Add Expression Node.
*/

class Eval_Expr_Tree : public Expr_Node_Visitor {
public:
	/// Default constructor.
	Eval_Expr_Tree (void);

	/// Destructor.
	virtual ~Eval_Expr_Tree (void);

   /**
   * Method for visiting concrete addition node
   *
   * @param[in]       node      Input object type to decide which of the method is called.
   */
	virtual void Visit_Addition_Node (const Addition_Node & node);

   /**
   * Method for visiting concrete subtraction node
   *
   * @param[in]       node      Input object type to decide which of the method is called.
   */
	virtual void Visit_Subtraction_Node (const Subtraction_Node & node);

   /**
   * Method for visiting concrete number node
   *
   * @param[in]       node      Input object type to decide which of the method is called.
   */
	virtual void Visit_Number_Node (const Number_Node & node);

   /**
   * Method for visiting concrete multiplication node
   *
   * @param[in]       node      Input object type to decide which of the method is called.
   */
	virtual void Visit_Multiplication_Node (const Multiplication_Node & node);

   /**
   * Method for visiting concrete division node
   *
   * @param[in]       node      Input object type to decide which of the method is called.
   */
	virtual void Visit_Division_Node (const Division_Node & node);

   /**
   * Method for visiting concrete modulus node
   *
   * @param[in]       node      Input object type to decide which of the method is called.
   */
	virtual void Visit_Modulus_Node (const Modulus_Node & node);

   /**
   * Method for visiting concrete unary node
   *
   * @param[in]       node      Input object type to decide which of the method is called.
   */
	virtual void Visit_Unary_Node (const Unary_Expr_Node & node);

   /**
   * Provides computation result.
   *
   * @return				  Returns the result of the operation.
   */
	int result (void) const;

private:
	int result_;
};

#endif   // !defined _EVAL_EXPR_TREE_H_