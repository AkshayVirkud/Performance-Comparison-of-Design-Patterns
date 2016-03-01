//==============================================================================
/**
 * @file       Add_Command.h
 *
 * $Id: Add_Command.h 819 2011-01-17 15:24:45Z hillj $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _ADD_COMMAND_H_
#define _ADD_COMMAND_H_

#include <string>
#include <iostream>
#include <exception>
#include "Binary_Op_Command.h"  

/**
 * @class Add_Command
 *
 * Basic implementation of a Add Command.
 */
class Add_Command : public  Binary_Op_Command
{
public:
  /// Default constructor.
  Add_Command (void);

   /// Destructor.
  ~Add_Command (void);

  /**
   * Implements the add operation.
   *
   * @param[in]      n1        First Operand.
   * @param[in]      n2        Second operand
   * @return				  Returns the result of the add operation.
   */
  int evaluate (int n1, int n2) const;

  /**
   * Gets the string value of the add token.
   *
   * @return				  Returns string equivalent of the token value.
   */
  std::string getTokenValue();

  /**
   * Gets the token priority of add command.
   *
   * @return				  Returns priority of the token.
   */
  int getTokenPriority();

};

#endif   // !defined _ADD_COMMAND_H_
