//==============================================================================
/**
* @file       Input_Generator.h
*
* $Id: Input_Generator.h 819 2011-01-17 15:24:45Z hillj $
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
#include "Array.h"
#include "Expr_Command.h"
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"
#include "Modulus_Command.h"
#include "OpenParanthesis_Command.h"
#include "ClosedParanthesis_Command.h"
#include "Number_Command.h"


/**
* @class Input_Generator
*
* Basic implementation of a InfixToPostFix.
*/

class Input_Generator
{
public:

	/// Default constructor.
	Input_Generator(void);

	/// Destructor.
	~Input_Generator(void);

	bool generateInputExpressions(void);

};