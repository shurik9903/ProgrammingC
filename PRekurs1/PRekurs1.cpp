#include "pch.h"
#include <iostream>

using namespace std;

int Frekurs1(int n){
	if(n == 1 || n == 0) 
		return 1;
	else
		return Frekurs1(n-1)*n;
}

int Frekurs2(int n){
	if(n == 0 || n == 1) return 1;
	int F = 1;
	for(int i = 2; i <= n; i++)
		F = F * i;
	return F;
}

int main(){
	unsigned int n;
	cin >> n;

	cout << "R1: " << Frekurs1(n) << endl;
	cout << "R2: " << Frekurs2(n) << endl;

	return 0;
}
