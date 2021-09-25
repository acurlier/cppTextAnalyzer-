//
// Created by augustin on 21/09/2021.
//
#include <iostream>
#include "LocalTxtListRetriever.h"
#include "TxtSourceRetriever.h"
#include "Utility.h"

int main(int argc, char *argv[]) {

    /*
    char tmp[256];
    getcwd(tmp, 256);
    std::cout << "Current working directory: " << tmp << std::endl;
    */

    std::string txtListAddress("sourceList.txt");
    LocalTxtListRetriever myTxTListRetriever(txtListAddress);
    std::cout << "*** Please indicate your selection (enter desired book index in the console) ***\n" ;
    std::vector<std::vector<std::string>> structTextList = myTxTListRetriever.returnAvailableTxtList();
    Utility::printFrame(structTextList);


    int userSelection;
    std::cin >> userSelection;
    std::cout << '\n';

    return 0;
}