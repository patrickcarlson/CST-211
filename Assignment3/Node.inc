template <typename T>
Node<T>::Node()
{

}

template <typename T>
Node<T>::Node(T& data)
	:m_data(data)
{
	m_next = nullptr;
	m_prev = nullptr;
}

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

template <typename T>
T& Node<T>::getData()
{

}

template <typename T>
void Node<T>::setData(T newData)
{

}

