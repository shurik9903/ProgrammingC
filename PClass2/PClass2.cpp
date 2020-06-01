#include "pch.h"
#include <iostream>
#include "MyDll.h"
#include "fstream"
#include "list"
#include "iterator"

using namespace std;
using namespace Dll;

class BookClass{
public:

	BookClass(){
		NameBook = "";
		AuthorFirstName = "";
		AuthorSecondName = "";
		AuthorMiddleName = "";
		NumberPages = 0;
	}

	string GetNameBook(){
		return NameBook;
	}

	string GetAuthorFirstName(){
		return AuthorFirstName;
	}

	string GetAuthorSecondName(){
		return AuthorSecondName;
	}

	string GetAuthorMiddleName(){
		return AuthorMiddleName;
	}

	int GetNumberPages(){
		return NumberPages;
	}

	int GetReleaseDate(){
		return ReleaseDate.GetDate();
	}

	string GetReleaseDateText(){
		return ReleaseDate.GetDateText();
	}

	void SetNameBook(string SNameBook){
		NameBook = SNameBook;
	}

	void SetAuthorFirstName(string SAuthorFirstName){
		AuthorFirstName = SAuthorFirstName;
	}

	void SetAuthorSecondName(string SAuthorSecondName){
		AuthorSecondName = SAuthorSecondName;
	}

	void SetAuthorMiddleName(string SAuthorMiddleName){
		AuthorMiddleName = SAuthorMiddleName;
	}

	void SetNumberPages(int SNumberPages){
		NumberPages = SNumberPages;
	}

	void SetReleaseDate(int SDay, int SMonth, int SYear){
		ReleaseDate.setDate(SDay, SMonth, SYear);
	}

	void SetReleaseDate(string SDate){
		ReleaseDate.setDate(SDate);
	}

	void OutAll(){
		cout << "NameBook: " << NameBook;
		cout << " |AuthorFirstName: " << AuthorFirstName;
		cout << " |AuthorSecondName: " << AuthorSecondName;
		cout << " |AuthorMiddleName: " << AuthorMiddleName;
		cout << " |NumberPages: " << NumberPages;
		cout << " |ReleaseDate: " << ReleaseDate.GetDateText() << endl;
	}

private:

	string NameBook;
	string AuthorFirstName;
	string AuthorSecondName;
	string AuthorMiddleName;
	int NumberPages;
	Date ReleaseDate;
};

int main(){

	MD_Class MD;

	ifstream UserFile("Book.txt");

	if(!MD.FileCheckStr(UserFile)){
		return 0;
	}

	int NumLine = MD.NumbertTextLine(UserFile);

	BookClass *Book = new BookClass[NumLine];

	string Text, Word;
	list<string> ListWord;
	int NoEmpty = 0;
	for(int i = 0; i < NumLine; i++){
		int k = 1;
		Text = MD.GetTextLine(UserFile, i+1);
		if(MD.NumberWordText(Text) != 6) cout << "Error, inappropriate word count in " << i << " line." << endl;
		else{
			MD.GetWordText(Text, ListWord);
			for(string s : ListWord){
				
				switch(k){
				case 1:
					Book[NoEmpty].SetNameBook(s);
					break;
				case 2:
					Book[NoEmpty].SetAuthorFirstName(s);
					break;
				case 3:
					Book[NoEmpty].SetAuthorSecondName(s);
					break;
				case 4:
					Book[NoEmpty].SetAuthorMiddleName(s);
					break;
				case 5:
					Book[NoEmpty].SetNumberPages(stoi(s));
					break;
				case 6:
					Book[NoEmpty].SetReleaseDate(s);
					break;
				}
				++k;
			}
			++NoEmpty;
		}
	}

	for(int i = 0; i < NoEmpty; i++)
		Book[i].OutAll();
	
}
