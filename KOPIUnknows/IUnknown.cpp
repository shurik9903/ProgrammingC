#include "pch.h"
#include "CA.h"
#include "IX.h"
#include "IY.h"
#include "IZ.h"

IUnknown* CreateInstance(){
	IUnknown* pI = static_cast<IX*>(new CA);
	pI->AddRef();
	return pI;
};

