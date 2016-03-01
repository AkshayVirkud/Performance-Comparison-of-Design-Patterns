// $Id: Array.cpp 1473 2014-01-20 15:48:07Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include <stdexcept>

//
// Array
// Default Constructor.
//

// Akshay, initialize each member in the base member initialization
// section on its own line. Otherwise, when a error occurs related to
// this section, each variable will not have a distinct line number.

// Dr. Hill, I have initialized each member in the base member initialization 
// section  on a new line.

// Akshay, it is not wise to allocate 0 bytes of memory. At this point,
// you will be taking up unnecessary space in the memory descriptor table.

// Dr. Hill, I have initialized the "data_" to "0" so that no memory is allocated.
template <typename T>
Array<T>::Array (void) : 
	data_ (0), 
	cur_size_(0), 
	max_size_(0) 
{

}

//
// Array (size_t)
// Initializing constructor that initializes the array with the specified length.
//

// Akshay, initialize each member in the base member initialization
// section on its own line. Otherwise, when a error occurs related to
// this section, each variable will not have a distinct line number.

// Dr. Hill, I have initialized each member in the base member initialization 
// section  on a new line.
template <typename T>
Array<T>::Array (size_t length) : 
	data_ (new T[length]), 
	cur_size_(length), 
	max_size_(length)
{

}

//
// Array (size_t, char)
// Initializing constructor that creates an array of the specified length and fills it with the specified character.
//

// Akshay, initialize each member in the base member initialization
// section on its own line. Otherwise, when a error occurs related to
// this section, each variable will not have a distinct line number.

// Dr. Hill, I have initialized each member in the base member initialization 
// section  on a new line.
template <typename T>
Array<T>::Array (size_t length, T fill) :
	data_(new T[length]),
	cur_size_(length),
	max_size_(length)
{
	for( size_t i = 0; i < length ; i++)
	{
		data_[i] = fill;
	}
}

//
// Array (const Array &)
// Copy constructor that creates an array which is a copy of the constant array that is passed as parameter.
//

// Akshay, initialize each member in the base member initialization
// section on its own line. Otherwise, when a error occurs related to
// this section, each variable will not have a distinct line number.

// Dr. Hill, I have initialized each member in the base member initialization 
// section  on a new line.

// Akshay, when access the data in the source array, you can just access
// the member variable directly (i.e., array.cur_size_). Right now, you
// are performing unncessary method calls. You did this below in operator=,
// why not do it here?!

// Dr. Hill, I have modified the code and accessed the data in the source array 
// using the member variable directly (for e.g. array.max_size_).
template <typename T>
Array<T>::Array (const Array & array) : 
	data_ (new T[array.max_size_]), 
	cur_size_(array.cur_size_), 
	max_size_(array.max_size_)
{
	for( size_t i = 0; i < cur_size_ ; i++)
	{
		data_[i] = array.data_[i];
	}
}

//
// ~Array
// Destructor which is called when objects are destroyed (deallocated).
//
template <typename T>
Array<T>::~Array (void)
{
	if(0 != data_)
		delete[] data_;

	// Akshay, there is no need to reset the data_ pointer to 0. This
	// is because the object, its methods, and its variables are no
	// longer accessible once the destructor returns.

	// Dr. Hill, I have deleted the code that resets the data_ pointer to 0.
}

//
// operator =
// Overloading operator =. It assigns the "data_", "cur_size_" and "max_size_" of one array to another array.
//
template <typename T>
const Array<T> & Array<T>::operator = (const Array & rhs)
{
	// Akshay, do not delete the old array of data until you are sure you
	// this class has copied over the data. Otherwise, if any error occurs
	// between the deletion of the old array and the saving of the new data
	// you will have unexpected behavior (especially in the destructor).
	// Unfortunately, the client will not be able to recover.

	// Dr. Hill, I have changed the logic. As per the new logic 
	// I am creating a new character array (temp) of length equal to rhs.max_size, 
	// making a temporary pointer (swapArray) point to contents data_, filling temp with 
	// rhs data, then making lhs data point to temp and finally deleting swaparray.  

	//If both arrays are not equal and "max_size" of lhs array is less than the "max_size" of the rhs array then assign "data_" to a new char array having size equal to the "max_size_" of rhs array.

	if(*this != rhs)
	{
		if(max_size_ < rhs.max_size_)
		{ 
			T * tempArray = new T[rhs.max_size_];
			T * swapArray = data_;

			for (size_t i = 0; i < rhs.cur_size_; i++)
			{
				tempArray[i] = rhs.data_[i];
			}

			data_ = tempArray;
			delete[] swapArray;

			max_size_ =  rhs.max_size_;
		}
		else
		{
			for (size_t i = 0; i < rhs.cur_size_; i++)
			{
				data_[i] = rhs.data_[i];
			}
		}
	}

	cur_size_ =  rhs.cur_size_;
	

	return *this;
}

//
// operator []
// This method gets character at the specified index. If the index is not within the range then it throws std::out_of_range exception. 
//
template <typename T>
T & Array<T>::operator [] (size_t index)
{
	// Akshay, by casting the size_t to an int, your logic will fail when index
	// is greater than 2^31.

	// Dr. Hill, I have removed the casting of size_t to an int.

	//If index is less than cur_size_ then return the character at the specified index.
	if(index < cur_size_)
	{
		return data_[index];
	}
	else
	{ 
		throw std::out_of_range("Invalid \a index value");
	}
}

//
// operator [] 
// Overloading of operator [] in which the return character is not modifiable.
//
template <typename T>
const T & Array<T>::operator [] (size_t index) const
{
	// Akshay, by casting the size_t to an int, your logic will fail when index
	// is greater than 2^31.

	// Dr. Hill, I have removed the casting of size_t to an int.

	//If index is less than cur_size_ then return the character at the specified index.
	if(index < cur_size_)
	{
		return data_[index];
	}
	else
	{ 
		throw std::out_of_range("Invalid \a index value");
	}
}

//
// get
// This method fetches the character at the specified index.If the index is not within the range then it throws std::out_of_range exception.
//
template <typename T>
T Array<T>::get (size_t index) const
{
	// Akshay, by casting the size_t to an int, your logic will fail when index
	// is greater than 2^31.

	// Dr. Hill, I have removed the casting of size_t to an int.

	if(index < cur_size_)
	{
		return data_[index];
	}
	else
	{
		throw std::out_of_range("Invalid index value");
	}
}

//
// set
// This method sets the specified character at the given index. If the index is not within the range then it throws std::out_of_range exception.
//
template <typename T>
void Array<T>::set (size_t index, T value)
{
	// Akshay, by casting the size_t to an int, your logic will fail when index
	// is greater than 2^31.

	// Dr. Hill, I have removed the casting of size_t to an int.

	if(index < cur_size_)
	{
		data_[index] = value;
	}
	else
	{
		throw std::out_of_range("Invalid \a index value");
	}

}

//
// resize
// Resize the array to the specified length.
//
template <typename T>
void Array<T>::resize (size_t new_size)
{
	// Akshay, do not delete the old array of data until you are sure you
	// this class has copied over the data. Otherwise, if any error occurs
	// between the deletion of the old array and the saving of the new data
	// you will have unexpected behavior (especially in the destructor).
	// Unfortunately, the client will not be able to recover.

	// Dr. Hill, I have modified the logic. Now I am first copying the array 
	// into a temp array and then deleting the old array. 

	//If "max_size_" is less than "new_size" then resize the array and copy the array elements
	//to the resized array and set "cur_size_"and "max_size_" values to  "new_size".  
	//If "max_size_" is not less than "new_size" then only set "cur_size_" value to  "new_size".

	if(max_size_ < new_size)
	{
		// Akshay, there is no need to a temp array here and doing a double
		// copy. What you are doing is creating a temp, copying over the data.
		// This creating another array (on data_) and copying over the data.
		// This doing another copy. You should just be swapping the pointers
		// of data and temp, then deleting the old data.

		// Dr. Hill, I have modified the logic. Now I am not copying the array twice. 
		// Instead of that I am swapping the pointers of data_ and temp and then 
		// deleting the old data

		T *tempArray  = new T[new_size];
		T * swapArray = data_;
		for (size_t i = 0; i < cur_size_; i++)
		{
			tempArray [i] = data_[i];
		}

		data_ = tempArray;
		delete[] swapArray;

		cur_size_ = new_size;
		max_size_ = new_size; 
	}
	else
	{
		cur_size_ = new_size;
	}
}

//
// find (char)
// This method finds the specified character in the given array. If the character is found, it returns the index of the first occurrence of the character else it returns -1. 
//
template <typename T>
int Array<T>::find (T ch) const
{
	for(size_t i = 0; i< cur_size_; i++)
	{
		if(data_[i] == ch)
		{
			return i;
		}
	}

	return -1;
}

//
// find (char, size_t)
// This method is an overloaded version of the "int Array::find (char ch) const" method. It allows you to specify the start index of the search.
//
template <typename T>
int Array<T>::find (T ch, size_t start) const
{
	// Akshay, by casting the size_t to an int, your logic will fail when index
	// is greater than 2^31.

	// Dr. Hill, I have removed the casting of size_t to an int.

	//If index to begin search - "start" is greater than the current size of the array then throw "out_of_range" exception
	if(start < cur_size_)
	{
		for(size_t i = start; i< cur_size_ ; i++)
		{
			if(data_[i] == ch)
			{
				return i;
			}
		}
		return -1;
	}
	else
	{
		throw std::out_of_range("Invalid index");
	}


}

//
// operator ==
// Overloading operator "==" .This method compares two arrays and returns true is they are equal and false if they are not equal.
//
template <typename T>
bool Array<T>::operator == (const Array & rhs) const
{
	bool isEqual = true;

	//If "cur_size_" of lhs array is not equal to "cur_size_" of rhs array then set "isEqual" = false, else proceed with comparing "data_" of both the arrays.
	if(rhs.cur_size_ != cur_size_)
	{
		isEqual = false;
	}
	else
	{
		for(size_t i = 0; i<cur_size_ ; i++)
		{
			if(data_[i] != rhs.data_[i])
			{
				isEqual = false;
				break;
			}
		}
	}

	return isEqual;
}

//
// operator !=
// Overloading operator "!=" .This method compares two arrays and returns true is they are not equal and false if they are equal.
//
template <typename T>
bool Array<T>::operator != (const Array & rhs) const
{
	// Akshay, it would be easier to define != in terms of ==.

	// Dr. Hill, I have removed code for computing != and defined != in terms of ==.  

	if(*this == rhs)
	{
		return false;
	}

	return true;
}

//
// fill
// The method fills the array upto its "cur_size_" with the specified character value. 
//
template <typename T>
void Array<T>::fill (T ch)
{
	for(size_t i = 0; i< cur_size_ ; i++)
	{
		data_[i] = ch;
	}
}
