#include <exception>
#include <cstdlib>
#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>
#include <ctime>
#include "Input_Generator.h"

int main (int argc, char * argv [])
{

	Input_Generator objInputGenerator;
	objInputGenerator.generateInputExpressions();

	system("pause");

	return 0;

}
