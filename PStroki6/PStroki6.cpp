#include "pch.h"
#include <iostream>
#include "MyDll.h"

using namespace std;
using namespace Dll;

int NumberOffers(ifstream &UserFile){
	char text[255];
	int Count = 0;
	while(UserFile.getline(text, 255)){
		for(char s : text)
			if(s == '.' || s == '\n' || s == '!' || s == '?') Count++;
	}
	return Count;
}

int main(){
	MD_Class MD;

	ifstream UserFile("Text.txt");

	if(!MD.FileCheckStr(UserFile)){
		return 0;
	}

	cout << "Number word: " << MD.NumberWordFile(UserFile) << endl;
	cout << "Number offers: " << NumberOffers(UserFile) << endl;

	return 0;
}

