#include "IX.h"
#include "IY.h"

class CB :public IX, public IY{
private:
	int a, b;
public:
	CB();
	~CB();
	void Fx();
	void Fy();
};

