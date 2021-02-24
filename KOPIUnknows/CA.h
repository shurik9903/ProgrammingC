#include "IX.h"
#include "IY.h"
#include <iostream>

using namespace std;

class CA : public IX, public IY{
public:
	virtual HRESULT __stdcall QueryInterface(const IID& iid, void** ppv);
	virtual ULONG __stdcall AddRef(){ return 0; }
	virtual ULONG __stdcall Release(){ return 0; }
	// Реализация интерфейса IX
	virtual void __stdcall Fx(){ cout << "Fx" << endl; }
	// Реализация интерфейса IY
	virtual void __stdcall Fy(){ cout << "Fy" << endl; }
};

