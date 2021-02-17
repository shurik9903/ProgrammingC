#include "pch.h"
#include "Server.h"
#include <iostream>

using namespace std;

Server::Server(){ a = 5; b = 10; }

Server::~Server(){
	cout << "Server destruct\n";
}

void Server::func(){
	int c = a + b;
	cout << "Func: " << c << endl;
}