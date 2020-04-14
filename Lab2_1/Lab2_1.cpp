#include "pch.h"
#include <iostream>
#include "random"

using namespace std;

void ArrayOut(int **, int);
void Swap(int &a, int &b);

int main(){
	int Size;
	int a, b;

	default_random_engine engine(random_device{}());

	do{
		cout << "Enter to size array: ";
		cin >> Size;
	} while(Size < 2);

	do{
		cout << "Enter to random range[a,b]: ";
		cin >> a >> b;
	} while(a >= b);

	uniform_int_distribution<int> distr(a, b);

	int **Mas = new int *[Size];
	for(int i = 0; i < Size; i++) Mas[i] = new int [Size];

	for(int i = 0; i < Size; i++)
		for(int j = 0; j < Size; j++)
			Mas[i][j] = distr(engine);
		
	int MaxI,MaxJ,Max = 0;
	int MinI, MinJ, Min = 0;

	for (int i = 0; i < Size; i++){
		for(int j = 0; j < Size - i; j++){
			if(Mas[i][j] < 0 && (Max < Mas[i][j] || Max == 0)){
				Max = Mas[i][j];
				MaxI = i; MaxJ = j;
			}
		}
	}

	ArrayOut(Mas,Size);

	if(Max == 0) cout << "No maximum negative element!\n"; else cout << "Maximum negative element: " << Max << endl;

	for(int i = 0; i < Size; i++){
		for(int j = Size-1; j >= Size - 1 - i && i < ceil(Size/2) ; j--){
			if(Mas[i][j] > 0 && (Min > Mas[i][j] || Min == 0)){
				Min = Mas[i][j];
				MinI = i; MinJ = j;
			}
		}
		for(int j = Size - 1; j >= ceil(Size/2) - (ceil(Size/2) -i) && i >= ceil(Size / 2); j--){
			if(Mas[i][j] > 0 && (Min > Mas[i][j] || Min == 0)){
				Min = Mas[i][j];
				MinI = i; MinJ = j;
			}
		}
	}
	
	if(Min == 0) cout << "No minimum positive element!\n"; else cout << "Minimum positive element: " << Min << endl;
	
	Swap(Mas[MaxI][MaxJ], Mas[MinI][MinJ]);
	ArrayOut(Mas, Size);

	for(int i = 0; i < Size; i++) delete[]Mas[i];
	delete[]Mas;

	system("pause");

	return 0;
}

