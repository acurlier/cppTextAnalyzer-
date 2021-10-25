#include <iostream>
#include <vector>
#include <cpr/cpr.h>
#include "TxtSourceRetriever.hpp"

TxtSourceRetriever::TxtSourceRetriever(const std::string webAddress) :
        m_address(webAddress), m_source("") {
        }


std::string TxtSourceRetriever::returnRetrievedSource() {
    m_source = downloadSource();
    return m_source;
};

std::string TxtSourceRetriever::downloadSource() {
    std::cout << "Fetch address : " << m_address <<  std::endl;
    cpr::Response r = cpr::Get(cpr::Url{m_address});
    std::cout << "status-code: " << r.status_code << std::endl;
    std::cout << "content-type: " << r.header["content-type"]<< std::endl;       // application/json; charset=utf-8
    return r.text;                         // JSON text string
};

void TxtSourceRetriever::saveText(std::string fileAddress) {
    std::ofstream outputSaveStream;
    outputSaveStream.open(fileAddress);
    outputSaveStream << m_source;
    outputSaveStream.close();
}

