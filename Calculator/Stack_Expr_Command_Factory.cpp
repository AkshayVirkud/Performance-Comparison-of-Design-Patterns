#include <string>
#include <iostream>
#include <exception>
#include "Stack_Expr_Command_Factory.h"

//
// Stack_Expr_Command_Factory
// Default Constructor.
//
Stack_Expr_Command_Factory :: Stack_Expr_Command_Factory()
{

}

//
// ~Stack_Expr_Command_Factory
// Destructor.
//
Stack_Expr_Command_Factory :: ~Stack_Expr_Command_Factory (void)
{

}

//
// createNumberCommand (int)
// Creates a  Number_Command having value that is passed as parameter.
//
Number_Command* Stack_Expr_Command_Factory :: createNumberCommand (int num)
{
	return new Number_Command(num);
}

//
// createAddCommand
// Creates an  Add Command.
//
Add_Command * Stack_Expr_Command_Factory :: createAddCommand (void)
{
	return new Add_Command();
}

//
// createSubtractCommand
// Creates a Subtract Command.
//
Subtract_Command * Stack_Expr_Command_Factory :: createSubtractCommand (void)
{
	return new Subtract_Command();
}

//
// createMultiplyCommand
// Creates a Multiply Command.
//
Multiply_Command * Stack_Expr_Command_Factory :: createMultiplyCommand (void)
{
	return new Multiply_Command();
}

//
// createDivideCommand
// Creates a Divide Command.
//
Divide_Command * Stack_Expr_Command_Factory :: createDivideCommand (void)
{
	return new Divide_Command();
}

//
// createModulusCommand
// Creates a Modulus Command.
//
Modulus_Command * Stack_Expr_Command_Factory :: createModulusCommand (void)
{
	return new Modulus_Command();
}

//
// createOpenparanthesisCommand
// Creates an Open Paranthesis Command.
//
OpenParanthesis_Command * Stack_Expr_Command_Factory :: createOpenparanthesisCommand (void)
{
	return new OpenParanthesis_Command();
}

//
// createClosedparanthesisCommand
// Creates an Close Paranthesis Command.
//
ClosedParanthesis_Command * Stack_Expr_Command_Factory :: createClosedparanthesisCommand (void)
{
	return new ClosedParanthesis_Command();
}
