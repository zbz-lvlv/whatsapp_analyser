#pragma once

struct DateTime{

	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;

};

struct Message
{

	DateTime dateTime;
	std::string name;
	std::string content;

};

std::string getSubstringUntilCharacter(std::string const& s, int startIndex, char character)
{
	std::string::size_type pos = s.find(character);
	if (pos != std::string::npos)
	{
		return s.substr(startIndex, pos);
	}
	else
	{
		return s;
	}
}

std::vector<std::string> splitString(std::string const& str, char delimiter){

	const char* cstr = str.c_str();
	std::vector<char> stringBuffer;
	std::vector<std::string> splitStringReturn;

	for (int i = 0; i < str.length(); i++){

		char thisChar = *cstr;

		if (thisChar == delimiter){
			//Add it to string for return
			std::string stringReturn(stringBuffer.begin(), stringBuffer.end());
			splitStringReturn.push_back(stringReturn);

			//Remove from stringbuffer
			stringBuffer.clear();
		}
		//Last char
		else if (i == str.length() - 1){

			stringBuffer.push_back(thisChar);

			//Add it to string for return
			std::string stringReturn(stringBuffer.begin(), stringBuffer.end());
			splitStringReturn.push_back(stringReturn);

			//Remove from stringbuffer
			stringBuffer.clear();
		}
		else {
			stringBuffer.push_back(thisChar);
		}

		cstr++;

	}

	return splitStringReturn;

}
