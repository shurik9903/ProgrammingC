//10 Вариант 2 задание

#include "pch.h"
#include <iostream>
#include <random>

using namespace std;

int main(){
	setlocale(LC_ALL, "Russian");

	default_random_engine generate;
	

	int a, b, k,n,negative = 0;
	do{
		cout << "Введите размер интервала(a,b): "; cin >> a; cin >> b;
	} while(a >= b);

	uniform_int_distribution<int> distribut(a, b);

	cout << "Введите размер массива: "; cin >> n;
	cout << "Введите число K: "; cin >> k;

	int *Mas = new int[n];

	for(int i = 0; i < n; i++){
		Mas[i] = distribut(generate);
		cout << Mas[i] << endl;
		if(Mas[i] < 0) negative++;
	}

	cout << "Сформированный массив: \n";
	for(int i = 0; i < negative; i++){
		cout << Mas[i] << endl;
	}

	negative += n;
	Mas = (int *)realloc(Mas, negative * sizeof(int));

	for(int i = 0; i < n; i++){
		if(Mas[i] < 0){
			n++;
			for(int j = n - 1; j > i + 1; j--){
				Mas[j] = Mas[j - 1];
			}
			Mas[i + 1] = k;
			i++;
		}
	}

	cout << "Конечный результат: \n";

	for(int i = 0; i < negative; i++){
		cout << Mas[i] << endl;
	}

	delete[]Mas;
	system("pause");

	return 0;
}

