#include "pch.h"
#include "MyDll.h"
#include <iostream>
#include "fstream"


using namespace std;
using namespace Dll;

int main(){

	MD_Class MD;

	int m, n;

	ifstream UserFile1("A.txt");
	ifstream UserFile2("B.txt");
	ifstream UserFile3("C.txt");
	ifstream UserFile4("D.txt");

	if(!MD.FileCheck(UserFile1) || !MD.FileCheck(UserFile2) || !MD.FileCheck(UserFile3) || !MD.FileCheck(UserFile4)){
		return 0;
	}

	do{
		cout << "Enter the number of rows, columns: ";
		cin >> m >> n;
	}while( m < 2 || n < 2);

	if((MD.FileLength(UserFile1) != (m*n)) || (MD.FileLength(UserFile2) != m) || 
		(MD.FileLength(UserFile3) != (m*n)) || (MD.FileLength(UserFile4) != m)){
		cout << "The size of the array does not match the number of numbers in the file!\n";
		return 0;
	}

	int *Vec1 = new int[m],*Vec2 = new int[m];
	int **Matrix3 = new int*[m], **Matrix1 = new int*[m], **Matrix2 = new int*[m];

	for(int i = 0; i < m; i++){
		Matrix1[i] = new int[n];
		Matrix2[i] = new int[n];
		Matrix3[i] = new int[m];
	}

	MD.FileArrayInt(Vec1, m, UserFile2);
	MD.FileArrayInt(Vec2, m, UserFile4);
	MD.FileArrayInt(Matrix1, m,n, UserFile1);
	MD.FileArrayInt(Matrix2, m,n, UserFile3);

	cout << "Vector B:\n";
	MD.ArrayOut(Vec1, m);
	cout << endl;

	cout << "Vector D:\n";
	MD.ArrayOut(Vec2, m);
	cout << endl;

	cout << "Matrix A:\n";
	MD.ArrayOut(Matrix1, m,n);
	cout << endl;

	cout << "Matrix C:\n";
	MD.ArrayOut(Matrix2, m,n);
	cout << endl;

	MD.VectorMultiplication(Vec1,m, 2);

	cout << "Vector B * 2:\n";
	MD.ArrayOut(Vec1, m);
	cout << endl;

	MD.VectorMultiplication(Vec1, Vec2, Matrix3, m);

	cout << "Vector B * Vector DT:\n";
	MD.ArrayOut(Matrix3, m);
	cout << endl;
	
	MD.MatrixTranspose(Matrix2, m,n);

	cout << "Transpose matrix C:\n";
	MD.ArrayOut(Matrix2, n,m);
	cout << endl;
	
	MD.MatrixMultiplication(Matrix1, m, n, -1);

	cout << "-A matrix:\n";
	MD.ArrayOut(Matrix1, m, n);
	cout << endl;

	MD.MatrixMultiplication(Matrix1, Matrix2, m,n);

	cout << "-A matrix * matrix C^T:\n";
	MD.ArrayOut(Matrix1, m);
	cout << endl;

	MD.MatrixSubtraction(Matrix1, Matrix3, m);

	cout << "-A * C^T - 2 * B * D^T :\n";
	MD.ArrayOut(Matrix1, m);
	cout << endl;

	for(int i = 0; i < m; i++){
		delete[]Matrix1[i];
		delete[]Matrix2[i];
		delete[]Matrix3[i];
	}

	delete[]Matrix1;
	delete[]Matrix2;
	delete[]Matrix3;
	
	system("pause");
	return 0;
}
