
#include <iostream>
#include <fstream>
#include "BstNode.hpp"
#include "BstBuilder.hpp"

// **** private methods ****
BstNode* BstBuilder::put(std::string key, BstNode* currentNode) { // this put the considered key into the tress
    if(currentNode == nullptr) // if we reach the bottom of the tree without correspondance, we create a new node
    {
        currentNode = new BstNode(key);
        currentNode->setValue(1);
        currentNode->setLeftNode(nullptr);
        currentNode->setRightNode(nullptr);
    }

    else if(key < currentNode->getKey()) { 
        currentNode->setLeftNode(BstBuilder::put(key,currentNode->getLeftNode()));
    }
    
    else if(key > currentNode->getKey()) {
        currentNode->setRightNode(BstBuilder::put(key,currentNode->getRightNode()));
    }
    
    else { // if we can find a node correspondig to the current key while going down the tree, we increment its value
        currentNode->setValue(currentNode->getValue()+1);
    }
    return currentNode;

};

void BstBuilder::inOrder(BstNode* targetNode, std::ofstream &ouputStream) { // this method allows to traverse the tree and writing the key - values pairs into a file
        
        if(targetNode == nullptr) return; // if we reach the bottom of the tree, we stop the recursive call
        
        inOrder(targetNode->getLeftNode(), ouputStream);
        std::string tempKey(targetNode->getKey());
        if (isalpha(tempKey[0])){ouputStream << targetNode->getKey() << "\t" << targetNode->getValue() << std::endl;} // add the tree element to the file only of it starts with a letter
        
        inOrder(targetNode->getRightNode(), ouputStream);
        
}

BstNode* BstBuilder::makeEmpty(BstNode* targetNode) {
        if(targetNode == nullptr)
            return nullptr;
        {
            makeEmpty(targetNode->getLeftNode());
            makeEmpty(targetNode->getRightNode());
            delete targetNode;
        }
        return nullptr;
    };

// **** API methods ****
void BstBuilder::setRoot(BstNode* rootNode) // this initialized the root of the tree
{
    m_root = rootNode;
    m_root->setValue(1);
    m_root->setLeftNode(nullptr);
    m_root->setRightNode(nullptr);
    
};

void BstBuilder::put(const std::string &key) { 
    BstBuilder::put(key, m_root);
};

void BstBuilder::saveContent(const std::string &fileName) {
    
    std::ofstream outputSaveStream;
    outputSaveStream.open(fileName);
    BstBuilder::inOrder(m_root, outputSaveStream);
    outputSaveStream.close();

    BstBuilder::makeEmpty(m_root); // clear the tree and free the allocated memory
};
