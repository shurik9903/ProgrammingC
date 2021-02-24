#include "IUnknown.h"

class IX : public IUnknown{
public:
	virtual void __stdcall Fx() = 0;
};