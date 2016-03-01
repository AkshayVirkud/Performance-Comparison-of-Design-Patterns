//==============================================================================
/**
* @file       Tree_Expr_Node_Factory.h
*
* $Id: Tree_Expr_Node_Factory.h 819 2011-01-17 15:24:45Z hillj $
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _TREE_EXPR_NODE_FACTORY_H_
#define _TREE_EXPR_NODE_FACTORY_H_

#include "Expr_Node_Factory.h"
#include "Addition_Node.h"
#include "Subtraction_Node.h"
#include "Number_Node.h"
#include "Modulus_Node.h"
#include "Division_Node.h"
#include "Multiplication_Node.h"

/**
* @class Tree_Expr_Node_Factory
*
* Basic implementation of a Tree Expression Node Factory.
*/

class Tree_Expr_Node_Factory : public Expr_Node_Factory
{
public :

	//constructor
	Tree_Expr_Node_Factory(void) ;

	//destructor
	virtual ~Tree_Expr_Node_Factory (void);

	/**
	* Method for creating Number node.
	*
	* @param[in]     num         The number value.
	* @return		 Newly created Number_Node. 
	*/
	virtual Number_Node * create_number_node (int num);

	/**
	* Method for creating Add node.
	* @return		 Newly created Addition_Node. 
	*/
	virtual Addition_Node * create_add_node ();

	/**
	* Method for creating Subtract node.
	* @return		 Newly created Subtraction_Node. 
	*/
	virtual Subtraction_Node * create_subtract_node ();

	/**
	* Method for creating Multiply node.
	* @return		 Newly created Multiplication_Node. 
	*/
	virtual Multiplication_Node * create_multiplication_node();

	/**
	* Method for creating Division node.
	* @return		 Newly created Division_Node. 
	*/
	virtual Division_Node * create_division_node();

	/**
	* Method for creating Modulus node.
	* @return		 Newly created Modulus_Node. 
	*/
	virtual Modulus_Node * create_modulus_node();

	/**
	* Method for creating Unary node
	* @return		 Newly created Unary_Expr_Node. 
	*/
	virtual Unary_Expr_Node * create_unary_node();

	/**
	* Method for creating Open Paranthesis node
	* @return		 Newly created OpenParanthesis_node.
	*/
	virtual OpenParanthesis_Node * create_openParanthesis_node();
};

#endif   // !defined _TREE_EXPR_NODE_FACTORY_H_