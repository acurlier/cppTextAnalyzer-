#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>

#include "BstNode.hpp"
#include "BstBuilder.hpp"
#include "BstClientBuilder.hpp"

BstClientBuilder::BstClientBuilder(std::string const &inputText): m_inputText(inputText) {}

void BstClientBuilder::buildTree() {

    BstNode* rootNode = new BstNode("");
    BstBuilder myBstBuilder(rootNode);

    
    std::istringstream iss(m_inputText);
    do
    {
        std::string subs;
        iss >> subs;
        BstClientBuilder::cleanWord(subs);
        myBstBuilder.put(subs);

    } while (iss);

    myBstBuilder.displayContent();
};

void BstClientBuilder::cleanWord(std::string &myString) {
    std::transform(myString.begin(), myString.end(), myString.begin(),
        [](unsigned char c){ return std::tolower(c); });
};