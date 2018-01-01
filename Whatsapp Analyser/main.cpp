#include <iostream>
#include <stdio.h>
#include <string.h>
#include "Data.h"

int main(){

	Data data;
	data.getRawData("C:\\Users\\Zbz\\Documents\\Visual Studio 2013\\Projects\\Whatsapp Analyser\\Debug\\chat.txt");
	data.getCleanedData();

	std::getchar();
	return 0;

}