#include "pch.h"
#include <iostream>
#include "string"

using namespace std;

class Object{
public:
	int Number;
	double Doub;
	string Text;
	char Text2[5] = {'F','i','v','e','\0'};
};

int main(){

	Object Obj;

	Obj.Doub = 3.14;
	Obj.Number = 666;
	Obj.Text = "This is text";
	for(int i = 0; i < 5; i++){
		cout << Obj.Text2[i];
	}
	cout << endl << Obj.Doub << endl << Obj.Number << endl << Obj.Text << endl;
}
