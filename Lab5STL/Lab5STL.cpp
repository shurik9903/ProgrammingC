#include "pch.h"
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class STL{
private:
	stack<string> stl;
	stack<string> Cstl;
	int Priority = -1;

	//Проверка на число
	bool TypeIntOrDouble(std::string Text){
		if(Text == "") return false;
		else if(Text.find_first_not_of("-0123456789") == string::npos && (Text.find_last_of("-") == 0 || Text.find_last_of("-") == string::npos) && Text != "-")return true;
		else if(Text.find_first_of(".") != 0 && Text.find_last_of(".") != Text.size() - 1 && Text.find_first_not_of("-0123456789.") == string::npos && (Text.find_first_of("0123456789") == 0 || Text.find_first_of("0123456789") == 1) && Text.find_last_of("0123456789") == Text.size() - 1 && (Text.find_first_of(".") == Text.find_last_of(".")) && (Text.find_last_of("-") == 0 || Text.find_last_of("-") == string::npos) && Text != "-"){
			return true;
		}
		else return false;
	}

	//Получение копии Stack уменьшенного на 'n' 
	stack<string> StepDown(stack<string> s1,int D){ 
		stack<string> s2;
		s2 = s1;
		for(int i = 1; i <= D ; i++) s2.pop();
		return s2;
	}


	string Calculation(stack<string> s){
		//Возврещение значения конечного Stack
		if(s.size() <= 1) return s.top();
		
		//Проверка на число
		else if(TypeIntOrDouble(s.top())){

			string Char = Calculation(StepDown(s, 1));
			if(Char == ")") return s.top();
			else{

				if(Char == "+"){
					if(StepDown(s, 2).top() == "("){
						int x = 1;
						stack<string> s2 = StepDown(s, 3);
						while(x != 0){
							if(s2.top() == ")") --x;
							if(s2.top() == "(") ++x;
							s2.pop();
						}

						if(s2.size() > 1){
							if(s2.top() == "+") return to_string((atof(s.top().c_str()) + atof(Calculation(StepDown(s, 2)).c_str())) + atof(Calculation(StepDown(s2, 1)).c_str()));
							if(s2.top() == "-") return to_string((atof(s.top().c_str()) + atof(Calculation(StepDown(s, 2)).c_str())) - atof(Calculation(StepDown(s2, 1)).c_str()));
							if(s2.top() == "*"){
								string result = to_string(atof(s.top().c_str()) + (atof(Calculation(StepDown(s, 2)).c_str())) * atof(Calculation(StepDown(s2, 1)).c_str()));
								if(StepDown(s2, 2).top() == "+") return to_string(atof(result.c_str()) + atof(Calculation(StepDown(s2, 3)).c_str()));
								if(StepDown(s2, 2).top() == "-") return to_string(atof(result.c_str()) - atof(Calculation(StepDown(s2, 3)).c_str()));
								if(StepDown(s2, 2).top() == "*") return to_string(atof(result.c_str()) * atof(Calculation(StepDown(s2, 3)).c_str()));
								if(StepDown(s2, 2).top() == "/") return to_string(atof(result.c_str()) / atof(Calculation(StepDown(s2, 3)).c_str()));
								else return result;
							}
							if(s2.top() == "/"){
								
								string result = to_string(atof(s.top().c_str()) + (atof(Calculation(StepDown(s, 2)).c_str())) / atof(Calculation(StepDown(s2, 1)).c_str()));
								if(StepDown(s2, 2).top() == "+") return to_string(atof(result.c_str()) + atof(Calculation(StepDown(s2, 3)).c_str()));
								if(StepDown(s2, 2).top() == "-") return to_string(atof(result.c_str()) - atof(Calculation(StepDown(s2, 3)).c_str()));
								if(StepDown(s2, 2).top() == "*") return to_string(atof(result.c_str()) * atof(Calculation(StepDown(s2, 3)).c_str()));
								if(StepDown(s2, 2).top() == "/") return to_string(atof(result.c_str()) / atof(Calculation(StepDown(s2, 3)).c_str()));
								else return result;
							}
						} else return to_string(atof(s.top().c_str()) + atof(Calculation(StepDown(s, 2)).c_str()));

					} else return to_string(atof(s.top().c_str()) + atof(Calculation(StepDown(s, 2)).c_str()));
				}
				if(Char == "-"){
					if(StepDown(s, 2).top() == "("){
						int x = 1;
						stack<string> s2 = StepDown(s, 3);
						while(x != 0){
							if(s2.top() == ")") --x;
							if(s2.top() == "(") ++x;
							s2.pop();
						}

						if(s2.size() > 1){
							if(s2.top() == "+") return to_string((atof(s.top().c_str()) - atof(Calculation(StepDown(s, 2)).c_str())) + atof(Calculation(StepDown(s2, 1)).c_str()));
							if(s2.top() == "-") return to_string((atof(s.top().c_str()) - atof(Calculation(StepDown(s, 2)).c_str())) - atof(Calculation(StepDown(s2, 1)).c_str()));
							if(s2.top() == "*"){
								string result = to_string(atof(s.top().c_str()) - (atof(Calculation(StepDown(s, 2)).c_str())) * atof(Calculation(StepDown(s2, 1)).c_str()));
								if(StepDown(s2, 2).top() == "+") return to_string(atof(result.c_str()) + atof(Calculation(StepDown(s2, 3)).c_str()));
								if(StepDown(s2, 2).top() == "-") return to_string(atof(result.c_str()) - atof(Calculation(StepDown(s2, 3)).c_str()));
								if(StepDown(s2, 2).top() == "*") return to_string(atof(result.c_str()) * atof(Calculation(StepDown(s2, 3)).c_str()));
								if(StepDown(s2, 2).top() == "/") return to_string(atof(result.c_str()) / atof(Calculation(StepDown(s2, 3)).c_str()));
								else return result;
							}
							if(s2.top() == "/"){
								string result = to_string(atof(s.top().c_str()) - (atof(Calculation(StepDown(s, 2)).c_str())) / atof(Calculation(StepDown(s2, 1)).c_str()));
								if(StepDown(s2, 2).top() == "+") return to_string(atof(result.c_str()) + atof(Calculation(StepDown(s2, 3)).c_str()));
								if(StepDown(s2, 2).top() == "-") return to_string(atof(result.c_str()) - atof(Calculation(StepDown(s2, 3)).c_str()));
								if(StepDown(s2, 2).top() == "*") return to_string(atof(result.c_str()) * atof(Calculation(StepDown(s2, 3)).c_str()));
								if(StepDown(s2, 2).top() == "/") return to_string(atof(result.c_str()) / atof(Calculation(StepDown(s2, 3)).c_str()));
								else return result;
							}
						} else return to_string(atof(s.top().c_str()) - atof(Calculation(StepDown(s, 2)).c_str()));

					} else return to_string(atof(s.top().c_str()) - atof(Calculation(StepDown(s, 2)).c_str()));
					
			}
				if(Char == "*"){

					if(StepDown(s, 2).top() != "(" && StepDown(s, 2).size() <= 1)
						return to_string( atof(s.top().c_str()) * atof(StepDown(s, 2).top().c_str()));
					else if(StepDown(s, 2).top() != "(" && StepDown(s, 2).size() > 1){
						string Char2 = Calculation(StepDown(s, 3));
						if(Char2 == "+") return to_string( (atof(s.top().c_str()) * atof(StepDown(s, 2).top().c_str())) + atof(Calculation(StepDown(s, 4)).c_str()) );
						if(Char2 == "-") return to_string( (atof(s.top().c_str()) * atof(StepDown(s, 2).top().c_str())) - atof(Calculation(StepDown(s, 4)).c_str()) );
						if(Char2 == "*") return to_string( (atof(s.top().c_str()) * atof(StepDown(s, 2).top().c_str())) * atof(Calculation(StepDown(s, 4)).c_str()) );
						if(Char2 == "/") return to_string( (atof(s.top().c_str()) * atof(StepDown(s, 2).top().c_str())) / atof(Calculation(StepDown(s, 4)).c_str()) );
						else return to_string(atof(s.top().c_str()) * atof(StepDown(s, 2).top().c_str()));
						
					} else {
						int x = 1;
						stack<string> s2 = StepDown(s, 3);
						while(x != 0){
							if(s2.top() == ")") --x;
							if(s2.top() == "(") ++x;
							s2.pop();
						}

						if(s2.size() > 1){
							if(s2.top() == "+") return to_string((atof(s.top().c_str()) * atof(Calculation(StepDown(s, 2)).c_str())) + atof(Calculation(StepDown(s2, 1)).c_str()));
							if(s2.top() == "-") return to_string((atof(s.top().c_str()) * atof(Calculation(StepDown(s, 2)).c_str())) - atof(Calculation(StepDown(s2, 1)).c_str()));
							if(s2.top() == "*"){
								string result = to_string((atof(s.top().c_str()) * atof(Calculation(StepDown(s, 2)).c_str())) * atof(Calculation(StepDown(s2, 1)).c_str()));
								if(StepDown(s2, 2).top() == "+") return to_string(atof(result.c_str()) + atof(Calculation(StepDown(s2, 3)).c_str()));
								if(StepDown(s2, 2).top() == "-") return to_string(atof(result.c_str()) - atof(Calculation(StepDown(s2, 3)).c_str()));
								if(StepDown(s2, 2).top() == "*") return to_string(atof(result.c_str()) * atof(Calculation(StepDown(s2, 3)).c_str()));
								if(StepDown(s2, 2).top() == "/") return to_string(atof(result.c_str()) / atof(Calculation(StepDown(s2, 3)).c_str()));
								else return result;
							}
							if(s2.top() == "/"){
								string result = to_string((atof(s.top().c_str()) * atof(Calculation(StepDown(s, 2)).c_str())) / atof(Calculation(StepDown(s2, 1)).c_str()));
								if(StepDown(s2, 2).top() == "+") return to_string(atof(result.c_str()) + atof(Calculation(StepDown(s2, 3)).c_str()));
								if(StepDown(s2, 2).top() == "-") return to_string(atof(result.c_str()) - atof(Calculation(StepDown(s2, 3)).c_str()));
								if(StepDown(s2, 2).top() == "*") return to_string(atof(result.c_str()) * atof(Calculation(StepDown(s2, 3)).c_str()));
								if(StepDown(s2, 2).top() == "/") return to_string(atof(result.c_str()) / atof(Calculation(StepDown(s2, 3)).c_str()));
								else return result;
							}
						}else return to_string( atof(s.top().c_str()) * atof(Calculation(StepDown(s, 2)).c_str()) );
					}
				}

				if(Char == "/"){

					if(StepDown(s, 2).top() != "(" && StepDown(s, 2).size() <= 1)
						return to_string( atof(s.top().c_str()) / atof(StepDown(s, 2).top().c_str()));
					else if(StepDown(s, 2).top() != "(" && StepDown(s, 2).size() > 1){
						string Char2 = Calculation(StepDown(s, 3));
						if(Char2 == "+") return to_string( (atof(s.top().c_str()) / atof(StepDown(s, 2).top().c_str())) + atof(Calculation(StepDown(s, 4)).c_str()) );
						if(Char2 == "-") return to_string( (atof(s.top().c_str()) / atof(StepDown(s, 2).top().c_str())) - atof(Calculation(StepDown(s, 4)).c_str()) );
						if(Char2 == "*") return to_string( (atof(s.top().c_str()) / atof(StepDown(s, 2).top().c_str())) * atof(Calculation(StepDown(s, 4)).c_str()) );
						if(Char2 == "/") return to_string( (atof(s.top().c_str()) / atof(StepDown(s, 2).top().c_str())) / atof(Calculation(StepDown(s, 4)).c_str()) );
						else return to_string(atof(s.top().c_str()) / atof(StepDown(s, 2).top().c_str()));
					} else{

						int x = 1;
						stack<string> s2 = StepDown(s, 3);
						while(x != 0){
							if(s2.top() == ")") --x;
							if(s2.top() == "(") ++x;
							s2.pop();
						}

						if(s2.size() > 1){
							if(s2.top() == "+") return to_string((atof(s.top().c_str()) / atof(Calculation(StepDown(s, 2)).c_str())) + atof(Calculation(StepDown(s2, 1)).c_str()));
							if(s2.top() == "-") return to_string((atof(s.top().c_str()) / atof(Calculation(StepDown(s, 2)).c_str())) - atof(Calculation(StepDown(s2, 1)).c_str()));
							if(s2.top() == "*"){
								string result = to_string((atof(s.top().c_str()) / atof(Calculation(StepDown(s, 2)).c_str())) * atof(StepDown(s2, 1).top().c_str()));
								if(StepDown(s2, 2).top() == "+") return to_string(atof(result.c_str()) + atof(Calculation(StepDown(s2, 3)).c_str()));
								if(StepDown(s2, 2).top() == "-") return to_string(atof(result.c_str()) - atof(Calculation(StepDown(s2, 3)).c_str()));
								if(StepDown(s2, 2).top() == "*") return to_string(atof(result.c_str()) * atof(Calculation(StepDown(s2, 3)).c_str()));
								if(StepDown(s2, 2).top() == "/") return to_string(atof(result.c_str()) / atof(Calculation(StepDown(s2, 3)).c_str()));
								else return result;
							}
							if(s2.top() == "/"){
								string result = to_string((atof(s.top().c_str()) / atof(Calculation(StepDown(s, 2)).c_str())) / atof(StepDown(s2, 1).top().c_str()));
								if(StepDown(s2, 2).top() == "+") return to_string(atof(result.c_str()) + atof(Calculation(StepDown(s2, 3)).c_str()));
								if(StepDown(s2, 2).top() == "-") return to_string(atof(result.c_str()) - atof(Calculation(StepDown(s2, 3)).c_str()));
								if(StepDown(s2, 2).top() == "*") return to_string(atof(result.c_str()) * atof(Calculation(StepDown(s2, 3)).c_str()));
								if(StepDown(s2, 2).top() == "/") return to_string(atof(result.c_str()) / atof(Calculation(StepDown(s2, 3)).c_str()));
								else return result;
							}
						} else  return to_string(atof(s.top().c_str()) / atof(Calculation(StepDown(s, 2)).c_str()));
					}
				}
				return "Error11";
			}
		}
		
		//Проверка на символ
		if(s.top() == "+" || s.top() == "-" || s.top() == "*" || s.top() == "/") return s.top(); 

		//Проверка на начало и закрытие скобок
		if(s.top() == "("){
			if(s.size() == stl.size()){

				int x = 1;
				stack<string> s2 = StepDown(s, 3);
				while(x != 0){
					if(s2.top() == ")") --x;
					if(s2.top() == "(") ++x;
					s2.pop();
				}

				if(s2.size() > 1){

					if(s2.top() == "+") return to_string( atof(Calculation(StepDown(s, 1)).c_str())  + atof(Calculation(StepDown(s2, 1)).c_str()) );
					if(s2.top() == "-") return to_string( atof(Calculation(StepDown(s, 1)).c_str()) - atof(Calculation(StepDown(s2, 1)).c_str()) );
					if(s2.top() == "*") return to_string( atof(Calculation(StepDown(s, 1)).c_str()) * atof(Calculation(StepDown(s2, 1)).c_str()) );
					if(s2.top() == "/") return to_string( atof(Calculation(StepDown(s, 1)).c_str()) / atof(Calculation(StepDown(s2, 1)).c_str()) );
					return Calculation(StepDown(s2, 1));
				} else return Calculation(StepDown(s, 1));
			}else return Calculation(StepDown(s, 1));
			
			
		}
		else if(s.top() == ")") return s.top();

		return "Error0";

		
	}


	

public:

	STL(string text){
		stl = PushString(text,stl);
	}

	//Проверка на скобки
	bool Brack(){
		stack<string> x, y;
		stack<string> s = stl;
		if(s.empty()){
			cout << "Empty text.\n";
			return 0;
		} else{
			for(int i = 0, size = s.size(); i < size; i++){
				if(s.top() == ")" || s.top() == "("){
					if(x.empty() || s.top() == ")"){
						x.push(s.top());
						s.pop();
					} else if(x.top() == ")" && s.top() == "("){
						x.pop();
						s.pop();
					} else s.pop();
				} else if(s.top() == "}" || s.top() == "{"){
					if(y.empty() || s.top() == "}"){
						y.push(s.top());
						s.pop();
					} else if(y.top() == "}" && s.top() == "{"){
						y.pop();
						s.pop();
					} else s.pop();
				} else s.pop();
			}
			return x.empty() && y.empty();
		}
	}

	//Запись текста в Stack
	stack<string> PushString(string Text, stack<string> x){
		string Number = "";
		for(int i = 0; i < Text.length(); i++){
			switch(Text[i]){
			case '.':
				if(Number != "" && Number != "-")
					Number += ".";
				break;
			case '-':
				if(x.empty()){
					if (Number == "") Number += '-';
					else if(Number != ""){
						if(Number.back() == '.')
							Number.pop_back();
						x.push(Number);
						x.push("-");
						Number = "";
					}
				}else if(!TypeIntOrDouble(x.top()) && Number == "")
					Number += '-';
				else if(TypeIntOrDouble(x.top())){
					x.push("-");
					Number = "";
				} else if(Number != ""){
					if(Number.back() == '.')
						Number.pop_back();
					x.push(Number);
					x.push("-");
					Number = "";
				}
				break;
			case '0':
				if(Number == "" || Number == "-")
					Number += "0";
				else if((Number == "-0" || Number == "0") && x.top() == "("){
					x.push("0");
					Number = "";
				} else if(Number != "")
					Number += "0";
				break;
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				Number += Text[i];
				break;
			case '(':
			case ')':
			case '+':
			case '*':
			case '/':
				if(Number != ""){
					if(Number.back() == '.' || Number == "-")
						Number.pop_back();
					else if(Number == "-0")
						Number = "0";
					x.push(Number);
				}
				x.push(string(1, Text[i]));
				Number = "";
				break;
			default:
				break;
			}

			if(i == Text.length() - 1){
				if(Number != ""){
					if(Number.back() == '.' || Number == "-")
						Number.pop_back();
					else if(Number == "-0")
						Number = "0";
					x.push(Number);
				}
				Number = "";
			}
		}

		return x;
	}

	//Переворо Stack
	stack<string> Flip(stack<string> s1){
		stack<string> s2;
		for(int i = 0, size = s1.size(); i < size; i++){
			s2.push(s1.top());
			s1.pop();
		}
		return s2;
	}

	//Вывод Stack
	void Print(){
		stack<string> s2 = Flip(stl);
		for(int i = 0, size = s2.size(); i < size; i++){
			cout << s2.top();
			s2.pop();
		}
		cout << endl;
	}

	//Вывод результатов вычисление
	void PrintResult(){
		cout << Calculation(Flip(stl));
	}
	

};





int main(){
    
	string Text = "(-2.5 +(23.12-2*3.4)/(4*2.1-7))*5.125";
	STL stl(Text);
	if(!stl.Brack()){
		cout << "Error: Not balance brack!\n";
		return 0;
	}
	stl.Print();
	stl.PrintResult();
}
