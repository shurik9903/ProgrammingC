#include "pch.h"
#include <iostream>
#include <time.h>

using namespace std;

int cache[100] = {0};

int fib(int n){
	if(n <= 1) return n;
	else if(cache[n] == 0)
		cache[n] = fib(n - 1) + fib(n - 2);
	return cache[n];
}

int fib_dynamic(int n){
	int *Fib = new int[n+1];
	Fib[0] = 0;
	Fib[1] = 1;
	for(int i = 2; i <= n; ++i)
		Fib[i] = Fib[i - 1] + Fib[i - 2];
	return Fib[n];
}

int main(){

	int Start_clock;
	int End_clock;

	for(int n = 1; n < 50; n++){
		Start_clock = clock();
		int Res = fib_dynamic(n);
		End_clock = clock();
		cout << "Fib " << n << ": " << Res << "   Time: " << (End_clock - Start_clock) * 1000 / CLOCKS_PER_SEC << endl;
	}
	

}
