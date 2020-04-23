#include "pch.h"
#include <iostream>

using namespace std;

int SumDigit(int n){
	if(n < 10) return n;
	else
		return SumDigit(n / 10) + n % 10;
}


int main(){
	int n;
	cin >> n;

	cout << "Sum " << n << " = " << SumDigit(n);


	return 0;
}
