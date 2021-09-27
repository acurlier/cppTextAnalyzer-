//
// Created by augustin on 21/09/2021.
//
#include <iostream>
#include <unistd.h>

#include <limits>
#include "LocalTxtListRetriever.hpp"
#include "TxtSourceRetriever.hpp"
#include "Utility.hpp"

int main(int argc, char *argv[]) {

    char tmp[256];
    getcwd(tmp, 256);
    std::cout << "Current working directory: " << tmp << std::endl;

    std::string txtListAddress("sourceList.txt");

    LocalTxtListRetriever myTxTListRetriever(txtListAddress);

    std::vector<std::vector<std::string>> structTextList = myTxTListRetriever.returnAvailableTxtList();
    Utility::printFrame(structTextList);
    TxtSourceRetriever mySourceRetriever(structTextList);

    bool valTest = false;

    int userSelection;

    while (!valTest) { //we
        std::cout << "*** Please indicate your selection (enter desired book index in the console) ***\n" ;
        userSelection = 1;
        //std::cin >> userSelection;
        std::cout << '\n';
        valTest = mySourceRetriever.setUserSelection(userSelection);
        if (!valTest) {
            std::cout << "! Incorrect input, please try again !";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max());
        } else {
            std::cout << "You have selected: " << mySourceRetriever.returnTextName() << std::endl;
        }
    }
    std::string retrievedSource = mySourceRetriever.returnRetrievedSource();
    std::cout << retrievedSource;
    return 0;
}
