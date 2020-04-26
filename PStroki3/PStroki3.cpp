#include "pch.h"
#include "MyDll.h"
#include <iostream>
#include "fstream"
#include "list"
#include <algorithm>

using namespace std;
using namespace Dll;

int main(){
	MD_Class MD;

	list <string> text;
	string TextLine;
	ifstream UserFile("Text.txt");

	if(!MD.FileCheckStr(UserFile)){
		return 0;
	}

	int Numb = 0;

	TextLine = MD.GetTextLine(UserFile, 0);
	transform(TextLine.begin(), TextLine.end(), TextLine.begin(), tolower);
	MD.GetWordText(TextLine,text);

	cout << "\nFirst Text: \n";
	for(string s : text) cout << s << endl;

	text.sort();
	
	cout << "\nSorting Text: \n";
	for(string s : text) cout << s << endl;

	return 0;
}