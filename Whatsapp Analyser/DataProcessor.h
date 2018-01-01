#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <map>
#include "Structs.h"

class DataProcessor
{
public:
	DataProcessor();
	~DataProcessor();

	void setTotalMessageCount(std::vector<Message> &cleanedData);
	void setTotalCharCount(std::vector<Message> &cleanedData);
	void setTotalWordCount(std::vector<Message> &cleanedData);

	void setMeanCharCount(std::vector<Message> &cleanedData);
	void setMeanMessageCount(std::vector<Message> &cleanedData);

	void setTopWords(std::vector<Message> &cleanedData);
	void setFrequencies(std::vector<Message> &cleanedData);

	void print();

private:

	int m_totalMessageCount;
	int m_totalCharCount;
	int m_totalWordCount;

	int m_meanCharCount;
	int m_meanWordCount;

	std::array<std::string, 10> topWords;
	std::map<int, int> frequencies; //Key - hour of day (0-23), value - number of msgs

};