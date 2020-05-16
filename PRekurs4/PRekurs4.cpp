#include "pch.h"
#include <iostream>

using namespace std;

int SM(int * Mas, int n){
	if(n == 0) return Mas[n];
	else return SM(Mas, n - 1)+Mas[n];
}

int main(){

	unsigned int n;
	cin >> n;

	int *Mas = new int[n];

	for(int i = 0; i < n; i++){
		cout << i << ": ";
		cin >> Mas[i];
	}

	cout << "Result: " << SM(Mas,n-1) << endl;

	return 0;
}
