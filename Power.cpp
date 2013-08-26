#include <iostream>
using namespace std;

double Power(double base, int n)
{
	if ((base - 0 > -0.0000001 && base - 0 < 0.0000001) && n < 0)
	{
		cout << "invalid input" << endl;
		return 0;
	}
	
	if (n == 0)	return 1;
	if (n < 0)	return 1.0f / Power(base, -n);
	
	if (n == 1)	return base;
	
	double fSqrt = Power(base, n >> 1);
	double fRes = fSqrt * fSqrt;
	
	if (n & 0x1 == 1)
		fRes *= base;
	
	return fRes;
};

int main()
{	
	double base;
	int n;
	
	cin >> base >> n;
	
	cout << Power(base, n) << endl;
}