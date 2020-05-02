#include "pch.h"
#include <iostream>
#include <random>
#include <cstring>
#include <stdlib.h>

using namespace std;

int main(){
	default_random_engine generate(random_device{}());
	uniform_int_distribution<int> Art(0,2);
	uniform_int_distribution<int> Word(0, 4);


	char Article[3][25]{{"an"}, {"the"}, {"a"}};
	
	char Noun[5][25]{{"dog"},{"cat"},{"flower"},{"human"},{"fish"}};
	
	char Verb[5][25]{{"stand"},{"tell"},{"watch"},{"ride"},{"read"}};
	
	char Pretext[5][25]{{"on"},{"in"},{"at"},{"by"},{"for"}};

	char Text[780];

	strcpy_s(Text, _countof(Text), Article[Art(generate)]);
	strcat_s(Text, _countof(Text), " ");
	strcat_s(Text, _countof(Text), Noun[Word(generate)]);
	strcat_s(Text, _countof(Text), " ");
	strcat_s(Text, _countof(Text), Verb[Word(generate)]);
	strcat_s(Text, _countof(Text), " ");
	strcat_s(Text, _countof(Text), Pretext[Word(generate)]);
	strcat_s(Text, _countof(Text), " ");
	strcat_s(Text, _countof(Text), Article[Art(generate)]);
	strcat_s(Text, _countof(Text), " ");
	strcat_s(Text, _countof(Text), Noun[Word(generate)]);
	strcat_s(Text, _countof(Text), ".");

	Text[0] = toupper(Text[0]);

	cout << Text;

	return 0;
}
