// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Stack
// Default Constructor.
//
template <typename T>
Stack <T>::Stack (void) :
	stack_top_ (0), 
	stack_data_(0)
{

}

//
// Stack
// Copy constructor that creates a stack which is a copy of the constant stack that is passed as parameter.
//
template <typename T>
Stack <T>::Stack (const Stack & stack) :
	stack_top_(stack.stack_top_),
	stack_data_(stack.stack_data_)
{

}

//
// ~Stack
// Destructor.
//
template <typename T>
Stack <T>::~Stack (void)
{

}

//
// push
// Inserts a new element at the top of the stack.
//
template <typename T>
void Stack <T>::push (T element)
{

	stack_data_.resize((stack_top_ + 1));
	stack_data_.set(stack_top_, element);
	stack_top_  = stack_top_ + 1;
}

//
// pop
// Removes the top-most element from stack.
//
template <typename T>
void Stack <T>::pop (void)
{
	//If the stack is empty throw empty exception else reduce the stack size by 1.
	if(is_empty())
	{
		throw empty_exception();
	}
  
  // Akshay, there is no need for an else block. This is
  // because if the 'if' condition is true, then control
  // will return. You can just write stack_top_ --.

  // Dr. Hill, I have removed the else block and directly written stack_top_ --

		stack_top_--;
}

//
// operator =
// Assignment operator which copies the stack-top and stack-data from one stack to another.
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
	stack_top_ = rhs.stack_top_;
	stack_data_ = rhs.stack_data_;
	return *this;
}

//
// clear
// Clears all the stack elements.
//
template <typename T>
void Stack <T>::clear (void)
{
	stack_top_ = 0;
}
