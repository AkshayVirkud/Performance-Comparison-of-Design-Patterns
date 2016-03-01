#include <exception>
#include <cstring>          // for size_t definition
#include <cstdlib>
#include <iostream>
#include <ctype.h>
#include <sstream>
#include <string>
#include <stdexcept>
#include "Stack_Expr_Command_Factory.h"
#include "Stack.h" 
#include "Postfix_Evaluator_Strategy.h"

//
// Postfix_Evaluator_Strategy
// Default Constructor.
//
Postfix_Evaluator_Strategy::Postfix_Evaluator_Strategy()
{

}

//
// ~Postfix_Evaluator_Strategy
// Destructor which is called when Postfix_Evaluator_Strategy objects are destroyed (deallocated).
//
Postfix_Evaluator_Strategy::~Postfix_Evaluator_Strategy()
{

}

//
// parse_expr (const string,  int &)
// This method gets input string from the user and evaluates it. 
//
bool Postfix_Evaluator_Strategy::parseExpr(const std::string & infix, int &result)
{
	Stack_Expr_Command_Factory factory;
	Array <Expr_Command *> postfix;
	Stack<int> integers;

	// Stores array size.
	size_t arraySize = 0;

	// Stores array start Index..
	size_t arrayStartIndex = 0;

	try
	{	
		convertInfixToPostfix(infix, factory, postfix);
		arraySize = postfix.size();

		for (size_t i = 0; i < postfix.size(); i++)
		{
			postfix[i] -> execute(integers);
			delete postfix[i];
			arraySize --;
			arrayStartIndex ++;
		}

		// Final result will be available on stack-top , so we 
		// take the stack-top value and pop the stack.
		// In case the stack is empty, it means that the expression was invalid.
		if(integers.is_empty())
		{
			throw std::runtime_error("Invalid Expression");
		}
		else
		{
			result = integers.top();
			integers.pop();
		}
		return true;
	}
	catch (std::exception & e)
	{
		std::cout << "Following Error Occurred : " << e.what() << "\n";

		// Delete all the array elements, starting from the array start index.
		size_t i = arrayStartIndex;
		if (arraySize != 0)
		{

			delete postfix[arrayStartIndex];

			arraySize--;
			arrayStartIndex++;
		}

		return false;
	}
}

//
// ConvertInfixToPostfix (string, Expr_Command_Factory,  Array <Expr_Command *>)
// This method converts the infix string into an array of postfix commands. 
// The Expr_Command_Factory is used for creating the commands. 
//
bool Postfix_Evaluator_Strategy :: convertInfixToPostfix (const std::string & infix, Expr_Command_Factory & factory, Array <Expr_Command *> & postfix)
{
	// Create a input stream parser
	std::istringstream input(infix); 

	// Current token in string/stream
	std::string token; 

	// Created command object
	Expr_Command * cmd = 0; 

	// Temporary stack for storing expression commands 
	Stack <Expr_Command *> temp;

	size_t arrSize = 0;

	if (isValidInfixExpression(infix))
	{

		while (!input.eof ()) 
		{
			// Akshay, many of your checks below can be methods on the command. Right now, the
			// checks are tightly coupled to the supported operations. In essense, you are
			// implemented the same problem with your checks that we actually overcome with
			// executing each operation. Please fix this design.

			// Dr. Hill, I have changed the design. Now instead of using two stacks, I am using method
			// getTokenValue that gets the command-token value which is a pure virtual method on the Expr_Command.
			// Thus the checks are not tightly coupled to the supported operations.  

			input >> token;

			// If the token is an operand, create number command and insert it in the postfix array.
			if(isNumber(token))
			{
				int numToken =  stoi(token);
				cmd = factory.createNumberCommand(numToken);
				arrSize = postfix.size();
				postfix.resize(arrSize + 1);
				postfix.set(arrSize, cmd);

			}
			// If the token is an open paranthesis, create an open paranthesis command and push it on the temporary stack.
			else if (token == "(")
			{
				cmd = factory.createOpenparanthesisCommand ();
				temp.push(cmd);
			}
			// If the token is an operator, check if the top of the stack has higher priority than the current (token) operator.
			// If the pririty is high, pop the stack till the stack is empty or till one encounters an open paranthesis and then
			// create a command corresponding to the operator and push it on the temporary stack.
			else if(checkOperator(token))
			{
				std::string rightOperator = token;
				int rightOperatorPriority = getOperatorPriority(token);
				while(!temp.is_empty() && checkOperator(temp.top()->getTokenValue()) && checkPriority(temp.top()->getTokenPriority(), rightOperatorPriority) && !("(" == token))
				{
					arrSize = postfix.size();
					postfix.resize(arrSize + 1);
					postfix.set(arrSize, temp.top());
					temp.pop();
				}
				if (token == "%")
					cmd = factory.createModulusCommand ();
				else if (token == "-")
					cmd = factory.createSubtractCommand ();
				else if (token == "*")
					cmd = factory.createMultiplyCommand ();
				else if (token == "/")
					cmd = factory.createDivideCommand ();
				else if (token == "+")
					cmd = factory.createAddCommand ();
				temp.push(cmd);
			}
			//If the token is a close paranthesis, keep popping the stack till we encounter an open paranthesis or till stack is empty.
			else if(")" == token) 
			{

				while(!temp.is_empty() && "(" != temp.top()->getTokenValue()) 
				{
					arrSize = postfix.size();
					postfix.resize(arrSize + 1);
					postfix.set(arrSize, temp.top());
					temp.pop();
				}
				// Pop that paranthesis and delete it.
				Expr_Command * tempCmd = temp.top();
				temp.pop();
				delete tempCmd;
			}
			// If none of the above conditions satisfy, it means there is some invalid token in the expression
			// or the expression itself is not valid.
			else
			{
				// Clear all the contents of the stack and then throw Invalid Expression exception.
				while(!temp.is_empty())
				{
					Expr_Command * tempCmd = temp.top();
					temp.pop();
					delete tempCmd;
				}
				throw std::runtime_error("Invalid Expression.");
			}


		}


		// After the entire infix string has been parsed successfully, pop all the items from the 
		// temp stack and add them to the postfix array.
		while(!temp.is_empty())
		{
			size_t arrSize = postfix.size();
			postfix.resize(arrSize + 1);
			postfix.set(arrSize, temp.top());

			temp.pop();
		}

		return true;
	}
	else
	{
		throw std::runtime_error("Invalid Expression");
	}
}

//
// GetOperatorPriority (string)
// Determines the priority for an operand.
//
int Postfix_Evaluator_Strategy :: getOperatorPriority(std::string objOperator)
{

	// Operators * , / and % will have a higher priority and hence assigned the value 2
	// and operators + and - have low priority and therefore their priority is 1.

	int priority = 0; 
	if((objOperator == "*" ) || (objOperator == "/" ) || (objOperator == "%" ))
	{
		priority = 2;
	}
	else if((objOperator == "+" )|| (objOperator == "-" ))
	{
		priority = 1;
	}

	return priority;
}
