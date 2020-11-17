#include "pch.h"
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include "MyDll.h"

using namespace std;
using namespace Dll;

//Вывод
void Print(stack<char> s){
	for(int i = 0, size = s.size();  i < size; i++){
		cout << s.top();
		s.pop();
	}
	cout << endl;
}
void Print(queue<char> q){
	for(int i = 0, size = q.size(); i < size; i++){
		cout << q.front();
		q.pop();
	}
	cout << endl;
}

//Сравнение на палиндромом
bool SeqQ(stack<char> s, queue<char> q){

	if(s.empty() || q.empty()) return false;

	for(int i = 0, size = s.size(); i < size; i++){
		
		if(s.top() == ' '){
			s.pop();
			i++;
		}
		if(q.front() == ' ') q.pop();

		if(s.top() == q.front()){
			s.pop();
			q.pop();
		} else return false;
	}

	return true;
}

//Проверка на скобки
void Brack(stack<char> s){

	stack<char> x, y;

	if(s.empty()){
		cout << "Empty text.\n";
	} else{
		for(int i = 0, size = s.size(); i < size; i++){
			if(s.top() == ')' || s.top() == '('){
				if(x.empty() || s.top() == ')'){
					x.push(s.top());
					s.pop();
				} else if(x.top() == ')' && s.top() == '('){
					x.pop();
					s.pop();
				} else s.pop();
			} else if(s.top() == '}' || s.top() == '{'){
				if(y.empty() || s.top() == '}'){
					y.push(s.top());
					s.pop();
				} else if(y.top() == '}' && s.top() == '{'){
					y.pop();
					s.pop();
				} else s.pop();
			} else s.pop();
		}
		if(x.empty()) cout << "'(',')' There is a balance.\n"; else cout << "'(',')' No balance.\n";
		if(y.empty()) cout << "'{','}' There is a balance.\n"; else cout << "'{','}' No balance.\n";
	}
}

//Заполнение из текста
void PushString(string Text, stack<char> &s){
	for(int i = 0; i < Text.size(); i++) s.push(Text[i]);
}
void PushString(string Text, queue<char> &s){
	for(int i = 0; i < Text.size(); i++) s.push(Text[i]);
}

int main(){
	/*
	stack<char> s;
	queue<char> q;

	string Text;
	getline(cin, Text);


	PushString(Text, s);
	PushString(Text, q);

	cout << (SeqQ(s,q) ? "Polindrom\n" : "Ne polindrom\n") << endl;
  
	stack<char> s2;
	getline(cin, Text);
	PushString(Text, s2);
	Brack(s2);
	*/
	//---------------------------------------------------------------------------------------------------------------------------------
	//Задание 2

	vector<int> v;

	MD_Class MD;

	ifstream UserFile("Text.txt");

	if(!MD.FileCheckStr(UserFile)) return 0;
	
	int N;
	while(UserFile >> N) v.push_back(N);
	
	for(auto const &V : v)
		cout << V << ' ';
	cout << endl;

	int n,id = 1;
	cin >> n;
	cout << "ID: ";
	cout << " |Number: " <<  count_if(v.begin(), v.end(), [n,&id](int i){
		if(i == n) cout << id << " ";
		id++;
		return i == n; 
	}) << endl;
	
	id = 1;
	int sum1 = 0, sum2 = 0;
	cout << "ID: ";
	cout << " |Number: " << count_if(v.begin(), v.end(), [&id,&sum1,&sum2](int i){
		if(i % 2 == 0){
			cout << id << " ";
			sum1 += i;
		}
		sum2 += i;
		id++;
		return i % 2 == 0;
	}) << endl;

	n = count_if(v.begin(), v.end(), [](int i){return i % 2 == 0; });

	if(n > v.size() - n)
		cout << "Sum is odd: " << sum1 << endl;
	else cout << "Sum of all: " << sum2 << endl;

	vector<int> v2 = v;
	sort(v2.begin(), v2.end());


	cout << "Original: ";
	for(auto const &V : v)
		cout << V << ' ';
	cout << endl;

	cout << "Sort: ";
	for(auto const &V : v2)
		cout << V << ' ';
	cout << endl;

	cout << "Swap: ";
	swap(v[0], v[v.size()-1]);
	for(auto const &V : v)
		cout << V << ' ';
	cout << endl;
}
