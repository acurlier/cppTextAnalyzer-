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

/*
//.app -w(--i)/r


*/
void prettyPrint(const std::string &selection, concatMetrics txtMetrics);

int main(int argc, char *argv[]) { 

// std::setlocale(LC_ALL, "en_US.utf8");
// Initialize Google’s logging library.
google::InitGoogleLogging(argv[0]);

    if (argv[1] == "-p") {
        
        // go into indexing mode
        if (argv[2] == "--a") {

        } else if (argv[2] == "--i") {


        
        } else {
            // print help
        }
    } else if (argv[1] == "-u") {
        // go into read mode
    } else {
        // print help
    }

    TextIndexManipulator myManipulator;
    std::cout << "*** Processed files discovered: ***\n" ;
    int i=0;
    for (const std::string &files : myManipulator.discoverAvailableFiles())
    {
        i++;
        std::cout << i << " - " << files << std::endl;
    };

    
    std::string selection = "Frankenstein or, The Modern Prometheus.tree";
    concatMetrics selectedTxtMetrics(myManipulator.displayMetrics(selection));
    prettyPrint(selection, selectedTxtMetrics);
    

    // std::string listAddress("sourceList.txt");
    // std::string txtListAddress(listAddress); // 

    // LocalTxtListRetriever myTxTListRetriever(txtListAddress);
    // std::vector<std::vector<std::string>> structTextList = myTxTListRetriever.returnAvailableTxtList();

    // Utility::printFrame(structTextList);

    // LOG(INFO) << "[main] Sucessfully located and loaded the local source file";

    // TxtSelectionInteractor myInteractor(structTextList);
    // bool valTest = false;
    // int userSelection;

    // std::string textName("");

    // while (!valTest) { //iterate as long as the user doesn't provide a correct input
    //     std::cout << "*** Please indicate your selection (enter desired book index in the console) ***\n" ;
    //     std::cin >> userSelection;
    //     std::cout << '\n';
    //     valTest = myInteractor.setUserSelection(userSelection);
    //     if (!valTest) {
    //         std::cout << "! Incorrect input, please try again !\n";
    //     } else {
    //         textName = myInteractor.returnTextName();
    //         std::string returnNamed(textName);
    //         std::cout << "You have selected: " << returnNamed << std::endl;
    //         LOG(INFO) << "[main] Text " << returnNamed << " selected by user from the list";
    //     }
    // }

    // TxtSourceRetriever mySourceRetriever(myInteractor.returnTextAddress());
    // std::string retrievedSource = mySourceRetriever.returnRetrievedSource();
    
    // BstClientBuilder myClient(retrievedSource);
    // std::string saveTreeFileName(textName + ".tree");
    // std::string saveTextFileName(textName + ".stxt");
    // myClient.buildTree(saveTreeFileName);
    // mySourceRetriever.saveText(saveTextFileName);


    return 0;
}

void printHelp() {
    std::string helpText("");
    // = "There are 3 modes for this program:\n 1. An interactive processing mode:\n"
    // "This mode allows you to select a specific text to process from a list (sourceList.txt),"
    // "it will ask you what you want to display during the course of the program,"
    // "will save the results and terminate. You can launch this mode with:"
    // "bstIndexing -p --i\n"
    // "2. An automatic processing mode:\n"
    // "This mode will sequentially select the elements from sourceList.txt, run the proper processing, will save the results"
    // "and terminate. You can launch this mode with:\n"
    // "bstIndexing -p --a\n"

    // "3. An interactive exploration mode: this will allow you to "load" the results of a previous indexing sequence and\n"
    // "   1. get metrics about this text.\n"
    // "   2. look for a specific term in the text, get the number of occurrences anf being proposed to display these occurrences in their context.\n"
    
    // "Of course you will first need to process at least one text before being able to use this mode.\n"
    // "You can access this mode by typing: bstIndexing -u\n";

    std::cout << helpText;
};


void prettyPrint(const std::string &selection, concatMetrics txtMetrics)
{
    std::cout << "The text : " << selection << std::endl;
    std::cout << "* Is made of : " << txtMetrics.first << " single words" << std::endl;
    std::cout << "* Longuest word used only once : " << txtMetrics.second.mostFreqSingle.first << std::endl;
    std::cout << "* Longuest word used multiple times : " << txtMetrics.second.mostFreqSingle.first << std::endl;
    
    std::cout << "* Words with more than 30 occurences : "  << std::endl;
    mapEntries currElement;
    while(!txtMetrics.second.highWordCount.empty())
    {
        currElement = txtMetrics.second.highWordCount.front();
        txtMetrics.second.highWordCount.pop();
        std::cout << "\t" << currElement.first << " with " << currElement.second[0] << " occurence(s)" << std::endl;
    }

    std::cout << "* Words with less than 5 & more than 1 occurences : "  << std::endl;
    while(!txtMetrics.second.lowWordCount.empty())
    {
        currElement = txtMetrics.second.lowWordCount.front();
        txtMetrics.second.lowWordCount.pop();
        std::cout << "\t" << currElement.first << " with " << currElement.second[0] << " occurence(s)" << std::endl;
        
    }


}