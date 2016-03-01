
//==============================================================================
/**
 * @file       Multiply_Command.h
 *
 * $Id: Multiply_Command.h 819 2011-01-17 15:24:45Z hillj $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _MULTIPLY_COMMAND_H_
#define _MULTIPLY_COMMAND_H_

#include <string>
#include <iostream>
#include <exception>
#include "Binary_Op_Command.h" 
/**
 * @class Multiply_Command
 *
 * Basic implementation of a Multiply_Command.
 */
class Multiply_Command : public  Binary_Op_Command
{
public:
  /// Default constructor.
  Multiply_Command (void);

   /// Destructor.
  ~Multiply_Command (void);

   /**
   * Implements the multiply operation.
   *
   * @param[in]      n1        First Operand.
   * @param[in]      n2        Second operand
   * @return				  Returns the result of the multiply operation.
   */
  int evaluate (int n1, int n2) const;

   /**
   * Gets the string value of the multiply token.
   *
   * @return				  Returns string equivalent of the token value.
   */
  std::string getTokenValue();

   /**
   * Gets the token priority of multiply command.
   *
   * @return				  Returns priority of the token.
   */
  int getTokenPriority();

};

#endif   // !defined _MULTIPLY_COMMAND_H_
