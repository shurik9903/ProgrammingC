#include "pch.h"
#include <iostream>

using namespace std;

int S(int a, int b){
	if(b == 1 ) return a;
	else if(b == -1) return -a;
	else if (b > 1) return S(a, b - 1) + a;
	else return S(a, b + 1) - a;
}

int main(){
	int a, b;
	cin >> a >> b;

	cout << "Result: " << S(a,b) << endl;

	return 0;
}
