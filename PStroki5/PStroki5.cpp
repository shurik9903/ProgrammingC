#include "pch.h"
#include <iostream>
#include "windows.h"

using namespace std;

bool Poli(char * text){

	for(int i = 0, j = strlen(text) - 1; i < j;){
		if(isalpha((unsigned char)text[i])){
			if(isalpha((unsigned char)text[j])){
				if(tolower(text[i]) != tolower(text[j])) return 0;
				i++; j--;
			} else j--;
		} else i++;
	}

	return 1;
}

int main(){
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char * text = new char[255];
	cout << "Введите строку длиной не более 255 символов: ";
	cin.getline(text, 255);


	if(Poli(text)) cout << "Палиндром\n"; else cout << "Не палиндром\n";

	system("pause");
	return 0;
}