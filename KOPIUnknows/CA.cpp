#include "pch.h"
#include "CA.h"

using namespace std;

extern const IID IID_IX;
extern const IID IID_IY;
extern const IID IID_IZ;

HRESULT __stdcall CA::QueryInterface(const IID& iid, void** ppv){
	if(iid == IID_IUnknown){
		cout << "QueryInterface: ������� ��������� �� IUnknown\n";
		*ppv = static_cast<IX*>(this);
	} else if(iid == IID_IX){
		cout << "QueryInterface: ������� ��������� �� IX\n";
		*ppv = static_cast<IX*>(this);
	} else if(iid == IID_IY){
		cout << "QueryInterface: ������� ��������� �� IY\n";
		*ppv = static_cast<IY*>(this);
	} else{
		cout << "QueryInterface: ��������� �� ��������������\n";
		*ppv = NULL;
		return E_NOINTERFACE;
	}
	reinterpret_cast<IUnknown*>(*ppv)->AddRef(); 
	return S_OK;
};