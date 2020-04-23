#include "pch.h"
#include <iostream>

using namespace std;

float  poww(float x, int  n)
{
	if(n == 0)  return 1;
	else
		if(n > 0) return x * pow(x, n - 1);
		else return pow(x, n + 1) / x;
}


int main()
{
	float x;
	int n;
	cin >> x >> n;

	cout << "Pww: " << poww(x, n);

	return 0;
}
