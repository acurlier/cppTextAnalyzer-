#pragma once

#include <iostream>
#include "BstNode.hpp"


class BstBuilder
{
public:
void put(std::string key);
void setRoot(BstNode* root);
BstNode* get();
void displayContent();


private:
BstNode* m_root;
BstNode* put(std::string key, BstNode* currentNode);
void inOrder(BstNode* targetNode);
BstNode* makeEmpty(BstNode* startNode);

};