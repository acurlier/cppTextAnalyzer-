//
// Created by augustin on 21/09/2021.
//
#include <iostream>
#include <unistd.h>
#include <glog/logging.h>

#include <limits>

#include "LocalTxtListRetriever.hpp"
#include "TxtSourceRetriever.hpp"
#include "BstClientBuilder.hpp"
#include "Utility.hpp"
#include "TxtSelectionInteractor.hpp"
#include "TextIndexManipulator.hpp"


void printHelp();
void prettyPrint(const std::string &selection, concatMetrics txtMetrics, const int &topListLength, const int & minWordLength, const int & minOccurence);

int main(int argc, char *argv[]) { 

// std::setlocale(LC_ALL, "en_US.utf8");
// Initialize Google’s logging library.
google::InitGoogleLogging(argv[0]);
if(argc == 1) {printHelp();}    
// go into indexing mode
else if (strcmp(argv[1], "-p") == 0) {

    std::string listAddress("sourceList.txt");
    std::string txtListAddress(listAddress); // 

    LocalTxtListRetriever myTxTListRetriever(txtListAddress);
    std::vector<std::vector<std::string>> structTextList = myTxTListRetriever.returnAvailableTxtList();

    // go into auto indexing mode
    if (strcmp(argv[2],"--a")==0) {

        for (int i(0); i <structTextList.size(); i++) {
            std::string currentText(structTextList[i][0]);
            std::string currentAuthor(structTextList[i][1]);
            std::string currentAddress(structTextList[i][2]);
            std::cout << "---------" << std::endl;
            std::cout << "Processing entry: " << i+1 << " over " << structTextList.size() << " - " << currentText << " from " << currentAuthor << std::endl;

            TxtSourceRetriever mySourceRetriever(currentAddress);
            std::string retrievedSource = mySourceRetriever.returnRetrievedSource();

            BstClientBuilder myClient(retrievedSource);
            std::string saveTreeFileName(currentText + ".tree");
            std::string saveTextFileName(currentText + ".stxt");
            myClient.buildTree(saveTreeFileName);
            mySourceRetriever.saveText(saveTextFileName);   

        }

    // go into interactive indexing mode
    } else if (strcmp(argv[2],"--i")==0)  {

        if (structTextList.size() == 0) {std::cout << "*FATAL ERROR* Unable to open sourceFile.txt or load its content ... did you move it from /resources to /build/bin ?" << std::endl; exit;} else {

            Utility::printFrame(structTextList);

            LOG(INFO) << "[main] Sucessfully located and loaded the local source file";

            TxtSelectionInteractor myInteractor(structTextList);
            bool valTest = false;
            int userSelection;

            std::string textName("");

            while (!valTest) { //iterate as long as the user doesn't provide a correct input
                std::cout << "*** Please indicate your selection (enter desired book index in the console) ***\n" ;
                std::cin >> userSelection;
                std::cout << '\n';
                valTest = myInteractor.setUserSelection(userSelection);
                if (!valTest) {
                    std::cout << "! Incorrect input, please try again !\n";
                } else {
                    textName = myInteractor.returnTextName();
                    std::string returnNamed(textName);
                    std::cout << "You have selected: " << returnNamed << std::endl;
                    LOG(INFO) << "[main] Text " << returnNamed << " selected by user from the list";
                }
            }

            TxtSourceRetriever mySourceRetriever(myInteractor.returnTextAddress());
            std::string retrievedSource = mySourceRetriever.returnRetrievedSource();

            BstClientBuilder myClient(retrievedSource);
            std::string saveTreeFileName(textName + ".tree");
            std::string saveTextFileName(textName + ".stxt");
            myClient.buildTree(saveTreeFileName);
            mySourceRetriever.saveText(saveTextFileName);
        }

        // print help
        } else {
            printHelp();
        }
    // go into interactive read mode
    } else if (strcmp(argv[1],"-u")==0) {

        TextIndexManipulator myManipulator;
        int index=0;
        std::vector<std::string> discoveredFile(myManipulator.discoverAvailableFiles());
        
        if (discoveredFile.size() == 0) 
        {std::cerr << "*FATAL ERROR* There is no input files (.tree) in the /bin directory, please run bstIndexing -p -- i first" << std::endl; exit;} 
        else {

            for (const std::string &files : discoveredFile)
            {
                std::cout << "*** Processed files discovered: ***\n" ;
                index++;
                std::cout << index << " - " << files << std::endl;
            };

            std::cout << "Please enter the index of the file you wish to process: ";
            int answer(-1);
            bool validAnswer(false);
            while (!validAnswer){
                std::cin >> answer; std::cin.ignore();
                if ((int) answer >0 && (int) answer <=index) {validAnswer=true;}
            }
            
            std::string selection = discoveredFile[answer-1];
            int topLength(10); // length of the top lists of most / least used words
            int lengthMin(6); // minimum size of words to considered
            int minOccur(5); // minimum number of occurences to be considered
            concatMetrics selectedTxtMetrics(myManipulator.displayMetrics(selection, topLength, lengthMin,minOccur));
            prettyPrint(selection, selectedTxtMetrics, topLength, lengthMin, minOccur);
        }

    // print help
    } else {
        printHelp();

    } return 0;
}

void printHelp() {

    std::string toPrint = R"(
**** 
HELP
****

This program is used to index the content of a (large) input text, and generate some metrics about it. There are 3 user modes that can be accessed from the command line:

1. An interactive processing mode:
This mode allows you to select a specific text to process from a list (sourceList.txt), it will ask you what you want to display during the course of the program,
will save the results and terminate. 

You can launch this mode with: bstIndexing -p --i

2. An automatic processing mode:
This mode will sequentially select the elements from sourceList.txt, run the proper processing, will save the results and terminate. 
You can launch this mode with: bstIndexing -p --a

3. An interactive exploration mode: 
This will allow you to "load" the results of a previous indexing sequence and:
    1. get metrics about this text.
    2. look for a specific term in the text, get the number of occurrences anf being proposed to display these occurrences in their context.

Of course you will first need to process at least one text before being able to use this mode.
You can access this mode with: bstIndexing -u
    )";

    std::cout << toPrint;
};


void prettyPrint(const std::string &selection, concatMetrics txtMetrics, const int &topListLength, const int & minWordLength, const int & minOccurence)
{
    std::cout << "The text : " << selection << std::endl;
    std::cout << "* Is made of : " << txtMetrics.first << " unique words" << std::endl;
    std::cout << "* Longuest word used in the text that has more than " << minOccurence << " occurences : " << txtMetrics.second.mostFreq.first.first << std::endl;
    
    std::cout << "* Top " << topListLength << " words used the most, that have more than " << minWordLength << " letters:"  << std::endl;
    entry currElement;
    while(!txtMetrics.second.highWordCount.empty())
    {
        currElement = txtMetrics.second.highWordCount.front();
        txtMetrics.second.highWordCount.pop();
        std::cout << "\t" << currElement.first.first << "  - with " << currElement.second << " occurence(s)" << std::endl;
    }

    std::cout << "* There are " << txtMetrics.second.lowWordCount.size() << " words that appear exactly " << minOccurence << " times";
    int ctr(0);
    bool bigList(txtMetrics.second.lowWordCount.size()>20);
    int listSize = txtMetrics.second.lowWordCount.size();
    if(bigList) {std::cout << ", among which:" << std::endl;} else {std::cout << ":" << std::endl;}
    while(!txtMetrics.second.lowWordCount.empty())
    {
        currElement = txtMetrics.second.lowWordCount.front();
        txtMetrics.second.lowWordCount.pop();
        if(bigList) {
            if (ctr <= 10 || ctr > (listSize-11)) 
            {std::cout << "\t" << currElement.first.first << std::endl;}
            else if (ctr == 11) {std::cout << "\t..." << std::endl;}
        } else {
            std::cout << "\t" << currElement.first.first << std::endl;
        }
        ctr++;        
    }


}