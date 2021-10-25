#pragma once

#include <iostream>
#include <vector>

class TxtSourceRetriever {
public:
    TxtSourceRetriever(const std::string webAddress);
    std::string returnRetrievedSource();
    void saveText(std::string fileAddress);

private:
    std::string downloadSource();
    std::string txtContent;
    const std::string m_address;
    std::string m_source;
};
