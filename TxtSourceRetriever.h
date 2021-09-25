//
// Created by augustin on 24/09/2021.
//

#ifndef CPPBINARYSEARCHTREE_TXTSOURCERETRIEVER_H
#define CPPBINARYSEARCHTREE_TXTSOURCERETRIEVER_H

#include <iostream>
#include <vector>

class TxtSourceRetriever {
public:
    TxtSourceRetriever(int &userSelection, std::vector<std::vector<std::string>> &txtList);
    std::string returnRetrievedString();

private:
    int m_userSelection;
    std::vector<std::vector<std::string>> &m_txtList;
    std::string txtContent;
};


#endif //CPPBINARYSEARCHTREE_TXTSOURCERETRIEVER_H
