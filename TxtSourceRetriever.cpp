//
// Created by augustin on 24/09/2021.
//
#include <iostream>
#include <vector>

#include <cpr/cpr.h>
#include "TxtSourceRetriever.hpp"

TxtSourceRetriever::TxtSourceRetriever(const std::vector<std::vector<std::string>> &txtList) :
        m_txtList(txtList), m_userSelection(0) {}

bool TxtSourceRetriever::setUserSelection(const int &userSelection)
{
    m_userSelection = userSelection;
    return TxtSourceRetriever::checkUserChoiceValidity(userSelection);
};

std::string TxtSourceRetriever::returnTextName()
{
    return m_txtList[m_userSelection - 1][0];
};

std::string TxtSourceRetriever::returnRetrievedSource() {
    std::string address = TxtSourceRetriever::extractTextAddress();
    std::string source = downloadSource(address);
    return source;
};

bool TxtSourceRetriever::checkUserChoiceValidity(int const &userSelection) {
    return ((userSelection != 0) && (userSelection <= m_txtList.size()));
};

std::string TxtSourceRetriever::downloadSource(const std::string &address) {
    cpr::Response r = cpr::Get(cpr::Url{address});
    std::cout << r.status_code << std::endl;
    std::cout << r.header["content-type"]<< std::endl;       // application/json; charset=utf-8
    return r.text;                         // JSON text string
};

std::string TxtSourceRetriever::extractTextAddress() {
    return m_txtList[m_userSelection - 1][2];
};