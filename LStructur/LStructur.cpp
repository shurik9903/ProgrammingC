#include "pch.h"
#include <iostream>

using namespace std;

class complex{
public:
	float Re, Lm;

	void input(){
		cout << "\nEnter to Re and Lm: \n";
		cin >> Re >> Lm;
	}

	void print(){
		if(Lm >= 0) cout << Re << " + " << Lm << "i\n";
		else cout << Re << "" << Lm << "i\n";
	}


	void set(float a, float b){
		Re = a; Lm = b;
	}

	complex operator + (complex a){
		complex temp;
		temp.Re = Re + a.Re;
		temp.Lm = Lm + a.Lm;
		return temp;
	}
	

	complex operator * (complex a){
		complex temp;
		temp.Re = (Re * a.Re) + (Lm * a.Lm*-1);
		temp.Lm = (Lm * a.Re) + (Re * a.Lm);
		return temp;
	}

};



int main(){

	complex c1, c2, sum,mul;
	c1.set(1,-3);
	cout << "c1 = "; 
	c1.print();

	c2.input();
	cout << "C2 = ";
	c2.print();

	sum = c1 + c2;
	cout << "c1 + c2 = ";
	sum.print();

	mul = c1 * c2;
	cout << "c1 * c2 = ";
	mul.print();
}

