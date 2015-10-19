/*template <typename T>
Node<T>::Node()
{

}
*/

template <typename T>
Node<T>::Node(T& data)
	:m_data(data)
{
	m_next = nullptr;
	m_prev = nullptr;
}
/*

//
//Necessary?
//
template <typename T>
Node<T>::Node(const Node& copy)
{
	m_data = copy.m_data;
	m_prev = nullptr;
	m_next = nullptr;
}

template <typename T>
Node<T>::~Node()
{

}

template <typename T>
Node& Node<T>::operator =(const Node& rhs)
{

}
*/

template <typename T>
T& Node<T>::getData()
{
	return m_data;
}

template <typename T>
void Node<T>::setData(T newData)
{
	m_data = newData;
}

template <typename T>
Node<T>* Node<T>::getNext()
{
	return m_next;
}

template <typename T>
Node<T>* Node<T>::getPrev()
{
	return m_prev;
}

template <typename T>
void Node<T>::setNext(Node<T>* input)
{
	m_next = input;
}

template <typename T>
void Node<T>::setPrev(Node<T>* input)
{
	m_prev = input;
}