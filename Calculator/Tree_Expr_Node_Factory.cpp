#include <string>
#include <iostream>
#include <exception>
#include "Tree_Expr_Node_Factory.h"

//
// Tree_Expr_Node_Factory
// Default Constructor.
//
Tree_Expr_Node_Factory :: Tree_Expr_Node_Factory()
{

}

//
// ~Tree_Expr_Node_Factory
// Destructor.
//
Tree_Expr_Node_Factory :: ~Tree_Expr_Node_Factory (void)
{

}

//
// create_number_node (int)
// Creates a  Number_Node having value that is passed as parameter.
//
Number_Node* Tree_Expr_Node_Factory ::create_number_node (int num)
{
	return new Number_Node(num);
}

//
// create_add_node()
// Creates an  Add node.
//
Addition_Node * Tree_Expr_Node_Factory ::create_add_node()
{
	return new Addition_Node();
}

//
// create_subtract_node()
// Creates a Subtract node.
//
Subtraction_Node * Tree_Expr_Node_Factory :: create_subtract_node()
{
	return new Subtraction_Node();
}

//
// create_multiplication_node()
// Creates a Multiply node.
//
Multiplication_Node * Tree_Expr_Node_Factory :: create_multiplication_node()
{
	return new Multiplication_Node();
}

//
// create_division_node()
// Creates a Division node.
//
Division_Node * Tree_Expr_Node_Factory :: create_division_node()
{
	return new Division_Node();
}

//
// create_modulus_node()
// Creates a Modulus node.
//
Modulus_Node * Tree_Expr_Node_Factory :: create_modulus_node()
{
	return new Modulus_Node();
}

//
// create_unary_node()
// Creates a Unary node.
//
Unary_Expr_Node * Tree_Expr_Node_Factory ::create_unary_node()
{
	return new Unary_Expr_Node();
}

//
// create_unary_node()
// Creates an Open Paranthesis node.
//
OpenParanthesis_Node * Tree_Expr_Node_Factory ::create_openParanthesis_node()
{
	return new OpenParanthesis_Node();
}