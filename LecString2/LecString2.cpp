#include "pch.h"
#include <iostream>
#include "Windows.h"
#include "MyDll.h"
#include "fstream"

using namespace Dll;
using namespace std;


int main(){

	MD_Class MD;
	const int len = 81;

	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ifstream UserFile("Text.txt");

	char word[len], s[len];

	if(!MD.FileCheckStr(UserFile)) return 0;

	do{
		cout << "введите заданное слово:   ";
		cin >> word;
	} while(strlen(word) == 0);

	MD.ArrayTolower(word);

	int n = strlen(word); 
	int count = 0;

	while(UserFile.getline(s, len)) 
	{
		MD.ArrayTolower(s);
		char *p = s; 
		while(p = strstr(p,word))
		{
			char *c = p; 
			p += n;
			
			if(c != s) 
				if(!ispunct(*(c - 1)) && !isspace(*(c - 1))){ continue; }

			if(ispunct(*p) || isspace(*p) || (*p == '\0')) count++;
		}
	}

	cout << "Слово  " << word << "  встречается в тексте " << count << " раз " << endl;

	system("pause");
	return 0;
}
