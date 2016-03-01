
//==============================================================================
/**
 * @file       ClosedParanthesis_Command.h
 *
 * $Id: ClosedParanthesis_Command.h 819 2011-01-17 15:24:45Z hillj $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _CLOSEDPARANTHESIS_COMMAND_H_
#define _CLOSEDPARANTHESIS_COMMAND_H_

#include <string>
#include <iostream>
#include <exception>
#include "Expr_Command.h"
#include "Stack.h" 
/**
 * @class ClosedParanthesis_Command
 *
 * Basic implementation of a Close Paranthesis.
 */
class ClosedParanthesis_Command : public  Expr_Command
{
public:
  /// Default constructor.
  ClosedParanthesis_Command (void);

   /// Destructor.
  ~ClosedParanthesis_Command (void);

  /**
   * Operations that need to be performed when token is a close paranthesis.
   *
   * @param[in]      s        Stack needed for execution.
   * @return				  Returns true if the execution was successful.
   */
  bool execute (Stack <int> & s);

  /**
   * Gets the string value of the Close Paranthesis token.
   *
   * @return				  Returns string equivalent of the token value.
   */
  std::string getTokenValue();

  /**
   * Gets the token priority of Closed Paranthesis command.
   *
   * @return				  Returns priority of the token.
   */
  int getTokenPriority();

};

#endif   // !defined _CLOSEDPARANTHESIS_COMMAND_H_
