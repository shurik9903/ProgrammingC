#include "pch.h"
#include <iostream>
#include "IUnknown.h"
#include "IX.h"
#include "IY.h"
#include "IZ.h"

using namespace std;

void trace(const char* msg){ cout << msg << endl; }


static const IID IID_IUnknown = 0;
static const IID IID_IX = 1;
static const IID IID_IY = 2;
static const IID IID_IZ = 3;

//
// Клиент
//
int main(){

	setlocale(LC_ALL, "Russian");

	HRESULT hr;
	trace("Клиент: Получить указатель на IUnknown");
	IUnknown* pIUnknown = CreateInstance();

	trace("Клиент: Получить указатель на IX");
	IX* pIX = NULL;
	hr = pIUnknown->QueryInterface(IID_IX, (void**)&pIX);
	if(hr){
		trace("Клиент: IX получен успешно");
		pIX->Fx(); // Использовать интерфейс IX
	}
	trace("Клиент: Получить указатель на IY");
	IY* pIY = NULL;
	hr = pIUnknown->QueryInterface(IID_IY, (void**)&pIY);
	if(hr){
		trace("Клиент: IY получен успешно");
		pIY->Fy(); // Использовать интерфейс IY
	}
	trace("Клиент: Запросить неподдерживаемый интерфейс");
	IZ* pIZ = NULL;
	hr = pIUnknown->QueryInterface(IID_IZ, (void**)&pIZ);
	if(hr){
		trace("Клиент: Интерфейс IZ получен успешно");
		pIZ->Fz();
	} else{
		trace("Клиент: Не могу получить интерфейс IZ");
	}
	trace("Клиент: Получить интерфейс IY через интерфейс IX");
	IY* pIYfromIX = NULL;
	hr = pIX->QueryInterface(IID_IY, (void**)&pIYfromIX);
	if(hr){
		trace("Клиент: IY получен успешно");
		pIYfromIX->Fy();
	}
	trace("Клиент: Получить интерфейс IUnknown через IY");
	IUnknown* pIUnknownFromIY = NULL;
	hr = pIY->QueryInterface(IID_IUnknown, (void**)&pIUnknownFromIY);
	if(hr){
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
};