

template <typename T>
LinkedList<T>::LinkedList()
{
	m_head = nullptr;
	m_tail = nullptr;

	
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& copy)
{
	if ( copy.m_head == nullptr)
	{
		m_head = nullptr;
		m_tail = nullptr;
	}
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	Node<T>* delNode = m_head;

	while (delNode != nullptr)
	{
		Node<T>* nextNode = delNode->m_next;
		delete delNode;
		delNode = nextNode;
	}

}

template <typename T>
LinkedList<T>& LinkedList<T>::operator = (const LinkedList& rhs)
{	
	Node<T>* delNode = m_head;

	while (delNode != nullptr)
	{
		Node<T>* nextNode = delNode->m_next;
		delete delNode;
		delNode = nextNode;
	}

	if (rhs.m_head == nulptr)
	{
		m_head = nullptr;
		m_tail = nullptr;

		return *this;
	}

	Node<T>* curNode = rhs.m_head;

	Node<T>* nextNode;

	while (curNode != nullptr)
	{
			
		this->Append(curNode->m_data);

		nextNode = curNode->m_next;

		curNode = nextNode;

	}

}

template <typename T>
bool LinkedList<T>::isEmpty()
{
	if (m_head == nullptr)
		return true;
	else
		return false;
}

template <typename T>
const Node<T>& LinkedList<T>::First()
{
	return m_head;
}

template <typename T>
const Node<T>& LinkedList<T>::Last()
{
	return m_tail;
}

template <typename T>
void LinkedList<T>::Prepend(T* input)
{
	Node<T>* newNode = new Node<T>(input);
	Node<T>* oldNode = this->m_head;
	oldNode->m_prev = newNode;
	newNode->m_next = oldNode;
	this->m_head = newNode;
}

template <typename T>
void LinkedList<T>::Append(T* input)
{
	Node<T>* newNode = new Node<T>(input);
	Node<T>* oldLast = this->m_tail;
	oldLast->m_next = newNode;
	newNode->m_prev = oldLast;
	this->m_tail = newNode;
}

template <typename T>
void LinkedList<T>::Purge()
{
	Node<T>* delNode = this->m_head;
	
	while (delNode != nullptr)
	{
		Node<T>* nextNode = delNode->m_next;
		delete delNode;
		delNode = nextNode;
	}
}

template <typename T>
Node<T>& LinkedList<T>::Extract(T input)
{
	//iterate
	//fix the if
	//set curNode
	if (data == input)
	{
		Node<T>* afterNode = curNode->m_next;
		Node<T>* beforeNode = curNode->m_prev;

		//delete curNode;

		afterNode->m_prev = beforeNode;
		beforeNode->m_next = afterNode;

		return curNode;
	}
}

template <typename T>
void LinkedList<T>::insertAfter(T data, T* inNode)
{
	//iterate
	//fix the if
	//set curNode
	if (m_data == data)
	{
		Node<T>* newNode = new Node<T>(inNode);
		newNode->m_prev = curNode;
		curNode->m_next = newNode;

		m_tail = newNode;
	}
}

//implimant?
template <typename T>
Iterator LinkedList<T>::Begin()
{
	return 0;
}

//implimant?
template <typename T>
Iterator LinkedList<T>::End()
{
	return 0;
}