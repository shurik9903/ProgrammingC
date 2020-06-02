#ifndef MY_DLL
#define MY_DLL

#include "string"
#include "fstream"
#include "list"



namespace Dll{
	class Date{
	public:

		Date();
		int GetDay();
		int GetMonth();
		int GetYear();
		int GetDate();
		std::string GetDateText();
		void setDate(int SDay, int SMonth, int SYear);
		void WhatIsDate();
		void setDate(std::string FullDate);

	private:
		
		int Day;
		int Month;
		int Year;
		bool LeapYear;
	};

	class MD_Class{
	public:

		

		void Swap(double &a, double &b);



		/*Matrix and Vector operations*/
							/*Resize*/

		void ArrayResize(double *&Array, int Size);

		void ArrayResize(double **&Array1, int OldSize, int NewSize);

		void ArrayResize(double **&Array1, int OldSize1, int OldSize2, int NewSize1, int NewSize2);

							/*Multiplication*/
		void VectorMultiplication(double *Vector1, double *Vector2, double **Array, int Size);

		void VectorMultiplication(double *Vector, int Size, int Number);

		void MatrixMultiplication(double **Array, int Size, int Number);

		void MatrixMultiplication(double **Array, int length1, int length2, int Number);

		void MatrixMultiplication(double **Array1, double **Array2, double **Array3, int Size);

		void MatrixMultiplication(double **Array1, double **Array2, int Size);

		void MatrixMultiplication(double **Array1, double **Array2, double **Array3, int length1, int length2);

		void MatrixMultiplication(double **&Array1, double **Array2, int length1, int length2);

		void MatrixVectorMultiplication(double **Array1, double *Vector1, double *Vector2, int Size);

							/*Subtraction */
		void VectorSubtraction(double *Vector1, double *Vector2, double *Vector3, int Size);

		void VectorSubtraction(double *Vector1, double *Vector2, int Size);

		void MatrixSubtraction(double **Array1, double **Array2, double **Array3, int Size);

		void MatrixSubtraction(double **Array1, double **Array2, int Size);

							/*Addition */
		void VectorAddition(double *Vector1, double *Vector2, double *Vector3, int Size);

		void VectorAddition(double *Vector1, double *Vector2, int Size);

		void MatrixAddition(double **Array1, double **Array2, double **Array3, int Size);

		void MatrixAddition(double **Array1, double **Array2, int Size);

							/*Transpose*/
		void MatrixTranspose(double **Array1, int Size);

		void MatrixTranspose(double **Array1, double **Array2, int Length1, int Length2);

		void MatrixTranspose(double **&Array1, int Length1, int Length2);



		/*Sorting*/
		void BubbleSort(double *Array, int length);

		void BubbleSort(double **Array, int length, std::string SortBy = "Array");

		void BubbleSort(double **Array, int length1, int length2, std::string SortBy = "Array");



		/*File*/
		void FileStartPosition(std::ifstream &UserFile);

		bool FileCheckInt(std::ifstream &UserFile);

		int FileLengthInt(std::ifstream &UserFile);

		bool FileCheckStr(std::ifstream &UserFile);

		int FileLengthStr(std::ifstream &UserFile);


		/*ArrayOut*/
		void ArrayOut(double *Array, int length);

		void ArrayOut(double **Array, int length);

		void ArrayOut(double **Array, int length1, int length2);



		/*ArrayInt*/
		void ArrayInt(double *Array, int length);

		void ArrayInt(double *Array, int length, int RandomStart, int RandomFinish);

		void ArrayInt(double **Array, int length1, int length2);

		void ArrayInt(double **Array, int length1, int length2, int RandomStart, int RandomFinish);

		void ArrayInt(double **Array, int length);

		void ArrayInt(double **Array, int length, int RandomStart, int RandomFinish);



		/*FileArrayint*/
		void FileArrayInt(double *Array, int length, std::ifstream &UserFile);

		void FileArrayInt(double *Array, std::ifstream &UserFile);

		void FileArrayInt(double **Array, int length, std::ifstream &UserFile);

		void FileArrayInt(double **Array, int length1, int length2, std::ifstream &UserFile);


		/*Work with text*/
		void ArrayTolower(char * text);
			
		int NumberWordText(std::string text, char Separator);

		int NumberWordText(std::string text);

		int NumberWordFile(std::ifstream &UserFile);

		int NumbertTextLine(std::ifstream &UserFile);

		std::string GetTextLine(std::ifstream & UserFile, int NumberLine);

		void GetWordText(std::string Text, std::list<std::string>& ListText, char Separator);

		void GetWordText(std::string Text, std::list<std::string>& ListText);

		void GetWordText(std::string Text, std::string* Word, char Separator);

		void GetWordText(std::string Text, std::string* Word);
	};
}

#endif