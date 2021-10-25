#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <regex>
#include <map>
#include <queue>

typedef std::pair <std::string,std::vector<int>> mapEntries;
struct returnMetrics
{
    std::queue<mapEntries> highWordCount;
    std::queue<mapEntries> lowWordCount;
    mapEntries mostFreqSingle;
    mapEntries mostFreqMultiple;
};
typedef std::pair <size_t,returnMetrics> concatMetrics;

class TextIndexManipulator
{

private:
std::string m_text;
std::string m_title;
std::string m_author;
std::vector<std::string> m_availableFiles;
std::map<std::string,std::vector<int>> m_treeMap; // store the word instances, their nb of occurence and their number of character

returnMetrics moreThanLessThan(int occurencesMin,int occurencesMax);

void getText(const std::string &fileName); // get xxx_text file and load text and basic info in memory
void generateIndex(const std::string &fileName); // get xxx_tree file and load the symbol table in memory
std::pair<size_t, returnMetrics> returnTxtMetrics();
// std::string returnWordContext(const std::string search);

public:
std::vector<std::string> discoverAvailableFiles();
concatMetrics displayMetrics(const std::string &selectedFile);
// void displayWordContext(); ... maybe later

};