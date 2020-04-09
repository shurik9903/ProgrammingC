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

	while(UserFile.getline(s, len)){
		MD.ArrayTolower(s);
		if(strstr(s, word)){
			cout << "данная последовательность символов есть в файле\n";
			system("pause");
			return 0;
		}
    }

	cout << "данной последовательности символов в файле нет\n";
	system("pause");
	return 0;
}
