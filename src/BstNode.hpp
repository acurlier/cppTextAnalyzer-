#pragma once
#include <iostream>

class BstNode
{
private:
    BstNode* m_leftNode;
    BstNode* m_rightNode;
    bool isBlack; // this is used to build red-black balanced trees
    std::string m_key; // this is the string used as the key for the node
    int m_value; // this is the int used as the value for the node

public:
    BstNode(std::string key);
    std::string getKey();

    void setRightNode(BstNode* providedNode);
    BstNode* getRightNode();

    void setLeftNode(BstNode* providedNode);
    BstNode* getLeftNode();

    void setValue(int value);
    int getValue();

    bool isThisNodeBlack();
};