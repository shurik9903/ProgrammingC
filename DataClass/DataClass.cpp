// BovtMOAP1.cpp: определяет точку входа для консольного приложения.
// Вариант 8

#include "pch.h"
#include "cassert"
#include "iostream"
#include <cmath>
#include "ctime"
#include "MyDll.h"

using namespace std;
using namespace Dll;

class Timedelta{
private:
	int day;
	int month;
	int year;
	int seconds;
	int minutes;
	int hours;

public:

	Timedelta(int newday = 0, int newmonth = 0, int newyear = 0, int newseconds = 0, int newminutes = 0, int newhours = 0){

		day =  newday;
		month =  newmonth;
		year = newyear;
		seconds =  newseconds;
		minutes =  newminutes;
		hours = newhours;
	}

	void settime(int newday = 0, int newmonth = 0, int newyear = 0, int newseconds = 0, int newminutes = 0, int newhours = 0){

		struct tm newtime;
		time_t now = time(0);
		localtime_s(&newtime, &now);

		day = newday == 0 ? newtime.tm_mday : newday;
		month = newmonth == 0 ? 1 + newtime.tm_mon : newmonth;
		year = newyear == 0 ? 1900 + newtime.tm_year : newyear;
		seconds = newseconds == 0 ? newtime.tm_sec : newseconds;
		minutes = newminutes == 0 ? newtime.tm_min : newminutes;
		hours = newhours == 0 ? newtime.tm_hour : newhours;
	}

	friend Timedelta operator + (Timedelta a, Timedelta b){
		int day = abs(a.day - b.day);
		int month = abs(a.month - b.month);
		int year = abs(a.year - b.year);
		int hours = abs(a.hours - b.hours);
		int minutes = abs(a.minutes - b.minutes);
		int seconds = abs(a.seconds - b.seconds);
		return Timedelta(day, month, year, seconds, minutes, hours);
	}

	friend ostream& operator<<(ostream& os, const Timedelta& dt){
		os << dt.day << '/' << dt.month << '/' << dt.year << " " << dt.hours << ":" << dt.minutes << ":" << dt.seconds << endl;
		return os;
	}
};

int main(){

	MD_Class MD;

	ifstream UserFile("Data.txt");

	if(!MD.FileCheckStr(UserFile)){
		return 0;
	}

	if(MD.NumbertTextLine(UserFile) < 1){
		cout << "No data in file\n";
		return 0;
	}

	int Size = MD.NumbertTextLine(UserFile);

	Datetime *Date = new Datetime[Size];
	Timedelta timedelta[3];

	for(int i = 0; i < Size; i++){
		Date[i].Separation(MD.GetTextLine(UserFile, i+1));
	}


	for(int i = 0; i < Size; i++){
		cout << i+1 << ": " << Date[i];
	}

	cout << endl;

	for(int i = 0; i < Size; i++){
		cout << i + 1 << ": " << Date[i] << " |Next day: ";
		++Date[i];
		cout << " |Previous day: ";
		--Date[i];
	}

	cout << endl << "Find:\n";
	for(int i = 0; i < Size - 1; i++){
		if(Date[i].getyear() != Date[i + 1].getyear()){
			cout << i + 1 << ": " << Date[i + 1] << " | " << Date[i];
		}
	}

	delete[] Date;
	
	timedelta[0].settime(20, 8, 2020, 50, 30, 15);
	timedelta[1].settime(25, 11, 2020, 13, 45, 22);
	timedelta[2].settime();
	cout << endl << "The current date: " << timedelta[2];
	timedelta[2] = timedelta[0] + timedelta[1];

	cout << timedelta[2];

	system("pause");
	return 0;
}