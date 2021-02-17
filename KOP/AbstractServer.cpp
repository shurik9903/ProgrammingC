#include "pch.h"
#include "Server.h"

AbstractServer* ReturnServer(){
	return new Server;
};

