#include "pch.h"
#include "CA.h"

IUnknown* CreateInstance(){
	IUnknown* pI = static_cast<IX*>(new CA);
	pI->AddRef();
	return pI;
}

