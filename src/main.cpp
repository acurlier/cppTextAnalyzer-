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

int main(int argc, char *argv[]) {


/*std::string sampleString("If a man has reported to you, that a certain person speaks ill of you, "
"do not make any defense to what has been told you: but reply, The man did not "
"know the rest of my faults, for he would not have "
"mentioned these only. - Epictetus");\
*/

std::string sampleString("rise and rise again, until lambs become lions");

BstClientBuilder myClient(sampleString);
myClient.buildTree();


/*
    // Initialize Google’s logging library.
    google::InitGoogleLogging(argv[0]);

    std::string txtListAddress("sourceList.txt");
    LocalTxtListRetriever myTxTListRetriever(txtListAddress);
    LOG(INFO) << "[main] Sucessfully located and loaded the local source file";

    std::vector<std::vector<std::string>> structTextList = myTxTListRetriever.returnAvailableTxtList();
    Utility::printFrame(structTextList);
    TxtSourceRetriever mySourceRetriever(structTextList);

    bool valTest = false;

    int userSelection;

    while (!valTest) { //iterate as long as the user doesn't provide a correct input
    //TODO: integrate control for non integer inputs
        std::cout << "*** Please indicate your selection (enter desired book index in the console) ***\n" ;
        std::cin >> userSelection;
        std::cout << '\n';
        valTest = mySourceRetriever.setUserSelection(userSelection);
        if (!valTest) {
            std::cout << "! Incorrect input, please try again !\n";
        } else {
            std::string returnNamed(mySourceRetriever.returnTextName());
            std::cout << "You have selected: " << returnNamed << std::endl;
            LOG(INFO) << "[main] Text " << returnNamed << " selected by user from the list";
        }
    }
    std::string retrievedSource = mySourceRetriever.returnRetrievedSource();
    //std::cout << retrievedSource;

    */
    return 0;
}
