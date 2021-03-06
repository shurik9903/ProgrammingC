//10 Вариант 1 Задание

#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;

void Swap(int &a, int &b){
	int c = a;
	a = b;
	b = c;
}


int main(){
	setlocale(LC_ALL, "Russian");

	ifstream NumFile("Number.txt");
	int n = 0,N;

	if(!NumFile){
		cout << "файл не найден.\n";
		return 0;
	}

	while(NumFile >> N){
		cout << N << endl;
		if(N < 0) n++;
	}
	if(n == 0){
		cout << "Файл пуст или не имеет отрицательных чисел.\n";
		return 0;
	}

	NumFile.clear();
	NumFile.seekg(0);

	int *Mas = new int[n];

	for(int i = 0; NumFile >> N;){
		if(N < 0){
			Mas[i] = N;
			i++;
		}
	}

	
	for(int i=0; i < n-1; i++){
		for(int j=0; j < n - 1; j++){
			if(Mas[j] < Mas[j + 1]) Swap(Mas[j], Mas[j + 1]);
		}
	}

	cout << "отсортированный по возрастанию массив отрицательных чисел\n";
	for(int i = 0; i < n; i++) cout << Mas[i] << endl;

	delete[]Mas;
	NumFile.close();
	system("pause");
	return 0;
}
