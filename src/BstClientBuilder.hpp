#pragma once

#include <iostream>

class BstClientBuilder {
public:
BstClientBuilder(std::string const &inputText);
void buildTree();
void saveTree(std::string fileName);

private:
std::string const &m_inputText;
void cleanWord(std::string &myString);
};

