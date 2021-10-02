#pragma once

#include <iostream>
#include "BstNode.hpp"


class BstBuilder
{
public:
BstBuilder(BstNode* root);
void put(std::string key);
BstNode* get();
void displayContent();

private:
BstNode* m_root;
BstNode* put(std::string key, BstNode* currentNode);
void inOrder(BstNode* targetNode);
BstNode* makeEmpty(BstNode* startNode);

};