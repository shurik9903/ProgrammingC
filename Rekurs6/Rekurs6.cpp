#include "pch.h"
#include <iostream>

using namespace std;

int SumNumb(int n){
	cout <<  "n: " << n << endl;
	if(n / 10 == 0) return 1;
	else
		return SumNumb(n / 10) + 1;
}


int main(){
	int n;
	cin >> n;
    
	cout << "Numb: " << SumNumb(n);

	return 0;
}
