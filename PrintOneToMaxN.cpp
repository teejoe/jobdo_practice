#include <iostream>
#include <memory.h>
using namespace std;

void PrintNumber(char* pNumber)
{
	while (*pNumber == '0' && *pNumber != '\0')
		pNumber++;
	
	cout << pNumber << endl;
}

bool Increment(char* pNumber, int n)
{
	int nTakeOver = 1;
	for (int i = n - 1; i >= 0; i--)
	{
		pNumber[i] = pNumber[i] + nTakeOver;
		if (pNumber[i] > '9')
		{
			nTakeOver = 1;
			pNumber[i] = '0';
		}
		else
		{
			nTakeOver = 0;
			break;
		}
	}
	
	if (nTakeOver == 1)
		return false;
	
	return true;
}

void Print1ToMaxN(int n)
{
	if (n <= 0)
		return;

	char* pNumber = new char[n + 1];
	memset(pNumber, '0', n + 1);
	pNumber[n] = '\0';
	
	while (Increment(pNumber, n))
	{
		PrintNumber(pNumber);
	}
	
	delete [] pNumber;
}

void Print1ToNRecurCore(char* pNumber, int index, int n)
{
	if (index == n)
	{
		PrintNumber(pNumber);
		return;
	}
	
	for (int i = 0; i < 10; i++)
	{
		pNumber[index] = '0' + i;
		Print1ToNRecurCore(pNumber, index + 1, n);
	}
}

void Print1ToNRecur(int n)
{
	if (n <= 0)
		return;
		
	char* pNumber = new char[n + 1];
	memset(pNumber, '0', n + 1);
	pNumber[n] = '\0';
	
	Print1ToNRecurCore(pNumber, 0, n);
	
	delete pNumber;
}


int main()
{	
	int n;
	cin >> n;
//	Print1ToMaxN(n);
	Print1ToNRecur(n);
}