#ifndef MY_DLL
#define MY_DLL

#include "string"
#include "fstream"

namespace Dll{
	class MD_Class{
	public:

		void Swap(int &a, int &b);



		/*Matrix and Vector operations*/
							/*Resize*/

		void ArrayResize(int *&Array, int Size);

		void ArrayResize(int **&Array1, int OldSize, int NewSize);

		void ArrayResize(int **&Array1, int OldSize1, int OldSize2, int NewSize1, int NewSize2);

							/*Multiplication*/
		void VectorMultiplication(int *Vector1, int *Vector2, int **Array, int Size);

		void VectorMultiplication(int *Vector, int Size, int Number);

		void MatrixMultiplication(int **Array, int Size, int Number);

		void MatrixMultiplication(int **Array, int length1, int length2, int Number);

		void MatrixMultiplication(int **Array1, int **Array2, int **Array3, int Size);

		void MatrixMultiplication(int **Array1, int **Array2, int Size);

		void MatrixMultiplication(int **Array1, int **Array2, int **Array3, int length1, int length2);

		void MatrixMultiplication(int **&Array1, int **Array2, int length1, int length2);

		void MatrixVectorMultiplication(int **Array1, int *Vector1, int *Vector2, int Size);

							/*Subtraction */
		void VectorSubtraction(int *Vector1, int *Vector2, int *Vector3, int Size);

		void VectorSubtraction(int *Vector1, int *Vector2, int Size);

		void MatrixSubtraction(int **Array1, int **Array2, int **Array3, int Size);

		void MatrixSubtraction(int **Array1, int **Array2, int Size);

							/*Addition */
		void VectorAddition(int *Vector1, int *Vector2, int *Vector3, int Size);

		void VectorAddition(int *Vector1, int *Vector2, int Size);

		void MatrixAddition(int **Array1, int **Array2, int **Array3, int Size);

		void MatrixAddition(int **Array1, int **Array2, int Size);

							/*Transpose*/
		void MatrixTranspose(int **Array1, int Size);

		void MatrixTranspose(int **Array1, int **Array2, int Length1, int Length2);

		void MatrixTranspose(int **&Array1, int Length1, int Length2);



		/*Sorting*/
		void BubbleSort(int *Array, int length);

		void BubbleSort(int **Array, int length, std::string SortBy = "Array");

		void BubbleSort(int **Array, int length1, int length2, std::string SortBy = "Array");



		/*File*/
		void FileStartPosition(std::ifstream &UserFile);

		bool FileCheck(std::ifstream &UserFile);

		int FileLength(std::ifstream &UserFile);



		/*ArrayOut*/
		void ArrayOut(int *Array, int length);

		void ArrayOut(int **Array, int length);

		void ArrayOut(int **Array, int length1, int length2);



		/*ArrayInt*/
		void ArrayInt(int *Array, int length);

		void ArrayInt(int *Array, int length, int RandomStart, int RandomFinish);

		void ArrayInt(int **Array, int length1, int length2);

		void ArrayInt(int **Array, int length1, int length2, int RandomStart, int RandomFinish);

		void ArrayInt(int **Array, int length);

		void ArrayInt(int **Array, int length, int RandomStart, int RandomFinish);



		/*FileArrayint*/
		void FileArrayInt(int *Array, int length, std::ifstream &UserFile);

		void FileArrayInt(int *Array, std::ifstream &UserFile);

		void FileArrayInt(int **Array, int length, std::ifstream &UserFile);

		void FileArrayInt(int **Array, int length1, int length2, std::ifstream &UserFile);


	};
}

#endif