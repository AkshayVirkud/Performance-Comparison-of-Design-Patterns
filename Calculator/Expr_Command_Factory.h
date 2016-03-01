
//==============================================================================
/**
* @file       Expr_Command_Factory.h
*
* $Id: Expr_Command_Factory.h 819 2011-01-17 15:24:45Z hillj $
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _EXPR_COMMAND_FACTORY_H_
#define _EXPR_COMMAND_FACTORY_H_

#include <string>
#include <iostream>
#include <exception>
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"
#include "Modulus_Command.h"
#include "OpenParanthesis_Command.h"
#include "ClosedParanthesis_Command.h"
#include "Number_Command.h"

/**
* @class Expr_Command_Factory
*
* Basic implementation of a Expr_Command_Factory.
*/

class Expr_Command_Factory 
{

public:

	//constructor
	Expr_Command_Factory (void);

	//destructor
	virtual ~Expr_Command_Factory (void) = 0;

	/**
	* Pure virtual method for creating Number_Command.
	*
	* @param[in]     num         The number value
	* @return		 Newly created Number_Command. 
	*/
	virtual Number_Command * createNumberCommand (int num) = 0;

	/**
	* Pure virtual method for creating Add_Command.
	*
	* @return		 Newly created Add_Command. 
	*/
	virtual Add_Command * createAddCommand (void) = 0;

	/**
	* Pure virtual method for creating Subtract_Command.
	*
	* @return		 Newly created Subtract_Command. 
	*/
	virtual Subtract_Command * createSubtractCommand (void) = 0;

	/**
	* Pure virtual method for creating Multiply_Command.
	*
	* @return		 Newly created Multiply_Command. 
	*/
	virtual Multiply_Command * createMultiplyCommand (void) = 0;

	/**
	* Pure virtual method for creating Divide_Command.
	*
	* @return		 Newly created Divide_Command. 
	*/
	virtual Divide_Command * createDivideCommand (void) = 0;

	/**
	* Pure virtual method for creating Modulus_Command.
	*
	* @return		 Newly created Modulus_Command 
	*/
	virtual Modulus_Command * createModulusCommand (void) = 0;

	/**
	* Pure virtual method for creating OpenParanthesis_Command.
	*
	* @return		 Newly created OpenParanthesis_Command 
	*/
	virtual OpenParanthesis_Command * createOpenparanthesisCommand (void) = 0;
	
	/**
	* Pure virtual method for creating ClosedParanthesis_Command.
	*
	* @return		 Newly created ClosedParanthesis_Command 
	*/
	virtual ClosedParanthesis_Command * createClosedparanthesisCommand (void) = 0;

private:
	// prevent the following operations
	Expr_Command_Factory (const Expr_Command_Factory &);
	const Expr_Command_Factory & operator = (const Expr_Command_Factory &);

};

#endif   // !defined _EXPR_COMMAND_FACTORY_H_