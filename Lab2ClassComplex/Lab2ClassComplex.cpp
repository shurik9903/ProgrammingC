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

class Vector{
private:
	double x, y;
public:

	Vector(double nx = 0, double ny = 0){
		x = nx;
		y = ny;
	}

	Vector(const Vector &vector) : x(vector.x), y(vector.y){}

	~Vector(){

	}

	double LengthVector(){
		return abs(sqrt((x * x) + (y * y)));
	}

	void setvector(double nx, double ny){
		x = nx;
		y = ny;
	}

	void setx(double nx){
		x = nx;
	}

	void sety(double ny){
		y = ny;
	}

	double getx(){
		return x;
	}

	double gety(){
		return y;
	}

	double Scolar(Vector vector){
		return ((x * vector.x) + (y * vector.y));
	}

	double Angle(Vector vector){
		return cos(Scolar(vector) / (LengthVector() * vector.LengthVector()));
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

	friend ostream& operator<<(ostream& out, const Vector &vector){
		out << "X: " << vector.x << " |Y: " << vector.y << endl;
		return out;
	}

	friend istream& operator>> (istream& is, Vector &vector){
		is >> vector.x >> vector.y;
		return is;
	}

	friend Vector operator+(const Vector &v1, const Vector &v2){
		return Vector(v1.x + v2.x,v1.y + v2.y);
	}

	friend Vector operator*(const Vector &v1, int a){
		return Vector(v1.x * a, v1.y * a);
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

	Vector v1{1,3}, v2;

	cin >> v2;

	cout << "Vec1: " << v1 << "Vec2: " << v2;

	cout << "Sum: ";
	cout << v1 + v2;

	cout << "Multi: ";
	cout << v1 * 5;

	cout << v1.Scolar(v2);

	cout << "Large: ";
	cout << (v1 > v2) << endl;

	cout << "Less: ";
	cout << (v1 < v2) << endl;

	v1.setvector(2, 2);
	v2.setvector(2, 2);

	cout << endl << "Vec1: " << v1 << "Vec2: " << v2;

	cout << "Equally: ";
	cout << (v1 == v2) << endl;

	cout << "Not equally: ";
	cout << (v1 != v2) << endl;

	cout << "Angle: ";
	cout << v1.Angle(v2) << endl;
}
