#include <exception>
#include <cstdlib>
#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include <vector>
#include <fstream>
#include "Input_Generator.h"

//
// Input_Generator
// Default Constructor.
//
Input_Generator::Input_Generator()
{

}

//
// Input_Generator
// Destructor which is called when Input_Generator objects are destroyed (deallocated).
//
Input_Generator::~Input_Generator()
{

}

//
// generateInputExpressions
// Generates input expressions as per the type entered by user.
//
bool Input_Generator::generateInputExpressions()
{
	std::string expressionType;
	std::string operators[] = { "+", "-", "*", "/", "%" };
	std::string inputExpression;
	std::string shouldContinue = "yes";
	std::string inputFileName = "";
	std::string expressionsCount;
	int expressiontypeCount = 0;

	try
	{
		while (shouldContinue != "no")
		{
			expressiontypeCount = expressiontypeCount + 1;
			expressionType = "";
			std::cout << "Enter the total no. of expressions that you wish to create :";
			std::getline(std::cin, expressionsCount);
			std::cout << "Enter expression type using a combination of 'operator' , 'number', + , '(' and ')' : \n";
			std::getline(std::cin, expressionType);
			std::cout << "Enter the name of the input file : \n";
			std::getline(std::cin, inputFileName);

			// Create a input stream parser
			std::istringstream input(expressionType);

			std::string token = "";
			std::vector<std::string> stringList;

			// Add all the tokens to a string list.
			while (!input.eof())
			{
				input >> token;
				stringList.push_back(token);
			}

			// Create a file and write all the input expresiion to that file.
			std::ofstream inputFile(inputFileName);
			if (inputFile.is_open())
			{
				for (int i = 1; i <= std::stoi(expressionsCount); i++)
				{
					inputExpression = "";

					for (std::vector<std::string>::iterator it = stringList.begin(); it != stringList.end(); ++it)
					{
						if (*it == "operator")
						{
							int operatorIndex = rand() % 5;
							inputExpression = inputExpression + operators[operatorIndex];
						}
						if (*it == "number")
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

						// After each token (number / operator) insert space. 
						// However do not insert space at the end of expression.
						if ((it + 1) != stringList.end())
						{
							inputExpression = inputExpression + " ";
						}

					}
					std::cout << inputExpression + "\n";
					inputFile << inputExpression << std::endl;
				}

				inputFile.close();
			}
			else std::cout << "Unable to open file";

			std::cout << "Do you wish to generate another type of expression input file (yes / no) : ";
			std::getline(std::cin, shouldContinue);
		}
	}
	catch (std::exception & e)
	{
		std::cout << "Following Error Occurred : " << e.what() << "\n";
	}
	return true;
}
