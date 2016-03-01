//==============================================================================
/**
* @file       Postfix_Evaluator_Strategy.h
*
* $Id: Postfix_Evaluator_Strategy.h 819 2011-01-17 15:24:45Z hillj $
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _POSTFIX_EVALUATOR_STRATEGY_H_
#define _POSTFIX_EVALUATOR_STRATEGY_H_

#include <string>
#include <iostream>
#include <exception>
#include "Expr_Command_Factory.h"
#include "Array.h"
#include "Expr_Command.h"
#include "Expr_Evaluator_Strategy.h"
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"
#include "Modulus_Command.h"
#include "OpenParanthesis_Command.h"
#include "ClosedParanthesis_Command.h"
#include "Number_Command.h"

/**
* @class Postfix_Evaluator_Strategy
*
* Basic implementation of a Postfix_Evaluator_Strategy.
*/

class Postfix_Evaluator_Strategy : public Expr_Evaluator_Strategy
{
public:
	/// Default constructor.
	Postfix_Evaluator_Strategy (void);

	/// Destructor.
	virtual ~Postfix_Evaluator_Strategy (void);

	/**
	* Takes an infix expression and converts it to postfix expression and evaluates it.
	*
	* @param[in]     infix       The infix string.
	* @param[in]     result      result of the evaluation.
	* @return		  Returns true if the parsing was successful.
	*/
	virtual bool parseExpr (const std::string & infix, int &result);

	/**
	* Converts an infix expression to postfix.
	*
	* @param[in]     infix       The infix string
	* @param[in]     factory     The factory for creating commands.
	* @param[in]     postfix     The infix string converted to postfix array of commands.
	* @return		  Returns true if the execution was successful.
	*/
	virtual bool convertInfixToPostfix (const std::string & infix,
		Expr_Command_Factory & factory,
		Array <Expr_Command *> & postfix);

	/**
	* Calculates the operator priority.
	*
	* @param[in]     objOperator     operator
	* @return		 Priority for the operator. 
	*/
	virtual int getOperatorPriority(std::string objOperator);

};

#endif   // !defined _POSTFIX_EVALUATOR_STRATEGY_H_
