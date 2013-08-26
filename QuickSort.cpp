#include <iostream>
using namespace std;

int Partition(int* pData, int begin, int end)
{
	if (pData == NULL || begin < 0)
		cout << "input error!" << endl;
		
	
	int pivot = pData[begin];
	
	int i = begin, j = end;
	
	while (i < j)
	{
		while (i < j && pData[j] >= pivot)
			j--;
		pData[i] = pData[j];
		
		while (i < j && pData[i] <= pivot)
			i++;
		pData[j] = pData[i];
	}
	
	pData[i] = pivot;
	
	return i;
}

void QuickSort(int* pData, int begin, int end)
{
	if (begin >= end)
		return;
		
	int mid = Partition(pData, begin, end);
	QuickSort(pData, begin, mid - 1);
	QuickSort(pData, mid + 1, end);
}

int main()
{
	int a[10] = {3, 4, 5, 6, 1, 2, 7, 8, 9, 0};
	QuickSort(a, 0, 9);
	
	for (int i = 0; i < 10; i++)
		cout << a[i] << endl;
	return 0;
}