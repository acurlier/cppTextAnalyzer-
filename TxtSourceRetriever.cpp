//
// Created by augustin on 24/09/2021.
//
#include <iostream>
#include <vector>
#include "TxtSourceRetriever.h"

TxtSourceRetriever::TxtSourceRetriever(int &userSelection,
                                       std::vector<std::vector<std::string>> &txtList):
                                       m_userSelection(userSelection), m_txtList(txtList){}

