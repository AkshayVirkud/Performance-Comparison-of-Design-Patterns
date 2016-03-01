
//==============================================================================
/**
 * @file       Number_Command.h
 *
 * $Id: Number_Command.h 819 2011-01-17 15:24:45Z hillj $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _NUMBER_COMMAND_H_
#define _NUMBER_COMMAND_H_

#include <string>
#include <iostream>
#include <exception>
#include "Expr_Command.h" 
#include "Stack.h"  
/**
 * @class Number_Command
 *
 * Basic implementation of a Number_Command.
 */
class Number_Command : public  Expr_Command
{
public:
  /// Default constructor.
  Number_Command (void);

  /// Initializing constructor.
  Number_Command (int num);


   /// Destructor.
  ~Number_Command (void);


   /**
   * Execute operation for Number Command
   *
   * @param[in]      s        Stack needed for execution.
   * @return				  Returns true if the execution was successful.
   */
  bool execute (Stack <int> & s);

  /**
   * Gets the string value of the operand/number token.
   *
   * @return				  Returns string equivalent of the token value.
   */
  std::string getTokenValue();

  /**
   * Gets the token priority of operand/number command.
   *
   * @return				  Returns priority of the token.
   */
  int getTokenPriority();

  private:
	  int n_;

};

#endif   // !defined _NUMBER_COMMAND_H_
