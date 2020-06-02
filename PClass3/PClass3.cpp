#include "pch.h"
#include <iostream>
#include "MyDll.h"
#include "String"
#include <algorithm>

using namespace std;
using namespace Dll;

class Tickets{
public:
	
	Tickets(){
		FlightNumber = 0;
		PassengerFirstName = " ";
		PassengerSecondName = " ";
		PassengerMiddleName = " ";
		Destination = " ";
		Duration = 0;
	}

	void SetFlightNumber(int SFlightNumber){
		FlightNumber = SFlightNumber;
	}

	void SetPassengerFirstName(string SPassengerFirstName){
		PassengerFirstName = SPassengerFirstName;
	}

	void SetPassengerSecondName(string SPassengerSecondName){
		PassengerSecondName = SPassengerSecondName;
	}

	void SetPassengerMiddleName(string SPassengerMiddleName){
		PassengerMiddleName = SPassengerMiddleName;
	}

	void SetDestination(string SDestination){
		Destination = SDestination;
	}

	void SetDuration(int SDuration){
		Duration = SDuration;
	}

	void SetTickets(int SFlightNumber, string SPassengerFirstName, string SPassengerSecondName, string SPassengerMiddleName, string SDestination, int SDuration){
		FlightNumber = SFlightNumber;
		PassengerFirstName = SPassengerFirstName;
		PassengerSecondName = SPassengerSecondName;
		PassengerMiddleName = SPassengerMiddleName;
		Destination = SDestination;
		Duration = SDuration;
	}

	int GetFlightNumber(){
		return FlightNumber;
	}

	string GetPassengerFirstName(){
		return PassengerFirstName;
	}

	string GetPassengerSecondName(){
		return PassengerSecondName;
	}

	string GetPassengerMiddleName(){
		return PassengerMiddleName;
	}

	string GetDestination(){
		return Destination;
	}

	int GetDuration(){
		return Duration;
	}

	void OutAll(){
		cout << "Flight number: " << FlightNumber;
		cout << " |Passenger first name: " << PassengerFirstName;
		cout << " |Passenger second name: " << PassengerSecondName;
		cout << " |Passenger middle name: " << PassengerMiddleName;
		cout << " |Destination: " << Destination;
		cout << " |Duration: " << Duration << endl;
	}

private:
	int FlightNumber;
	string PassengerFirstName;
	string PassengerSecondName;
	string PassengerMiddleName;
	string Destination;
	int Duration;
};

int main(){
	MD_Class MD;

	ifstream UserFile("Tickets.txt");

	if(!MD.FileCheckStr(UserFile)){
		return 0;
	}

	int NumLine = MD.NumbertTextLine(UserFile);
	Tickets *Tick = new Tickets[NumLine];

	string Text, Word;
	list<string> ListWord;

	int NoEmpty = 0;
	
	for(int i = 0; i < NumLine; i++){
		int k = 1;
		Text = MD.GetTextLine(UserFile, i + 1);
		if(MD.NumberWordText(Text, '|') != 6) cout << "Error, inappropriate word count in " << i + 1 << " line." << endl;
		else{
			MD.GetWordText(Text, ListWord, '|');
			for(string s : ListWord){
				switch(k){
				case 1:
					Tick[NoEmpty].SetFlightNumber(stoi(s));
					break;
				case 2:
					Tick[NoEmpty].SetPassengerSecondName(s);
					break;
				case 3:
					Tick[NoEmpty].SetPassengerFirstName(s);
					break;
				case 4:
					Tick[NoEmpty].SetPassengerMiddleName(s);
					break;
				case 5:
					Tick[NoEmpty].SetDestination(s);
					break;
				case 6:
					Tick[NoEmpty].SetDuration(stoi(s));
					break;
				}
				++k;
			}
			++NoEmpty;
		}
	}
	
	int SizeNewClass = 0;

	for(int i = 0; i < NoEmpty; i++){
		Tick[i].OutAll();

		if(Tick[i].GetDuration() > 180)
			++SizeNewClass;
	}

	cout << "\nFind flight number 'Sidorov': \n";
	for(int i = 0; i < NoEmpty; i++){
		if(Tick[i].GetPassengerSecondName() == "Sidorov")
			cout << Tick[i].GetFlightNumber() << endl;
	}


	Tickets *FindTic = new Tickets[SizeNewClass];
	

	for(int i = 0,j = 0; i < NoEmpty; i++)
		if(Tick[i].GetDuration() > 180){
			FindTic[j] = Tick[i];
			++j;
		}

	Tickets Temp;
	for(int i = 0; i < SizeNewClass - 1; i++){
		for(int j = 0; j < SizeNewClass - i - 1; j++){
			if(FindTic[j].GetPassengerSecondName() > FindTic[j + 1].GetPassengerSecondName()){
				Temp = FindTic[j];
				FindTic[j] = FindTic[j + 1];
				FindTic[j + 1] = Temp;
			}
			
		}
	}
	
	cout << "\nInformation on all tickets for flights lasting more than three hours: \n\n";
	for(int i = 0; i < SizeNewClass; i++)
		FindTic[i].OutAll();

	
}