#include "pch.h"
#include <iostream>
#include "IUnknown.h"
#include <objbase.h>
#include "IX.h"
#include "IY.h"
#include "IZ.h"

using namespace std;

void trace(const char* msg){ cout << msg << endl; }

// {32bb8320-b41b-11cf-a6bb-0080c7b2d682}
static const IID IID_IX =
{0x32bb8320, 0xb41b, 0x11cf,
{0xa6, 0xbb, 0x0, 0x80, 0xc7, 0xb2, 0xd6, 0x82}};
// {32bb8321-b41b-11cf-a6bb-0080c7b2d682}
static const IID IID_IY =
{0x32bb8321, 0xb41b, 0x11cf,
{0xa6, 0xbb, 0x0, 0x80, 0xc7, 0xb2, 0xd6, 0x82}};
// {32bb8322-b41b-11cf-a6bb-0080c7b2d682}
static const IID IID_IZ =
{0x32bb8322, 0xb41b, 0x11cf,
{0xa6, 0xbb, 0x0, 0x80, 0xc7, 0xb2, 0xd6, 0x82}};
//
// Клиент
//
int main(){
	HRESULT hr;
	trace("Клиент: Получить указатель на IUnknown");
	IUnknown* pIUnknown = CreateInstance();

	trace("Клиент: Получить указатель на IX");
	IX* pIX = NULL;
	hr = pIUnknown->QueryInterface(IID_IX, (void**)&pIX);
	if(SUCCEEDED(hr)){
		trace("Клиент: IX получен успешно");
		pIX->Fx(); // Использовать интерфейс IX
	}
	trace("Клиент: Получить указатель на IY");
	IY* pIY = NULL;
	hr = pIUnknown->QueryInterface(IID_IY, (void**)&pIY);
	if(SUCCEEDED(hr)){
		trace("Клиент: IY получен успешно");
		pIY->Fy(); // Использовать интерфейс IY
	}
	trace("Клиент: Запросить неподдерживаемый интерфейс");
	IZ* pIZ = NULL;
	hr = pIUnknown->QueryInterface(IID_IZ, (void**)&pIZ);
	if(SUCCEEDED(hr)){
		trace("Клиент: Интерфейс IZ получен успешно");
		pIZ->Fz();
	} else{
		trace("Клиент: Не могу получить интерфейс IZ");
	}
	trace("Клиент: Получить интерфейс IY через интерфейс IX");
	IY* pIYfromIX = NULL;
	hr = pIX->QueryInterface(IID_IY, (void**)&pIYfromIX);
	if(SUCCEEDED(hr)){
		trace("Клиент: IY получен успешно");
		pIYfromIX->Fy();
	}
	trace("Клиент: Получить интерфейс IUnknown через IY");
	IUnknown* pIUnknownFromIY = NULL;
	hr = pIY->QueryInterface(IID_IUnknown, (void**)&pIUnknownFromIY);
	if(SUCCEEDED(hr)){
		cout << "Совпадают ли указатели на IUnknown? ";
		if(pIUnknownFromIY == pIUnknown){
			cout << "Да, pIUnknownFromIY == pIUnknown" << endl;
		} else{
			cout << "Нет, pIUnknownFromIY != pIUnknown" << endl;
		}
	}
	// Удалить компонент
	delete pIUnknown;
	return 0;
}