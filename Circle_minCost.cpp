#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(int argc, char** argv)
{
	vector<double> vCircle;
	
	int nCount;
	cin >> nCount;
	double fTotal = 0;
	for (int i = 0; i < nCount; i++)
	{
		double temp;
		cin >> temp;
		vCircle.push_back(temp);
		fTotal += temp;
	}
	
	double fAvg = fTotal / nCount;
	
	vector<double> vSum;
	double fSum = vCircle[0];
	for (int i = 1; i < nCount; i++)
	{
		vSum.push_back(fSum - i * fAvg);
		fSum += vCircle[i];
	}
	
	vector<double> vCopySum = vSum;
	sort(vCopySum.begin(), vCopySum.end());
	double p1 = vCopySum[(nCount - 1)/ 2];
	
//	cout << p1 << endl;
//	cout << abs(p1) << endl;
	
	double fCost = abs(p1);
	for (int i = 0; i < nCount - 1; i++)
		fCost += abs(p1 - vSum[i]);
		
	cout << "Min cost: " << fCost << endl;
	cout << "Move: " << p1 << " ";
	for (int i = 0; i < nCount - 1; i++)
		cout << p1 - vSum[i] << " ";
	
	return 0;
}