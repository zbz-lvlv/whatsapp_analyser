#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <istream>
#include <string>
#include <sstream>
#include "Structs.h"

class Data
{
public:
	Data();
	~Data();

	void getRawData(std::string address);
	void getCleanedData();
	bool isDate(std::string dateStr);

private:

	//One string representing everything
	std::string rawDataString;
	std::vector<std::string> rawDataVector;

	//Line by line data of chat
	std::vector<Message> cleanedData;

	//Extract out the names
	std::vector<std::string> names;

};