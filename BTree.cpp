#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class BTNode
{
public:
	BTNode(){m_pLeft = NULL; m_pRight = NULL;}
	int m_nValue;
	BTNode* m_pLeft;
	BTNode* m_pRight;
};

void InitializeTree1(BTNode*& pRoot)
{
	if (pRoot == NULL)
		pRoot = new BTNode;
	
	BTNode* pNode1 = new BTNode;	
	BTNode* pNode2 = new BTNode;
	BTNode* pNode3 = new BTNode;	
	BTNode* pNode4 = new BTNode;
	BTNode* pNode5 = new BTNode;	
	BTNode* pNode6 = new BTNode;
	
	pRoot->m_nValue = 8;
	pNode1->m_nValue = 8;
	pNode2->m_nValue = 7;
	pNode3->m_nValue = 9;
	pNode4->m_nValue = 2;
	pNode5->m_nValue = 4;
	pNode6->m_nValue = 7;

	pRoot->m_pLeft = pNode1;
	pRoot->m_pRight = pNode2;
	pNode1->m_pLeft = pNode3;
	pNode1->m_pRight = pNode4;
	pNode4->m_pLeft = pNode5;
	pNode4->m_pRight = pNode6;
}

void InitializeTree2(BTNode*& pRoot)
{
	if (pRoot == NULL)
		pRoot = new BTNode;
		
	BTNode* pNode1 = new BTNode;
	BTNode* pNode2 = new BTNode;
	
	pRoot->m_nValue = 8;
	pNode1->m_nValue = 9;
	pNode2->m_nValue = 2;
	
	pRoot->m_pLeft = pNode1;
	pRoot->m_pRight = pNode2;
}

void PrintTree(BTNode* pRoot)
{
	if (pRoot == NULL)
		return;
		
	cout << pRoot->m_nValue << ", ";
		
	PrintTree(pRoot->m_pLeft);
	PrintTree(pRoot->m_pRight);
}

bool IsSubTree(BTNode* pRoot1, BTNode* pRoot2)
{
	if (pRoot2 == NULL)
		return true;
	if (pRoot1 == NULL)
		return false;
		
	bool bHas = true;
	if (pRoot1->m_nValue != pRoot2->m_nValue)
		bHas = false;
	else 
		bHas = IsSubTree(pRoot1->m_pLeft, pRoot2->m_pLeft) && IsSubTree(pRoot1->m_pRight, pRoot2->m_pRight);
	
	return bHas;
}

bool HasSubTree(BTNode* pRoot1, BTNode* pRoot2)
{
	bool bHasSub = false;
	if (pRoot1 != NULL && pRoot2 != NULL)
	{
		bHasSub = IsSubTree(pRoot1, pRoot2);
	
		if (!bHasSub)
			bHasSub = HasSubTree(pRoot1->m_pLeft, pRoot2);

		if (!bHasSub)
			bHasSub = HasSubTree(pRoot1->m_pRight, pRoot2);
	}
	return bHasSub;
}

void Mirror(BTNode* pRoot)
{
	if (pRoot == NULL)
		return;
	
	BTNode* pTemp = pRoot->m_pLeft;
	pRoot->m_pLeft = pRoot->m_pRight;
	pRoot->m_pRight = pTemp;
	
	if (pRoot->m_pLeft)
		Mirror(pRoot->m_pLeft);
	if (pRoot->m_pRight)
		Mirror(pRoot->m_pRight);
}

// 前序遍历二叉树，非递归算法
void PreOrderTraverse(BTNode* pRoot)
{
	if (pRoot == NULL)
		return;
		
	stack<BTNode*> s;
	cout << pRoot->m_nValue << " ";
	
	if (pRoot->m_pRight != NULL)
		s.push(pRoot->m_pRight);
		
	BTNode* pNode = pRoot->m_pLeft;
	while (pNode != NULL || !s.empty())
	{
		if (pNode == NULL)
		{
			pNode = s.top();
			s.pop();
		}
		
		cout << pNode->m_nValue << " ";
		if (pNode->m_pRight != NULL)
			s.push(pNode->m_pRight);
		
		pNode = pNode->m_pLeft;
	}
}

// 前序遍历二叉树，递归算法
void PreOrderTraverseRecur(BTNode* pRoot)
{
	if (pRoot == NULL)
		return;
		
	cout << pRoot->m_nValue << " ";
	
	PreOrderTraverseRecur(pRoot->m_pLeft);
	PreOrderTraverseRecur(pRoot->m_pRight);
}

// 中序遍历二叉树，非递归算法
void InOrderTraverse(BTNode* pRoot)
{
	if (pRoot == NULL)
		return;
	
	stack<BTNode*> s;
	BTNode* pNode = pRoot;
	while (pNode != NULL || !s.empty())
	{
		while (pNode != NULL)
		{
			s.push(pNode);
			pNode = pNode->m_pLeft;
		}
		
		pNode = s.top();
		s.pop();
		cout << pNode->m_nValue << " ";
		
		pNode = pNode->m_pRight;
	}
}

// 中序遍历二叉树，递归算法
void InOrderTraverseRecur(BTNode* pRoot)
{
	if (pRoot == NULL)
		return;
		
	InOrderTraverseRecur(pRoot->m_pLeft);
	cout << pRoot->m_nValue << " ";
	InOrderTraverseRecur(pRoot->m_pRight);
}

// 后序遍历二叉树，非递归算法
// http://www.cnblogs.com/dolphin0520/archive/2011/08/25/2153720.html
void PostOrderTraverse(BTNode* pRoot)
{
	if (pRoot == NULL)
		return;
		
	stack<BTNode*> s;
	BTNode* pCur = pRoot;
	BTNode* pPre = NULL;
	s.push(pRoot);
	
	while (!s.empty())
	{
		pCur = s.top();
		if ((pCur->m_pLeft == NULL && pCur->m_pRight == NULL)
			|| (pPre != NULL && (pPre == pCur->m_pLeft || pPre == pCur->m_pRight)))
		{
			cout << pCur->m_nValue << " ";
			s.pop();
			pPre = pCur;
		}
		else
		{
			if (pCur->m_pRight != NULL)
				s.push(pCur->m_pRight);
			if (pCur->m_pLeft != NULL)
				s.push(pCur->m_pLeft);
		}
	}
}

void PostOrderTraverseRecur(BTNode* pRoot)
{
	if (pRoot == NULL)
		return;
		
	PostOrderTraverseRecur(pRoot->m_pLeft);
	PostOrderTraverseRecur(pRoot->m_pRight);
	
	cout << pRoot->m_nValue << " ";
}


// 根据前序遍历和中序遍历序列重构二叉树
BTNode* ConstructCore(int* pPreOrderStart, int* pPreOrderEnd, int* pInOrderStart, int* pInOrderEnd)
{
	BTNode* pRoot = new BTNode;
	pRoot->m_nValue = *pPreOrderStart;
	pRoot->m_pLeft = pRoot->m_pRight = NULL;
	
	if (pPreOrderStart == pPreOrderEnd)
	{
		if (pInOrderStart == pInOrderEnd && (*pPreOrderStart == *pInOrderStart))
			return pRoot;
		else
			cout << "Invalid Input!" << endl;
	}
	
	int* pNode = pInOrderStart;
	while (pNode != pInOrderEnd && *pNode != *pPreOrderStart)
		pNode++;
	
	int nLeftLen = pNode - pInOrderStart;
	if (pNode != pInOrderStart)
	{
		pRoot->m_pLeft = ConstructCore(pPreOrderStart + 1, pPreOrderStart + nLeftLen,
									   pInOrderStart, pNode - 1);
	}
	
	if (pNode != pInOrderEnd)
	{
		pRoot->m_pRight = ConstructCore(pPreOrderStart + nLeftLen + 1, pPreOrderEnd,
										pNode + 1, pInOrderEnd);
	}
	
	return pRoot;
}
BTNode* Construct(int* pPreOrder, int* pInOrder, int nLength)
{
	if (pPreOrder == NULL || pInOrder == NULL || nLength <= 0)
		return NULL;
	
	return ConstructCore(pPreOrder, pPreOrder + nLength - 1,
					 pInOrder, pInOrder + nLength - 1);
}

int main()
{
/*
	BTNode *pRoot1 = NULL, *pRoot2 = NULL;
	InitializeTree1(pRoot1);
	InitializeTree2(pRoot2);
	PrintTree(pRoot1);

	if (HasSubTree(pRoot1, pRoot2))
		cout << "Has sub tree" << endl;
		
	Mirror(pRoot1);
	PrintTree(pRoot1);
*/

	// 遍历二叉树
	BTNode* pRoot1 = NULL;
	InitializeTree1(pRoot1);
	
	PreOrderTraverse(pRoot1);
	cout << endl;
	PreOrderTraverseRecur(pRoot1);
	cout << endl;
	InOrderTraverse(pRoot1);
	cout << endl;
	InOrderTraverseRecur(pRoot1);
	cout << endl;
	PostOrderTraverse(pRoot1);
	cout << endl;
	PostOrderTraverseRecur(pRoot1);
	cout << endl;
	
	// 重构二叉树
	int pPreOrder[8] = {1,2,4,7,3,5,6,8};
	int pInOrder[8] = {4,7,2,1,5,3,8,6};
	
	cout << "Reconstruct result:" << endl;
	BTNode* pRoot = Construct(pPreOrder, pInOrder, 8);
	PreOrderTraverse(pRoot);
	cout << endl;
	InOrderTraverse(pRoot);
	cout << endl;
	delete pRoot;

	return 0;
}