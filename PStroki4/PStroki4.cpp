#include "pch.h"
#include <iostream>
#include "list"


using namespace std;

int LengthText(char text[255]){
	cout << text << endl;
	int Numb;
	for(Numb = 0; text[Numb] != '\0'; ++Numb);
	return Numb;
}

int main(){
	char text[255];
	
	cin.getline(text, 255);
	cout << "Length: " << LengthText(text) << endl;

	return 0;
}
