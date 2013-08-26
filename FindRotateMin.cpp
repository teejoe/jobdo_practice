#include <iostream>
using namespace std;

int FindMinInOrder(int* pData, int low, int high)
{
	int min = pData[low];
	for (int i = low + 1; i <= high; i++)
	{
		if (pData[i] < min)
			min = pData[i];
	}
	
	return min;
}

int FindMin(int* pData, int length)
{
	if (pData == NULL || length <= 0)
	{
		cout << "Invalid parameters!" << endl;
		return 0;
	}
	
	int low = 0, high = length - 1;
	int mid;
	
	if (pData[low] < pData[high])
		return pData[low];
			
	while (low < high)
	{
		mid = (low + high) / 2;
		
		if (pData[mid] == pData[high] && pData[mid] == pData[low])
			return FindMinInOrder(pData, low, high);
		
		if (pData[mid] < pData[high])
			high = mid;
			
		if (pData[mid] > pData[low])
			low = mid + 1;
	}
	
	return pData[low];
}

int main()
{
	int a[5] = {4, 5, 1, 2, 3};
	int a1[5] = {1, 2, 3, 4, 5};
	int a2[5] = {1, 0, 1, 1, 1};
	
	cout << FindMin(a, 5) << endl;
	cout << FindMin(a1, 5) << endl;
	cout << FindMin(a2, 5) << endl;		
	
	
	return 0;
}