#include "pch.h"
#include <iostream>
#include "String"

using namespace std;


double Convert(string text){
	double Numb = NULL;
	int NN = 1;
	bool First = true, NumbRec = false, Positive = true, Dot = false;

	for(char s : text){
		if(s == '-'){
			if(!Positive){
				cout << "Error, in number can not stand more than 1 negation\n";
				return 0;
			} else Positive = false;
			if(!First){
				cout << "Error, denial cannot stand not at the beginning\n";
				return 0;
			} else First = false;
		} else if(s == '.'){
			if(!NumbRec){
				cout << "Error, point cannot be at the beginning of a number\n";
				return 0;
			} 
			if(Dot){
				cout << "Error, in number can not stand more than 1 point\n";
				return 0;
			} else Dot = true;
			
		} else if(s == '1' || s == '2' || s == '3' || s == '4' || s == '5' || s == '6' || s == '7' || s == '8' || s == '9' || s == '0'){
			if(First) First = false;

			if(Numb == NULL && !Dot) Numb = s-48;
			else if(!Dot) Numb = Numb * 10 + (s - 48);
			else{
				Numb = Numb + ((s - 48) / pow(10, NN));
				NN++;
			}

			NumbRec = true;
		} else{
			cout << "Error, the number contains letters or symbols\n";
			return 0;
		}
	}
	if(!NumbRec){
		cout << "Error, you did not enter a number\n";
		return 0;
	}else if(Positive) return Numb; else return Numb * (-1);

}

int main(){
	string text;
	cin >> text;

	double Numb = Convert(text);
	cout << "Number: " << Numb << endl;
	
	return 0;
}

