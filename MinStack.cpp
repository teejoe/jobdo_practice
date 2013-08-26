#include <iostream>
#include <stack>
using namespace std;

template <typename T>
class MinStack
{
public:
	void Push(const T& n);
	T Pop();
	T Min();
private:
	stack<T> m_stack;
	stack<T> m_minStack;
};

template <typename T>
void MinStack<T>::Push(const T& n)
{
	m_stack.push(n);
	if (m_minStack.empty())
		m_minStack.push(n);
	else if (m_minStack.top() >= n)
		m_minStack.push(n);
}

template <typename T>
T MinStack<T>::Pop()
{
	T temp;
	if (!m_stack.empty())
	{
		temp = m_stack.top();
		m_stack.pop();
	}
	
	if (!m_minStack.empty() && temp == m_minStack.top())
		m_minStack.pop();
	
	return temp;
}

template <typename T>
T MinStack<T>::Min()
{
	return m_minStack.top();
}

int main()
{
	MinStack<int> s;
	s.Push(4); 
	s.Push(3);
	s.Push(1);
	s.Push(1);
	s.Push(2);
	
	s.Pop();
	s.Pop();
	
	cout << s.Min() << endl;
	
	
	return 0;
}