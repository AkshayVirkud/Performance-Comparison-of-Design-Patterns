//==============================================================================
/**
* @file       Input_Generator.h
*
* $Id: Input_Generator.h 819 2011-01-17 15:24:45Z hillj $
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _INPUT_GENERATOR_H_
#define _INPUT_GENERATOR_H_

#include <string>
#include <iostream>
#include <exception>

/**
* @class Input_Generator
*
* Basic implementation of a Input_Generator.
*/

class Input_Generator
{
public:

	/// Default constructor.
	Input_Generator(void);

	/// Destructor.
	~Input_Generator(void);

	/**
	* Generates input expressions as per the type entered by user.
	*
	* @return		Returns true if the generation was successful.
	*/
	bool generateInputExpressions(void);

};

#endif   // !defined _INPUT_GENERATOR_H_