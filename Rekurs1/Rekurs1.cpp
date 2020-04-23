#include "pch.h"
#include <iostream>

using namespace std;

void Towers(int n, char A, char B, char C){
	if(n == 1) cout << A << "->" << B << endl;
	else if(n == 2){
		Towers(1, A, B, C);
		Towers(1, A, C, B);
		Towers(1, B, C, A);
	} else {
		Towers(n-1, A, B, C); 
		Towers(1, A, B, C); 
		Towers(n-1, C, A, B); 
	}
}

int main(){
	Towers(3, 'A', 'B', 'C');

	return 0;
}

