#include "pch.h"
#include <iostream>

using namespace std;

bool  isSimple(int n, int i){
	if(n < 2){ return false; } 
	if(n == 2){ return true; } 
	if(n % i == 0){ return false; } 
	else
		if(i < n / 2)
			return isSimple(n, i + 1);
		else  return true;
}


int main(){

	int n;
	cin >> n;
	if(isSimple(n, 2)) cout << "Simple \n"; else cout << "No simple\n";

	return 0;
}
