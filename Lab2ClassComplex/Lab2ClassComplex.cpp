#include "pch.h"
#include <iostream>

using namespace std;

class ComplexNumbers{
private:
	double a, b, i;

public:

	ComplexNumbers(double A = 0, double B = 0){
		a = A;
		b = B;	
		i = 1;
	}

	ComplexNumbers(const ComplexNumbers &complex) : a(complex.a), b(complex.b){}

	void seta(double A){
		a = A;
	}

	void setb(double B){
		b = B;
	}

	void setab(double A, double B){
		a = A;
		b = B;
	}

	double geta(){
		return a;
	}

	double getb(){
		return b;
	}

	double LengthComplex(){
		return abs(sqrt((a * a) + (b * b)));
	}

	friend ComplexNumbers operator+(const ComplexNumbers &c1, const ComplexNumbers &c2){
		return ComplexNumbers(c1.a + c2.a,c1.b + c2.b);
	}

	friend ComplexNumbers operator-(const ComplexNumbers &c1, const ComplexNumbers &c2){
		return ComplexNumbers(c1.a - c2.a, c1.b - c2.b);
	}

	friend ComplexNumbers operator*(const ComplexNumbers &c1, const ComplexNumbers &c2){
		return ComplexNumbers( ((c1.a * c2.a) + (c1.b * c2.b)*-1) , ((c1.b * c2.a) + (c1.a * c2.b)) );
	}

	friend ComplexNumbers operator/(const ComplexNumbers &c1, const ComplexNumbers &c2){
		return ComplexNumbers( (((c1.a * c2.a) + (c1.b * c2.b)) / ((c2.a * c2.a) + (c2.b * c2.b))) , (((c1.b * c2.a) - (c1.a * c2.b)) / ((c2.a * c2.a) + (c2.b * c2.b))) );
	}

	bool operator>(ComplexNumbers &complex){
		return LengthComplex() > complex.LengthComplex();
	}

	bool operator<(ComplexNumbers &complex){
		return LengthComplex() < complex.LengthComplex();
	}

	bool operator==(ComplexNumbers &complex){
		return LengthComplex() == complex.LengthComplex();
	}

	bool operator!=(ComplexNumbers &complex){
		return LengthComplex() != complex.LengthComplex();
	}

	friend ostream& operator<<(ostream& out, const ComplexNumbers &complex){
		if(complex.i == 0){
			if(complex.a == 0 && complex.b == 0) out << "0\n";
			else if(complex.a == 0) out << complex.b << endl;
			else if(complex.b == 0) out << complex.a << endl;
			else if(complex.b > 0) out << complex.a << " + " << complex.b << endl;
			else out << complex.a << " " << complex.b << endl;
		} else{
			if(complex.a == 0 && complex.b == 0) out << "0\n";
			else if(complex.a == 0) out << complex.b << "*i\n";
			else if(complex.b == 0) out << complex.a << endl;
			else if(complex.b > 0) out << complex.a << " + " << complex.b << "*i\n";
			else out << complex.a << " " << complex.b << "*i\n";
		}
		return out;
	}

	friend istream& operator>> (istream& is, ComplexNumbers &complex){
		is >> complex.a >> complex.b;
		return is;
	}

};

class Matrix;

class Vector{

	friend Matrix;
private:
	int size;
	double *x;

public:

	Vector(int NSize = 0, double* Array = NULL){
		size = abs(NSize);
		x = NULL;
		if(NSize != 0){
			x = new double[size];
			for(int i = 0; i < size; i++)
				x[i] = Array[i];
		}
	}

	Vector(const Vector &vector) : x(vector.x), size(vector.size){}

	void ArrayResize(int NewSize){
		double *Array = new double[NewSize];
		for(int i = 0; (i < size) && (i < NewSize); i++)
			Array[i] = x[i];

		size = NewSize;

		delete[]x;
		x = Array;
	}

	int Size(){
		return size;
	}

	void add(double value){
		ArrayResize(size);
		x[size - 1] = value;
	}

	double Scolar(Vector vector){
		return ((x[0] * vector.x[0]) + (x[1] * vector.x[1]));
	}

	double Angle(Vector vector){

		return cos(Scolar(vector) / (LengthVector() * vector.LengthVector()));
	}

	double LengthVector(){
		double Summ = 0;
		for(int i = 0; i < size-1; i++)
			Summ += abs(sqrt((x[i] * x[i]) + (x[i + 1] * x[i + 1])));
		return Summ;
	}

	friend istream& operator>> (istream& is, Vector &vector){
		for(int i = 0; i < vector.size; i++) if(vector.x[i] == NULL && vector.x[i] != 0){
			is >> vector.x[i];
			return is;
		}

		vector.ArrayResize(vector.size + 1);
		is >> vector.x[vector.size - 1];
		return is;
		
	}

	friend ostream& operator<<(ostream& out, const Vector &vector){
		if(vector.size == 0){
			out << "This array empty.\n" << endl;
			return out;
		} else{
			for(int i = 0; i < vector.size; i++){
				out << i+1 << ": " << vector.x[i] << endl;
			}

			return out;
		}
	}

	friend Vector operator+(const Vector &v1, const Vector &v2){
		Vector vector;
		if(v1.size != v2.size){
			cout << "Error, different size vectors.\n";
			exit(0);
		}else{
			vector.ArrayResize(v1.size);
			for(int i = 0; i < vector.size; i++) vector.x[i] = v1.x[i] + v2.x[i];
		}
		return vector;
	}

	friend Vector operator*(const Vector &v1, int a){
		Vector vector;
		vector.ArrayResize(v1.size);
		for(int i = 0; i < v1.size; i++) vector.x[i] = v1.x[i] * a;
		return vector;
	}

	bool operator>(Vector &vector){

		return LengthVector() > vector.LengthVector();
	}

	bool operator<(Vector &vector){
		return LengthVector() < vector.LengthVector();
	}

	bool operator==(Vector &vector){
		return LengthVector() == vector.LengthVector();
	}

	bool operator!=(Vector &vector){
		return LengthVector() != vector.LengthVector();
	}

	double& operator[](int index){
		if(size <= index || index <= 0){
			cout << "Error, there is no variable with this index\n";
			exit(0);
		} else return x[index];
	}

	~Vector(){
	}

};

class Matrix{
private:
	int Sx, Sy;
	double **XY;
public:

	void ArrayResize(int NewSize1, int NewSize2){
		double **Array = new double*[NewSize1];
		for(int i = 0; i < NewSize1; i++)
			Array[i] = new double[NewSize2];

		for(int i = 0; (i < Sx) && (i < NewSize1); i++)
			for(int j = 0; (j < Sy) && (j < NewSize2); j++)
				Array[i][j] = XY[i][j];

		for(int i = 0; i < Sx; i++) delete[]XY[i];
		delete[]XY;

		Sx = NewSize1;
		Sy = NewSize2;

		XY = Array;
	}

	void setSize(int NewSize1, int NewSize2){
		XY = new double*[NewSize1];
		for(int i = 0; i < NewSize1; i++)
			XY[i] = new double[NewSize2];

		Sx = NewSize1;
		Sy = NewSize2;
	}

	Matrix(int NSx = 0, int NSy = 0){
		Sx = abs(NSx);
		Sy = abs(NSy);
		XY = NULL;
		if(Sx != 0 && Sy != 0){
			XY = new double*[Sx];
			for(int i = 0; i < Sx; i++)
				XY[i] = new double[Sy];

			for(int i = 0; i < Sx; i++)
				for(int j = 0; j < Sy; j++)
					XY[i][j] = NULL;
		}
	}

	Matrix(const Matrix &matrix) : XY(matrix.XY), Sx(matrix.Sx), Sy(matrix.Sy){}

	~Matrix(){
	}

	friend istream& operator>> (istream& is, Matrix &matrix){
		for(int i = 0; i < matrix.Sx; i++) 
			for(int j = 0; j < matrix.Sy; j++)
					is >> matrix.XY[i][j];
					return is;
	}

	friend ostream& operator<<(ostream& out, const Matrix &matrix){
		if(matrix.Sx == 0 || matrix.Sy == 0){
			out << "This array empty.\n" << endl;
			return out;
		} else{
			for(int i = 0; i < matrix.Sx; i++){
				out << endl;
				for(int j = 0; j < matrix.Sy; j++){
					out.width(3);
					out << matrix.XY[i][j] << " | ";
				}
			}
			out << endl;
		}
		return out;
	}

	friend Matrix operator+(const Matrix &m1, const Matrix &m2){
		Matrix matrix;
		if(m1.Sx != m2.Sx || m1.Sy != m2.Sy){
			cout << "Error, different size matrix.\n";
			exit(0);
		}else{
			matrix.ArrayResize(m1.Sx,m1.Sy);
			for(int i = 0; i < matrix.Sx; i++)
				for(int j = 0; j < matrix.Sy; j++)
					matrix.XY[i][j] = m1.XY[i][j] + m2.XY[i][j];
		}
		return matrix;
	}

	friend Matrix operator*(const Matrix &m1, int a){
		Matrix matrix;
		matrix.ArrayResize(m1.Sx, m1.Sy);
		for(int i = 0; i < matrix.Sx; i++)
			for(int j = 0; j < matrix.Sy; j++)
				matrix.XY[i][j] = m1.XY[i][j] * a;

		return matrix;
	}

	 friend Vector operator*(const Matrix &m1, Vector &v1){
		Vector vector;
		vector.ArrayResize(v1.Size());
		
		if(m1.Sx != v1.Size() || m1.Sy != v1.Size()){
			cout << "Error, different size matrix.\n";
			exit(0);
		} else{
			for(int j = 0; j < v1.Size(); j++)
				for(int i = 0; i < v1.Size(); i++)
					m1.XY[i][j] = m1.XY[i][j] * v1[j];
			
			for(int i = 0; i < v1.Size(); i++)
				for(int j = 0; j < v1.Size(); j++)
					vector[i] = m1.XY[i][j];
				
		}

		return vector;
	}

	friend Matrix operator*(const Matrix &m1, const Matrix &m2){
		Matrix matrix;
		if((m1.Sx != m2.Sy || m1.Sy != m2.Sx) && (m1.Sx != m2.Sx || m1.Sy != m2.Sy)){
			cout << "Error, different size matrix.\n";
			exit(0);
		}else{
			matrix.ArrayResize(m1.Sx,m1.Sy);
			for(int i = 0; i < matrix.Sx; i++)
				for(int j = 0; j < matrix.Sy; j++){
					double sum = 0;
					for(int k = 0; k < matrix.Sy; k++)
						sum += m1.XY[i][k] * m2.XY[k][j];
					matrix.XY[i][j] = sum;
				}
		}

		return matrix;
	}

};

int main(){

	
	ComplexNumbers c1{1,3}, c2;

	cin >> c2;//{4,-5}

	cout << "Com1: " << c1 << "Com2: " << c2;

	cout << "Sum: ";
	cout << c1 + c2;

	c1.setab(-2, 1);
	c2.setab(3, 5);

	cout << endl << "Com1: " << c1 << "Com2: " << c2;

	cout << "Sub: ";
	cout << c1 - c2;

	c1.setab(1, -1);
	c2.setab(3, 6);

	cout << endl << "Com1: " << c1 << "Com2: " << c2;

	cout << "Multi: ";
	cout << c1 * c2;

	c1.setab(13, 1);
	c2.setab(7, -6);

	cout << endl << "Com1: " << c1 << "Com2: " << c2;

	cout << "Div: ";
	cout << c1 / c2;

	c1.setab(2, 2);
	c2.setab(3, 2);
	
	cout << "Large: ";
	cout << (c1 > c2) << endl;

	cout << "Less: ";
	cout << (c1 < c2) << endl;

	c1.setab(2, 2);
	c2.setab(2, 2);

	cout << endl << "Com1: " << c1 << "Com2: " << c2;

	cout << "Equally: ";
	cout << (c1 == c2) << endl;

	cout << "Not equally: ";
	cout << (c1 != c2) << endl;
	

	cout << "\n---Vectors---\n";
	double s[] = {1,2,3,4,5};
	Vector v1(5,s), v2;
	
	for(int i = 0; i < 5; i++){
		cin >> v2;
	}

	cout << "Vec1:\n" << v1 << "Vec2:\n" << v2;

	cout << "Sum: ";
	cout << v1 + v2;

	cout << "Multi: ";
	cout << v1 * 5;

	cout << "Scolar: ";
	cout << v1.Scolar(v2) << endl;

	cout << "Angle: ";
	cout << v1.Angle(v2) << endl;

	cout << "Large: ";
	cout << (v1 > v2) << endl;

	cout << "Less: ";
	cout << (v1 < v2) << endl;


	Vector v3{5,s}, v4{5,s};

	cout << endl << "Vec3:\n" << v3 << "Vec4:\n" << v4;

	cout << "Equally: ";
	cout << (v3 == v4) << endl;

	cout << "Not equally: ";
	cout << (v4 != v3) << endl;

	double x[] = {9,8,7,6,5};
	Vector v5{5,s}, v6{5,x};

	cout << endl << "Vec5:\n" << v5 << "Vec6:\n" << v6;

	cout << "Equally: ";
	cout << (v5 == v6) << endl;

	cout << "Not equally: ";
	cout << (v5 != v6) << endl;
	

	cout << "\n---Matrix---\n";
	double b[] = {3,7,9};

	Matrix m1(3,3), m2;
	Vector v0(3, b);

	m2.setSize(3,3);

	cin >> m1;

	cin >> m2;

	
		
	cout << "Mat1:\n" << m1 << "Mat2:\n" << m2;

	cout << "Sum: ";
	cout << m1 + m2;

	cout << "Multi1: ";
	cout << m1 * 5;

	cout << "Multi2: ";
	cout << m1 * m2;

	cout << "Multi3: ";
	cout << "Vector: " << v0 << endl;
	cout << m1 * v0;


}
