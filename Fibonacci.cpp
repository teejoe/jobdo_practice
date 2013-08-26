#include <iostream>
using namespace std;

long long Fibonacci(int n)
{
	if (n <= 1)
		return n;
		
	long long nCur;
	long long nPre1 = 1;
	long long nPre2 = 0;
	
	for (int i = 2; i <= n; i++)
	{
		nCur = nPre1 + nPre2;
		nPre2 = nPre1;
		nPre1 = nCur;
	}
	
	return nCur;
}

int main()
{	
	int n;
	cin >> n;
	
	for (int i = 0; i <= n; i++)
		cout << Fibonacci(i) << endl;
	return 0;
}