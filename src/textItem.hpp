#pragma once
#include <iostream>

class textItem
{

private:
std::string m_text;
std::string m_title;
std::string m_author;
std::string m_address;

int m_nunberOfWord;


public:
void setTextContent(std::string text);
void setTextData(std::string text, std::string title, std::string author, std::string address);

std::string getContent();
std::string getData();

};