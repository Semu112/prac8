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
    newNode->set_next(get_head());

    set_head(newNode);

    return;
    
}

void LinkedList::addEnd(int newItem){

    Node* itr = get_head(); //sets endPtr to the start of the list

    Node* newNode = new Node;
    newNode->set_data(newItem);

    if(itr == nullptr){
        this->set_head(newNode);
    }
    else{

        while(itr->get_next() != nullptr){ //Iterates through list until endPtr is nullPtr

            itr = itr->get_next();

        }

        itr->set_next(newNode);

    }

    return;

}

void LinkedList::addAtPosition(int position, int newItem){

    if(position == 0){
        this->addFront(newItem);
    }
    else{

        Node* newNode = new Node;
        newNode->set_data(newItem);

        Node* itr = get_head();

        for(int i = 0; i<position-1; i++){
            itr = itr->get_next();

            if(itr == nullptr){
                this->addEnd(newItem);
                return;
            }
        }

        Node* nextNode = itr->get_next();

        newNode->set_next(nextNode);

        itr->set_next(newNode);

    }

    return;
}

void LinkedList::deleteFront(){

    Node* newHead = this->get_head()->get_next();

    delete[] this->get_head();

    this->set_head(newHead);

    return;

}

void LinkedList::deleteEnd(){

    Node* itr = this->get_head();

    while(itr->get_next()->get_next() != nullptr){

        itr = itr->get_next();

    }

    delete[] itr->get_next();

    itr->set_next(nullptr);

    return;

}

void LinkedList::deletePosition(int position){

    if(position<1){
        std::cout << "Outside range" << std::endl;
        return;
    }

    Node* itr = get_head();

    for(int i = 0; i<position-1; i++){
        itr = itr->get_next();
    }

    if(itr == nullptr){
        std::cout << "Outside range" << std::endl;
        return;
    }

    Node* temp = itr->get_next();

    itr->set_next(itr->get_next()->get_next());

    delete[] temp;

    return;

}

int LinkedList::getItem(int position){

    Node* itr = get_head();

    for(int i = 0; i<position; i++){
        itr = itr->get_next();
    }

    int data;

    if(itr == nullptr){
        data = std::numeric_limits < int >::max();
    }
    else{
        data = itr->get_data();
    }

    std::cout << data << " ";

    return data;

}

int LinkedList::search(int item){

    Node* itr = get_head();

    int pos = 1;

    while(itr->get_data() != item){

        if(itr == nullptr){
            pos = 0;
            break;
        }

        itr = itr->get_next();
        pos++;

    }

    std::cout << pos << " ";

    return pos;

}

void LinkedList::printItems(){

    Node* itr = this->get_head();

    while(itr != nullptr){

        std::cout << itr->get_next()->get_data() << " ";
        itr = itr->get_next();
    }

    return;

}