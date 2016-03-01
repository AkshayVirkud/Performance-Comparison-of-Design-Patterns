//==============================================================================
/**
* @file       Stack_Expr_Command_Factory.h
*
* $Id: Stack_Expr_Command_Factory.h 819 2011-01-17 15:24:45Z hillj $
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#include <string>
#include <iostream>
#include <exception>
#include "Expr_Command_Factory.h"

/**
 * @class Stack_Expr_Command_Factory
 *
 * Basic implementation of a Stack_Expr_Command_Factory.
 */

class Stack_Expr_Command_Factory : public Expr_Command_Factory
{
	public :

	//constructor
	Stack_Expr_Command_Factory(void) ;

	//destructor
	virtual ~Stack_Expr_Command_Factory (void);

	/**
	* Method for creating Number_Command.
	*
	* @param[in]     num         The number value.
	* @return		 Newly created Number_Command. 
	*/
	virtual Number_Command * createNumberCommand (int num);

	/**
	* Method for creating Add_Command.
	*
	* @return		 Newly created Add_Command. 
	*/
	virtual Add_Command * createAddCommand (void);

	/**
	* Method for creating Subtract_Command.
	*
	* @return		 Newly created Subtract_Command. 
	*/
	virtual Subtract_Command * createSubtractCommand (void);

	/**
	* Method for creating Multiply_Command.
	*
	* @return		 Newly created Multiply_Command. 
	*/
	virtual Multiply_Command * createMultiplyCommand (void);

	/**
	* Method for creating Divide_Command.
	*
	* @return		 Newly created Divide_Command. 
	*/
	virtual Divide_Command * createDivideCommand (void);

	/**
	* Method for creating Modulus_Command.
	*
	* @return		 Newly created Modulus_Command. 
	*/
	virtual Modulus_Command * createModulusCommand (void);

	/**
	* Method for creating OpenParanthesis_Command.
	*
	* @return		 Newly created OpenParanthesis_Command.
	*/
	virtual OpenParanthesis_Command * createOpenparanthesisCommand (void);

	/**
	* Method for creating ClosedParanthesis_Command.
	*
	* @return		 Newly created ClosedParanthesis_Command. 
	*/
	virtual ClosedParanthesis_Command * createClosedparanthesisCommand (void);
};