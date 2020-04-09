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
	char  seps[] = " ,.;";
	char *token,*NextToken;

	if(!MD.FileCheckStr(UserFile)) return 0;

	do{
		cout << "введите заданное слово:   ";
		cin >> word;
	} while(strlen(word) == 0);

	MD.ArrayTolower(word);

	int count = 0;

	while(UserFile.getline(s, len)){
		MD.ArrayTolower(s);
		token = strtok_s(s, seps, &NextToken);
		while(token != NULL){
			if(strcmp(word,token) == 0) count++;
			token = strtok_s(NULL, seps, &NextToken);
		}
	}

	cout << "Слово  " << word << "  встречается в тексте " << count << " раз " << endl;

	system("pause");
	return 0;
}
