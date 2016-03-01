

//==============================================================================
/**
 * @file       OpenParanthesis_Command.h
 *
 * $Id: OpenParanthesis_Command.h 819 2011-01-17 15:24:45Z hillj $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _OPENPARANTHESIS_COMMAND_H_
#define _OPENPARANTHESIS_COMMAND_H_

#include <string>
#include <iostream>
#include <exception>
#include "Expr_Command.h" 
#include "Stack.h"  
/**
 * @class OpenParanthesis_Command
 *
 * Basic implementation of a OpenParanthesis_Command.
 */
class OpenParanthesis_Command : public  Expr_Command
{
public:
  /// Default constructor.
  OpenParanthesis_Command (void);

   /// Destructor.
  ~OpenParanthesis_Command (void);

   /**
   * Operations that need to be performed when token is an open paranthesis.
   *
   * @param[in]      s        Stack needed for execution.
   * @return				  Returns true if the execution was successful.
   */
  bool execute (Stack <int> & s);

  /**
   * Gets the string value of the Open Paranthesis token.
   *
   * @return				  Returns string equivalent of the token value.
   */
  std::string getTokenValue();

  /**
   * Gets the token priority of Open Paranthesis command.
   *
   * @return				  Returns priority of the token.
   */
  int getTokenPriority();

};

#endif   // !defined _OPENPARANTHESIS_COMMAND_H_
