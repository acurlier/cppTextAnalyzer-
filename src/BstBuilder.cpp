
#include <iostream>
#include "BstNode.hpp"
#include "BstBuilder.hpp"

BstBuilder::BstBuilder(BstNode* root): m_root(root) {}

// **** private methods ****
BstNode* BstBuilder::put(std::string key, BstNode* currentNode) {
    if(currentNode == NULL)
    {
        currentNode = new BstNode(key);
        currentNode->setValue(1);
        currentNode->setLeftNode(NULL);
        currentNode->setRightNode(NULL);
    }

    else if(key < currentNode->getKey()) {
        currentNode->setLeftNode(BstBuilder::put(key,currentNode->getLeftNode()));
    }
    
    else if(key > currentNode->getKey()) {
        currentNode->setRightNode(BstBuilder::put(key,currentNode->getRightNode()));
    }
    
    else { // if the node correspondig to the current key already exists, we increment its value
        currentNode->setValue(currentNode->getValue()+1);
    }
    return currentNode;

};

void BstBuilder::inOrder(BstNode* targetNode) {
        if(targetNode == NULL) return;
        inOrder(targetNode->getLeftNode());
        std::cout << targetNode->getKey() << " - " << targetNode->getValue() << std::endl;
        inOrder(targetNode->getRightNode());
}

BstNode* BstBuilder::makeEmpty(BstNode* startNode) {
        if(startNode == NULL)
            return NULL;
        {
            makeEmpty(startNode->getLeftNode());
            makeEmpty(startNode->getRightNode());
            delete startNode;
        }
        return NULL;
    };

// **** API methods ****
void BstBuilder::put(std::string key) {
    BstBuilder::put(key, m_root);
};

void BstBuilder::displayContent() {
    BstBuilder::inOrder(m_root);
    BstBuilder::makeEmpty(m_root);
};
