/***********************************************************
* Author:				Patrick Carlson
* Date Created:			10/1/2015
* Last Modification Date:	10/17/2015
* Assignment Number:    CST 211 Assignment 3
* Filename:				Exception.h
*
* Overview:
*	This files contains the Exception class, used to throw
*	custom error messages for invalid parameters set by
*	users.
*
* Input:
*	Constructor takes an input of a String which is used
*	as the message when an exception is thrown.
*
* Output:
*	Utilizes the overloaded ostream operator to easily
*	use output methods to display thrown exception's 
*	message.
************************************************************/
#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>


/************************************************************************
* Class: Exception
*
* Constructors:
*		Exception()
*				m_msg set the string "Standard Error"
*		Exception(char *msg)
*				m_msg is set to argument value msg.
*		Exception(const Exception &copy)
*				New Exception object member variables are set to same values
*				as copied Exception object.
*
* Mutators:
*		void setMessage(char *msg)
*				Allows mutation of the m_msg member variable.
*
* Methods:
*		const char* getMessage()
*				Inspector which returns value in member variable m_msg.
*		friend std::ostream& operator<<(std::ostream &stream, const Exception &except)
*				ostream operator overload.
*		Exception& operator=(const Exception &rhs)
*				Overloads the assignment operator for the Exception class
*************************************************************************/
class Exception
{
public:
	// Default Constructor
	Exception();

	// Single argument constructor
	Exception(char *msg);

	// Copy constructor
	Exception(const Exception &copy);

	// Destructor
	~Exception();

	// Assignment operator overload
	Exception& operator =(const Exception &rhs);

	// m_msg member variable inspector
	const char* getMessage();

	// m_msg member variable mutator
	void setMessage(char *msg);

	// ostream operator overload.
	friend std::ostream& operator<<(std::ostream &stream, const Exception &except);

private:
	char* m_msg; //Stored message for thrown exception.


};

#include "Exception.inc"

#endif