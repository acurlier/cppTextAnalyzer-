//
// Created by augustin on 24/09/2021.
//
#include <iostream>
#include <vector>

#include "Utility.h"

void Utility::printFrame(std::vector<std::vector<std::string>> &matrixToPrint) {
    int lineIndex = 0;
    if (matrixToPrint.size()==0)
    {
        std::cout << "Nothing to print !!" << std::endl;
    }

    for (int i = 0; i < matrixToPrint.size(); i++) {
        lineIndex = lineIndex+1;
        std::cout << lineIndex << " - ";
        for (int j = 0; j < matrixToPrint[i].size(); j++) {
            std::cout << matrixToPrint[i][j] << "";
            if (j < matrixToPrint[i].size()-1) {std::cout << " - ";}
        }
        std::cout << std::endl;
    }
}