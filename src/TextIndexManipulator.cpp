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
// it is possible to set the minimum length of words to be considered, as well as their minimum number of occurence
void TextIndexManipulator::generateIndex(const std::string &fileName, const int & lengthMin,  const int & minOccurence) {
       
    std::cout << "Opening tree file ... "<< std::endl;
    std::ifstream inputStream(fileName);
    std::string myinput;
    // int i(0);
    if(!inputStream) {std::cout << "Error opening the file: " << fileName << std::endl; return;}

    bool isKey = true;
    std::string tempKey("");
    std::string value("");
    m_wordCount = 0;

    // get the content of the file: the key and its value are separated by a \t
    while  (!inputStream.eof()) {
        if (isKey) { inputStream >> tempKey;} else {
            inputStream >> value; m_wordCount++;
            // load into the vector only the entries that match the spec
            if(std::stoi(value) >= minOccurence && tempKey.size() >= lengthMin) {
                m_treeVect.push_back({{tempKey, tempKey.size()},std::stoi(value)});}
        }
        isKey = !isKey;
    }
    inputStream.close();
    std::cout << "Index table loaded successfuly ! "<< std::endl;
}

/*
Work on the text index loaded as a member variable (m_treeMap)
- determine number of words used
- pair it with the results of the generateMetrics member function
*/
concatMetrics TextIndexManipulator::returnTxtMetrics(const int & topListLength, const int &occurenceMatch)
{

    return {m_wordCount, TextIndexManipulator::generateMetrics(topListLength, occurenceMatch)};

};

/*
Work on the text index loaded as a member variable (m_treeVect)
- determine top x used words
- determine the list of words used exactly y times
- determine longest word used in the text
*/
returnMetrics TextIndexManipulator::generateMetrics(const int &topListLength, const int &occurenceMatch)
{
    returnMetrics returnedValues;
    returnedValues.mostFreq = {{"",0},0};

    textTree myTextTree(m_treeVect); // create a local copy
    // sort the entries using their count; but keeping the alpha ordering between words with the same count
    std::stable_sort(myTextTree.begin(), myTextTree.end(),[](auto &left, auto &right) {
    return left.second < right.second;}); 

    // for(entry ent: myTextTree)
    // {std::cout << ent.first.first << " - " << ent.second << std::endl;}

    for(int i(0); i < topListLength; i++)
    {int index = myTextTree.size() - 1 - i;
    returnedValues.highWordCount.push(myTextTree[index]);}

    for (const entry &myEntries : myTextTree) {
        if (myEntries.first.second >= returnedValues.mostFreq.first.second)
        {returnedValues.mostFreq = myEntries;}
        
        if (myEntries.second == occurenceMatch)
        returnedValues.lowWordCount.push(myEntries);
    }
    return returnedValues;
}

// **** API methods ****

std::pair<size_t, returnMetrics> TextIndexManipulator::displayMetrics(const std::string &selectedFile, const int &topListLength, const int & lengthMin,  const int & occurenceMatch){
    TextIndexManipulator::generateIndex(selectedFile, lengthMin, occurenceMatch);
    return TextIndexManipulator::returnTxtMetrics(topListLength, occurenceMatch);
};

// look for file in the execution directory and get the name of those with the .tree extension
std::vector<std::string> TextIndexManipulator::discoverAvailableFiles(){
    
    std::vector<std::string> completeOutput;
    std::string path = std::filesystem::current_path();;

    for (const auto & file : directory_iterator(path)){
        std::string currentFile(file.path());
        if (currentFile.compare(currentFile.size()-5,5,".tree") == 0)
        {completeOutput.push_back(currentFile);}
    }
    return completeOutput;
};
   

