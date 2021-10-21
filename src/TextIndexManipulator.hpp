#pragma once
#include <iostream>
#include <vector>

class TextIndexManipulator
{

private:
std::string m_text;
std::string m_title;
std::string m_author;
std::vector<std::string> m_availableFiles;

std::vector<std::string> discoverAvailableFiles();
void getText(const std::string &fileName); // get xxx_text file and load text and basic info in memory
void generateIndex(const std::string &fileName); // get xxx_tree file and load the symbol table in memory
std::vector<std::string> returnTxtMetrics(const int &fileRef);
std::string returnWordContext(const std::string search);

public:
void displayAvailableFiles();
void displayMetrics();
void displayWordContext();

};