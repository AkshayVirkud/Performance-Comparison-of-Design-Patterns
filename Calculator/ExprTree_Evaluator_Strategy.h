//==============================================================================
/**
* @file       ExprTree_Evaluator_Strategy.h
*
* $Id: ExprTree_Evaluator_Strategy.h 819 2011-01-17 15:24:45Z hillj $
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _EXPRTREE_EVALUATOR_STRATEGY_H_
#define _EXPRTREE_EVALUATOR_STRATEGY_H_

#include <string>
#include <iostream>
#include <exception>
#include "Expr_Node_Factory.h"
#include "Array.h"
#include "Binary_Expr_Node.h"
#include "Subtraction_Node.h"
#include "Addition_Node.h"
#include "Number_Node.h"
#include "Eval_Expr_Tree.h"
#include "Expr_Evaluator_Strategy.h"

/**
* @class ExprTree_Evaluator_Strategy
*
* Basic implementation of a ExprTree_Evaluator_Strategy.
*/

class ExprTree_Evaluator_Strategy : public Expr_Evaluator_Strategy
{
public:
	/// Default constructor.
	ExprTree_Evaluator_Strategy (void);

	/// Destructor.
	virtual ~ExprTree_Evaluator_Strategy (void);

	/**
	* Takes an infix expression and converts it to tree expression using builder methods and evaluates it.
	*
	* @param[in]     infix       The infix string.
	* @param[in]     result      result of the evaluation.
	* @return			Returns true if the parsing was successful.
	*/
	virtual bool parseExpr (const std::string & infix, int &result);

};

#endif   // !defined _EXPRTREE_EVALUATOR_STRATEGY_H_
