#include "pch.h"
#include <iostream>


using namespace std;

class MyExp{
private:
	int KeyError;
	const char* msg;
public:
	MyExp(int k, const char* m) :KeyError(k), msg(m){}
	int GetKey(){ return KeyError; }
	const char* GetMsg(){ return msg; }
};

class Figure{
protected:
	int *x, *y;
public:
	Figure(){
		x = new int;
		y = new int;
	}

	Figure(int x1, int y1){
		x = new int;
		y = new int;
		*x = x1;
		*y = y1;
	}

	Figure(int x1){
		x = new int;
		*x = x1;
		y = new int;
	}

	~Figure(){
		delete x;
		delete y;
	}

	virtual Figure* Copy() = 0;
	virtual double CalcArea() = 0;
	virtual void Show() = 0;
	virtual void Error(int v) throw (MyExp) = 0;
};


class Cylinder{
private:
	double* H;
	Figure* F;
public:

	Cylinder(Figure* F1, double h){
		F = F1->Copy();
		H = new double;
		*H = h;
	};

	~Cylinder(){
		delete F;
		delete H;
	}

	double CalcColVol(){
		try{
			Error(*H);
		} catch(MyExp& e){
			cout << "\nCatch |Key: " << e.GetKey() << " |Msg: " << e.GetMsg() << endl;
			return 0;
		} catch(...){
			cout << "\nUnknown error.";
			return 0;
		}
		return F->CalcArea()**H;
	}

	void Error(int v) throw (MyExp){
		if(v < 0){
			MyExp e(v, "Negative meaning.");
			throw e;
		}
	}

};

class Circle :public Figure{
public:
	Circle() :Figure(){};

	Circle(int size) :Figure(size){};

	~Circle(){}

	double CalcArea(){
		try{
			Error(*x);
		} catch(MyExp& e){
			cout << "\nCatch |Key: " << e.GetKey() << " |Msg: " << e.GetMsg() << endl;
			return 0;
		} catch(...){
			cout << "\nUnknown error.";
			return 0;
		}
		return 3.14 * (*x * *x);
	}

	void Show(){
		cout << "Area circle: " << CalcArea();
	}

	int* GetX(){
		return x;
	}

	Figure* Copy(){
		return new Circle(*x);
	};

	void Error(int v) throw (MyExp){
		if(v < 0){
			MyExp e(v, "Negative meaning.");
			throw e;
		}
	}

};

class Rectangle :public Figure{
public:
	Rectangle() :Figure(){};

	Rectangle(int x, int y) :Figure(x, y){};

	~Rectangle(){}

	double CalcArea(){
		try{
			Error(*x);
			Error(*y);
		} catch(MyExp& e){
			cout << "\nCatch |Key: " << e.GetKey() << " |Msg: " << e.GetMsg() << endl;
			return 0;
		} catch(...){
			cout << "\nUnknown error.";
			return 0;
		}
		return *x * *y;
	}

	void Show(){
		cout << "Area rectangle: " << CalcArea();
	}

	int* GetX(){
		return x;
	}
	int* GetY(){
		return y;
	}

	Figure* Copy(){
		return new Rectangle(*x, *y);
	};

	void Error(int v) throw (MyExp){
		if(v < 0){
			MyExp e(v, "Negative meaning.");
			throw e;
		}
	}
};



class Hexagon :public Figure{
public:
	Hexagon() :Figure(){};

	Hexagon(int x) :Figure(x){};

	~Hexagon(){}

	double CalcArea(){
		try{
			Error(*x);
		} catch(MyExp& e){
			cout << "\nCatch |Key: " << e.GetKey() << " |Msg: " << e.GetMsg() << endl;
			return 0;
		} catch(...){
			cout << "\nUnknown error.";
			return 0;
		}
		return (3 * sqrt(3) * (*x * *x)) / 2;
	}

	void Show(){
		cout << "Area Hexagon: " << CalcArea();
	}

	int* GetX(){
		return x;
	}

	Figure* Copy(){
		return new Hexagon(*x);
	};

	void Error(int v) throw (MyExp){
		if(v < 0){
			MyExp e(v, "Negative meaning.");
			throw e;
		}
	}
};


int main(){

	Figure* figure = nullptr;

	int key = 1, x = 0, y = 0;

	while(key <= 3 && key > 0){

		cout << "Select figure:\n"
			"1. Circle\n"
			"2. Rectangle\n"
			"3. Hexagon\n"
			"0. Exit\n"
			<< endl;

		cin >> key;

		switch(key){
		case 1:
			cout << "Enter to size Circle: ";
			cin >> x;
			figure = new Circle(x);
			break;
		case 2:
			cout << "Enter to size Rectangle: ";
			cin >> x >> y;
			figure = new Rectangle(x, y);
			break;
		case 3:
			cout << "Enter to size Hexagon: ";
			cin >> x;
			figure = new Hexagon(x);
			break;
		case 0:
			cout << "\nExit\n";
			figure = nullptr;
			break;
		default:
			cout << "\nError, this figure not found.\n";
			break;
		}

		if(figure != NULL){
			figure->Show();
			Cylinder* Cl = new Cylinder(figure, -10);
			delete figure;
			cout << "Volume: " << Cl->CalcColVol() << endl;
			delete Cl;
		}
	}

}

