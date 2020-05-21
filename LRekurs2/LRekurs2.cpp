#include "pch.h"
#include <iostream>

using namespace std;

int Number_of_trajectories(int n){
	int *K = new int [n + 1];
	
	K[0] = 0;
	K[1] = 1;

	for(int i = 2; i <= n; ++i)
		K[i] = K[i - 1] + K[i-2];
	return K[n];

}

int main(){

	int Fin;
	cin >> Fin;
	cout << "Grasshopper has " << Number_of_trajectories(Fin) << " trajectories from 1 " << "to " << Fin << endl;

	return 0;

}
