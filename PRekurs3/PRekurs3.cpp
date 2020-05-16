#include "pch.h"
#include <iostream>

using namespace std;

int R(int N){
	if(N == 0 || N % 2 != 0) return 0;
	else if(N / 2 == 1) return 1;
	else return R(N / 2);
}

int main(){
	unsigned int N;
	cin >> N;

	cout << "Result: " << ((R(N) == 1) ? "YES" : "NO") << endl;

	return 0;
}
