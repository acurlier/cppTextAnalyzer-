//
// Created by augustin on 24/09/2021.
//
#pragma once

#include <iostream>
#include <vector>

class LocalTxtListRetriever {
public:
    LocalTxtListRetriever(std::string &fileRef);
    std::vector<std::vector<std::string>> returnAvailableTxtList();
    
private:
    std::vector<std::vector<std::string>> returnTxtListFileContent();
    std::vector<std::vector<std::string>> m_unwrappedTxtList;
    std::string &m_txtListAddress;
    std::string m_txtList;
    int m_userSelection;
};
