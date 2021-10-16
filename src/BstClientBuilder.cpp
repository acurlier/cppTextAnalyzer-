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
    
    // std::cout << "Tree built!" << std::endl;
    myBstBuilder.displayContent();
};

void BstClientBuilder::cleanWord(std::string &myString) {

    for (char letter:myString) { // remove Uppercase
        if (std::isupper(letter)) break;
        // myString[0] = std::tolower(myString[0]); 
        // std::tolower(letter);
    }

    if (std::regex_match(myString,std::regex("([.;,!?:_\"“”—-]+.*)|(.*)[.;,!?:_\"“”—-]+"))) {

        std::regex punct("[.;,!?:_\"“”—-]+");
        std::stringstream result;
        std::regex_replace(std::ostream_iterator<char>(result), myString.begin(), myString.end(), punct, "");
        myString = result.str();
    }
};