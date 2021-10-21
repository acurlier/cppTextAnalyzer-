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



int main(int argc, char *argv[]) {

// std::setlocale(LC_ALL, "en_US.utf8");



    // Initialize Google’s logging library.
    google::InitGoogleLogging(argv[0]);
    
    std::string listAddress = "sourceList.txt";
    std::string txtListAddress(listAddress); // 

    LocalTxtListRetriever myTxTListRetriever(txtListAddress);
    std::vector<std::vector<std::string>> structTextList = myTxTListRetriever.returnAvailableTxtList();

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
    
    // std::string sampleString("If ;a man has reported- to you, that a certain? person speaks ill of you, "
    // "do not make any defense to what has been -told you:; but reply, _The man did not "
    // "know the rest of my ,faults, for he would not have "
    // "mentioned these! only. - Epictetus");
    //BstClientBuilder myClient(sampleString);
    
    BstClientBuilder myClient(retrievedSource);
    std::string saveFileName(textName + ".tree");
    myClient.buildTree(saveFileName);

    return 0;
}
