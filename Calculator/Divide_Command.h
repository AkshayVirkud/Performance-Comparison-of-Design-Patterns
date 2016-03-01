
//==============================================================================
/**
 * @file       Divide_Command.h
 *
 * $Id: Divide_Command.h 819 2011-01-17 15:24:45Z hillj $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _DIVIDE_COMMAND_H_
#define _DIVIDE_COMMAND_H_

#include <string>
#include <iostream>
#include <exception>
#include "Binary_Op_Command.h" 
/**
 * @class Divide_Command
 *
 * Basic implementation of a Add_Command.
 */
class Divide_Command : public  Binary_Op_Command
{
public:
  /// Default constructor.
  Divide_Command (void);

   /// Destructor.
  ~Divide_Command (void);

   /**
   * Implements the divide operation.
   *
   * @param[in]      n1        First Operand.
   * @param[in]      n2        Second operand
   * @return				  Returns the result of the divide operation.
   */
  int evaluate (int n1, int n2) const;

   /**
   * Gets the string value of the divide token.
   *
   * @return				  Returns string equivalent of the token value.
   */
  std::string getTokenValue();

   /**
   * Gets the token priority of divide command.
   *
   * @return				  Returns priority of the token.
   */
  int getTokenPriority();

};

#endif   // !defined _DIVIDE_COMMAND_H_
