#include "pch.h"
#include "MyDll.h"
#include <iostream>
#include "fstream"

using namespace std;
using namespace Dll;

int main(){
	MD_Class MD;

	ifstream UserFile("Text.txt");

	if(!MD.FileCheckStr(UserFile)){
		return 0;
	}

	int Numb = 0;

	cout << "Number word: " << MD.NumberWordText(MD.GetTextLine(UserFile, 0)) << endl;

	return 0;
}
