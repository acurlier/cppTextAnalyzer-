#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <regex>
#include <map>
#include <queue>

#include "TextIndexManipulator.hpp"
using std::filesystem::directory_iterator;



// **** private methods ****

// get xxx_tree file and load the symbol table in memory
void TextIndexManipulator::generateIndex(const std::string &fileName) {
       
    std::cout << "Opening tree file ... "<< std::endl;
    std::ifstream inputStream(fileName);
    std::string myinput;
    // int i(0);
    if(!inputStream)
    {
        std::cout << "Error opening the file: " << fileName << std::endl;
        return;
    }

    bool isKey = true;
    std::string tempKey("");
    std::string value("");

    // get the content of the file: the key and its value are separated by a \t
    while  (!inputStream.eof()) {

        if (isKey) 
        {
            inputStream >> tempKey;

        } else {
            inputStream >> value;
            m_treeMap[tempKey] = {std::stoi(value), (int) tempKey.length()};
        }
        isKey = !isKey;
    }
    inputStream.close();
    std::cout << "Index table loaded successfuly ! "<< std::endl;
}

/*
Work on the text index loaded as a member variable (m_treeMap)
- determine number of words used
- pair it with the results of the moreThanLessThan member function
*/
concatMetrics TextIndexManipulator::returnTxtMetrics()
{

    return {m_treeMap.size(), TextIndexManipulator::moreThanLessThan(300,3)};

};

/*
Work on the text index loaded as a member variable (m_treeMap)
- determine words with more than 30 occurences
- determine words with more than 1 occurences but less than 5
- determine longest word used in the text (repeated)
- determine longest word used in the text (single intance)
*/
returnMetrics TextIndexManipulator::moreThanLessThan(int occurencesMin,int occurencesMax)
{
    returnMetrics returnedValues;
    returnedValues.mostFreqSingle = {"",{0,0}};
    returnedValues.mostFreqMultiple = {"",{0,0}};

    for (const mapEntries &entries : m_treeMap)
    {
        // fill the queues with words corresponding to the specification
        if (entries.second[0] > occurencesMin)
        {
            returnedValues.highWordCount.push(entries);
        } else if (entries.second[0] < occurencesMax && entries.second[0] > 1) {
            returnedValues.lowWordCount.push(entries);
        }
        
        if (entries.second[0] == 1) { // find the longest word met only once
            if (entries.second[1] >= returnedValues.mostFreqSingle.second[1])  
            {returnedValues.mostFreqSingle = entries;}
        } else if (entries.second[0] > 1) { // find the longest word met more than once
            if (entries.second[1] >= returnedValues.mostFreqMultiple.second[1]) 
            {returnedValues.mostFreqMultiple = entries;}
        }

    }

    return returnedValues;

}

// **** API methods ****

std::pair<size_t, returnMetrics> TextIndexManipulator::displayMetrics(const std::string &selectedFile){
    TextIndexManipulator::generateIndex(selectedFile);
    return TextIndexManipulator::returnTxtMetrics();
};

// look for file in the execution directory and get the name of those with the .tree extension
std::vector<std::string> TextIndexManipulator::discoverAvailableFiles(){
    
    std::vector<std::string> completeOutput;
    std::string path = std::filesystem::current_path();;

    for (const auto & file : directory_iterator(path)){
        
        std::string currentFile(file.path());
        if (std::regex_match(currentFile,std::regex(".*(.tree)")));//|.*(.stxt)"))) 
        { 
            // std::cout << currentFile << std::endl;
            completeOutput.push_back(currentFile);
        }
    }
    
    return completeOutput;
};
   

