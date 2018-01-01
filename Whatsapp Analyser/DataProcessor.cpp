#include "DataProcessor.h"

void DataProcessor::setTotalMessageCount(std::vector<Message> &cleanedData){
	m_totalMessageCount = cleanedData.size();
}

void DataProcessor::setTotalCharCount(std::vector<Message> &cleanedData){

	int charCount = 0;

	for (int i = 0; i < cleanedData.size(); i++){
		charCount += cleanedData.at(i).content.length();
	}

	m_totalCharCount = charCount;
}

void DataProcessor::setTotalWordCount(std::vector<Message> &cleanedData){

	int wordCount = 0;

	for (int i = 0; i < cleanedData.size(); i++){
		wordCount += splitString(cleanedData.at(i).content, ' ').size();
	}

	m_totalWordCount = wordCount;

}

void DataProcessor::setMeanCharCount(std::vector<Message> &cleanedData){

	m_meanCharCount = m_totalCharCount / m_totalMessageCount;

}

void DataProcessor::setMeanMessageCount(std::vector<Message> &cleanedData){

	m_meanWordCount = m_totalWordCount / m_totalMessageCount;

}

void DataProcessor::setTopWords(std::vector<Message> &cleanedData){

}

void DataProcessor::setFrequencies(std::vector<Message> &cleanedData){

}

void DataProcessor::print(){

}