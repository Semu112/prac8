#include "LinkedList.h"

#include <iostream>
#include <limits>

Node* LinkedList::get_head(){
    return this->head;
}

void LinkedList::set_head(Node* newHead){
    this->head = newHead;

    return;
}

bool LinkedList::isEmpty(){
    if(this->get_head() == nullptr){
        return true;
    }
    else{
        return false;
    }
}

void LinkedList::addFront(int newItem){

    Node* newNode = new Node;

    newNode->set_data(newItem);
    newNode->set_next(this->get_head());
    this->set_head(newNode);

    return;
    
}

void LinkedList::addEnd(int newItem){

    Node* endNode = this->getEnd();

    Node* newNode = new Node;
    newNode->set_data(newItem);

    if(endNode == nullptr){ //If list has one element or less
        this->set_head(newNode);
    }
    else{
        endNode->set_next(newNode);
    }

    return;

}

void LinkedList::addAtPosition(int position, int newItem){

    if(position<=1){
        this->addFront(newItem);
    }
    else{

        Node* nodeBefore = this->getNode(position-1);

        //If conditions for if we are trying to add an item at or beyond the end index
        if(nodeBefore != nullptr){

            Node* nextNode = nodeBefore->get_next();
            if(nodeBefore->get_next() != nullptr){ //If there is an element at the index we've chosen

                Node* newNode = new Node;
                newNode->set_data(newItem);
                newNode->set_next(nextNode); 

                nodeBefore->set_next(newNode);

                return;

            }
        }
        this->addEnd(newItem);

    }

    return;
}

void LinkedList::deleteFront(){

    Node* newHead = this->get_head()->get_next();

    delete this->get_head();

    this->set_head(newHead);

    return;

}

void LinkedList::deletePosition(int position){

    if(position<1){
        std::cout << "Outside range" << std::endl;
        return;
    }

    Node* nodeBefore = this->getNode(position-1);
    if(nodeBefore == nullptr){
        std::cout << "Outside range" << std::endl;
        return;
    }

    Node* node = nodeBefore->get_next();

    if(node == nullptr){ //Assuming that if get_next() is called on a null pointer it will return a null pointer
        std::cout << "Outside range" << std::endl;
        return;
    }

    nodeBefore->set_next(node->get_next());

    delete node;

    return;

}

void LinkedList::deleteEnd(){

    if(this->get_head() != nullptr){
        if(this->get_head()->get_next() == nullptr){ //If there's only one element in the list

            delete this->get_head();
            this->set_head(nullptr);

        }
        else{

            Node* nodeBefore = this->getBeforeEnd();
            Node* node = nodeBefore->get_next();

            nodeBefore->set_next(nullptr);

            delete node;

        }
    }

    return;

}

int LinkedList::getItem(int position){

    int data;

    if(!(position<1)){
        Node* node = this->getNode(position);

        if(node == nullptr){
            data = std::numeric_limits<int>::max();
        }
        else{
            data = node->get_data();
        }
    }
    else{
        data = std::numeric_limits<int>::max();
    }

    std::cout << data << " ";

    return data;

}

int LinkedList::search(int item){

    Node* itr = this->get_head();

    if(itr == nullptr){
        return 0;
    }

    int pos = 1;

    while(itr->get_data() != item){

        itr = itr->get_next();

        if(itr == nullptr){

            pos = 0;
            break;
        }

        pos++;

    }

    std::cout << pos << " ";

    return pos;

}

void LinkedList::printItems(){

    Node* itr = this->get_head();
    if(itr == nullptr){
        return;
    }

    while(itr != nullptr){

        std::cout << itr->get_data() << " ";
        itr = itr->get_next();

    }

    return;

}

Node* LinkedList::getNode(int position){

    Node* itr = this->get_head();

    for(int i = 0; i<position-1; i++){
        if(itr == nullptr){
            return nullptr;
        }

        itr = itr->get_next();
    }

    return itr;
}

Node* LinkedList::getBeforeEnd(){

    Node* itr = this->get_head();

    if(itr != nullptr){ //If list has at least 1 element

        if(itr->get_next()->get_next() != nullptr){ //If list has at least 2 elements

            while(itr->get_next()->get_next() != nullptr){

                itr = itr->get_next();

            }
        }        
    }

    return itr;

}

Node* LinkedList::getEnd(){

    Node* itr = this->get_head();

    if(itr != nullptr){ //If list has at least 1 element

        while(itr->get_next() != nullptr){

            itr = itr->get_next();

        }    
    }

    return itr;

}