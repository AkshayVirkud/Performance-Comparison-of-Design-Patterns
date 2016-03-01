//==============================================================================
/**
* @file       Expr_Node_Visitor.h
*
* $Id: Expr_Node_Visitor.h 819 2011-01-17 15:24:45Z hillj $
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _EXPR_NODE_VISITOR_H_
#define _EXPR_NODE_VISITOR_H_

#include <string>
#include <iostream>
#include <exception>
#include "Binary_Expr_Node.h"
#include "Subtraction_Node.h"
#include "Addition_Node.h"
#include "Number_Node.h"
#include "Multiplication_Node.h"
#include "Division_Node.h"
#include "Modulus_Node.h"
#include "Unary_Expr_Node.h"

/**
* @class Expr_Node_Visitor
*
* Basic implementation of a Expression Node Visitor.
*/

class Expr_Node_Visitor {
public:
	/// Default constructor.
	Expr_Node_Visitor (void);

	/// Destructor.
	virtual ~Expr_Node_Visitor (void);

   /**
   * Visit operation for Addition_Node class.
   *
   * @param[in]       node      Input object type to decide which of the method is called.
   */
	virtual void Visit_Addition_Node (const Addition_Node & node) = 0;

   /**
   * Visit operation for Subtraction_Node class.
   *
   * @param[in]       node      Input object type to decide which of the method is called.
   */
	virtual void Visit_Subtraction_Node (const Subtraction_Node & node)= 0;

   /**
   * Visit operation for Number_Node class.
   *
   * @param[in]       node      Input object type to decide which of the method is called.
   */
	virtual void Visit_Number_Node (const Number_Node & node)= 0;

   /**
   * Visit operation for Multiplication_Node class.
   *
   * @param[in]       node      Input object type to decide which of the method is called.
   */
	virtual void Visit_Multiplication_Node (const Multiplication_Node & node)= 0;

   /**
   * Visit operation for Division_Node class.
   *
   * @param[in]       node      Input object type to decide which of the method is called.
   */
	virtual void Visit_Division_Node (const Division_Node & node)= 0;

   /**
   * Visit operation for Modulus_Node class.
   *
   * @param[in]       node      Input object type to decide which of the method is called.
   */
	virtual void Visit_Modulus_Node (const Modulus_Node & node)= 0;

   /**
   * Visit operation for Unary_Node class.
   *
   * @param[in]       node      Input object type to decide which of the method is called.
   */
	virtual void Visit_Unary_Node (const Unary_Expr_Node & node)= 0;
};

#endif   // !defined Expr_Node_Visitor