#include <iostream>
#include <stack>
using namespace std;

template <class T>
class CQueue
{
public:
	void appendTail(const T& value);
	T deleteHead();
private:
	stack<T> m_stack1;
	stack<T> m_stack2;
};

template <class T>
void CQueue<T>::appendTail(const T& value)
{
	m_stack1.push(value);
}

template <class T>
T CQueue<T>::deleteHead()
{
	T ret;
	if (m_stack2.empty())
	{
		while (!m_stack1.empty())
		{
			m_stack2.push(m_stack1.top());
			m_stack1.pop();
		}
	}
	
	if (m_stack2.empty())
	{
		cout << "Queue is empty" << endl;
		return ret;
	}
	
	ret = m_stack2.top();
	m_stack2.pop();	
	
	return ret;
}

int main()
{
	CQueue<int> Queue;
	for (int i = 0; i < 10; i++)
		Queue.appendTail(i);
		
	for (int i = 0; i < 10; i++)
		cout << Queue.deleteHead() << " ";
		
	return 0;
}