#include "pch.h"
#include <iostream>
#include "AbstractServer.h"

using namespace std;

int main(){

	AbstractServer* s = ReturnServer();
	
	s->func();
	delete s;

	cout << "End";
	system("pause");
}
