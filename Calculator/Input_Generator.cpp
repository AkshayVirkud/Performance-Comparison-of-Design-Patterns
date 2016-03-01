#include <exception>
#include <cstdlib>
#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include <vector>
#include <fstream>
#include "Input_Generator.h"

Input_Generator::Input_Generator()
{

}

Input_Generator::~Input_Generator()
{

}


bool Input_Generator::generateInputExpressions()
{
	std::string expressionType;
	std::string operators[] = { "+", "-", "*", "/", "%" };
	std::string inputExpression;
	std::string shouldContinue = "yes";
	std::string inputFileName = "";
	std::string expressionsCount;
	int expressiontypeCount = 0;

	while (shouldContinue != "no")
	{
		expressiontypeCount = expressiontypeCount + 1;
		expressionType = "";
		std::cout << "Enter the total no. of expressions that you wish to create :";
		std::getline(std::cin, expressionsCount);
		std::cout << "Enter expression type using a combination of 'op' , 'no' , '(' and ')' : \n";
		std::getline(std::cin, expressionType);
		std::cout << "Enter the name of the input file : \n";
		std::getline(std::cin, inputFileName);


		// Create a input stream parser
		std::istringstream input(expressionType);

		// Current token in string/stream
		std::string token = "";
		std::vector<std::string> stringList;


		while (!input.eof())
		{
			input >> token;
			stringList.push_back(token);
		}

		std::ofstream myfile(inputFileName + ".txt");
		if (myfile.is_open())
		{
			for (int i = 1; i <= std::stoi(expressionsCount); i++)
			{
				inputExpression = "";

				for (std::vector<std::string>::iterator it = stringList.begin(); it != stringList.end(); ++it)
				{
					if (*it == "op")
					{
						int operatorIndex = rand() % 5;
						inputExpression = inputExpression + operators[operatorIndex];
					}
					if (*it == "no")
					{
						int numberValue = rand() % 100 + 1;
						inputExpression = inputExpression + std::to_string(numberValue);
					}
					if (*it == "+")
					{
						inputExpression = inputExpression + "+";
					}
					if (*it == "(")
					{
						inputExpression = inputExpression + "(";
					}
					if (*it == ")")
					{
						inputExpression = inputExpression + ")";
					}

					if ((it + 1) != stringList.end())
					{
						inputExpression = inputExpression + " ";
					}
					
				}
				std::cout << inputExpression + "\n";
				myfile << inputExpression << std::endl;
			}

			myfile.close();
		}
		else std::cout << "Unable to open file";

		std::cout << "Do you wish to generate another type of expression input file (yes / no) : ";
		std::getline(std::cin, shouldContinue);
	}
	return true;
}
