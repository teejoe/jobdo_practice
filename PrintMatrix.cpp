#include <iostream>
using namespace std;

void PrintCircle(int** matrix, int m, int n, int nStart)
{
	int nStartX, nStartY;
	nStartX = nStartY = nStart;
	int nEndX = n - nStart - 1;
	int nEndY = m - nStart - 1;
	
	for (int i = nStartX; i <= nEndX; i++)
		cout << matrix[nStartY][i] << " ";
		
	if (nEndY > nStartY)
	{
		for (int i = nStartY + 1; i <= nEndY; i++)
			cout << matrix[i][nEndX] << " ";
	}
	
	if (nEndY > nStartY && nEndX > nStartX)
	{
		for (int i = nEndX - 1; i >= nStartX; i--)
			cout << matrix[nEndY][i] << " ";
	}
	
	if (nEndX > nStartX && nEndY > nStartY + 1)
	{
		for (int i = nEndY - 1; i > nStartY; i--)
			cout << matrix[i][nStartX] << " ";
	}
	cout << endl;
}

void PrintMatrix(int** matrix, int m, int n)
{
	if (matrix == NULL || m	<= 0 || n <= 0)
		return;
	
	int nStart = 0;
	while (nStart < m / 2 && nStart < n / 2)
	{
		PrintCircle(matrix, m, n, nStart);
		nStart++;
	}
}


int main()
{
	int matrix1[4][5] = {1,  2,  3,  4,  5,
						6,  7,  8,  9,  10,
						11, 12, 13, 14, 15,
						16, 17, 18, 19, 20};
	int matrix2[1][1] = {1};
	int matrix3[1][2] = {1, 2};
	int matrix4[2][1] = {2, 1};
	
	int** matrix = new int*[4];
	for (int i = 0; i < 4; i++)
		matrix[i] = new int[5];
		
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			matrix[i][j] = matrix1[i][j];
		}
	}
	
	PrintMatrix(matrix, 4, 5);
	
	/*
	PrintMatrix(matrix1, 4, 5);
	PrintMatrix(matrix2, 1, 1);
	PrintMatrix(matrix3, 1, 2);
	PrintMatrix(matrix4, 2, 1);
	*/
	
	return 0;
}