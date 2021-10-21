
#include <iostream>
#include <vector>
#include "TxtSelectionInteractor.hpp"

TxtSelectionInteractor::TxtSelectionInteractor(const std::vector<std::vector<std::string>> &txtList): m_userSelection(-1), m_txtList(txtList) 
{}

bool TxtSelectionInteractor::setUserSelection(const int &userSelection)
{
    return TxtSelectionInteractor::checkUserChoiceValidity(userSelection);
};

std::string TxtSelectionInteractor::returnTextName()
{
    return m_txtList[m_userSelection - 1][0];
};

std::string TxtSelectionInteractor::returnTextAddress() {
    return m_txtList[m_userSelection - 1][2];
};

bool TxtSelectionInteractor::checkUserChoiceValidity(int const &userSelection) {
    // std::cout << std::isdigit(userSelection);
    if ((userSelection > 0) && (userSelection <= m_txtList.size())) {
        m_userSelection = userSelection;
        return true;
} else {return false;}
};
