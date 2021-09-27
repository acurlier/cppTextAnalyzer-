//
// Created by augustin on 24/09/2021.
//

#ifndef CPPBINARYSEARCHTREE_TXTSOURCERETRIEVER_H
#define CPPBINARYSEARCHTREE_TXTSOURCERETRIEVER_H

#include <iostream>
#include <vector>

class TxtSourceRetriever {
public:
    TxtSourceRetriever(const std::vector<std::vector<std::string>> &txtList);
    bool setUserSelection(const int &userSelection);
    std::string returnTextName();
    std::string returnRetrievedSource();


private:
    bool checkUserChoiceValidity(int const &userSelection);
    std::string downloadSource(const std::string &address);
    std::string extractTextAddress();
    int m_userSelection;
    const std::vector<std::vector<std::string>> &m_txtList;
    std::string txtContent;
};


#endif //CPPBINARYSEARCHTREE_TXTSOURCERETRIEVER_H
