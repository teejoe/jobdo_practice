#include <iostream>
#include <stdlib.h>
using namespace std;

int Partition(int* pData, int begin, int end)
{
	if (pData == NULL || begin < 0)
		cout << "Invalid Params!" << endl;
		
	int pos = rand() % (end - begin) + begin;
	int pivot = pData[pos];
	swap(pData[pos], pData[end]);
	
	while (begin < end)
	{
		while (pData[begin] < pivot && begin < end)	begin++;
		pData[end] = pData[begin];
		
		while (pData[end] > pivot && end > begin)	end--;
		pData[begin] = pData[end];
	}
	
	pData[begin] = pivot;
	
	return begin;
}

void QuickSort(int* pData, int length, int begin, int end)
{
	if (begin >= end)
		return;
		
	int mid = Partition(pData, begin, end);
	QuickSort(pData, length, begin, mid - 1);
	QuickSort(pData, length, mid + 1, end);
}

void QuickSort(int* pData, int length)
{
	if (pData == NULL || length <= 1)
		return;
		
	QuickSort(pData, length, 0, length - 1);
}

int main()
{
	int a[] = {1, 4, 5, 6, 2, -1, -3, 8, 10, 40};
	QuickSort(a, 10);
	
	for (int i = 0; i < 10; i++)
		cout << a[i] << "  ";
}