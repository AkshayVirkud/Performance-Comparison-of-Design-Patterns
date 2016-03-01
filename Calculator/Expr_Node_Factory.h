//==============================================================================
/**
* @file       Expr_Node_Factory.h
*
* $Id: Expr_Node_Factory.h 819 2011-01-17 15:24:45Z hillj $
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _EXPR_NODE_FACTORY_H_
#define _EXPR_NODE_FACTORY_H_

#include "Addition_Node.h"
#include "Subtraction_Node.h"
#include "Number_Node.h"
#include "Multiplication_Node.h"
#include "Division_Node.h"
#include "Modulus_Node.h"
#include "Unary_Expr_Node.h"
#include "OpenParanthesis_Node.h"

/**
* @class Expr_Node_Factory
*
* Basic implementation of a Expr_Node_Factory.
*/

class Expr_Node_Factory 
{

public:

	//constructor
	Expr_Node_Factory (void);

	//destructor
	virtual ~Expr_Node_Factory (void);

	/**
	* Pure virtual method for creating Number_Node.
	*
	* @param[in]     num         The number value
	* @return		 Newly created Number_Node. 
	*/
	virtual Number_Node * create_number_node (int n1) = 0;

	/**
	* Pure virtual method for creating Addition_Node.
	*
	* @return		 Newly created Addition_Node. 
	*/
	virtual Addition_Node * create_add_node () = 0;

	/**
	* Pure virtual method for creating Subtraction_Node.
	*
	* @return		 Newly created Subtraction_Node. 
	*/
	virtual Subtraction_Node * create_subtract_node () = 0;

	/**
	* Pure virtual method for creating Multiplication_Node.
	*
	* @return		 Newly created Multiplication_Node. 
	*/
	virtual Multiplication_Node * create_multiplication_node () = 0;

	/**
	* Pure virtual method for creating Division_Node.
	*
	* @return		 Newly created Division_Node. 
	*/
	virtual Division_Node * create_division_node () = 0;

	/**
	* Pure virtual method for creating Modulus_Node.
	*
	* @return		 Newly created Modulus_Node. 
	*/
	virtual Modulus_Node * create_modulus_node () = 0;

	/**
	* Pure virtual method for creating Unary_Expr_Node.
	*
	* @return		 Newly created Unary_Expr_Node. 
	*/
	virtual Unary_Expr_Node * create_unary_node () = 0;

	/**
	* Pure virtual method for creating open paranthesis node
	*
	* @return		 Newly created openParanthesis_node.
	*/
	virtual OpenParanthesis_Node * create_openParanthesis_node () = 0;

private:
	// prevent the following operations
	Expr_Node_Factory (const Expr_Node_Factory &);
	const Expr_Node_Factory & operator = (const Expr_Node_Factory &);

};

#endif   // !defined Expr_Node_Factory