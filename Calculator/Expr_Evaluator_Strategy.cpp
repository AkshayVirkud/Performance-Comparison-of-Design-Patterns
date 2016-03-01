#include <exception>
#include <cstring>          // for size_t definition
#include <cstdlib>
#include <iostream>
#include <ctype.h>
#include <sstream>
#include <string>
#include <stdexcept>
#include "Expr_Evaluator_Strategy.h"

//
// Expr_Evaluator_Strategy
// Default Constructor.
//
Expr_Evaluator_Strategy::Expr_Evaluator_Strategy()
{

}

//
// ~Expr_Evaluator_Strategy
// Destructor which is called when Expr_Evaluator_Strategy objects are destroyed (deallocated).
//
Expr_Evaluator_Strategy::~Expr_Evaluator_Strategy()
{

}

//
// isValidInfixExpression(string)
// checks whether the infix expression is valid or not.
//
bool Expr_Evaluator_Strategy::isValidInfixExpression(std::string infixExpression)
{
	// Create a input stream parser.
	std::istringstream input(infixExpression);

	// Keeps track if the previous token is a digit.
	bool isPrevNoDigit = false;

	// Keeps track if the current token is a digit.
	bool isCurrentNoDigit = false;

	// Stores count of open paranthesis in the infix string. 
	int totalOpenParanthesis = 0;

	// Stores count of close paranthesis in the infix string.
	int totalCloseParanthesis = 0;

	// If the expression length is less than 5, then it is an incomplete expression as even a simplest form of expression 
	// will be in the format : <number><blankspace><operator><blankspace><number>
	if (infixExpression.length() < 5)
	{
		throw std::runtime_error("invalid expression : expression is incomplete.");
	}

	// If the expression begins or ends with a blank space, it is an invalid expression.
	if (infixExpression[0] == ' ' || infixExpression[infixExpression.length() - 1] == ' ')
	{
		throw std::runtime_error(" invalid expression : expression should not begin or end with a blank space.");
	}

	for (size_t i = 0; i < infixExpression.length(); i++)
	{
		// If the expression has consecutive blank spaces, then it is an invalid expression.
		if (infixExpression[i] == ' ' && i < (infixExpression.length() - 1))
		{
			if (infixExpression[i + 1] == ' ')
				throw std::runtime_error("invalid expression : consecutive blank spaces present in the expression.");
		}

		// If Open Paranthesis is encountered while parsing expression, increment the Open Paranthesis counter by 1.
		if (infixExpression[i] == '(')
		{
			totalOpenParanthesis = totalOpenParanthesis + 1;
		}

		// If Close Paranthesis is encountered while parsing expression, increment the Close Paranthesis counter by 1.
		if (infixExpression[i] == ')')
		{
			totalCloseParanthesis = totalCloseParanthesis + 1;
		}

	}



	while (!input.eof())
	{
		// Current token in string/stream
		std::string token;

		input >> token;

		// Preserve the boolean value if the previous token was a number.
		isPrevNoDigit = isCurrentNoDigit;

		// If token is a number, then set the value of isCurrentNoDigit variable to true else set it to false.
		if (isNumber(token))
		{
			isCurrentNoDigit = true;
		}
		else
		{
			isCurrentNoDigit = false;
		}

		// If both current and previous number are valid numbers then it means that 
		// two operands are not separated by an operator resulting in an invalid expression.
		if (isPrevNoDigit && isCurrentNoDigit)
		{
			throw std::runtime_error("invalid expression : two operands are not separated by an operator.");
		}
	}

	// If the count of open paranthesis is greater than count of close paranthesis then expression is missing closed paranthesis. 
	if (totalOpenParanthesis > totalCloseParanthesis)
		throw std::runtime_error("invalid expression : missing closed parenthesis");

	// If the count of close paranthesis is greater than count of open paranthesis then expression is missing open paranthesis. 
	if (totalCloseParanthesis > totalOpenParanthesis)
		throw std::runtime_error(" invalid expression : missing open parenthesis");

	return true;
}

//
// isNumber (string)
// Determines whether the token is a valid decimal number.
//
bool Expr_Evaluator_Strategy:: isNumber(std::string operand)
{
	// If length of operand is one, check whether it is a single digit number.
	if(operand.length() == 1)
	{
		return isdigit(operand[0]) == 0 ? false : true;
	}
	// If length of operand is greater than one, then the first character of the operand can either be
	// a number or a -ve sign.
	else if(operand.length() > 1)
	{
		for(size_t i = 0; i < operand.length(); i++)
		{
			if(i == 0)
			{
				if (!(operand[i] == '-') && isdigit(operand[i]) == 0)
					return false;
			}
			else
			{
				if (isdigit(operand[i]) == 0)
					return false;
			}
		}
	}

	return true;
}

//
// checkOperator (string)
// This method checks if the given token is an operator. 
//
bool Expr_Evaluator_Strategy::checkOperator(std::string objString)
{
	if((objString == "+" )|| (objString == "-" ) || (objString == "*" )|| (objString == "/" )|| (objString == "%" )|| (objString == "u" ))
	{
		return true;
	}
	return false;
}

//
// checkPriority (int, int)
// Determines whether the left or the right operator has the higher priority.
//
bool Expr_Evaluator_Strategy::checkPriority(int leftPriority, int rightPriority)
{
	if(leftPriority >= rightPriority)
	{
		return true;
	}

	return false;
}

