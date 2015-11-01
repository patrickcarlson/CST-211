template <typename T>
CircularQueue<T>::CircularQueue(int size)
	:m_capacity(size)

{
	Array<T> m_queue(m_capacity);
	m_first = -1;
	m_last = -1;
	m_size = 0;
}


template <typename T>
void CircularQueue<T>::Enqueue(T input)
{
	if (!isFull())
	{
		if (m_last == m_capacity - 1 || m_last == -1)
		{
			m_queue[0] = input;
			m_last = 0;
			if (m_first == -1)
			{
				m_first = 0;
			}
		}
		else
		{
			m_queue[m_last + 1] = input;

			++m_last;
		}

		m_size++;
	}
	else
		throw Exception("Overflow: queue is full");
}

template <typename T>
T CircularQueue<T>::Dequeue()
{
	if (!isEmpty())
	{
		T reElement = m_queue[m_first];
		if (m_first == m_last)
		{
			m_first = -1;
			m_last = -1;
		}
		else if (m_first == m_capacity - 1)
		{
			m_first = 0;
		}
		else
			m_first++;

		m_size--;

		return reElement;
	}
	else
	{
		throw Exception("Underflow: Queue is empty, nothing to return");
	}

}

template <typename T>
T& CircularQueue<T>::Front()
{
	if (!isEmpty())
	{
		T* reElement = &m_queue[m_first];

		return *reElement;
	}
	else
		throw Exception("Queue is empty, nothing to return");
}

template <typename T>
int CircularQueue<T>::size()
{
	return m_size;
}

template <typename T>
bool CircularQueue<T>::isEmpty()
{
	if (m_first == -1 && m_last == -1)
		return true;
	else
		return false;
}

template <typename T>
bool CircularQueue<T>::isFull()
{
	if (m_first - 1 == m_last || (m_first == 0 && m_last == m_size - 1))
		return true;
	else
		return false;
}