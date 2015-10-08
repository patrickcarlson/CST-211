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
	Exception() { m_msg = "Standard Error"; }

	// Single argument constructor
	Exception(char *msg) : m_msg(msg) {}

	// Copy constructor
	Exception(const Exception &copy) { m_msg = copy.m_msg; }

	// Destructor
	~Exception(){}

	// Assignment operator overload
	Exception& operator =(const Exception &rhs) {
		m_msg = rhs.m_msg;
		return *this;
	}

	// m_msg member variable inspector
	const char* getMessage() { return m_msg; }

	// m_msg member variable mutator
	void setMessage(char *msg){ m_msg = msg; }

	// ostream operator overload.
	friend std::ostream& operator<<(std::ostream &stream, const Exception &except) {
		stream << except.m_msg;
		return stream;
	}

private:
	char* m_msg; //Stored message for thrown exception.
};