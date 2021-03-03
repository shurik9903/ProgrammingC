#pragma once
typedef int HRESULT, IID;
typedef long ULONG;

class IUnknown{
public:
	virtual HRESULT __stdcall QueryInterface(const IID& iid, void** ppv) = 0;
	virtual ULONG __stdcall AddRef() = 0;
	virtual ULONG __stdcall Release() = 0;
};

IUnknown* CreateInstance();
