#include "pch.h"
#include "CA.h"
#include <iostream>

using namespace std;

CA::CA(){
	a = 2;
	b = 25;
}

CA::~CA(){}

void CA::Fx(){
	int c = a * b;
	cout << "CA::Fx = " << c << endl;
}