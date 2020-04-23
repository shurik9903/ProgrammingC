#include "pch.h"
#include <iostream>
#include <random>

using namespace std;

int sum(int *A, int N){
	if(N == 0) return A[0];
	else
		return sum(A, N - 1) + A[N];
}


int main(){
	default_random_engine generate(random_device{}());
	uniform_int_distribution<int> distribut(-100, 100);

	int n;
	cin >> n;
	
	int *Array = new int[n];

	for(int i = 0; i < n; i++){
		Array[i] = distribut(generate);
		cout << i << ": " << Array[i] << endl;
	}
	cout << "Sum: " << sum(Array, n - 1);

	return 0;
}