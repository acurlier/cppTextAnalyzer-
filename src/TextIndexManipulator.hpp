#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <regex>
#include <map>
#include <queue>

typedef std::pair<std::pair<std::string,int>,int> entry;
typedef std::vector<entry> textTree;
struct returnMetrics
{
    std::queue<entry> highWordCount;
    std::queue<entry> lowWordCount;
    entry mostFreq;
};
typedef std::pair <size_t,returnMetrics> concatMetrics;

class TextIndexManipulator
{

private:
std::string m_text;
int m_wordCount;
textTree m_treeVect; // store the word instances, their nb of occurence and their number of character

returnMetrics generateMetrics(const int &topListLength, const int &occurenceMatch);

void getText(const std::string &fileName); // get xxx_text file and load text and basic info in memory
void generateIndex(const std::string &fileName, const int & lengthMin,  const int & minOccurence); // get xxx_tree file and load the symbol table in memory
std::pair<size_t, returnMetrics> returnTxtMetrics(const int & topListLength, const int &occurenceMatch);
// std::string returnWordContext(const std::string search);

public:
std::vector<std::string> discoverAvailableFiles();
concatMetrics displayMetrics(const std::string &selectedFile, const int &topListLength, const int & lengthMin,  const int & minOccurence);
// void displayWordContext(); ... maybe later

};