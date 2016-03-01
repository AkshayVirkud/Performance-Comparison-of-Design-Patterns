//==============================================================================
/**
 * @file       Binary_Op_Command.h
 *
 * $Id: Binary_Op_Command.h 819 2011-01-17 15:24:45Z hillj $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _BINARY_OP_COMMAND_H_
#define _BINARY_OP_COMMAND_H_

#include <string>
#include <iostream>
#include <exception>
#include "Stack.h"  
#include "Expr_Command.h"  

/**
 * @class Binary_Op_Command
 *
 * Basic implementation of a Add Command.
 */
class Binary_Op_Command : public  Expr_Command
{
public:
  /// Default constructor.
  Binary_Op_Command (void);

   /// Destructor.
  ~Binary_Op_Command (void);


  /**
   * Implements the execute operation.
   *
   * @param[in]      s        Stack needed for execution.
   * @return				  Returns true if the execution was successful.
   */
  virtual bool execute (Stack <int> & s);

  /**
   * abstract definition of the eveluate function.
   *
   * @param[in]      n1        First Operand.
   * @param[in]      n2        Second operand
   * @return				  Returns the result of the binary operation.
   */
  virtual int evaluate (int n1, int n2) const = 0;

  /**
   * abstract definition of the GetTokenValue function.
   *
   * @return				  Returns string equivalent of the token value.
   */
  virtual std::string getTokenValue() = 0;

  /**
   * abstract definition of the function to get token priority.
   *
   * @return				  Returns priority of the token.
   */
  virtual int getTokenPriority() = 0;

};

#endif   // !defined Binary_Op_Command
