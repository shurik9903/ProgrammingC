#include "pch.h"
#include <iostream>

using namespace std;

int F(int n){
	if(n == 1)
		return 3;
	else 
		return F(n - 1)*(n - 1);
}

int main(){
	unsigned int n;
	cin >> n;

	cout << "Result: " << F(n) << endl;

	return 0;
}
