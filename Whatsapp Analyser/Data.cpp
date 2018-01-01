#include "Data.h"

Data::Data()
{
}

Data::~Data()
{
}

void Data::getRawData(std::string address){

	std::ifstream t(address);
	std::stringstream buffer;
	buffer << t.rdbuf();

	rawDataString = buffer.str();
	std::vector<std::string> rawDataVector0 = splitString(rawDataString, '\n');

	//Ignore first line because it's the "your msgs are encrypted thing"
	for (int i = 1; i < rawDataVector0.size(); i++){

		//Check if string has comma or is empty
		if (rawDataVector0.at(i).find(",") && rawDataVector0.at(i) != ""){

			//Check if the string follows date format
			if (isDate(getSubstringUntilCharacter(rawDataVector0.at(i), 0, ','))){
				rawDataVector.push_back(rawDataVector0.at(i));
			}
			else{
				rawDataVector[rawDataVector.size() - 1] = rawDataVector[rawDataVector.size() - 1] + rawDataVector0.at(i);
			}
		}

	}

	int a = 0;

}

bool Data::isDate(std::string dateStr){

	bool rtn = true;

	const char* dateCStr = dateStr.c_str();
	for (int i = 0; i < dateStr.length(); i++){
		if (*dateCStr != '/' && 
			*dateCStr != '0' &&
			*dateCStr != '1' &&
			*dateCStr != '2' &&
			*dateCStr != '3' &&
			*dateCStr != '4' &&
			*dateCStr != '5' &&
			*dateCStr != '6' &&
			*dateCStr != '7' &&
			*dateCStr != '8' &&
			*dateCStr != '9'){
			rtn = false;
			break;
		}

		dateCStr++;

	}

	return rtn;

}

void Data::getCleanedData(){

	for (int i = 0; i < rawDataVector.size(); i++)
	{

		std::string line = rawDataVector.at(i);

		if (line.find("Messages to this chat and calls are now secured with end-to-end encryption.") != std::string::npos) {
			continue;
		}

		//Clean the data
		Message message;

		DateTime dateTime;

		//Process date
		std::string dateString = getSubstringUntilCharacter(line, 0, ',');
		std::vector<std::string> dateStringVector = splitString(dateString, '/');
		dateTime.year = std::atoi(dateStringVector.at(2).c_str());
		dateTime.month = std::atoi(dateStringVector.at(1).c_str());
		dateTime.day = std::atoi(dateStringVector.at(0).c_str());

		//Process time
		std::string timeString = line.substr(dateString.length() + 2, 8); //+2 for the comma and space, time is always 8 chars long
		std::vector<std::string> timeStringVector = splitString(timeString, ':');
		dateTime.hour = std::atoi(timeStringVector.at(0).c_str());
		dateTime.minute = std::atoi(timeStringVector.at(1).c_str());
		dateTime.second = std::atoi(timeStringVector.at(2).c_str());

		message.dateTime = dateTime;

		//Process name
		int processedLength = dateString.length() + 2 + timeString.length() + 2; //+2 for the comma and space
		std::string remainingString = line.substr(processedLength, line.length() - processedLength); 

		message.name = getSubstringUntilCharacter(remainingString, 0, ':');
		if (std::find(names.begin(), names.end(), message.name) == names.end()){
			names.push_back(message.name);
		}

		//Process content
		std::string content = remainingString.substr(message.name.length() + 2, remainingString.length() - (message.name.length() + 2));
		message.content = content;

		cleanedData.push_back(message);

	}

}
