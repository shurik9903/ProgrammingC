#include "pch.h"
#include "CB.h"
#include <iostream>

using namespace std;

CB::CB(){
	a = 4;
	b = 25;
}

CB::~CB(){}

void CB::Fx(){
	int c = a * b;
	cout << "CA::Fx = " << c << endl;
}

void CB::Fy(){
	int c = a + b;
	cout << "CA::Fy = " << c << endl;
}