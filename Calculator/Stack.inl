// -*- C++ -*-
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

//
// size
// Returns the number of elements present in the stack.
//
template <typename T>
inline
size_t Stack <T>::size (void) const
{
	return (stack_top_);
}

//
// top
// Returns the topmost element of the stack.
//
template <typename T>
inline
T Stack <T>::top (void) const
{
	//If the value of stack-top is 0, throw the stack is empty exception else return the topmost element of the stack.
	if(stack_top_ == 0)
	{
		throw empty_exception();
	}
	else
	{
		return stack_data_.get((stack_top_ - 1));
	}
}

//
// is_empty
// Determines whether the stack is empty.
//
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
	//If the top of the stack is set to 0, it means that the stack is empty. 
	if(stack_top_ == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
