#include "pch.h"
#include <iostream>
#include "IX.h"
#include "IY.h"

int main()
{
    
	IX* Ix = ReturnXCA();
	Ix->Fx();
	Ix = ReturnXCB();
	Ix->Fx();
	delete Ix;

	IY* Iy = ReturnYCB();
	Iy->Fy();
	delete Iy;

	system("pause");
}

