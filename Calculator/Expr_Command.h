
//==============================================================================
/**
* @file       Expr_Command.h
*
* $Id: Expr_Command.h 819 2011-01-17 15:24:45Z hillj $
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _EXPR_COMMAND_H_
#define _EXPR_COMMAND_H_

#include <string>
#include <iostream>
#include <exception>
#include "Stack.h"          

/**
* @class Expr_Command
*
* Basic implementation of a Expr_Command.
*/

class Expr_Command 
{
public:

	/// Default constructor.
	Expr_Command (void);

	/// Destructor.
	~Expr_Command (void);

	/**
	* Pure virtual execute operation.
	*
	* @param[in]      s        Stack needed for execution.
	* @return				  Returns true if the execution was successful.
	*/
	virtual bool execute (Stack <int> & stack) = 0;
	
	/**
	* Pure virtual get string value of token operation.
	*
	* @return				  Returns string equivalent of the token value.
	*/
	virtual std::string getTokenValue() = 0;

	/**
	 * Pure virtual get token priority operation.
     *
     * @return				  Returns priority of the token.
     */
	virtual int getTokenPriority() = 0;

};

#endif   // !defined _EXPR_COMMAND_H_
