#include <string>
#include <iostream>
#include <exception>
#include "Expr_Command_Factory.h"

//
// Expr_Command_Factory
// Default Constructor.
//
Expr_Command_Factory :: Expr_Command_Factory () 
{

}

//
// ~Expr_Command_Factory
// Destructor for Expr_Command_Factory
//
Expr_Command_Factory:: ~Expr_Command_Factory () 
{


}


//
// Expr_Command_Factory
// Copy Constructor.
//
Expr_Command_Factory::Expr_Command_Factory(const Expr_Command_Factory &)
{


}



//
// operator=
// Copies the content of RHS Expr_Command_Factory object to the LHS Expr_Command_Factory object.
//
const Expr_Command_Factory &  Expr_Command_Factory::operator=(const Expr_Command_Factory &)
{
	return *this;
}