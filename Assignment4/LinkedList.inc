/***********************************************************
* Author:				Patrick Carlson
* Date Created:			10/13/2015
* Last Modification Date:	10/25/2015
* Assignment Number:    CST 211 Assignment 3
* Filename:				LinkedList.inc
*
* Overview:
*	This is the inc file for the templated LinkedList
*	class. LinkedList is a doubly linked list storing the
*	locations of the first and last node in the list.
*
* Input:
*
*
* Output:
*	Accessor functions allow manipulation of data stored
*	within the linked list.
************************************************************/


/**************************************************************
*	  Purpose:  Default constructor
*
*         Entry: 
*
*          Exit:	Assigns member variables m_head and m_tail
*					to nullptr.
****************************************************************/
template <typename T>
LinkedList<T>::LinkedList()
{
	m_head = nullptr;
	m_tail = nullptr;

	
}

/**************************************************************
*	  Purpose:  Copy Constructor
*
*         Entry:	LinkedList object to be copied
*
*          Exit:	Failed to perform deep copy. Too late.
****************************************************************/
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& copy)
{
	if ( copy.m_head == nullptr)
	{
		m_head = nullptr;
		m_tail = nullptr;
	}

	else
	{
		m_head = nullptr;
		m_tail = nullptr;

		Node<T>* curNode = copy.m_head;

		Node<T>* nextNode;

		while (curNode != nullptr)
		{

			this->Append(&curNode->getData());

			nextNode = curNode->getNext();

			curNode = nextNode;

		}
	}
}

/**************************************************************
*	  Purpose:  Destructor
*
*         Entry:
*
*          Exit:	Deletes nodes, which are dynamically allocated
****************************************************************/
template <typename T>
LinkedList<T>::~LinkedList()
{
	Node<T>* delNode = m_head;

	while (delNode != nullptr)
	{
		Node<T>* nextNode = delNode->getNext();
		delete delNode;
		delNode = nextNode;
	}

}

/**************************************************************
*	  Purpose:  Assignment operator overload
*
*         Entry:	Linked list object that is to be copied.
*
*          Exit:	Returns new linked list with same data
*					values as copied list.
****************************************************************/
template <typename T>
LinkedList<T>& LinkedList<T>::operator = (const LinkedList& rhs)
{	
	Node<T>* delNode = m_head;

	while (delNode != nullptr)
	{
		Node<T>* nextNode = delNode->getNext();
		delete delNode;
		delNode = nextNode;
	}

	if (rhs.m_head == nullptr)
	{
		m_head = nullptr;
		m_tail = nullptr;

		return *this;
	}

	Node<T>* curNode = rhs.m_head;

	Node<T>* nextNode;

	while (curNode != nullptr)
	{
			
		this->Append(&curNode->getData());

		nextNode = curNode->getNext();

		curNode = nextNode;

	}

	return *this;

}

/**************************************************************
*	  Purpose:  List status inspector.
*
*         Entry:
*
*          Exit:	Returns false unless list has no nodes.
****************************************************************/
template <typename T>
bool LinkedList<T>::isEmpty()
{
	if (m_head == nullptr)
		return true;
	else
		return false;
}

/**************************************************************
*	  Purpose:  Inspector for member variable m_head.
*
*         Entry:
*
*          Exit:	Return member variable m_head
****************************************************************/
template <typename T>
const Node<T>& LinkedList<T>::First()
{
	return *m_head;
}

/**************************************************************
*	  Purpose:  Inspector for member variable m_tail.
*
*         Entry:
*
*          Exit:	Return member variable m_tail.
****************************************************************/
template <typename T>
const Node<T>& LinkedList<T>::Last()
{
	return *m_tail;
}

/**************************************************************
*	  Purpose:  Assign node to front of linked list
*
*         Entry:	data value for new node to contain
*
*          Exit:	
****************************************************************/
template <typename T>
void LinkedList<T>::Prepend(T* input)
{
	Node<T>* newNode = new Node<T>(*input);
	Node<T>* oldNode = m_head;
	if (!oldNode)
	{
		m_tail = newNode;
		m_head = newNode;
	}

	else
	{
		m_head = newNode;
		oldNode->setPrev(newNode);
		newNode->setNext(oldNode);
	}
	m_head = newNode;
}

/**************************************************************
*	  Purpose:  Assign node to back of linked list
*
*         Entry:	data value for new node to contain
*
*          Exit:
****************************************************************/
template <typename T>
void LinkedList<T>::Append(T* input)
{
	
	
	Node<T>* newNode = new Node<T>(*input);
	Node<T>* oldLast = m_tail;

	if (!oldLast)
	{
		m_head = newNode;
		m_tail = newNode;
				
	}
	
	else
	{
		m_tail = newNode;
		oldLast->setNext(newNode);
		newNode->setPrev(oldLast);

	}

}

/**************************************************************
*	  Purpose:  Remove all dynamically allocated nodes from list
*
*         Entry:	
*
*          Exit:
****************************************************************/
template <typename T>
void LinkedList<T>::Purge()
{
	Node<T>* delNode = this->m_head;
	
	while (delNode != nullptr)
	{
		Node<T>* nextNode = delNode->getNext();
		delete delNode;
		delNode = nextNode;
	}

	m_head = nullptr;
	m_tail = nullptr;
}

/**************************************************************
*	  Purpose:  Remove node containing indicated value
*
*         Entry:	Data to be matched to node
*
*          Exit:	
****************************************************************/
template <typename T>
Node<T>& LinkedList<T>::Extract(T input)
{
	for (Iterator<T> i = this->Begin(); i != this->End(); ++i)
	{

		if (*i == input)
		{
			Node<T>* curNode = &i.getItNode();
			Node<T>* afterNode = curNode->getNext();			
			Node<T>* beforeNode = curNode->getPrev();
			if (afterNode == nullptr)
			{
				m_tail = curNode;
				beforeNode->setNext(nullptr);

				return *curNode;
			}
			else if (beforeNode == nullptr)
			{
				m_head = curNode;
				afterNode->setPrev(nullptr);

				return *curNode;
			}

			afterNode->setPrev(beforeNode);
			beforeNode->setNext(afterNode);

			return *curNode;
		}
	}
}

/**************************************************************
*	  Purpose:  Delete last node in LinkedList and return 
*				data contained within.
*
*         Entry:	
*
*          Exit: Deletes last node, returns data contained within
****************************************************************/
template <typename T>
T LinkedList<T>::popBack()
{
	T data = m_tail->getData();

	Node<T>* oldend = m_tail;
	
	m_tail = m_tail->getPrev();

	m_tail->setNext(nullptr);

	delete oldend;

	return data;
}

/**************************************************************
*	  Purpose:  insert node after node containing indicated 
*				value
*
*         Entry:	Data to be matched to node, data for new node
*
*          Exit:
****************************************************************/
template <typename T>
void LinkedList<T>::insertAfter(T data, T* inNode)
{
	for (Iterator<T> i = this->Begin(); i != this->End(); ++i)
	{
		if (*i == data)
		{

			Node<T>* curNode = &i.getItNode();

			Node<T>* newNode = new Node<T>(*inNode);
			newNode->setPrev(curNode);
			newNode->setNext(curNode->getNext());
			curNode->setNext(newNode);

			if (!newNode->getNext())
				m_tail = newNode;
			
		}
	}
}

/**************************************************************
*	  Purpose:   Insert node before node containing indicated 
*				value
*
*         Entry:	Data to be matched to node, data to be 
*					inserted.
*
*          Exit:	
****************************************************************/
template <typename T>
void LinkedList<T>::insertBefore(T data, T* inNode)
{
	for (Iterator<T> i = this->Begin(); i != this->End(); ++i)
	{
		if (*i == data)
		{

			Node<T>* curNode = &i.getItNode();

			Node<T>* newNode = new Node<T>(*inNode);
			newNode->setNext(curNode);
			newNode->setPrev(curNode->getPrev());
			curNode->setPrev(newNode);

			if (!newNode->getPrev())
				m_head = newNode;

		}
	}
}

/**************************************************************
*	  Purpose:  Inspector returning iterator to first node.
*
*         Entry:	
*
*          Exit:	Returns iterator for first node.
****************************************************************/
template <typename T>
const Iterator<T> LinkedList<T>::Begin()
{
	Iterator<T> first(m_head);

	return first;
}

/**************************************************************
*	  Purpose:  Inspector returning iterator to last node.
*
*         Entry:
*
*          Exit:	Returns iterator for last node.
****************************************************************/
template <typename T>
const Iterator<T> LinkedList<T>::End()
{
	Iterator<T> last(m_tail->getNext());

	return last;
}

