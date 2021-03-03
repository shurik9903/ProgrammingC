#include "pch.h"
#include "CA.h"

using namespace std;

extern const IID IID_IUnknown = 0;
extern const IID IID_IX = 1;
extern const IID IID_IY = 2;
extern const IID IID_IZ = 3;

HRESULT __stdcall CA::QueryInterface(const IID& iid, void** ppv){
	if(iid == IID_IUnknown){
		cout << "QueryInterface: Вернуть указатель на IUnknown\n";
		*ppv = static_cast<IX*>(this);
	} else if(iid == IID_IX){
		cout << "QueryInterface: Вернуть указатель на IX\n";
		*ppv = static_cast<IX*>(this);
	} else if(iid == IID_IY){
		cout << "QueryInterface: Вернуть указатель на IY\n";
		*ppv = static_cast<IY*>(this);
	} else{
		cout << "QueryInterface: Интерфейс не поддерживается\n";
		*ppv = NULL;
		return 0;
	}
	reinterpret_cast<IUnknown*>(*ppv)->AddRef(); 
	return 1;
};