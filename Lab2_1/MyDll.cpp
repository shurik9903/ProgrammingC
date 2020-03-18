#include "pch.h"
#include "iostream"
#include "random"
#include "fstream"
#include "string"


using namespace std;

default_random_engine engine(random_device{}());

void Swap(int &a, int &b) {
	int c = a;
	a = b;
	b = c;
}

 /*Sorting*/
	void BubbleSort(int *Array, int length) {
		for (int i = 0; i < length - 1; i++) {
			for (int j = 0; j < length - 1; j++) {
				if (Array[j] > Array[j + 1]) Swap(Array[j], Array[j + 1]);
			}
		}
	}
	
	void BubbleSort(int **Array, int length, std::string SortBy) {

		if(SortBy == "Line"){
			for(int i = 0; i < length; i++){
				for(int s = 0; s < length - 1; s++){
					for(int j = 0; j < length - 1; j++){
						if(Array[i][j] > Array[i][j + 1]) Swap(Array[i][j], Array[i][j + 1]);
					}
				}
			}
		} else if(SortBy == "Column"){
			for(int i = 0; i < length; i++){
				for(int s = 0; s < length - 1; s++){
					for(int j = 0; j < length - 1; j++){
						if(Array[j][i] > Array[j][i + 1]) Swap(Array[j][i], Array[j][i + 1]);
					}
				}
			}
		}
	}

	void BubbleSort(int **Array, int length1, int length2, std::string SortBy){

		if(SortBy == "Line"){
			for(int i = 0; i < length1; i++){
				for(int s = 0; s < length2 - 1; s++){
					for(int j = 0; j < length2 - 1; j++){
						if(Array[i][j] > Array[i][j + 1]) Swap(Array[i][j], Array[i][j + 1]);
					}
				}
			}
		} else if(SortBy == "Column"){
			for(int i = 0; i < length1; i++){
				for(int s = 0; s < length2 - 1; s++){
					for(int j = 0; j < length2 - 1; j++){
						if(Array[j][i] > Array[j][i + 1]) Swap(Array[j][i], Array[j][i + 1]);
					}
				}
			}
		}
	}



/*File*/
	bool FileCheck(ifstream &UserFile){

		int length = 0;

		if (!UserFile) {

			UserFile.clear();
			UserFile.seekg(0);

			cout << "файл не найден.\n";
			return 0;
		}

		int N;
		while (UserFile >> N) {
			cout << N << endl;
			length++;
		}

		if (length == 0) {

			UserFile.clear();
			UserFile.seekg(0);

			cout << "Файл пуст.\n";
			return 0;
		}

		UserFile.clear();
		UserFile.seekg(0);
		return 1;
	}

	int FileLength(ifstream UserFile) {
		int length = 0,N;

		while (UserFile >> N) {
			cout << N << endl;
			length++;
		}

		if (length == 0) cout << "Файл пуст.\n";

		return length;
	}


/*ArrayOut*/
	void ArrayOut(int *Array, int length) {
		for (int i = 0; i < length; i++) {
			cout.width(3);
			cout << Array[i] << " | ";
		}
		cout << endl;
	}

	void ArrayOut(int **Array, int length) {
		for (int i = 0; i < length; i++) {
			cout << endl;
			for (int j = 0; j < length; j++) {
				cout.width(3);
				cout << Array[i][j] << " | ";
			}
		}
		cout << endl;
	}

	void ArrayOut(int **Array, int length1, int length2) {
		for (int i = 0; i < length1; i++) {
			cout << endl;
			for (int j = 0; j < length2; j++) {
				cout.width(3);
				cout << Array[i][j] << " | ";
			}
		}
		cout << endl;
	}


/*ArrayInt*/
void ArrayInt(int *Array, int length) {
	for (int i = 0; i < length; i++) {
		cin >> Array[i];
	}
}

void ArrayInt(int *Array, int length, int RandomStart, int RandomFinish) {
	uniform_int_distribution<int> distribut(RandomStart, RandomFinish);
	for (int i = 0; i < length; i++){
		Array[i] = distribut(engine);
	}
}

void ArrayInt(int **Array, int length1, int length2) {
	for (int i = 0; i < length1; i++) {
		for (int j = 0; j < length2; j++)
		{
			cin >> Array[i][j];
		}
	}
}

void ArrayInt(int **Array, int length1, int length2, int RandomStart, int RandomFinish) {
	uniform_int_distribution<int> distribut(RandomStart, RandomFinish);
	for (int i = 0; i < length1; i++) {
		for (int j = 0; j < length2; j++){
			Array[i][j] = distribut(engine);
		}
	}
}

void ArrayInt(int **Array, int length) {
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++)
		{
			cin >> Array[i][j];
		}
	}
}

void ArrayInt(int **Array, int length, int RandomStart, int RandomFinish) {
	uniform_int_distribution<int> distribut(RandomStart, RandomFinish);
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			Array[i][j] = distribut(engine);
		}
	}
}


/*FileArrayint*/
	void FileArrayInt(int *Array, int length, ifstream UserFile) {
		if (!FileCheck(UserFile)) return ;
		int N;
		for (int i = 0; UserFile >> N && i < length; i++) {
			Array[i] = N;
		}
	}

	void FileArrayInt(int *Array, ifstream UserFile) {
		if (!FileCheck(UserFile)) return ;
		int N;
		for (int i = 0; UserFile >> N; i++) {
			Array[i] = N;
		}
	}

	void FileArrayInt(int **Array, int length, ifstream UserFile) {
		if (!FileCheck(UserFile)) return ;
		int N;
		for (int i = 0; i < length; i++) {
			for (int j = 0; UserFile >> N && j < length; j++)
				Array[i][j] = N;
		}
	}

	void FileArrayInt(int **Array, int length1, int length2, ifstream UserFile) {
		if (!FileCheck(UserFile)) return ;
		int N;
		for (int i = 0; i < length1; i++) {
			for (int j = 0; UserFile >> N && j < length2; j++)
				Array[i][j] = N;
		}
	}

