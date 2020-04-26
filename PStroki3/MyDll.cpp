#include "pch.h"
#include "MyDll.h"
#include "iostream"
#include "random"
#include "fstream"
#include "string"
#include "list"

using namespace std;
using namespace Dll;

default_random_engine engine(random_device{}());

	void MD_Class::Swap(double &a, double &b){
		double c = a;
		a = b;
		b = c;
	}


	/*Matrix and Vector operations*/
						/*Resize*/
	void MD_Class::ArrayResize(double *&Array, int Size){
		Array = (double *)realloc(Array, sizeof(double) * Size);
	}

	void MD_Class::ArrayResize(double **&Array1,int OldSize,int NewSize){
		double **Array = new double*[NewSize];
		for(int i = 0; i < NewSize; i++)
			Array[i] = new double[NewSize];

		for(int i = 0; (i < OldSize) && (i < NewSize); i++)
			for(int j = 0; (j < OldSize) && (j < NewSize); j++)
				Array[i][j] = Array1[i][j];

		for(int i = 0; i < OldSize; i++) delete[]Array1[i];
		delete[]Array1;

		Array1 = Array;
	}

	void MD_Class::ArrayResize(double **&Array1, int OldSize1, int OldSize2, int NewSize1, int NewSize2){
		double **Array = new double*[NewSize1];
		for(int i = 0; i < NewSize1; i++)
			Array[i] = new double[NewSize2];

		for(int i = 0; (i < OldSize1) && (i < NewSize1); i++)
			for(int j = 0; (j < OldSize2) && (j < NewSize2); j++)
				Array[i][j] = Array1[i][j];

		for(int i = 0; i < OldSize1; i++) delete[]Array1[i];
		delete[]Array1;

		Array1 = Array;
	}

						/*Multiplication*/
	void MD_Class::VectorMultiplication(double *Vector1, double *Vector2, double **Array, int Size){
		for(int i = 0; i < Size; i++)
			for(int j = 0; j < Size; j++)
				Array[i][j] = Vector1[i] * Vector2[j];
	}

	void MD_Class::VectorMultiplication(double *Vector, int Size, int Number){
		for(int i = 0; i < Size; i++)
			Vector[i] = Vector[i] * Number;
	}

	void MD_Class::MatrixMultiplication(double **Array, int Size, int Number){
		for(int i = 0; i < Size; i++)
			for(int j = 0; j < Size; j++)
				Array[i][j] = Array[i][j] * Number;
	}

	void MD_Class::MatrixMultiplication(double **Array, int Length1, int Length2, int Number){
		for(int i = 0; i < Length1; i++)
			for(int j = 0; j < Length2; j++)
				Array[i][j] = Array[i][j] * Number;
	}

	void MD_Class::MatrixMultiplication(double **Array1, double **Array2, double **Array3, int Size){
		for(int i = 0; i < Size; i++)
			for(int j = 0; j < Size; j++){
				double sum = 0;
				for(int k = 0; k < Size; k++)
					sum += Array1[i][k] * Array2[k][j];
				Array3[i][j] = sum;
			}
	}

	void MD_Class::MatrixMultiplication(double **Array1, double **Array2, int Size){
	
		double **Array = new double*[Size];
		for(int i = 0; i < Size; i++)
			Array[i] = new double[Size];

		for(int i = 0; i < Size; i++)
			for(int j = 0; j < Size; j++){
				double sum = 0;
				for(int k = 0; k < Size; k++)
					sum += Array1[i][k] * Array2[k][j];
				Array[i][j] = sum;
			}

		for(int i = 0; i < Size; i++)
			for(int j = 0; j < Size; j++)
				Array1[i][j] = Array[i][j];

		for(int i = 0; i < Size; i++) delete[]Array[i];
		delete[]Array;

	}

	void MD_Class::MatrixMultiplication(double **Array1, double **Array2, double **Array3, int Length1, int Length2){
		for(int i = 0; i < Length1; i++)
			for(int j = 0; j < Length2; j++){
				double sum = 0;
				for(int k = 0; k < Length2; k++)
					sum += Array1[i][k] * Array2[k][j];
				Array3[i][j] = sum;
			}
	}
		
	void MD_Class::MatrixMultiplication(double **&Array1, double **Array2, int Length1, int Length2){
		if(Length1 == Length2) MatrixMultiplication(Array1, Array2, Length1);
		else{

			double **Array = new double*[Length1];
			for(int i = 0; i < Length1; i++)
				Array[i] = new double[Length1];

			for(int i = 0; i < Length1; i++)
				for(int j = 0; j < Length1; j++){
					double sum = 0;
					for(int k = 0; k < Length2; k++)
						sum += Array1[i][k] * Array2[k][j];
					Array[i][j] = sum;
				}

			ArrayResize(Array1, Length1, Length2, Length1, Length1);
			
			for(int i = 0; i < Length1; i++)
				for(int j = 0; j < Length1; j++)
					Array1[i][j] = Array[i][j];

			for(int i = 0; i < Length1; i++) delete[]Array[i];
			delete[]Array;
		}
	}

	void MD_Class::MatrixVectorMultiplication(double **Array1, double *Vector1, double *Vector2, int Size){
		for(int j = 0; j < Size; j++)
			for(int i = 0; i < Size; i++)
				Array1[i][j] = Array1[i][j] * Vector1[j];
		
		ArrayOut(Array1, Size);

		for(int i = 0; i < Size; i++)
			for(int j = 0; j < Size; j++)
				Vector2[i] += Array1[i][j];
	}

						/*Addition */
	void MD_Class::VectorAddition(double *Vector1, double *Vector2, double *Vector3, int Size){
		for(int i = 0; i < Size; i++)
			Vector3[i] = Vector1[i] + Vector2[i];
	}

	void MD_Class::VectorAddition(double *Vector1, double *Vector2, int Size){
		for(int i = 0; i < Size; i++)
				Vector1[i] += Vector2[i];
	}

	void MD_Class::MatrixAddition(double **Array1, double **Array2, double **Array3, int Size){
		for(int i = 0; i < Size; i++)
			for(int j = 0; j < Size; j++)
				Array3[i][j] = Array1[i][j] + Array2[i][j];
	}

	void MD_Class::MatrixAddition(double **Array1, double **Array2, int Size){
		for(int i = 0; i < Size; i++)
			for(int j = 0; j < Size; j++)
				Array1[i][j] += Array2[i][j];
	}

						/*Subtraction */
	void MD_Class::VectorSubtraction(double *Vector1, double *Vector2, double *Vector3, int Size){
		for(int i = 0; i < Size; i++)
			Vector3[i] = Vector1[i] - Vector2[i];
	}

	void MD_Class::VectorSubtraction(double *Vector1, double *Vector2, int Size){
		for(int i = 0; i < Size; i++)
			Vector1[i] -= Vector2[i];
	}

	void MD_Class::MatrixSubtraction(double **Array1, double **Array2, double **Array3, int Size){
		for(int i = 0; i < Size; i++)
			for(int j = 0; j < Size; j++)
				Array3[i][j] = Array1[i][j] - Array2[i][j];
	}

	void MD_Class::MatrixSubtraction(double **Array1, double **Array2, int Size){
		for(int i = 0; i < Size; i++)
			for(int j = 0; j < Size; j++)
				Array1[i][j] -= Array2[i][j];
	}

						/*Transpose */
	void MD_Class::MatrixTranspose(double **Array1, int Size){
		for(int i = 0; i < Size; i++)
			for(int j = 1+i; j < Size; j++)
				Swap(Array1[i][j], Array1[j][i]);
	}

	void MD_Class::MatrixTranspose(double **Array1, double **Array2, int Length1, int Length2){
		for(int i = 0; i < Length2; i++)
			for(int j = 0; j < Length1; j++)
				Array2[i][j] = Array1[j][i];
	}

	void MD_Class::MatrixTranspose(double **&Array1, int Length1, int Length2){
		double **Array = new double*[Length1];
		for(int i = 0; i < Length1; i++)
			Array[i] = new double[Length2];

		for(int i = 0; i < Length1; i++)
			for(int j = 0; j < Length2; j++)
				Array[i][j] = Array1[i][j];

		ArrayResize(Array1, Length1, Length2, Length2, Length1);

		for(int i = 0; i < Length2; i++)
			for(int j = 0; j < Length1; j++)
				Array1[i][j] = Array[j][i];

		for(int i = 0; i < Length1; i++) delete[]Array[i];
		delete[]Array;
	}


	/*Sorting*/
	void MD_Class::BubbleSort(double *Array, int length){
		for(int i = 0; i < length - 1; i++){
			for(int j = 0; j < length - 1; j++){
				if(Array[j] > Array[j + 1]) Swap(Array[j], Array[j + 1]);
			}
		}
	}

	void MD_Class::BubbleSort(double **Array, int length, std::string SortBy){

		if(SortBy == "Array"){
			int Numb = length * length;
			for(int k = 0; k < Numb - 1; k++){
				for(int i = 0; i < Numb - k - 1; ++i){
					if(Array[i / length][i % length] > (Array[(i + 1) / length][(i + 1) % length]))
						Swap(Array[i / length][i % length], Array[(i + 1) / length][(i + 1) % length]);
				}
			}
		} else if(SortBy == "Line"){
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

	void MD_Class::BubbleSort(double **Array, int length1, int length2, std::string SortBy){
		if(SortBy == "Array"){
			int Numb = length1 * length2;
			for(int k = 0; k < Numb - 1; k++){
				for(int i = 0; i < Numb - k - 1; ++i){
					if(Array[i / length2][i % length2] > (Array[(i + 1) / length2][(i + 1) % length2]))
						Swap(Array[i / length2][i % length2], Array[(i + 1) / length2][(i + 1) % length2]);
				}
			}
		} else if(SortBy == "Line"){
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
	void MD_Class::FileStartPosition(ifstream &UserFile){
		UserFile.clear();
		UserFile.seekg(0);
	}

	bool MD_Class::FileCheckInt(ifstream &UserFile){

		int length = 0;

		if(!UserFile){

			FileStartPosition(UserFile);

			cout << "File not found.\n";
			return 0;
		}

		double N;
		while(UserFile >> N) length++;


		if(length == 0){

			FileStartPosition(UserFile);

			cout << "File empty.\n";
			return 0;
		}

		FileStartPosition(UserFile);
		return 1;
	}

	int MD_Class::FileLengthInt(ifstream &UserFile){
		int length = 0;
		double N;
		while(UserFile >> N) length++;
	

		if(length == 0) cout << "File empty.\n";

		FileStartPosition(UserFile);

		return length;
	}

	bool MD_Class::FileCheckStr(ifstream &UserFile){

		int length = 0;

		if(!UserFile){

			FileStartPosition(UserFile);

			cout << "File not found.\n";
			return 0;
		}

		char N;
		while(UserFile >> N) length++;


		if(length == 0){

			FileStartPosition(UserFile);

			cout << "File empty.\n";
			return 0;
		}

		FileStartPosition(UserFile);
		return 1;
	}

	int MD_Class::FileLengthStr(ifstream &UserFile){
		int length = 0;
		char N;
		while(UserFile >> N) length++;


		if(length == 0) cout << "File empty.\n";

		FileStartPosition(UserFile);

		return length;
	}



	/*ArrayOut*/
	void MD_Class::ArrayOut(double *Array, int length){
		for(int i = 0; i < length; i++){
			cout.width(3);
			cout << Array[i] << " | ";
		}
		cout << endl;
	}

	void MD_Class::ArrayOut(double **Array, int length){
		for(int i = 0; i < length; i++){
			cout << endl;
			for(int j = 0; j < length; j++){
				cout.width(3);
				cout << Array[i][j] << " | ";
			}
		}
		cout << endl;
	}

	void MD_Class::ArrayOut(double **Array, int length1, int length2){
		for(int i = 0; i < length1; i++){
			cout << endl;
			for(int j = 0; j < length2; j++){
				cout.width(3);
				cout << Array[i][j] << " | ";
			}
		}
		cout << endl;
	}



	/*ArrayInt*/
	void MD_Class::ArrayInt(double *Array, int length){
		for(int i = 0; i < length; i++){
			cin >> Array[i];
		}
	}

	void MD_Class::ArrayInt(double *Array, int length, int RandomStart, int RandomFinish){
		uniform_int_distribution<int> distribut(RandomStart, RandomFinish);
		for(int i = 0; i < length; i++){
			Array[i] = distribut(engine);
		}
	}

	void MD_Class::ArrayInt(double **Array, int length1, int length2){
		for(int i = 0; i < length1; i++){
			for(int j = 0; j < length2; j++){
				cin >> Array[i][j];
			}
		}
	}

	void MD_Class::ArrayInt(double **Array, int length1, int length2, int RandomStart, int RandomFinish){
		uniform_int_distribution<int> distribut(RandomStart, RandomFinish);
		for(int i = 0; i < length1; i++){
			for(int j = 0; j < length2; j++){
				Array[i][j] = distribut(engine);
			}
		}
	}

	void MD_Class::ArrayInt(double **Array, int length){
		for(int i = 0; i < length; i++){
			for(int j = 0; j < length; j++){
				cin >> Array[i][j];
			}
		}
	}

	void MD_Class::ArrayInt(double **Array, int length, int RandomStart, int RandomFinish){
		uniform_int_distribution<int> distribut(RandomStart, RandomFinish);
		for(int i = 0; i < length; i++){
			for(int j = 0; j < length; j++){
				Array[i][j] = distribut(engine);
			}
		}
	}


	/*FileArrayInt*/
	void MD_Class::FileArrayInt(double *Array, int length, ifstream &UserFile){
		if(!FileCheckInt(UserFile)) return;
		double N;
		for(int i = 0; UserFile >> N && i < length; i++){
			Array[i] = N;
		}
		FileStartPosition(UserFile);
	}

	void MD_Class::FileArrayInt(double *Array, ifstream &UserFile){
		if(!FileCheckInt(UserFile)) return;
		double N;
		for(int i = 0; UserFile >> N; i++){
			Array[i] = N;
		}
		FileStartPosition(UserFile);
	}

	void MD_Class::FileArrayInt(double **Array, int length, ifstream &UserFile){
		if(!FileCheckInt(UserFile)) return;
		double N;
		for(int i = 0; i < length; i++){
			for(int j = 0; j < length; j++)
				if(UserFile >> N) Array[i][j] = N;	
		}
		FileStartPosition(UserFile);
	}

	void MD_Class::FileArrayInt(double **Array, int length1, int length2, ifstream &UserFile){
		if(!FileCheckInt(UserFile)) return;
		double N;
		for(int i = 0; i < length1; i++){
			for(int j = 0;j < length2; j++)
				if(UserFile >> N) Array[i][j] = N;
		}
		FileStartPosition(UserFile);
	}


	/*Work with text*/
	void MD_Class::ArrayTolower(char * text){
		for(int i = 0; i < strlen(text); i++) text[i] = tolower(text[i]);
	}

	int MD_Class::NumberWordText(std::string text){
		int Count = 0;
		bool word = false;

		for(char s : text){
			if((s == ' ' || s == '\n') && word){
				Count++;
				word = false;
			} else word = true;
		}

		if(word) return ++Count; else return Count;
	}

	int MD_Class::NumberWordFile(ifstream &UserFile){
		int Numb = 0;
		string text;
		while(UserFile >> text) Numb++;

		FileStartPosition(UserFile);

		return Numb;
	}

	int MD_Class::NumbertTextLine(ifstream &UserFile){
		int Numb = 0;
		string text;

		while(std::getline(UserFile,text)) Numb++;

		FileStartPosition(UserFile);

		return Numb;
	}

	std::string MD_Class::GetTextLine(ifstream &UserFile, int NumberLine){
		string text = "";
		int Numb = 1;

		while(std::getline(UserFile, text) && (NumberLine != Numb)) Numb++;

		FileStartPosition(UserFile);

		return text;
	}

	void MD_Class::GetWordText(std::string text, list<std::string>& ListText){
		string TextWord;
		bool word = false;

		for(char s : text){

			if((s == ' ' || s == '\n') && word){
				ListText.push_front(TextWord);
				word = false;
				TextWord = "";
			} else{
				word = true;
				TextWord += s;
			}
		}

		if(word) ListText.push_front(TextWord);
		
	}