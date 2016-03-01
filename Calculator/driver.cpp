#include <exception>
#include <cstdlib>
#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>
#include <ctime>
#include "Expr_Evaluator_Strategy.h"
#include "ExprTree_Evaluator_Strategy.h"
#include "Postfix_Flyweight_Evaluator_Strategy.h"
#include "Postfix_Flyweight_Performance_Evaluator_Strategy.h"
#include "Postfix_Evaluator_Strategy.h"

int main (int argc, char * argv [])
{
	std::string strategyNo;
	std::string strategyName;
	std::string expressionTypeFile;
	std::string isContinue = "yes";

	Expr_Evaluator_Strategy *objExprEvaluatorStrategy;


	while(isContinue == "yes")
	{

		std::cout<<"Select the strategy no. that you wish to implement  \n1 : Postfix  \n2 : Postfix - Flyweight \n3 : Postfix - Flyweight and Performance For Add \n4 : Tree \nEnter Strategy No  :";
		std::getline(std::cin, strategyNo); 

		if(strategyNo == "1")
		{
			objExprEvaluatorStrategy = new Postfix_Evaluator_Strategy();
			strategyName = "Postfix Evaluator";
		}
		else if(strategyNo == "2")
		{
			objExprEvaluatorStrategy = new Postfix_Flyweight_Evaluator_Strategy();
			strategyName = "Postfix with Flyweight Evaluator";
		}
		else if(strategyNo == "3")
		{
			objExprEvaluatorStrategy = new Postfix_Flyweight_Performance_Evaluator_Strategy();
			strategyName = "Postfix with Flyweight and Performance Evaluator";
		}
		else if(strategyNo == "4")
		{
			objExprEvaluatorStrategy = new ExprTree_Evaluator_Strategy();
			strategyName = "Tree Evaluator";
		}
		else
		{
			std::cout<<"Invalid Strategy";
			system("pause");
			return 0;
		}

		std::cout<<"Enter input file name :";
		std::getline(std::cin, expressionTypeFile); 

		std::ifstream file(expressionTypeFile);
		std::string str;

		if(file.is_open())
		{
			clock_t start, stop;
			double totalTime;

			//record the start time stamp
			start = clock();

			int expressionCount = 0;
			while (std::getline(file, str))
			{
				int result = 0;
				expressionCount = expressionCount + 1;

				if(objExprEvaluatorStrategy->parseExpr(str, result))
				{
					std::cout << "The result = " <<result << "\n";
				}
			}

			delete objExprEvaluatorStrategy;

			//record the stop time stamp
			stop = clock();
			totalTime = 1000 * (stop - start) / (double)CLOCKS_PER_SEC;
			std::cout << "Total expressions = " <<expressionCount << "\n";
			std::cout << "The total execution time for " + strategyName +  "= " <<totalTime << "\n";
		}
		else
		{
			std::cout<<"Unable to open file.";
			system("pause");
			return 0;
		}

		std::cout << "Do you wish to check for another type of strategy ? (yes / no) : ";
		std::getline(std::cin, isContinue);
	}

	system("pause");

	return 0;

}
