#include "pch.h"
#include <iostream>
#include "MyDll.h"
#include "String"

using namespace std;
using namespace Dll;

class Tickets{
public:
	
	Tickets(){
		FlightNumber = 0;
		FullNamePassenger = " ";
		Destination = " ";
		Duration = 0;
	}

	void SetFlightNumber(int SFlightNumber){
		FlightNumber = SFlightNumber;
	}

	void SetFullNamePassenger(string SFullNamePassenger){
		FullNamePassenger = SFullNamePassenger;
	}

	void SetDestination(string SDestination){
		Destination = SDestination;
	}

	void SetDuration(int SDuration){
		Duration = SDuration;
	}

	void SetTickets(int SFlightNumber, string SFullNamePassenger, string SDestination, int SDuration){
		FlightNumber = SFlightNumber;
		FullNamePassenger = SFullNamePassenger;
		Destination = SDestination;
		Duration = SDuration;
	}

	int GetFlightNumber(){
		return FlightNumber;
	}

	string GetFullNamePassengerr(){
		return FullNamePassenger;
	}

	string GetDestination(){
		return Destination;
	}

	int GetDuration(){
		return Duration;
	}

	void OutAll(){
		cout << "Flight number: " << FlightNumber;
		cout << " |Full name passenger: " << FullNamePassenger;
		cout << " |Destination: " << Destination;
		cout << " |Duration: " << Duration << endl;
	}

private:
	int FlightNumber;
	string FullNamePassenger;
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
		if(MD.NumberWordText(Text, '|') != 4) cout << "Error, inappropriate word count in " << i+1 << " line." << endl;
		else{
			MD.GetWordText(Text, ListWord, '|');
			for(string s : ListWord){
				switch(k){
				case 1:
					Tick[NoEmpty].SetFlightNumber(stoi(s));
					break;
				case 2:
					Tick[NoEmpty].SetFullNamePassenger(s);
					break;
				case 3:
					Tick[NoEmpty].SetDestination(s);
					break;
				case 4:
					Tick[NoEmpty].SetDuration(stoi(s));
					break;
				}
				++k;
			}
			++NoEmpty;
		}
	}

	for(int i = 0; i < NoEmpty; i++)
		Tick[i].OutAll();
}