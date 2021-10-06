#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <regex>

class BstClientBuilder {
public:
BstClientBuilder(std::string const &inputText);
void buildTree();
void saveTree(std::string fileName);

private:
std::string const &m_inputText;
std::regex m_regexPonctuatedWords;

void cleanWord(std::string &myString);
};

