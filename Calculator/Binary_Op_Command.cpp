#include <string>
#include <iostream>
#include <exception>
#include "Binary_Op_Command.h"
#include "Stack.h"  
#include "Expr_Command.h"

//
// Add_Command
// Default Constructor.
//
Binary_Op_Command :: Binary_Op_Command()
{

}

//
// ~Add_Command
// Destructor which is called when AddCommand objects are destroyed (deallocated).
//
Binary_Op_Command:: ~Binary_Op_Command()
{

}



//
// execute(Stack<int>)
// It pops top two operands from the stack, evaluates them and and pushes the result back on stack.
//

bool Binary_Op_Command:: execute (Stack <int> & s)
{
	int n2 = s.top (); 
	s.pop();
	int n1 = s.top ();
	s.pop();
	int result = this->evaluate (n1, n2);
	s.push (result);
	return true;

}