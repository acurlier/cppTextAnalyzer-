#include <iostream>
#include <vector>
#include <cpr/cpr.h>
#include "TxtSourceRetriever.hpp"

TxtSourceRetriever::TxtSourceRetriever(const std::string webAddress) :
        m_address(webAddress) {
        }


std::string TxtSourceRetriever::returnRetrievedSource() {
    std::string source = downloadSource();
    return source;
};

std::string TxtSourceRetriever::downloadSource() {
    std::cout << "Fetch address : " << m_address <<  std::endl;
    cpr::Response r = cpr::Get(cpr::Url{m_address});
    std::cout << "status_code: " << r.status_code << std::endl;
    std::cout << "content-type: " << r.header["content-type"]<< std::endl;       // application/json; charset=utf-8
    return r.text;                         // JSON text string
};

