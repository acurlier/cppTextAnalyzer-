#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <regex>

#include "BstNode.hpp"
#include "BstBuilder.hpp"
#include "BstClientBuilder.hpp"

BstClientBuilder::BstClientBuilder(std::string const &inputText): m_inputText(inputText) 
{
    //std::regex m_regexPonctuatedWords(".*[,;.]");
    std::regex m_regexPonctuatedWords("([a-z]*)");
    }

void BstClientBuilder::buildTree() {
 
    std::istringstream iss(m_inputText);
    std::string subs;
    
    BstBuilder myBstBuilder;
    bool firstString = true;
    while(iss >> subs)
    {
        BstClientBuilder::cleanWord(subs);
        if (firstString) {
            BstNode* rootNode = new BstNode(subs);
            myBstBuilder.setRoot(rootNode);
            firstString = false;
        } else {
            myBstBuilder.put(subs);
        }
    };
    
    std::cout << "Tree built!";
    myBstBuilder.displayContent();
};

void BstClientBuilder::cleanWord(std::string &myString) {

    myString[0] = std::tolower(myString[0]); // remove Uppercase

    if (std::regex_match(myString,std::regex("(.*)([,.;-?!]\")"))) { // remove punctuation at the end of the words
        //std:: cout << "matched :"<< myString << "\n";
        myString.pop_back();
    }

    // std::transform(myString.begin(), myString.end(), myString.begin(),
    //     [](unsigned char c){ return std::tolower(c); });
};