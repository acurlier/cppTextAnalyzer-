#include <iostream>
#include <memory>
#include "BstNode.hpp"


//**** API methods ***

BstNode::BstNode(std::string key) : m_key(key) {};

void BstNode::setValue(int value)
{
    m_value = value;
};

void BstNode::setRightNode(BstNode* providedNode)
{
    m_rightNode = providedNode;
};

BstNode* BstNode::getRightNode()
{
    return m_rightNode;
};

void BstNode::setLeftNode(BstNode* providedNode)
{
    m_leftNode = providedNode;
};

BstNode* BstNode::getLeftNode()
{
    return m_leftNode;
};

std::string BstNode::getKey(){
    return m_key;
};

int BstNode::getValue(){
    return m_value;
};
