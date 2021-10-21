#pragma once

#include <iostream>
#include <fstream>
#include "BstNode.hpp"


class BstBuilder
{
public:
void put(const std::string &key);
void setRoot(BstNode* root);
BstNode* get();
void saveContent(const std::string &fileName);


private:
BstNode* m_root;
BstNode* put(std::string key, BstNode* currentNode);
void inOrder(BstNode* targetNode, std::ofstream &ouputStream);
BstNode* makeEmpty(BstNode* startNode);

};