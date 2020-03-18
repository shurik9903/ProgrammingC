#include "stdafx.h"
#include <iostream>

int Walk = 0;
char Mas[3][3];

using namespace std;

void Message(){
	cout << endl;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cout << Mas[i][j] << " | ";
		}
		cout << endl << "-----------" << endl;
	}
	return;
}

void MovePlayer(int &Move){
	int Row, Col;
	
	do{
		cout << "Enter to coordinate(1-3 Row,1-3 Column): ";
		cin >> Row >> Col;

			if(!(Row > 3 || Col > 3 || Row < 1 || Col < 1))
				if(!(Mas[Row - 1][Col - 1] == 'X' || Mas[Row - 1][Col - 1] == 'O')) break;
				else cout << "This cell is already taken !" << endl;

	} while(true);

	if(Walk == 1) Mas[Row - 1][Col - 1] = 'X'; else Mas[Row - 1][Col - 1] = 'O';

	Message();
	Move++;
}

void EntCells(int &a,int &b, int step){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if((Mas[i][j] == ' ') && (step == 1)){
				a = i, b = j;
				return;
			} else if(Mas[i][j] == ' ') step--;
		}
	}
}

bool EmpCells(){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(Mas[i][j] == ' ') return true;
		}
	}
	return false;
}

void WinLose(int &EndGame){

	if(((Mas[0][0] == 'X') && (Mas[1][1] == 'X') && (Mas[2][2] == 'X')) ||
		((Mas[2][0] == 'X') && (Mas[1][1] == 'X') && (Mas[0][2] == 'X')) ||
		((Mas[0][0] == 'X') && (Mas[0][1] == 'X') && (Mas[0][2] == 'X')) ||
		((Mas[1][0] == 'X') && (Mas[1][1] == 'X') && (Mas[1][2] == 'X')) ||
		((Mas[2][0] == 'X') && (Mas[2][1] == 'X') && (Mas[2][2] == 'X')) ||
		((Mas[0][0] == 'X') && (Mas[1][0] == 'X') && (Mas[2][0] == 'X')) ||
		((Mas[0][1] == 'X') && (Mas[1][1] == 'X') && (Mas[2][1] == 'X')) ||
		((Mas[0][2] == 'X') && (Mas[1][2] == 'X') && (Mas[2][2] == 'X'))){

		EndGame = 1;
		
	}else if(((Mas[0][0] == 'O') && (Mas[1][1] == 'O') && (Mas[2][2] == 'O')) ||
		((Mas[2][0] == 'O') && (Mas[1][1] == 'O') && (Mas[0][2] == 'O')) ||
		((Mas[0][0] == 'O') && (Mas[0][1] == 'O') && (Mas[0][2] == 'O')) ||
		((Mas[1][0] == 'O') && (Mas[1][1] == 'O') && (Mas[1][2] == 'O')) ||
		((Mas[2][0] == 'O') && (Mas[2][1] == 'O') && (Mas[2][2] == 'O')) ||
		((Mas[0][0] == 'O') && (Mas[1][0] == 'O') && (Mas[2][0] == 'O')) ||
		((Mas[0][1] == 'O') && (Mas[1][1] == 'O') && (Mas[2][1] == 'O')) ||
		((Mas[0][2] == 'O') && (Mas[1][2] == 'O') && (Mas[2][2] == 'O'))){

		EndGame = 2;
	} 
}

void AI(int step, int Move, bool Play, int &ScoreWin){
	int i, j, Win = 0;

	EntCells(i, j, step);
	
		if(Play){
			if(Walk == 1) Mas[i][j] = 'O'; else Mas[i][j] = 'X';
			WinLose(Win);
			Move++;
			if((Walk == 1 && Win == 2) || (Walk == 2 && Win == 1)){
				ScoreWin = 10;
				Mas[i][j] = ' ';
			} else if(!EmpCells()) ScoreWin = 0;
			else{
				int BestScore = 10000;
				for(int m = 1; m <= (9 - Move); m++){
					AI(m, Move, false, ScoreWin);
					if(ScoreWin < BestScore) BestScore = ScoreWin;
				}
				ScoreWin = BestScore;
			}
			Mas[i][j] = ' ';
		} else{
			if(Walk == 1) Mas[i][j] = 'X'; else Mas[i][j] = 'O';
			WinLose(Win);
			Move++;
			if((Walk == 2 && Win == 2) || (Walk == 1 && Win == 1)){
				ScoreWin = -10;
				Mas[i][j] = ' ';
			} else if(!EmpCells()) ScoreWin = 0;
			else{
				int BestScore = -10000;
				for(int m = 1; m <= (9 - Move); m++){
					AI(m, Move, true, ScoreWin);
					if(ScoreWin > BestScore) BestScore = ScoreWin;
				}
				ScoreWin = BestScore;
			}
			Mas[i][j] = ' ';
		}
}

void AIPlayer(int &Move){
	int Besti = 0, Bestj = 0, BestScore= -10000, ScoreWin;
	for(int m = 1; m <= (9 - Move); m++){
		AI(m, Move, true, ScoreWin);
		if(ScoreWin > BestScore){
			BestScore = ScoreWin;
			EntCells(Besti, Bestj, m);
		}
	}

	if(Walk == 2) Mas[Besti][Bestj] = 'X'; else Mas[Besti][Bestj] = 'O';

	Message();
	Move++;
}

int main(){

	int Move = 0, EndGame = 0;

	do{
		cout << "How will you walk ?(1,2)" << endl;
		cin >> Walk;

		if(Walk == 1 || Walk == 2) break;
	} while(true);

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			Mas[i][j] = ' ';
		}
	}

	while(true){

		if(Move >= 9) EndGame = 3; else if(Move >= 3) WinLose(EndGame);
		if(EndGame != 0) break;

		if(Walk == 1){
			MovePlayer(Move);
			AIPlayer(Move);
		} else{
			AIPlayer(Move);
			if(Move >= 9) EndGame = 3; else if(Move >= 3) WinLose(EndGame);
			if(EndGame != 0) break;
			MovePlayer(Move);
		}
	}

	switch(EndGame){
		case 1: 
			if(Walk == 1) cout << "You win !" << endl; else cout << "You lose !" << endl;
		break;
		if(Walk == 2) cout << "You win !" << endl; else cout << "You lose !" << endl;
		case 2:

		break;
	default:
		cout << "Draw" << endl;
		break;
	}

	system("pause");

	return 0;
}
