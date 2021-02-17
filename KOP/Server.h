#include "AbstractServer.h"

class Server: public AbstractServer{
private:
	int a, b;
public:
	Server();
	~Server();
	void func();
};

