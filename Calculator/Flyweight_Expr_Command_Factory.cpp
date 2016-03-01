#include <string>
#include <iostream>
#include <exception>
#include "Flyweight_Expr_Command_Factory.h"

//
// Flyweight_Expr_Command_Factory
// Default Constructor.
//
Flyweight_Expr_Command_Factory ::Flyweight_Expr_Command_Factory(void):
	add_(0),
	closedParanthesis_(0),
	divide_(0),
	modulus_(0),
	multiply_(0),
	openParanthesis_(0),
	subtract_(0)
{

}

//
// ~Flyweight_Expr_Command_Factory
// Destructor.
//
Flyweight_Expr_Command_Factory :: ~Flyweight_Expr_Command_Factory (void)
{
	if(this->add_ != 0)
		delete this->add_;
	if(this->closedParanthesis_ != 0)
		delete this->closedParanthesis_;
	if(this->divide_ != 0)
		delete this->divide_;
	if(this->modulus_ != 0)
		delete this->modulus_;
	if(this->multiply_ != 0)
		delete this->multiply_;
	if(this->openParanthesis_ != 0)
		delete this->openParanthesis_;
	if(this->subtract_ != 0)
		delete this->subtract_;
}

//
// createNumberCommand (int)
// Creates a  Number_Command having value that is passed as parameter.
//
Number_Command* Flyweight_Expr_Command_Factory :: createNumberCommand (int num)
{
	return new Number_Command(num);
}

//
// createAddCommand
// Creates an  Add Command.
//
Add_Command * Flyweight_Expr_Command_Factory :: createAddCommand (void)
{
	if(this->add_ == 0)
	{
		this-> add_ = new Add_Command(); 
	}
	return this->add_;
}

//
// createSubtractCommand
// Creates a Subtract Command.
//
Subtract_Command * Flyweight_Expr_Command_Factory :: createSubtractCommand (void)
{
	if(this->subtract_ == 0)
	{
		this-> subtract_ = new Subtract_Command(); 
	}
	return this->subtract_;
}

//
// createMultiplyCommand
// Creates a Multiply Command.
//
Multiply_Command * Flyweight_Expr_Command_Factory :: createMultiplyCommand (void)
{
	if(this->multiply_ == 0)
	{
		this-> multiply_ = new Multiply_Command(); 
	}
	return this->multiply_;
}

//
// createDivideCommand
// Creates a Divide Command.
//
Divide_Command * Flyweight_Expr_Command_Factory :: createDivideCommand (void)
{
	if(this->divide_ == 0)
	{
		this-> divide_ = new Divide_Command();
	}
	return this->divide_;
}

//
// createModulusCommand
// Creates a Modulus Command.
//
Modulus_Command * Flyweight_Expr_Command_Factory :: createModulusCommand (void)
{
	if(this->modulus_ == 0)
	{
		this-> modulus_ = new Modulus_Command(); 
	}
	return this->modulus_;
}

//
// createOpenparanthesisCommand
// Creates an Open Paranthesis Command.
//
OpenParanthesis_Command * Flyweight_Expr_Command_Factory :: createOpenparanthesisCommand (void)
{
	if(this->openParanthesis_ == 0)
	{
		this-> openParanthesis_ = new OpenParanthesis_Command(); 
	}
	return this->openParanthesis_;
}

//
// createClosedparanthesisCommand
// Creates an Close Paranthesis Command.
//
ClosedParanthesis_Command * Flyweight_Expr_Command_Factory :: createClosedparanthesisCommand (void)
{
	if(this->closedParanthesis_ == 0)
	{
		this-> closedParanthesis_ = new ClosedParanthesis_Command(); 
	}
	return this->closedParanthesis_;
}
