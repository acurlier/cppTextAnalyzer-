//
// Created by augustin on 24/09/2021.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>

#include "LocalTxtListRetriever.hpp"


LocalTxtListRetriever::LocalTxtListRetriever(std::string &fileRef): m_txtListAddress(fileRef), m_txtList("") 
{
}

std::vector<std::vector<std::string>> LocalTxtListRetriever::returnAvailableTxtList() {
    // public method to return the formated text list (for display into the console)
    std::vector<std::vector<std::string>> structTextList = returnTxtListFileContent();
    return structTextList;

};

std::vector<std::vector<std::string>> LocalTxtListRetriever::returnTxtListFileContent() //open the designated file and get the content as a string, then return it
{
    // parse the content of the text source file

    std::ifstream ifs(m_txtListAddress); // read the content of the file as a stream


    char elemDelimiter(';'); // element delimiter on the same line
    char lineDelimiter('\n'); // element delimiter to switch to next line

    std::vector<std::string> tokensLines;
    std::vector<std::string> tokensElementBuffer;
    std::vector<std::vector<std::string>> AllFileTokens;

    std::string tempTextListLine;
    std::string tempElement;

    while(std::getline(ifs, tempTextListLine, lineDelimiter))    // Tokenizing w.r.t. line feed character
    {
        std::stringstream tempStream(tempTextListLine); // convert back each line back to a stream, not too elegant though...
        while(std::getline(tempStream, tempElement, elemDelimiter))
        {
            tokensElementBuffer.push_back(tempElement); // populate the line buffer w/ the various elements of the line
        }
        AllFileTokens.push_back(tokensElementBuffer);
        tokensElementBuffer.clear();
    }

    return AllFileTokens;
};



