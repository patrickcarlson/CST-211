
template <typename T>
NormalQueue<T>::NormalQueue(int size)
	:m_capacity(size)
{
	m_size = 0;
}

template <typename T>
void NormalQueue<T>::Enqueue(T* input)
{
	if (!isFull())
	{
		m_queue.Append(input);
		m_size++;
	}
	else
		throw Exception("Overflow: Queue is full, no more room");
}

template <typename T>
T NormalQueue<T>::Dequeue()
{
	if (!isEmpty())
	{
		m_size--;

		return m_queue.popFront();
	}
	else
		throw Exception("Underflow: Queue is empty, nothing to remove");

}

template <typename T>
T& NormalQueue<T>::Front()
{
	return m_queue.First().getData();
}

template <typename T>
int NormalQueue<T>::size()
{
	return m_size;
}

template <typename T>
bool NormalQueue<T>::isEmpty()
{
	return m_queue.isEmpty();
}

template <typename T>
bool NormalQueue<T>::isFull()
{
	if (m_size == m_capacity)
		return true;
	else
		return false;
}