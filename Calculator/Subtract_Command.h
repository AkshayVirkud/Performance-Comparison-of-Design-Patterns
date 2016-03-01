
//==============================================================================
/**
 * @file       Subtract_Command.h
 *
 * $Id: Subtract_Command.h 819 2011-01-17 15:24:45Z hillj $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _SUBTRACT_COMMAND_H_
#define _SUBTRACT_COMMAND_H_

#include <string>
#include <iostream>
#include <exception>
#include "Binary_Op_Command.h" 
/**
 * @class Subtract_Command
 *
 * Basic implementation of a Subtract_Command.
 */
class Subtract_Command : public  Binary_Op_Command
{
public:
  /// Default constructor.
  Subtract_Command (void);

   /// Destructor.
  ~Subtract_Command (void);

  /**
   * Implements the subtract operation.
   *
   * @param[in]      n1        First Operand.
   * @param[in]      n2        Second operand
   * @return				  Returns the result of the add operation.
   */
  int evaluate (int n1, int n2) const;

  /**
   * Gets the string value of the subtract token.
   *
   * @return				  Returns string equivalent of the token value.
   */
  std::string getTokenValue();

  /**
   * Gets the token priority of subtract command.
   *
   * @return				  Returns priority of the token.
   */
  int getTokenPriority();
};

#endif   // !defined _SUBTRACT_COMMAND_H_
