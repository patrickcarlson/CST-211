/***********************************************************
* Author:				Patrick Carlson
* Date Created:			10/17/2015
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
#include <string>

/**************************************************************
*	  Purpose:  Default no argument constructor constructor
*				for Exception class.
*
*         Entry:  Creation of a new Exception object with 0 
*					arguments.
*
*          Exit:	Assigns m_msg to message "Standard Error".
****************************************************************/
Exception::Exception()
{
	m_msg = "Standard Error";
}

/**************************************************************
*	  Purpose:  Single argument constructor for Exception class
*
*         Entry:  Creation of a new Exception object with 1
*					arguments.
*
*          Exit:	Assigns m_msg to char argument
****************************************************************/
Exception::Exception(char *msg) 
: m_msg(msg) 
{

}

/**************************************************************
*	  Purpose:  Copy Constructor for Exception class.
*
*         Entry:  Takes single argument of Exception to be 
*					copied.
*
*          Exit:	Constructs of deep copy of another exception
****************************************************************/
Exception::Exception(const Exception &copy) 
{ 
	m_msg = new char[strlen(copy.m_msg)];
	
	for (size_t i = 0; i < strlen(copy.m_msg); ++i)
	{
		m_msg[i] = copy.m_msg[i];
	}

}

/**************************************************************
*	  Purpose:  Custom destructor of Exception object.
*
*         Entry:  
*
*          Exit:	Deletes dynamic allocation of m_msg
****************************************************************/
Exception::~Exception()
{
	delete[] m_msg;
}

/**************************************************************
*	  Purpose:  Operator assignment overload
*
*         Entry:  Takes single argument of Exception to be
*					assigned as.
*
*          Exit:	Constructs of deep copy of another exception
****************************************************************/
Exception& Exception::operator =(const Exception &rhs) 
{
	delete[] m_msg;

	size_t len = strlen(rhs.m_msg) + 1;
	m_msg = new char[len];
	strcpy_s(m_msg, len, rhs.m_msg);

	return  *this;
}

/**************************************************************
*	  Purpose:  m_msg variable inspector
*
*         Entry:  None
*
*          Exit:	Returns char array, string, stored in m_msg
****************************************************************/
const char* Exception::getMessage() 
{ 
	return m_msg; 
}

/**************************************************************
*	  Purpose:  m_msg mutator.
*
*         Entry:  Takes single argument of char array to be
*					set to m_msg.
*
*          Exit:	None
****************************************************************/
void Exception::setMessage(char *msg)
{ 
	m_msg = msg; 
}

/**************************************************************
*	  Purpose:  ostream operator overload
*
*         Entry:  stream to be output and exception object
*
*          Exit:	reference to output stream.
****************************************************************/
std::ostream& operator<<(std::ostream &stream, const Exception &except)
{
	stream << except.m_msg;
	return stream;
}