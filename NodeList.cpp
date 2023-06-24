#include "NodeList.h"
#include <iostream>

NodeList::NodeList(){
    length = 0;
}

NodeList::~NodeList(){
    // Delete all the nodes in the list
    for (int i = 0; i < length; i++) {
        delete nodes[i];
    }
}

NodeList::NodeList(NodeList& other){
   // Perform a deep copy of the other NodeList
    length = other.length;
    for (int i = 0; i < length; i++) {
        nodes[i] = new Node(*(other.nodes[i]));
    }
}

int NodeList::getLength(){
    return length;
}

void NodeList::addElement(Node* newNode) {
    // Check if the NodeList is already full
    if (length >= NODE_LIST_ARRAY_MAX_SIZE) {
        std::cout << "Cannot add element. NodeList is full." << std::endl;
        return;
    }

    // Make a copy of the newNode and add it to the list
    Node* copyNode = new Node(*newNode);
    nodes[length] = copyNode;
    length++;
}


Node* NodeList::getNode(int i){
    // Check if the index is within the valid range
    if (i >= 0 && i < length) {
        return nodes[i];
    }

    std::cout << "Invalid index. Returning nullptr." << std::endl;
    return nullptr;
}