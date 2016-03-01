
//==============================================================================
/**
 * @file       Modulus_Command.h
 *
 * $Id: Modulus_Command.h 819 2011-01-17 15:24:45Z hillj $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _MODULUS_COMMAND_H_
#define _MODULUS_COMMAND_H_

#include <string>
#include <iostream>
#include <exception>
#include "Binary_Op_Command.h" 
/**
 * @class Modulus_Command
 *
 * Basic implementation of a Modulus_Command.
 */
class Modulus_Command : public  Binary_Op_Command
{
public:
  /// Default constructor.
  Modulus_Command (void);

   /// Destructor.
  ~Modulus_Command (void);

  /**
   * Implements the modulus operation.
   *
   * @param[in]      n1        First Operand.
   * @param[in]      n2        Second operand
   * @return				  Returns the result of the modulus operation.
   */
  int evaluate (int n1, int n2) const;

   /**
   * Gets the string value of the modulus token.
   *
   * @return				  Returns string equivalent of the token value.
   */
  std::string getTokenValue();

   /**
   * Gets the token priority of modulus command.
   *
   * @return				  Returns priority of the token.
   */
  int getTokenPriority();

};

#endif   // !defined _MODULUS_COMMAND_H_
