#include <iostream>
#include <string.h>
using namespace std;

char* ReplaceBlank(char* lpszSrc)
{
	if (lpszSrc == NULL)
		return NULL;
		
	int nLength = strlen(lpszSrc);
	if (nLength == 0)
		return NULL;
		
	int nNewLength = nLength;
	char* p = lpszSrc;
	while (*p != '\0')
	{
		if (*p == ' ')
			nNewLength += 2;
		p++;
	}
	
	char* lpszNew = new char[nNewLength + 1];
	lpszNew[nNewLength] = '\0';
	
	char* p1 = lpszSrc + nLength;
	char* p2 = lpszNew + nNewLength;
	
	while (p1 >= lpszSrc)
	{
		if (*p1 == ' ')
		{
			*p2-- = '0';
			*p2-- = '2';
			*p2-- = '%';
		}
		else
		{
			*p2-- = *p1;
		}
		p1--;
	}
	
	return lpszNew;
}

int main(int argc, char** argv)
{
	char str[80] = " ";
	
	cout << ReplaceBlank(str) << endl;
	
	return 0;
}