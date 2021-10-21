#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <regex>

#include "BstNode.hpp"
#include "BstBuilder.hpp"
#include "BstClientBuilder.hpp"

/*
this object is used as a client to use the BSTBuilder API, it sweep through the text and put the keys in the BST
it is also used to save the resulting sorted table for later use.
*/
BstClientBuilder::BstClientBuilder(std::string const &inputText): m_inputText(inputText) 
{ }

void BstClientBuilder::buildTree(const std::string &fileName) {
    std::cout << "Start building tree ...";
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
    
    std::cout << "Tree built!" << std::endl;
    myBstBuilder.saveContent(fileName);
};

void BstClientBuilder::cleanWord(std::string &myString) {

    for (int i=0; i<myString.length(); i++) { // remove Uppercase, some words are written entirerly in uppercase
        if (std::islower(myString[i])) { // if we reach the lowercase part of the word we stop
            break; 
        } else if (std::isalpha(myString[i])) { // TODO: I trust tolower() will mess up with non alpha characters
            myString[i] = std::tolower(myString[i]);
        }
    }

    if (std::regex_match(myString,std::regex("([.;,!?:_\"“”—-]+.*)|(.*)[.;,!?:_\"“”—-]+"))) { // lets detect words with punctuation marks stuck either before or after

        std::regex punct("[.;,!?:_\"“”—-]+");
        std::stringstream result;
        std::regex_replace(std::ostream_iterator<char>(result), myString.begin(), myString.end(), punct, ""); // we remove punctuation marks stuck either before or after the word
        myString = result.str();
    }
};