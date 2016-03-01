#include <exception>
#include <cstring>          // for size_t definition
#include <cstdlib>
#include <iostream>
#include <ctype.h>
#include <sstream>
#include <string>
#include <stdexcept>
#include "Expr_Tree_Builder.h"
#include "Stack.h" 
#include "Expr_Builder.h" 
#include "ExprTree_Evaluator_Strategy.h"

//
// ExprTree_Evaluator_Strategy
// Default Constructor.
//
ExprTree_Evaluator_Strategy::ExprTree_Evaluator_Strategy()
{

}

//
// ~ExprTree_Evaluator_Strategy
// Destructor which is called when ExprTree_Evaluator_Strategy objects are destroyed (deallocated).
//
ExprTree_Evaluator_Strategy::~ExprTree_Evaluator_Strategy()
{

}

//
// parse_expr (const string,  int &)
// This method gets input string from the user and generate 
// expression tree using builder methods and finally evaluates it. 
//
bool ExprTree_Evaluator_Strategy::parseExpr (const std::string & infix, int &result)
{
	// Create a input stream parser
	std::istringstream input(infix); 

	// Current token in string/stream
	std::string token; 

	Expr_Tree_Builder objExprTreeBuilder;
	result = 0;

	bool isCurrentNodeOperator = false;

	bool isFirstNode = true;

	bool isPreviousNodeOperator = false;

	try
	{

		if(isValidInfixExpression(infix))
		{

			while (!input.eof ()) 
			{
				input >> token;

				isPreviousNodeOperator = isCurrentNodeOperator;

				if(isFirstNode)
				{
					if(token == "-")
					{
						token = "u";
					}

					isFirstNode = false;
				}

				if(checkOperator(token))
				{
					isCurrentNodeOperator = true;

					if(isPreviousNodeOperator == true && token == "-")
					{
						token = "u";
					}
				}
				else
				{
					isCurrentNodeOperator = false;
				}

				if(token == "%") objExprTreeBuilder.build_modulus_operand ();
				else if (token == "-") objExprTreeBuilder.build_subtract_operand();
				else if (token == "*") objExprTreeBuilder.build_multiply_operand();
				else if (token == "/") objExprTreeBuilder.build_divide_operand();
				else if (token == "+") objExprTreeBuilder.build_add_operand();
				else if (token == "u") objExprTreeBuilder.build_unary_operand();
				else if (token == "(") objExprTreeBuilder.build_openParanthesis_operand();
				else if (token == ")") objExprTreeBuilder.build_closedParanthesis_operand();
				else if (isNumber(token)) objExprTreeBuilder.build_number(stoi(token));
			}

			Expr_Node * expr_tree = objExprTreeBuilder.get_expression();
			Eval_Expr_Tree eval;

			expr_tree->accept (eval);
			result = eval.result ();

			delete expr_tree;


		}
	}
	catch (std::exception & e)
	{
		Stack<Expr_Node*> operatorStack = objExprTreeBuilder.get_operatorStack();
		Stack<Expr_Node*> expressionStack = objExprTreeBuilder.get_expressionStack();

		while(!operatorStack.is_empty())
		{
			Expr_Node* tempNode = operatorStack.top();
			operatorStack.pop();
			delete tempNode;
		}

		while(!expressionStack.is_empty())
		{
			Expr_Node* tempNode = expressionStack.top();
			expressionStack.pop();
			delete tempNode;
		}

		std::cout << "Following Error Occurred : " << e.what() << "\n";

		return false;
	}

	return true;
}

