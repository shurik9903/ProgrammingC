// BovtMOAP1.cpp: определяет точку входа для консольного приложения.
// Вариант 8

#include "pch.h"
#include "cassert"
#include "iostream"
#include <cmath>
#include "ctime"
#include "MyDll.h"

using namespace std;
using namespace Dll;


int main(){

	MD_Class MD;

	ifstream UserFile("Data.txt");

	if(!MD.FileCheckStr(UserFile)){
		return 0;
	}

	if(MD.NumbertTextLine(UserFile) < 1){
		cout << "No data in file\n";
		return 0;
	}

	int Size = MD.NumbertTextLine(UserFile);
	Datetime *Date = new Datetime[Size];
	
	for(int i = 0; i < Size; i++){
		Date[i].Separation(MD.GetTextLine(UserFile, i+1));
	}


	for(int i = 0; i < Size; i++){
		cout << i+1 << ": " << Date[i];
	}

	cout << endl;

	for(int i = 0; i < Size; i++){
		cout << i + 1 << ": " << Date[i] << " |Next day: ";
		++Date[i];
		cout << " |Previous day: ";
		--Date[i];
	}

	cout << endl << "Find:\n";
	for(int i = 0; i < Size - 1; i++){
		if(Date[i].getyear() != Date[i + 1].getyear()){
			cout << i + 1 << ": " << Date[i + 1] << " | " << Date[i];
		}
	}

	delete[] Date;
	system("pause");
	return 0;
}