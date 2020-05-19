#include "pch.h"
#include <iostream>
#include <chrono>

using namespace std;

unsigned long int Frekurs1(int n){
	if(n == 1 || n == 0) 
		return 1;
	else
		return Frekurs1(n-1)*n;
}

unsigned long int Frekurs2(int n){
	if(n == 0 || n == 1) return 1;
	unsigned long int F = 1;
	for(int i = 2; i <= n; i++)
		F = F * i;
	return F;
}

int main(){
	unsigned int n;
	cin >> n;

	auto Start = std::chrono::steady_clock::now();
	cout << "R1: " << Frekurs1(n) << endl;
	auto End = std::chrono::steady_clock::now();
	cout << "Function 1 time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(End - Start).count() << "Ns\n";

	Start = std::chrono::steady_clock::now();
	cout << "R2: " << Frekurs2(n) << endl;
	End = std::chrono::steady_clock::now();
	cout << "Function 2 time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(End - Start).count() << "Ns\n";

	return 0;
}
