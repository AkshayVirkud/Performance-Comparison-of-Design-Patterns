//==============================================================================
/**
* @file       Expr_Evaluator_Strategy.h
*
* $Id: Expr_Evaluator_Strategy.h 819 2011-01-17 15:24:45Z hillj $
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _EXPR_EVALUATOR_STRATEGY_H_
#define _EXPR_EVALUATOR_STRATEGY_H_

#include <string>
#include <iostream>
#include <exception>

/**
* @class Expr_Evaluator_Strategy
*
* Basic implementation of a Expr_Evaluator_Strategy.
*/

class Expr_Evaluator_Strategy 
{
public:
	/// Default constructor.
	Expr_Evaluator_Strategy (void);

	/// Destructor.
	virtual ~Expr_Evaluator_Strategy (void);

	/**
	* Used to travese the tree.
	*
	* @param[in]     infix     infix string
	* @param[in]     result    evaluation result
	* @return		 Returns true if the parsing was success else returns false. 
	*/
	virtual bool parseExpr (const std::string & infix, int &result) = 0;

	/**
	* Checks whether the infix expression is valid.
	*
	* @param[in]     infixExpression     infix string
	* @return		 Returns true if expression is valid else returns false. 
	*/
	virtual bool isValidInfixExpression(std::string infixExpression);

	/**
	* Checks whether the token is a number.
	*
	* @param[in]     operand     input token
	* @return		 Returns true if the token is a number else returns false. 
	*/
	virtual bool isNumber(std::string operand);

	/**
	* Checks whether the token is an operator.
	*
	* @param[in]     objString     input token
	* @return		 Returns true if the token is an operator else returns false. 
	*/
	virtual bool checkOperator(std::string objString);

	/**
	* Checks for higher priority operator.
	*
	* @param[in]     leftPriority     LHS operator
	* @param[in]     rightPriority    RHS operator
	* @return		 Returns true if the LHS operator has higher priority else returns false. 
	*/
	virtual bool checkPriority(int leftPriority, int rightPriority);

};

#endif   // !defined _EXPR_EVALUATOR_STRATEGY_H_
