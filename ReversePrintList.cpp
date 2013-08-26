#include <iostream>
#include <stack>
using namespace std;

struct Node
{
	Node(int n){m_nValue = n, m_pNext = NULL;}
	int m_nValue;
	Node* m_pNext;
};

void ReversePrint(Node* pHead)
{
	if (pHead == NULL)
		return;
		
	Node* pTemp = pHead;
	stack<Node*> s;
	while (pTemp != NULL)
	{
		s.push(pTemp);
		pTemp = pTemp->m_pNext;
	}
	
	while (!s.empty())
	{
		cout << s.top()->m_nValue << endl;
		s.pop();
	}
}

int main()
{
	Node* node1 = new Node(1);
	Node* node2 = new Node(2);
	Node* node3 = new Node(3);
	node1->m_pNext = node2;
	node2->m_pNext = node3;
	
	ReversePrint(node1);
	
	return 0;
}