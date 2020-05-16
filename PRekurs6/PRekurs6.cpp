#include "pch.h"
#include <iostream>

using namespace std;

int G(int n);

int F(int n){
	if(n == 1) return 10;
	else return F(n - 1) + G(n - 1);
}

int G(int n){
	if(n == 1) return -1;
	else return F(n - 1) + G(n - 1);
}

int main(){

	for(int i = 1; i <= 10 ; i++){
		cout << "F" << i << ": " << F(i) << endl;
		cout << "G" << i << ": " << G(i) << endl;
	}

	return 0;
}
