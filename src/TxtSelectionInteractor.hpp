#pragma once

#include <iostream>
#include <vector>

class TxtSelectionInteractor {
public:
    TxtSelectionInteractor(const std::vector<std::vector<std::string>> &txtList);
    bool setUserSelection(const int &userSelection);
    std::string returnTextName();
    std::string returnTextAddress();
    
private:
    bool checkUserChoiceValidity(int const &userSelection);
    const std::vector<std::vector<std::string>> &m_txtList;
    int m_userSelection;
};