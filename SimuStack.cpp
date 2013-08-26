#include <iostream>
#include <queue>
using namespace std;

template <class T>
class CStack
{
public:
	void appendTail(const T& value);
	T deleteHead();
private:
	queue<T> m_queue1;
	queue<T> m_queue2;
};

template <class T>
void CStack<T>::appendTail(const T& value)
{
	if (m_queue1.empty())
		m_queue2.push(value);
	else
		m_queue1.push(value);
	
}

template <class T>
T CStack<T>::deleteHead()
{
	if (m_queue1.empty())
	{
		while (m_queue2.size() > 1)
		{
			m_queue1.push(m_queue2.front());
			m_queue2.pop();
		}
		
		T ret = m_queue2.front();
		m_queue2.pop();
		return ret;
	}
	else
	{
		while (m_queue1.size() > 1)
		{
			m_queue2.push(m_queue1.front());
			m_queue1.pop();
		}
		T ret = m_queue1.front();
		m_queue1.pop();
		return ret;
	}
}

int main()
{
	CStack<int> Stack;
	for (int i = 0; i < 10; i++)
		Stack.appendTail(i);
		
	for (int i = 0; i < 10; i++)
		cout << Stack.deleteHead() << " ";
		
	return 0;
}