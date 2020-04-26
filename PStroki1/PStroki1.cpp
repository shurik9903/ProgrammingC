#include "pch.h"
#include <iostream>
#include "String"

using namespace std;


int Convert(string text){
	int Numb = 0;

	bool First = true, Positive = true;

	for(char s : text){
		if(First && s == '-'){
			First = false;
			Positive = false;
		}

		if(s == '1' || s == '2' || s == '3' || s == '4' || s == '5' || s == '6' || s == '7' || s == '8' || s == '9' || s == '0'){
			if(First) First = false;
			if(Numb == 0) Numb = s-48;
			else Numb = Numb * 10 + (s - 48);
		}
		
	}

	if(Positive) return Numb; else return Numb * (-1);

}

int main(){
    
	string text;
	int Numb;
	cin >> text;

	Numb = Convert(text);
	cout << "Number: " << Numb << endl;
	return 0;

}

